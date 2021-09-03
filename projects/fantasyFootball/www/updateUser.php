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
$userID = $_POST['userID'];
$username = $_POST['username'];
$userFirstName = $_POST['userFirstName'];
$userLastName = $_POST['userLastName'];
$userEmail = $_POST['userEmail'];
//inserting data order
$result=mysqli_query($conn, "UPDATE users SET username='$username', userFirstName='$userFirstName', userLastName='$userLastName', userEmail='$userEmail' WHERE userID='$userID'");
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