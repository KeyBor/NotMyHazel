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

## 二、使用spdLog日志系统

```cpp
//使用git直接将代码作为项目的子模块
git submodule add $(ProjectGitAddress) $(Dirs'/'...)
```

知识点：

1、静态类成员变量必须在类外进行初始化
2、静态变量必须且只能一次被初始化
3、静态变量初始化时必须携带类型

Cherno是在头文件内定义了**私有静态成员变量**的get函数(当然也是静态函数)，一开始我想在**类外进行静态函数的定义**，但是我**忘记了私有成员变量无法在类外访问**。虽然后来改掉了，但是我想，既然这样的话，那我可以**利用友元(friend)定义静态成员函数**，所以我直接在静态成员函数前加了friend关键字，但是我在cpp文件实现时，发现在**Log类的作用域下找不到静态成员函数**，后来查询才发现，一旦定义了**友元函数，那么该函数将不是类的成员函数**，即不带this指针,后来尝试之后，个人的理解是，**带了友元的静态成员函数是全局静态函数**(不知道这么理解对不对)。

```cpp
//学会宏的多参数传递
#define HZ_CORE_ERROR(...)		Hazel::Log::GetCorelogger()->error(__VA_ARGS__)
```