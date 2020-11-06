# toolload
The dynamically linked tool is initialized too late (after foo_init):
```
$ make
$ ./app
begin libtest constructor
  libtest calling foo_init
    libfoo foo_init()
      libfoo pfoo_init()
  libtest calling foo_init returned
  libtest calling foo
    TOOL foo
      libfoo pfoo()
  libtest calling foo returned
end libtest constructor
begin TOOL constructor
  libfoo foo_register()
    libfoo pfoo_register()
end TOOL constructor
main calling foo
  TOOL foo
    libfoo pfoo()
main calling foo returned
main calling bar
  libtest bar called
main calling bar returned

```

By dlopen-ing the tool library in foo_init, the constructor is executed before foo_init returns:
```
$ FOO_LOAD_LIBRARIES=$PWD/libtool.so ./app
begin libtest constructor
  libtest calling foo_init
    libfoo foo_init()
      libfoo pfoo_init()
      begin TOOL constructor
        libfoo foo_register()
          libfoo pfoo_register()
      end TOOL constructor
  libtest calling foo_init returned
  libtest calling foo
    TOOL foo
      libfoo pfoo()
  libtest calling foo returned
end libtest constructor
main calling foo
  TOOL foo
    libfoo pfoo()
main calling foo returned
main calling bar
  libtest bar called
main calling bar returned
```
