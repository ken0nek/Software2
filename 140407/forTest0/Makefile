# cpp: test0.o
# 	g++ -o $@ $^
# 	./$@

# %.o: %.cpp
# 	g++ -o $@ -c $<

# c: test0.o
# 	gcc -o $@ $^
# 	./$@

# %.o: %.c
# 	gcc -o $@ -c $<

c: test0.c
	gcc -o $(basename $^) $^
	./$(basename $^)

cpp: test0.cpp
	g++ -o $(basename $^) $^
	./$(basename $^)

java: test0.java
	javac $^
	java $(basename $^)

js: test0.js
	rhino $^

coffee: test0.coffee
	coffee $^

perl: test0.pl
	perl $^

python: test0.py
	python $^

php: test0.php
	php $^

ruby: test0.rb
	ruby $^

all: c cpp java js coffee perl python php ruby
