def test(i, j)
	return (i * j)
end

def main()
	i = 2
	j = 3
	k = test(i, j)
	if k > 5
		print ">5\n"
	else
		print "<=5\n"
	end
end

main()