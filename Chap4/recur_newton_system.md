## 关于递归、newton 和 system() 函数
---
- 递归相当慢
- newton method 有一定要求，我记得教科书上学过，从一个角度讲，要满足压缩条件
- cstdlib 中的 system()，在 win10 的 powershell 里，使用 ls 失败，推测不支持别名
- 搞清楚了，system() 应该只能用 cmd 里的东西，所以要加上 powershell 的调用
```
    ...
    system("powershell ls");//运行成功
    ...
```
- 另，学习了 gdb 和 gprof 的用法，都很直观，但细节很繁
- 今天看了一下《数值分析》中的自适应求积，用 simpson 实现的自适应收敛到指定精度比梯形的快许多