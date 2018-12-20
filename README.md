# XCloudScript7.0
这是一个用c++编写的伪解释语言，效率<=c++等级
在code.txt编写代码并且运行explain.exe即可
语法example1：
provide normal
print("helloworld")

语法example2:
provide normal
formem(1000)
  print(mem," ")

XCS7.0可以将非XCS代码直接交给c++编译，意思就是说可以完全裸着写C++代码也是一样的

（注意：XCS7.1会加上Ofast，速度将达到2w位数加减乘除控制在1s~2s以内的等级)
XCS7.0更新日志：
1.provide是调用库的意思，目前除了normal以外没有多大作用
2.安装XCS的windows必须带有g++环境，后期将推出简易版XCS7.0系列供给linux运行
3.g++版本应在4.7.1的环境下(5.0以上的亲测print会出点小问题）
4.后期版本将自带g++编译器，可等下个版本更新
