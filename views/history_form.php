<div>
    <table style="width:100%" >
    <?php
        $allstock = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        
    ?>
        <tr>
        <th>Date</th>
        <th>Company Name</th>
        <th>Trading Symbol</th> 
        <th>Number of Shares</th>
        <th>Price</th>
        <th>Method</th>
        </tr>
    <?php
    
        //var_dump($allstock);
        foreach($allstock as $stock){
                $position = lookup($stock["symbol"]);
    ?>
                <tr>
                <td><?= $stock["date"] ?></td>
                <td><?= $position["name"] ?></td>
                <td><?= $position["symbol"] ?></td>
                <td><?= $stock["shares"] ?></td>
                <td><?= $stock["price"] ?></td>
                <td><?= $stock['method'] ?></td>
                </tr>
    <?php
        }
    ?>
    </table>
</div>