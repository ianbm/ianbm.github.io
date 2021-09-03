<html>
	<center>
		<h1>Update results</h1>
		<body>
			<?php
			session_start();
			$conn=mysqli_connect("localhost",$_SESSION['sess_username'],$_SESSION['sess_pass'],"fantasyfootball");
			
			$transactionID = $_POST['transactionID'];
			$userID = $_POST['userID'];
			$playerID = $_POST['playerID'];
			
			$result=mysqli_query($conn, "UPDATE transactions SET userID='$userID', playerID='$playerID' WHERE transactionID='$transactionID'");

			if($result)
			{
				echo("Update data succeeded");
			}
				else
			{
				echo("Update data failed");
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