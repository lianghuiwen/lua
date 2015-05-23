test: lua_interface.cc lua_export.cc tolua_test.cc
	g++ lua_interface.cc lua_export.cc tolua_test.cc -lm -ldl -llua -ltolua++

.PHONY: clean
clean:
	-rm -f a.out *.o
