<HTML>
<center>
<BODY>
<H1>Update results</h1>
<BODY>
<?php
session_start();
//the example of inserting data with variable from HTML form
$conn=mysqli_connect("localhost",$_SESSION['sess_username'],$_SESSION['sess_pass'],"fantasyfootball");//database connection
//Get values from form
$playerID = $_POST['playerID'];
$playerFirstName = $_POST['playerFirstName'];
$playerLastName = $_POST['playerLastName'];
$teamID = $_POST['teamID'];
//inserting data order
$result=mysqli_query($conn, "UPDATE players SET playerFirstName='$playerFirstName', playerLastName='$playerLastName', teamID='$teamID' WHERE playerID='$playerID'");
//declare in the order variable
//$result = mysql_query($update);    //order executes
if($result)
{
 echo " & Update data success";
}
else
{
 echo(" & Update data fail");
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