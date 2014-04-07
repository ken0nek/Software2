# test0.coffee #
test = (i, j) ->
	i * j

main = () ->
	i = 2
	j = 3
	k = test(i, j)
	if k > 5
		console.log ">5\n"
	else
		console.log "<=5\n"

main()