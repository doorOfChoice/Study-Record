# jquery ajax上传文件

---
昨天晚上以及今天一直在尝试使用sm.ms提供的API往服务器上上传文件，可是屡次失败，直到今天在stackover上面看到了一篇文章[jquery ajax](http://stackoverflow.com/questions/5392344/sending-multipart-formdata-with-jquery-ajax)，解决了问题.

html的代码如下
```html
  <form id="form" enctype="multipart/form-data">
    <input type="file" name="smfile" value="" id='smfile'>
    <input type="button" name="button" value="" id='button'>
</form>
```

刚开始的时候我的javascript是这样写的

```javascript
  <script>
    $('#form').submit(function(e){
      e.preventDefault();
      $.ajax({
        type : 'post',
        url : 'https://sm.ms/api/upload',
        data : $('#form').serialize()   ,
        contentType : 'multipart/form-data'
      });
    });
  </script>
```
不过发现始终有问题，无法获得想要的请求.
1. Content-Type 根本没在Request Header里面出现
2. 没有消息体，要上传的文件也根本没有在消息体中

后面将代码做了修改

```javascript
  <script>
  $('#form').submit(function(e){
    e.preventDefault();
    //新建一个表单对象，可以把所有数据用JSON存储~
    var data = new FormData($('#form')[0]);
    $.ajax({
      type : 'post',
      url : 'https://sm.ms/api/upload',
      data : data,
      contentType : false,
      //是否进行query string转换，默认为true。
      processData : false
    });
  });
  </script>
```

就成功了!
因为$.seriliaze()这个函数不能序列化文件.
