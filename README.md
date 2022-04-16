# NotMyHazel

## 一、初始构建一个项目

```
作为输出目录
$(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\

作为中间目录（int指intermediate）
$(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\ 
```

```cpp
在winodws下，构建动态库的项目，对于函数声明需要增加
__declspec(dllexport) void Print();
在使用函数的地方的声明应该如下
__declspce(dllimport) void Print();
```