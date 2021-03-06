### 七层协议
应用层：http，ftp，pop3，dns ,telnet(远程登录)  
表示层  
会话层  
运输层  
网络层  ip，icmp（internet控制信息协议），ARP（地址解析协议），RARP（反向地址解析协议）
数据链路层
物理层


### TCP/IP(四层)
应用层 :决定了向用户提供应用服务时通信的活动 FTP(文件传输协议),DNS(域名系统),HTTP  
传输层 :提供处于网络连接中的两台计算机之间的数据传输 TCP(传输控制协议),UDP(用户数据报协议)  
网络层 :处理网络上流动的数据包 (IP).数据包是网络传输的最小数据单位.该层规定了通过怎样的路径(选择一条传输路线)到达对方计算机,并把数据包传送给对方  
数据链路层 :用来处理连接网络的硬件部分  
!["TCP/IP"](/img/http-4.jpg)  
发送端在层与层之间传输数据时,每经过一层时必定会被打上一个该层所属的首部信息.反之,接收端在层与层传输数据时,每经过一层时会把对应的首部去掉.  
负责传输的IP协议 : 把各种数据包传送给对方(需要IP地址和MAC地址)  
IP地址指明了节点被分配到的地址,MAC地址是指网卡所属的固定地址,IP地址可以和MAC地址进行配对,在进行中转时,会利用下一站中转设备的MAC地址来搜索下一个中转目标,这时会采用ARP协议(地址解析协议),根据通信方的IP地址就可以反查出对应的MAC地址.  
确保可靠性的TCP协议 : 提供可靠的字节流服务,即为了方便传输,将大块数据分割成以报文段为单位的数据包进行管理,能够把数据准确可靠地传给对方    
为了准确无误地将数据送达目标处,TCP采用三次握手策略.  
!["三次握手"](/img/http-1.jpg)  
http://www.imooc.com/article/details/id/20812
client发出的第一个连接请求报文段并没有丢失，而是在某个网络结点长时间的滞留了，以致延误到连接释放以后的某个时间才到达server。本来这是一个早已失效的报文段。但server收到此失效的连接请求报文段后，就误认为是client再次发出的一个新的连接请求。于是就向client发出确认报文段，同意建立连接。假设不采用“三次握手”，那么只要server发出确认，新的连接就建立了。由于现在client并没有发出建立连接的请求，因此不会理睬server的确认，也不会向server发送数据。但server却以为新的运输连接已经建立，并一直等待client发来数据。这样，server的很多资源就白白浪费掉了  
负责域名解析的DNS服务(应用层) : 提供域名到IP之间的解析服务  
!["过程"](/img/http-5.jpg)
### HTTP
请求报文是由请求请求方法,请求URI,协议版本,可选的请求首部字段和内容实体构成  
!["请求报文"](/img/http-2.jpg)  
响应报文由协议版本,状态码,原因短语,可选的响应首部字段和实体主体构成  
!["请求报文"](/img/http-3.jpg) 

#### HTTP方法

|方法|含义|
|--------|-----------|
|GET     |获取资源,指定的资源经服务器端解析后返回响应的内容 |
|POST    |传输实体主体|
|PUT     |传输文件|
|HEAD    |获得报文首部,(对应请求资源的实体首部不随报文主体作为响应返回,即在响应中只返回首部,不会返回实体的主体部分)|
|DELETE  |删除文件|
|OPTIONS |询问支持的方法|
|TRACE   |追踪路径|
|CONNECT |要求用隧道协议连接代理|  
+ 持久连接 : 只要任意一端没有明确提出断开连接则保持TCP连接状态  
+ 管线化 : 不用等待响应亦可直接发送下一个请求  
##### Cookie
Cookie会根据从服务器端发送的响应报文内的一个叫做Set-Cookie的首部字段信息,通知客户端保存Cookie.当下次客户端再往服务器发送请求时,客户端会自动在请求报文中加入Cookie值后发送出去
##### HTTP报文

#### 状态码
HTTP状态码负责表示客户端HTTP请求的返回结果,标记服务端的处理是否正常,通知出现的错误等工作  

|    |类别|原因短语|
|----|----|--------------|
|1XX|信息性状态码|  接受的请求正在处理        |  
|2XX |成功状态码       |  请求正常处理完毕          |
|3XX |重定向状态码     |  需要进行附加操作以完成请求  |
|4XX |客户端错误状态码  |  客户端是发生错误的原因所在  |
|5XX |服务器错误状态码  |  服务器处理请求出错  |  


|状态码|原因短语||
|-----|----|------|
|200  |OK |      表示从客户端发来的请求在服务器端被正常处理了  |
|204  |NO Content| 代表服务器接收的请求已成功处理,但在返回的响应报文中不含实体的主体部分|  
|206  |Partial Content| 表示客户端进行了范围请求,而服务器成功执行了这部分的GET请求|  
|301  |Moved Permanedntly| 永久性重定向|  
|302  |Found |临时性重定向 | 
|303  |See Other|由于请求的资源存在另一个URI,应使用GET方法定向获取请求的资源 |
|304  |Not Modified|表示客户端发送附带条件的请求时,服务器端允许请求访问资源,但未满足条件的情况|
|307  |Temporary Redirect|临时重定向|
|400  |Bad Request| 请求报文中存在语法错误  |
|402  |Unauthorized|发送的请求需要有通过HTTP认证的认证信息|
|403  |Forbidden| 对请求资源的访问被服务器拒绝了(未获得文件系统的访问授权,访问权限出现某些问题)|  
|404  |Not Found| 服务器上无法找到请求的资源  |
|500  |Internal Server Error| 服务器端在执行请求时发生了错误  |
|503  |Service Unavailable |服务器暂时处于超负载或正在进行停机维护|  

通信数据转发程序  
代理:服务器和客户端的中间人  
网关:使通信线路上的服务器提供非HTTP协议服务  
隧道:在相隔甚远的客户端和服务器两者之间进行中转,并保持双方通信连接  

### HTTPS　
#### HTTP的缺点
##### 通信使用明文,内容可能会被窃听 
+ 将通信加密,可以通过和SSL(安全套接层)或TLS(安全层传输协议)的组合使用加密HTTP的通信内容  
+ 将通信的内容本身加密,要求客户端和服务端同时具备加密和解密机制  
##### 不验证通信方的身份,因此有可能遭遇伪装  
+ SSL不仅提供加密处理,还使用了一种被称为证书的手段,用以证明客户端和服务器是实际存在的
##### 无法证明报文的完整性,所以有可能已遭篡改  
#### HTTP+加密＋认证＋完整性保护＝HTTPS
加密方法:公开秘钥加密(使用一对非对称的秘钥,一把叫做叫做私有秘钥,一把叫做公开秘钥,发送密文的一方使用对方的公开秘钥进行加密处理,对方收到被加密的信息后再使用自己的私有秘钥进行解密)
HTTPS比HTTP要慢2到100倍
SSL的慢分两种,一种是指通信慢,另一种是指由于大量消耗CPU及内存等资源,导致处理速度变慢




























