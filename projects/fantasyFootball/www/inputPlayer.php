<HTML>
<center>
<BODY>
<H1>Input results</h1>
<BODY>
<?php
session_start();
//the example of inserting data with variable from HTML form
$conn=mysqli_connect("localhost",$_SESSION['sess_username'],$_SESSION['sess_pass'],"fantasyfootball");//database connection


//Get values from form
$playerFirstName = $_POST['playerFirstName'];
$playerLastName = $_POST['playerLastName'];
$teamID = $_POST['teamID'];

//inserting data order
$result=mysqli_query($conn, "INSERT INTO players (playerFirstName, playerLastName, teamID) VALUES ('$playerFirstName','$playerLastName','$teamID')");

//declare in the order variable
//$result = mysqli_query($order);    //order executes
if($result)
{
 echo("Player input data succeeded");
}
else
{
 echo("Player input data failed");
}

?>
<BR>
<BR>
<!--                                                                                -->
<FORM METHOD="LINK" ACTION="mainmenu.html">
<INPUT TYPE="submit" VALUE="Return to Main Menu">
</form>

</body>
</center>
</html>