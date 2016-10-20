# About the file format of ubuntu

在linux系统中， 安装程序是十分方便的，路径不需要你去挑选而是系统自动为你分配了程序安装的路径。这继承了Unix的风格.

**通常情况下，linux会这样放软件的组件**：

> * 程序的文档->/usr/share/doc; /usr/local/share/doc
> * 程序->/usr/share; /usr/local/share
> * 程序的启动项->/usr/share/apps; /usr/local/share
> * 程序的语言包->/usr/share/locale; /usr/local/share/locale
> * 可执行文件->/usr/bin; /usr/local/bin

**从服务器上安装程序十分简单**
> * `sudo apt-get install filename`

用这个之前要确保电脑列表里面有这个软件， 所以要经常更新源
> * `sudo apt-get uodate`



## Deb安装包
类似于windows下的.msi文件，
百度了一下， 
msi就类似于一个安装包能实现安装卸载修复等等功能的安装程序，相对于普通的steup.exe文件要方便维护的多.

Ubuntu软件包格式为deb，安装方法如下：

 > * `  sudo  dpkg  -i  package.deb`

dpkg的详细使用方法：

 > * ` dpkg -r package 删除包 `
 > * `  dpkg -P package 删除包（包括配置文件） `
 > * `  dpkg -L package 列出与该包关联的文件 `
 > * `  dpkg -l packag 显示该包的版本e `
 > * `  dpkg –unpack package.de 解开 deb 包的内容  `
 > * `   dpkg -S keyword 搜索所属的包内容 `
 > * `   dpkg -l 列出当前已安装的包`
 > * `  dpkg -c package.deb 列出 deb 包的内容 `
 > * `   dpkg –configure package 配置包`

