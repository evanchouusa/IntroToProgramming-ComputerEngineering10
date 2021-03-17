<html>
	<body>
		
		<?php
			$x = array($_POST["num"], $_POST["num1"], $_POST["num2"], $_POST["num3"], $_POST["num4"]);
			$y = array(0, 0, 0, 0, 0);

			$counter=0;
			$size1=count($x);
			$size2=count($y);
			

			//unique numbers
			for($i=0;$i<5;$i++){
				$y[$i]=rand(1,20);
				if($i!=0){
					//traverse backward to check
					for($j=$i-1; $j>=0; $j--){
						if($y[$j]==$y[$i]){
							$i--;
							break;
						}
					}
				}
			}
			
			//check if numbers match
			for($i=0; $i<$size1; $i++)
				for($j=0; $j<$size2; $j++)
					if($x[$i] == $y[$j])
						$counter++;

			//print lottery numbers
			echo "The lottery numbers were: ";
			for($i=0; $i<$size1; $i++)
				echo $y[$i]." ";
			//print guessed numbers
			echo "Your guess numbers were: ";

			for($j=0; $j<$size2; $j++)
				echo $x[$j]." ";
			//print number of matched numbers
			echo "You've Matched ".$counter;
		?>

		<form method="POST" action="Lab4.html">
			<input type="submit"value="Choose Again?"/>
		</form>

	</body>
</html>	
