<html>
	<center>
		<h1>Input results</h1>
		<body>
			<?php
			session_start();
			$conn=mysqli_connect("localhost",$_SESSION['sess_username'],$_SESSION['sess_pass'],"fantasyfootball");
			
			$userID = $_POST['userID'];
			$playerID = $_POST['playerID'];
			
			$result=mysqli_query($conn, "INSERT INTO transactions (userID, playerID, transactionDate) VALUES ('$userID','$playerID',NOW())");

			if($result)
			{
				echo("Input data succeeded");
			}
				else
			{
				echo("Input data failed");
			}

			?>
			<br>
			<br>
			<form METHOD="LINK" ACTION="mainmenu.html">
				<input TYPE="submit" VALUE="Return to Main Menu">
			</form>
		</body>
	</center>
</html>