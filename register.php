<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if($_POST["username"] == "" || $_POST["password"] == "" || $_POST["password_confirm"] == ""){
            apologize("Please Ensure All Fields Are Filled.");
        }
        if($_POST["password"] == $_POST["password_confirm"]){
            $code = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
            if($code != 0){
                $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
                $id = $rows[0]["id"];
                $_SESSION["id"] = $id;
                redirect("index.php");
            }
            else{
                apologize("That Username Has Been Taken.");
            }
        }
        else{
            apologize("Please Ensure Password Fields Match.");
        }
        
    }

?>