<?php

    // configuration
    require("../includes/config.php");
    $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy" ]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["stock_name"]);
        var_dump($_POST);
        if($stock == ''){
            apologize("Sorry we could not find that stock.");
        }
        if($_POST['stock_amount'] <= 0){
            apologize("You must buy atleast one stock.");
        }
        if($_POST['stock_name'] = ''){
            apologize("You must enter a stock name.");
        }
        if(!preg_match("/^\d+$/", $_POST["stock_amount"])){
            apologize("You need a non-negative number with no symbols in the amount field.");
        }
        $newcost = $stock["price"] * $_POST["stock_amount"];
        //var_dump($newcost);
        //var_dump(floatval($cash[0]['cash']));
        $newcash = round(floatval($cash[0]['cash']) - $newcost,2);
        //dump($stock);
        if($newcash > '0'){
            CS50::query("UPDATE users SET cash = ? WHERE id = ?", $newcash, $_SESSION['id']);
            //INSERT INTO portfolios (user_id, symbol, shares) VALUES(9, 'FREE', 10) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)
            CS50::query("INSERT INTO `history`(`user_id`, `symbol`, `shares`, `method`, `price`) VALUES ( ?, ?, ?, ?, ?)", $_SESSION['id'], $stock["symbol"], $_POST['stock_amount'], 'BUY', $stock['price'] * $_POST['stock_amount']);
            CS50::query("INSERT INTO stocks (user_id, symbol, shares) VALUES (?,?,?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $stock["symbol"], $_POST["stock_amount"]);
            redirect("/");
        }
        else{
            apologize("You dont have the money for that much stock.");
        }
    }
?>