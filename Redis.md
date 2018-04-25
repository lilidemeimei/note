
#### Redis适用场景
+ 缓存: 将热点数据放到内存中  
+ 消息队列: List类型是双向链表,很适合用于消息队列  
+ 计数器: 能支持计数器频繁的读写操作  
+ 好友关系: 使用Set类型的交集操作容易知道两个用户的共同好友  

#### Redis 数据类型
##### String (字符串)  

| 命令 | 描述 |
|-----|------|
|set key value|设置指定key值|
|get key|获取指定key值|
|getrange  key start end|返回key中字符串的子字符|

+ Hash(哈希)  

#### 语法
##### 在远程服务上执行命令
redis-cli -h host -p port -a password
