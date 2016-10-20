# 如何设置PHP在windows下的环境

## 首先安装 Apache
  去到官网下载最新的apache， 解压到一个几乎不会发生改变的磁盘里面

  然后找到**Apache/conf/httpd.conf**这个文件，寻找到 **Define SRVROOT**,改为:

  > * Define SRVROOT "F:/Apache24"(注意斜线)

  在命令行里面切换到**Apache/bin** 目录下, 你也可以把Apache的bin目录设置到环境变量下，默认我设置了环境变量.输入:

  > *  httpd -k install

  如果发现启动端口有问题，出现443端口被占，请在cmd输入以下命令
  > * netstat -ano | findstr "443"

  会显示所有占了443端口的进程, 最右边的数字对应进程的ID, 请结束对应ID的进程
  > * taskkill /pid id /f


  ## PHP的配置

  去到官网下载5开头的版本，最好是5开头的新的版本。

  请将其解压到一个文件夹中，我设定为**php**, 且放在**/Apache**下

  将其**php.ini-development** 改为 **php.ini**

  继续打开**httpd.conf**文件

  找到 **DirectoryIndex index.html**， 改为：

  > * DirectoryIndex index.html index.php

  找到**#LoadModule vhost_alias_module modules/mod_vhost_alias.so**

  在下面添加
  > * LoadModule php5_module "F:/Apache24/php/php5apache2_4.dll"
  > * PHPIniDir "F:/Apache24/php"

  并且在文件末尾添加
  > * AddHandler  php5-script     PHP
  > * AddType     application/x-httpd-php        .php .php5
  > * AddType     application/x-httpd-php-source .phps

  打开 **php.ini**，找到extension_dir, 将其改为
  > * 实际路径/etc

  现在可以在 /Apache/htdocs 目录下放置你的主页了，你的php等等文件.

  ## Mysql

  去官网下载安装包，按照其指示安装即可
