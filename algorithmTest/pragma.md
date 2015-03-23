### pragma pack(N)详解

#### 例子
```
//搜狗2015研发笔试
//64位机器
#include <iostream>
#pragma pack(8)

class Base{ 
public:
	Base(){}
	~Base(){}
private:
	char *p
	int a;
}

int main(){ 
	std::cout<<sizeof(Base)<<std::endl;
	reuturn 0;
}
```
#### 解释
#####    对变量的约束
- 1\.如果n大于等于该变量所占用的字节数，那么偏移量必须满足默认的对齐方式.
- 2\.如果n小于该变量的类型所占用的字节数，那么偏移量为n的倍数，不用满足默认的对齐方式.

#####    对结构总大小的约束
- 如果n大于所有成员变量类型所占用的字节数，那么结构的总大小必须为占用空间最大的变量占用
的空间数的倍数；否则必须为n的倍数。


### 参考链接

[csdn](http://blog.csdn.net/jamesf1982/article/details/4375719)