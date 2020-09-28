
### lower_bound
- 函数lower_bound() 
- 函数upper_bound()
>
>函数lower_bound()在first和last中的前闭后开区间进行二分查找，返回大于或等于val的第一个元素位置。如果所有元素都小于val，则返回last的位置.

>函数upper_bound()返回的在前闭后开区间查找的关键字的上界，返回大于val的第一个元素位置

>注意：返回查找元素的最后一个可安插位置，也就是“元素值>查找值”的第一个元素的位置。同样，如果val大于数组中全部元素，返回的是last。(注意：数组下标越界)

```c++
 int pos = lower_bound(a, a + 4, 3) - a;//a表示数组的起始位置 
vector<int>::iterator it = lower_bound(v.begin(), v.end(), 3,greater<int>()); 

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
```


### priority_queue
- 头文件：#include\<queue>
- 声明：priority_queue <T,vector<T>,greater<T> > q;

```c++
#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int x, y;
    Node( int a= 0, int b= 0 ):
        x(a), y(b) {}
};

bool operator<( Node a, Node b ){
    if( a.x== b.x ) return a.y> b.y;
    return a.x> b.x;
}

int main(){
    priority_queue<Node> q;
   
    for( int i= 0; i< 10; ++i )
    q.push( Node( rand(), rand() ) );
   
    while( !q.empty() ){
        cout << q.top().x << ' ' << q.top().y << endl;
        q.pop();
    }
   
    getchar();
    return 0;
}

```

```c++
//第二种方法
struct node{
	int size;
	int id;
}; 
struct cmp{
	bool operator()(const node &x, const node &y) const{
		return x.size > y.size;
	}
};
priority_queue<node, vector<node>, cmp> q;
priority_queue<int, vector<int>, greater<int>> q;
```
### 读入
- getline(cin, s);读入整行，注意之前需要getchar()
- sscanf("2006:03:18", "%d:%d:%d", &a, &b, &c);



### 字符串转数字

- to_string(val)	把val转换成string
  
- stoi(s,p,b)	把字符串s从p开始转换成b进制的int
- stol(s,p,b)	把字符串s从p开始转换成b进制的long
- stoul(s,p,b)	把字符串s从p开始转换成b进制的unsigned long
- stoll(s,p,b)	把字符串s从p开始转换成b进制的long long
- stoull(s,p,b)	把字符串s从p开始转换成b进制的unsigned long long
- stof(s,p)	把字符串s从p开始转换成float
- stod(s,p)	把字符串s从p开始转换成double
- stold(s,p)	l把字符串s从p开始转换成long double
