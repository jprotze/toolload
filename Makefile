all: app app_static



libtool.so: tool.c foo.h
	gcc -shared -fPIC tool.c -o libtool.so

libfoo.so: libfoo.c foo.h
	gcc -shared -fPIC libfoo.c -o libfoo.so -ldl

libtest.a: libtest.c foo.h
	gcc -c libtest.c
	ar rcs libtest.a libtest.o

libtest.so: libtest.c foo.h
	gcc -shared -fPIC libtest.c -o libtest.so


app_static: app.c foo.h libtest.a libfoo.so
	gcc app.c -Wl,--whole-archive libtest.a  -Wl,--no-whole-archive -L. -lfoo -Wl,--rpath,. -o app
	
app: app.c foo.h libtest.so libfoo.so libtool.so 
	gcc app.c -L. -ltool -ltest -lfoo -Wl,--rpath,. -o app
	

