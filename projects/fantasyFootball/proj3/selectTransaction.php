<HTML>
<head>
	<title>Data Listing</title>
</head>
<BODY>
<header>
<center><H1>Data Listing</h1></center>
</header>
<center>
<?php   
session_start();
$conn = @mysqli_connect("localhost",$_SESSION['sess_username'],$_SESSION['sess_pass'],"fantasyfootball")
or die("Could not connect to a could not select database");

$sql = "SELECT transactions.transactionID, users.username, players.playerFirstName, players.playerLastName, teams.teamName FROM teams, users, players, transactions WHERE transactions.userID=users.userID AND transactions.playerID=players.playerID AND teams.teamID=players.teamID";
$result = @mysqli_query($conn, $sql);

if($result = mysqli_query($conn, $sql)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
            echo "<tr>";
                echo "<th>transactionID</th>";
				echo "<th>username</th>";
				echo "<th>playerFirstName</th>";
                echo "<th>playerLastName</th>";
                echo "<th>teamName</th>";
            echo "</tr>";
        while($row = mysqli_fetch_array($result)){
            echo "<tr>";
                echo "<td>" . $row['transactionID'] . "</td>";
				echo "<td>" . $row['username'] . "</td>";
				echo "<td>" . $row['playerFirstName'] . "</td>";
                echo "<td>" . $row['playerLastName'] . "</td>";
                echo "<td>" . $row['teamName'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
        // Close result set
        mysqli_free_result($result);
    } else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}
// Close connection

// mysqli_close($link);

?>
<FORM METHOD="LINK" ACTION="MainMenu.html">
<INPUT TYPE="submit" VALUE="Return to Main Menu">
</form>
</center>
</div>
</body>
</html>