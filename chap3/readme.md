<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>
## 与数值计算有关的一些程序说明
---
- page98.cpp 实现了一种简单的比较，在数学上赞同的算法在计算机上由于精度的关系会有不同，常见的禁区是大数吃小数。程度比较了三种计算 \\(x-1)^8\\ 在 \\x = 1\\ 附近的表现
   - 展开成多项式再计算
   - [Horner 算法](https://en.wikipedia.org/wiki/Horner%27s_method)
   - 直接计算，用作标准
- 前两种算法都出现了负值，误差比直接计算要大许多。 Horner 算法效率要高一些
- page100.cpp 比较了两种求积方法，simpson 方法是二次曲线分段拟合，误差要小于梯形公式。
