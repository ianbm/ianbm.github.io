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
$teamLocation = $_POST['teamLocation'];
$teamName = $_POST['teamName'];

//inserting data order
$result=mysqli_query($conn, "INSERT INTO teams (teamLocation, teamName) VALUES ('$teamLocation','$teamName')");

//declare in the order variable
//$result = mysqli_query($order);    //order executes
if($result)
{
 echo("Team input data succeeded");
}
else
{
 echo("Team input data failed");
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