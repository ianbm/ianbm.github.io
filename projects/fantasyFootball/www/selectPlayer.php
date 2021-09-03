<HTML>
<style>
		body
		{
			background-image: url("http://wallup.net/wp-content/uploads/2016/05/25/176883-minimalism-geometry-hexagon-simple_background-monochrome-white_background.png");
			img {
				opacity: 0.5;
				filter: alpha(opacity=50);
				}
			background-repeat: no-repeat;
			background-size: cover;
		}
	</style>
<head>
	<title>Player Listing</title>
</head>
<BODY>
<header>
<center><H1>Player Listing</h1></center>
</header>
<center>
<?php   
session_start();
$conn = @mysqli_connect("localhost",$_SESSION['sess_username'],$_SESSION['sess_pass'],"fantasyfootball")
or die("Could not connect to a could not select database");

$sql = "SELECT * FROM players";
$result = @mysqli_query($conn, $query);

if($result = mysqli_query($conn, $sql)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
            echo "<tr>";
                echo "<th>playerID</th>";
                echo "<th>playerFirstName</th>";
                echo "<th>playerLastName</th>";
				echo "<th>teamID</th>";
            echo "</tr>";
        while($row = mysqli_fetch_array($result)){
            echo "<tr>";
                echo "<td>" . $row['playerID'] . "</td>";
                echo "<td>" . $row['playerFirstName'] . "</td>";
				echo "<td>" . $row['playerLastName'] . "</td>";
				echo "<td>" . $row['teamID'] . "</td>";
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