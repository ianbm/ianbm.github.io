<HTML>
<center>
<BODY>
<H1>Results</h1>
<BODY>
<?php
session_start();
//the example of inserting data with variable from HTML form
$conn=mysqli_connect("localhost",$_SESSION['sess_username'],$_SESSION['sess_pass'],"fantasyfootball");//database connection

//Get values from form
$userID = $_POST['userID'];

//inserting data order

$result=mysqli_query($conn, "DELETE FROM users WHERE (userID='$userID')");

//declare in the order variable

//$result = mysql_query($update);    //order executes
if($result)
{
 echo " & Delete data success";
}
else
{
 echo(" & Delete data fail");
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