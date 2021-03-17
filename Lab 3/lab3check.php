<html>
<body>
   
<?php
   
$value = rand (0,20);
$value1 = rand (0,20);
$value2 = rand (0,20);
$value3 = rand (0,20);
$value4 = rand (0,20);
  
$x = array ($value, $value1, $value2, $value3, $value4);
  
$num = $_POST["num"];
  
$size = count ($x);
for ($i=0; $i<$size; $i++)
	echo $x[$i]." ";
  
$set = 0;
for ($i=0; $i<$size; $i++){
	if($num==$x[$i])
		$set=1;
}

if ($set==1)
	echo "Good guess! You guessed $num.";
else{
	echo "were the correct numbers. Wrong! You guessed $num. Try again";
}
 
?>
  
<form method="POST" action="lab3.html">
	<input type="submit"value="Guess Again?" />
</form>
 
<body>
<html>
