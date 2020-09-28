/*
  Name: 查找 
  CopyRight:
  Author: Cz
  Date: 2019/8/28 10:27:35
  Description:
*/



#include<iostream>
#include<queue>
#include<list>
#include<vector>
#include<cstring>
#include<set>
#include<stack>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;
typedef long long ll;

/*
顺序查找 ：从后往前扫描，找到了就返回下标，找不到返回0
折半查找：有序表二分查找 
分块查找：块之间有序，块内无序，查找时先对块索引表进行二分确定key所在的块，再在块内进行顺序扫描
二叉排序树；实质上是二分 
红黑树：解决了二叉排序树最坏情况下呈链状结构的问题
平衡二叉排序树：严格平衡的红黑树
 
*/ 

typedef struct Seqlist{
	int elem[1000];//有序表 从小到大 起始下标为0 
	int len; //已经用的长度 
}Seqlist;
//折半查找 
int binarySearch(Seqlist L, int key){
	int low = 0, high = L.len-1;
	int mid;
	while(low <= high){
		mid = (low + high) >> 1;
		if(L.elem[mid] == key) return mid;
		else if (L.elem[mid] > key) high = mid - 1;
		else low = mid + 1; 
	} 
	return -1;
} 


int main(){
	Seqlist list;
	for(int i=0; i<10; i++){
		list.elem[i] = i*2+10;
	} 
	list.len = 10;
	cout<<binarySearch(list , 16)<<endl;

	return 0;
}

