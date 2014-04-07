# test0.pl #
sub test {
	($i, $j) = @_;
	return ($i * $j);
}

sub main {
	$i = 3;
	$j = 2;
	$k = &test($i, $j);
	if ($k > 5) {
		print ">5\n";
	} else {
		print "<=5\n";
	}
}

&main();