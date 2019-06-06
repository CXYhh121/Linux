libmymath.so:add.o sub.o
	gcc -shared -o $@ $^
add.o:add.c
	gcc -fPIC -c add.c
sub.o:sub.c
	gcc -fPIC -c sub.c 

.PHONY:output
output:
	mkdir -p lib/lib
	mkdir -p lib/include
	cp -rf *.h lib/include
	cp -rf *.so lib/lib

.PHONY:clean
clean:
	rm -f *.o *.so

