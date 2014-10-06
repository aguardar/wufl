+ webusb文件夹下的代码是server和测试前端代码
   + 采用python编写，server框架使用django
   + usb通讯采用CH375DLL.DLL文件，具体方法为使用python中的ctypes调用
   + fun.py用来处理各种api，扩展的话直接修改fun.py即可
   + html文件夹中的是前端代码，可以与服务端完全分离，使用Ajax通讯，可跨域通讯
   + 扩展js的时候直接按照com.js中已有的例子直接继续扩充com.js即可
   + control用于连接js代码和html代码，主要进行事件绑定和控制

+ nios文件夹下为nios程序源代码，原理很简单，接收server端通过usb发送过来的信号，然后点亮四个led灯，维持一定时间后熄灭
  + 扩展nios代码也很简单，只需要对usb过来的信号进行判断然后分发处理即可
