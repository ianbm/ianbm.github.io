<?php
// name as startsession.php
session_start();

$_SESSION['NAME']=$_POST['username'];
$_SESSION['PASS']=$_POST['userPass'];
echo "Done";

?>