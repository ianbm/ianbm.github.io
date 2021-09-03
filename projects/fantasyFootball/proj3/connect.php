<?php
session_start();
$_SESSION['sess_username'] = $_POST['username'];
$_SESSION['sess_pass'] = $_POST['userPass'];  //$_Post 8 character Restriction

//the example of inserting data with variable from HTML form
$conn = @mysqli_connect("localhost",$_SESSION['sess_username'],$_SESSION['sess_pass'],"fantasyfootball");
echo "Connected";
if ($conn)
{
header ("Location: MainMenu.html");
}
else
{
header ("Location: index.html");
}
?>