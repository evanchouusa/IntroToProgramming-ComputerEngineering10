<html>
<body>
   
<?php
   
$number1 = $_POST["number1"];
$number2 = $_POST["number2"];
$number3 = $_POST["number3"];

echo "The answer for $number1*$number2 is " . ($number1*$number2)."<br>";


if($number3==($number1*$number2))
	echo "Good Job";
else
	echo "Incorrect";

?>

<form method="POST" action="Main.php">
	<input type="submit" value="Study More!!!"/>
</form>

</body>
</html>

