<div>
    <table style="width:100%" >
    <?php
        $allstock = CS50::query("SELECT * FROM stocks WHERE user_id = ?", $_SESSION["id"]);
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        
        //var_dump($cash);
        if($cash[0]['cash'] > 0){
            echo("<tr> Your current cash is " . $cash[0]['cash'] . "</tr>");
        }
        else{
            echo("You are broke!");
        }
    ?>
    <form action="add_cash.php" method="post">
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                Add Funds
            </button>
        </div>
    </form>
        <tr>
        <th>Company Name</th>
        <th>Trading Symbol</th> 
        <th>Number of Shares</th>
        <th>Price</th>
        <th>Total Money in Shares</th>
        </tr>
    <?php
    
        //var_dump($allstock);
        foreach($allstock as $stock){
                $position = lookup($stock["symbol"]);
                $total = $position["price"] * $stock["shares"];
    ?>
                <tr>
                <td><?= $position["name"] ?></td>
                <td><?= $position["symbol"] ?></td>
                <td><?= $stock["shares"] ?></td>
                <td><?= $position["price"] ?></td>
                <td><?= $total ?></td>
                </tr>
    <?php
        }
    ?>
    </table>
</div>

