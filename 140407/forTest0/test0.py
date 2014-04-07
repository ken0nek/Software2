def test(i, j):
	return (i * j)

def main():
	i = 3;
	j = 2;
	k = test(i, j);
	if k > 5:
		print ">5";
	else:
		print "<=5"

main()