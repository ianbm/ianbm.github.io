<?php
//name as seesession.php

session_start();

$name=$_SESSION['NAME'];
$pass=$_SESSION['PASS'];

echo $name.'<br>';
echo $pass.'<br>';
?>