# lua
just a test use lua

使用lua：  
1、创建Lua运行环境  
2、加载Lua基本库  
3、加载Lua脚本  
4、注册C++函数  
5、调用Lua函数  
  
使用tolua++：  
1、编写C++类  
2、创建package文件，只列出所有我们希望暴露给lua使用的常数，变量，函数，类和方法  
3、使用tolua++工具生成C++代码：tolua++ -o lua_export.cc export.pkg  
4、可以直接编辑lua_export.cc添加自定义函数，例如要返回多个值到lua  
  
ps:  
tolua++的编译比较麻烦，需要scons这个软件，用以下方法可以生成libtolua++.a：  
  cd tolua++-1.0.93/src/lib  
  gcc -c *.c -I../../include  
  ar cr libtolua++.a *.o  
然后把include/tolua++.h src/lib/libtolua++.a放到系统环境路径就可以了  