<?php
// test0.php //
function test($i, $j)
{
	return ($i * $j);
}

function main()
{
	$i = 2;
	$j = 3;
	$k = test($i, $j);
	if (k > 5) {
		echo ">5\n";
	} else {
		echo "<=5\n";
	}
}

main();
?>