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
$username = $_POST['username'];
$userFirstName = $_POST['userFirstName'];
$userLastName = $_POST['userLastName'];
$userEmail = $_POST['userEmail'];

//inserting data order
$result=mysqli_query($conn, "INSERT INTO users (username, userFirstName, userLastName, userEmail, joinDate) VALUES ('$username','$userFirstName','$userLastName','$userEmail', NOW())");

//declare in the order variable
//$result = mysqli_query($order);    //order executes
if($result)
{
 echo("User input data succeeded");
}
else
{
 echo("User input data failed");
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