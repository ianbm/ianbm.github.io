---
layout: project
type: project
image: images/fantasyFootballProject.jpg
title: Fantasy Football
permalink: projects/fantasyFootballProject
date: 2017-02-03
labels:
  - HTML
  - PHP
  - SQL
  - Database
summary: I created a web application that simulates Fantasy Football
---
<img class="ui medium right floated rounded image" src="/images/fantasyFootballProject.jpg">

Fantasy Football is a game that many sports fans play. The concept in this game is to select football players every week, and based on how well they play during that week, you would gain "Fantasy Points." Whoever gets the most Fantasy Points by the end of the week is the winner of that week.

A few years ago I took a Database Systems class which topics like HTML, PHP, SQL, and Databases. 

Here is some code from the project:

```js
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
```
