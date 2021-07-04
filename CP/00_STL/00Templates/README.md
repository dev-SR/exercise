# How do templates work?

Templates are expanded at compiler time. This is like `macros`. The difference is, the compiler does type checking before template expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of same function/class.

<div align="center"><img src="../../../img/templates-cpp.jpg" alt="temp in c++"></div>


**The syntax is:**

`template <class T> function_declaration;`
or
`template <typename T> function_declaration;`

We can use either of construct. They are not different since both expressions have exactly the same meaning and behave exactly the same way.