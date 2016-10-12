# Windows 1day
Windows.h

微微的看了一下Windows程序设计, 感触颇深, 深入了解操作系统,感觉到了计算机的神秘, 和一种莫名的自由.

----

# 有关系统的知识

## 进程和线程
> * ”进程“ 是一段程序的执行过程, 是线程的容器, 进程里面包含了各种资源.
> * ”线程“ 是用来执行进程内代码的, 任何进程至少都需要一个线程, 没有线程, 进程就没有存在的意义.

## 虚拟内存

> * "虚拟内存" 不单单是指用磁盘来拓展物理内存, 也是指在内存中 "逻辑上连续而存储上不连续"的一段内存. 这种技术使得大型程序编写更加容易

## 内核模式 和 用户模式
推荐:https://zryfish.github.io/computer%20related/2015/08/28/user-mode-and-kernel-mode/
> * "内核模式"（Kernel Mode）： 在内核模式下，代码具有对硬件的所有控制权限。可以执行所有CPU指令，可以访问任意地址的内存。内核模式是为操作系统最底层，最可信的函数服务的。在内核模式下的任何异常都是灾难性的，将会导致整台机器停机。
> * "用户模式" (User Mode)：在用户模式下，代码没有对硬件的直接控制权限，也不能直接访问地址的内存。程序是通过调用系统接口(System APIs)来达到访问硬件和内存。在这种保护模式下，即时程序发生崩溃也是可以恢复的。在你的电脑上大部分程序都是在用户模式下运行的。

## 内核对象
> * 内核对象是一块内核分配的内存, 这块内存只能被运行在内核模式下的代码访问.内核对象记录的数据在整个系统中只有一份, 也叫系统资源.
> * 每个内核对象在Window都有对应的API可以对他进行访问, 这些API可以让应用程序读or写系统数据，但是一切都在系统的监控下.

## 句柄
> * 句柄相当于是一块内核对象的临时名字, 应用程序通过传递句柄可以访问到制定的内核对象.

## 使用计数
> * 每当打开一个内核对象, 他的计数就会+1 ； 被关闭, 计数就会减一. 一旦技术为0, 系统就会释放该内核对象所占用的内存了.

## C/C++如何启动的
C/C++程序运行的时候, 并不是直接运行main函数的.
> * 调用C/C++运行期启动函数, 为进程分配虚拟地址。先CreateProcess创建内核对象, 但是该内核对象并不是进程, 只是系统用来管理该进程的一块小数据结构.系统紧接着会创建一个主线程, 这个主线程通过运行C/C++运行期间代码开始运行, 运行期间代码又会调用main函数.

---

# Windows API

## 常见的数据类型

> * `typedef unsigned long DWORD`
> * `typedef int BOOL`
> * `typedef unsigned char BYTE`
> * `typedef unsigned short WORD`
> * `typedef float FLOAT`
> * `typedef void * LPVOID`
> * `typedef int INT`
> * `typedef unsigned int UINT`
> * `typedef char* LPSTR`
> * `typedef const char* LPCSTR`
> * `typedef wchar_t* LPWSTR`
> * `typedef const wchar_t* LPCWSTR`
> * `typedef char TCHAR`
> * `typedef wchar_t WCHAR`


## 常见的函数和宏定义(宏用#表示)
**创建进程**

`BOOL CreateProcess(NULL, WCHAR[], NULL, NULL, FLASE, NULL, NULL, NULL, &STARTUPINFO, &PROCRSS_INFORMATION) `

**分配0内存**:

`#ZeroMomery(Destination, Length) memset(Destination, 0, length);`

**退出当前程序**:

`void ExitProcess(UINT uExitCode)`

**打开进程**

`HANDLE OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHanle,DWORD dwProcessId)`
> * PROCESS_ALL_ACCESS 所有可进行的权限
> * PROCESS_QUERY_INFORMATION 查看该进程信息的权限


**终止进程** `BOOL TerminateProcess(DWORD HANDLE, UINT uExitCode)`
