<?php
// the example of inserting data with variable from HTML form
// $conn = @mysqli_connect("localhost",$_SESSION['sess_username'],$_SESSION['sess_pass'],"premiere") or die(" ");
// mysql_select_db("premiere") or die("Could not connect to a ould not select database");
// echo "Connected";
// the example of inserting data with variable from HTML form
mysqli_connectmysqli_connect("localhost",$_SESSION['sess_username'],$_SESSION['sess_pass'],"fantasyfootball");//database connection
// Check connection
if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }

else;
      echo "connected";
?>