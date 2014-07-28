test-mmx: test-mmx.c
	gcc -L /usr/local/include -L /usr/local/lib -O2 -msse2 -o $@ $< -lxmm
test-mmx2: test-mmx2.c
	gcc -L /usr/local/include -L /usr/local/lib -O2 -msse2 -o $@ $< -lxmm
test-minus: test-minus.c
	gcc -o $@ $<
test-float: test-float.c
	gcc -o $@ $<
test-float2: test-float2.c
	gcc -o $@ $< -lm
test-byteorder: test-byteorder.c
	gcc -o $@ $<
