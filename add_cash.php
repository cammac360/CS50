<?php

    // configuration
    require("../includes/config.php");
    // if user reached page via GET (as by clicking a link or via redirect)
    $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("portfolio.php", ["title" => "Portfolio" ]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        CS50::query("UPDATE users SET cash = ? WHERE id = ?", $cash[0]['cash'] + 500, $_SESSION['id']);
        redirect("/");
    }
?>