## 关于本章的一些想法（主要是 namespace) ##
---

- 同名 namespace 会被依次查找，所以可以混合多个同名 namespace ，类似接口的扩展
- 无名 namespace 相当于 static 去声明，也就是说，有内部链接性，不会被别的文件使用
- 别名，namespace a = b;
- 为什么 namespace 大括号后不用加分号？包括函数也不加，而类、结构（也是类）、联合什么的要加呢？
>百度了一下，感觉是因为要去兼容 C 的一种表达方式，在 C 中`struct {...} a, b, c`是一种常见的风格，所以必须要加分号。我习惯使用`struct a, b, c {...}`所以会认为可以不加分号
>>由此可以知道，也可以试验，函数和 namespace 大括号后本来就不能再加东西，自然也不需要去加分号，这是编译器所知晓的
- using 引入会覆盖上一级作用域的变量名
- 为了函数不修改传入数组，书上用的形参是 `const double ** const`，这是不对的，会报错，可能是书比较老了，c++后来的标准不允许这样。这也很好理解，二级指针要想像常量一样去使用，应该层层`const`, 正确的声明是 `const double * const * const`
- 函数的形参如果有某个 namespace 里的变量，不用声明那个 namespace 中的函数，也不用 :: 在调用的函数前，编译器会去搜索的
```
f(ns::a){
    g(a) \\ g in ns, no need to use ::
}
```