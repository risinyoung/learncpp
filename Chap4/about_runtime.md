## 关于单双精度的运行时间
---
- page135.cpp 是代码，书上举了两个例子，说明了在一些老的编译器上(书中是 gcc version 2.8.1)，单精度会转为双精度再运算，实际上会比双精度还慢
- 我的电脑上双精度还是快得多

wall time | 1 seconds
---:|:---
CPU  time | 0.31seconds
wall time | 0 seconds
CPU  time | 0.241seconds

The current time is: Wed Oct 17 23:02:49 2018

- wall time 是由 ctime 头文件里的 time 函数得到的，返回的是日历时间，单位是秒，因此个人感觉 CPU time 会更有参考意义 
