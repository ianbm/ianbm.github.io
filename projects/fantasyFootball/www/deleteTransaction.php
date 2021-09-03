<html>
	<center>
		<h1>Results</h1>
		<body>
			<?php
			session_start();
			$conn=mysqli_connect("localhost",$_SESSION['sess_username'],$_SESSION['sess_pass'],"fantasyfootball");
			
			$transactionID = $_POST['transactionID'];
			
			$result=mysqli_query($conn, "DELETE FROM transactions WHERE(transactionID='$transactionID')");

			if($result)
			{
				echo("Delete data succeeded");
			}
				else
			{
				echo("Delete data failed");
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