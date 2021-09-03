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
	<title>User Listing</title>
</head>
<BODY>
<header>
<center><H1>User Listing</h1></center>
</header>
<center>
<?php   
session_start();
$conn = @mysqli_connect("localhost",$_SESSION['sess_username'],$_SESSION['sess_pass'],"fantasyfootball")
or die("Could not connect to a could not select database");

$sql = "SELECT * FROM users";
$result = @mysqli_query($conn, $query);

if($result = mysqli_query($conn, $sql)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
            echo "<tr>";
                echo "<th>userID</th>";
				echo "<th>username</th>";
                echo "<th>userFirstName</th>";
                echo "<th>userLastName</th>";
				echo "<th>userEmail</th>";
				echo "<th>joinDate</th>";
            echo "</tr>";
        while($row = mysqli_fetch_array($result)){
            echo "<tr>";
                echo "<td>" . $row['userID'] . "</td>";
                echo "<td>" . $row['username'] . "</td>";
                echo "<td>" . $row['userFirstName'] . "</td>";
				echo "<td>" . $row['userLastName'] . "</td>";
				echo "<td>" . $row['userEmail'] . "</td>";
				echo "<td>" . $row['joinDate'] . "</td>";
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