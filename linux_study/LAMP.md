# How to install the LAMP(Linux, Apache, Mysql, PHP)

本文参照了[Etel Sverdlov的文章](https://www.digitalocean.com/community/tutorials/how-to-install-linux-apache-mysql-php-lamp-stack-on-ubuntu)

## 安装Apache2
> * `sudo apt-get update`
> * `sudo apt-get apache2`

然后根据流程安装apache2, linux下的apache2安装十分的简单。

## 安装Mysql
> * `sudo apt-get mysql-server`

Mysql会让你设置root的密码，让你拥有最高的权限。

结束安装后可以开始设置mysql的安全性

> * `sudo /usr/bin/mysql_secure_installation`

登录mysql
> * `mysql -u user -h ip -p password`

## 安装php
> * `sudo apt-get php`

这会让你安装php的最新版本

## 就绪过后
请查找本机的IP， 尝试在browser上输入localhost 或者你的 本机IP（默认127.0.0.1）

如果出现
> it's work的网页

则表示你的apache2已经启动

Apache的启动/关闭/重启命令
> * `/etc/init.d/apache2 start`
> * `/etc/init.d/apache2 stop`
> * `/etc/init.d/apache2 restart`

但是你看见的这个‘ it‘s work的网页是存在哪里的呢？’

这个网页在 /var/www/html下，名字是index.html

这时候你可以往html这个folder下放置php或者html等等文件

之前要设置folder的访问权限，例如
> * `sudo chmod 777 /var/www`
> * `sudo chmod 777 /var/www/html`

文件放到html下去过后，你就可以通过browser输入localhost/xxxxx访问了