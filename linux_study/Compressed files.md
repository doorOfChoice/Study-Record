# How to unpack from Compressed file

## Zip格式

Zip格式是常见的几种格式之一，还有rar，7-zip等等。
zip的特点就是压缩速度快，相对来说压缩率就比较小了。

>name.zip : 目的zip包, file/directories : 文件或目录
### 如何打包一个文件？
> * `zip -q(安静模式) -r(递归目录) -o(输出) name.zip file/directories`

当然你可以选择压缩率 1-9
> * `zip -5 -q -r -o ....`

### 如何解压?
> * `unzip name.zip`

### 也可以删除压缩包里面的文件

> * `zip -d name.zip file/directories`

----

## tar格式
tar 命令详解

-c: 建立压缩档案

-x：解压

-t：查看内容

-r：向压缩归档文件末尾追加文件

-u：更新原压缩包中的文件

-f : 使用档案名字，切记，这个参数是最后一个参数，后面只能接档案名。

-z：有gzip属性的

-j：有bz2属性的

-Z：有compress属性的

-v：显示所有过程

-O：将文件解开到标准输出

### 创建一个tar档案
> * `tar -cf test.tar *.txt`

### 创建一个tar包
> * `tar -rf text.tar *.txt`

### 查看一个tar包的内容
> * `tar -tf text.tar *.txt`

### 解压一个tar包
> * `tar -xf text.tar *.txt`

### 更新源数据包的文件
> * `tar -uf text.tar *.txt`

### 创建一个tar.bz2包
> * `tar -cjf text.tar.bz2 *.txt`

### 解压一个tar.bz2包
> * `tar -xjf text.tar.bz2`

### 创建一个tar.gzip包
> * `tar -czf text.tar.gz *.txt`

### 解压一个tar.gzip包
> * `tar -xzf text.rar.gz *.txt`

### 创建一个rar包
> * `rar a name.rar *.txt`

### 解压一个rar包
> * `rar x name.rar`