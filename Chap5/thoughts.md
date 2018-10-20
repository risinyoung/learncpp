## 关于 rk 方法和隐式欧拉
---
- 练习17可知，都在稳定域时，rk 方法精度很高，但隐式欧拉似乎不会崩溃，我记得稳定域是整个平面来着（几年前上的课了），rk 在 lambada 到-500 多就崩溃了
- 隐式欧拉的编写让我学会了 lambda 函数的写法，ode 类中的函数是
```
f(double t, doublt x);
fder(double t, double x); // f() 对 x 的偏导，newton 方法迭代时要用
```
而我以前写的 newton() 是单参数的
```
newton(double x);
```
而且迭代时实际求的函数是
<a href="http://www.codecogs.com/eqnedit.php?latex=x_i-hf(t_(k&plus;1),y)-y=0" target="_blank"><img src="http://latex.codecogs.com/gif.latex?x_i-hf(t_(k&plus;1),y)-y=0" title="x_i-hf(t_(k+1),y)-y=0" /></a>
其解正是$x_{i+1}$，编写过程中使用 lambda 以方便地生成迭代需要的函数及其导数，而且返回类型需是
```
funcion<double(double)>
```
其在`<functional>`中定义，`newton()`也需用模板，这些都是我每一次接触的
- 利用`gnuplot`和`powershell`（在`windows`下用脱水的话，感觉比`python`更好）完成批量做图