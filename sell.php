<?php

    // configuration
    require("../includes/config.php");
    // if user reached page via GET (as by clicking a link or via redirect)
    $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("sell_form.php", ["title" => "Sell" ]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["stock_name"]);
        
        if($stock == ''){
            apologize("Sorry we could not find that stock.");
        }
        if($_POST['stock_amount'] <= 0){
            apologize("You must buy atleast one stock.");
        }
        if($_POST['stock_name'] = ''){
            apologize("You must enter a stock name.");
        }
        if(!preg_match('/^\d+$/', $_POST['stock_amount'])){
            apologize("You need a non-negative number with no symbols in the amount field.");
        }
        $sale = CS50::query("SELECT * FROM stocks WHERE user_id = ? AND symbol = ?", $_SESSION['id'], $stock['symbol']);
        //var_dump($sale);
        if($sale[0]['shares'] >= $_POST["stock_amount"]){
            $newcost = $stock["price"] * $_POST["stock_amount"];
            $newcash = round(floatval($cash[0]['cash']) + $newcost,2);
            CS50::query("UPDATE users SET cash = ? WHERE id = ?", $newcash, $_SESSION['id']);
            CS50::query("INSERT INTO `history`(`user_id`, `symbol`, `shares`, `method`, `price`) VALUES ( ?, ?, ?, ?, ?)", $_SESSION['id'], $stock['symbol'], $_POST['stock_amount'], 'SELL', $stock['price'] * $_POST['stock_amount']);
            CS50::query("INSERT INTO stocks (user_id, symbol, shares) VALUES (?,?,?) ON DUPLICATE KEY UPDATE shares = shares - VALUES(shares)", $_SESSION["id"], $stock["symbol"], $_POST["stock_amount"]);
            redirect("/");
        }
        else
        {
            apologize("You have no stock of that type to sell.");
        }
    }
?>