<html>
<body>

<h1><center>Multiplication Test</center></h1>

<h1>your answer?</h1>

<?php

$value = rand (0,12);
$value1 = rand (0,12);

echo $value. "*". $value1;

?>

<form action="check.php" method="POST">

	<input type="hidden" name="number1" value="<?php echo $value;?>" />

	<input type="hidden" name="number2" value="<?php echo $value1;?>" />

	<input type="number" name="number3" />

	<input type="submit" value"Calculate!" />

</form>

</body>
</html>
