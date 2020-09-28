/*
  Name:排序算法大合集 
  CopyRight:
  Author: Cz
  Date: 2019/10/1 21:29:02
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
const int maxn =100;
int num[maxn];//测试数组 
const int len = 15;//数字大小 
const int inf = 0x3f3f3f3f;
void exch(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
} 
void  show(){
	for(int i=0; i<len; i++){
		cout<<num[i]<<" "; 
	}
	cout<<endl;
}


//选择排序
//基本思想：每次选出一个最小值放在当前位置上，一个一个码好
void selectSort(){
	int pos = 0;
	int min = inf;
	for(int i=0; i<len; i++){
		pos = i;
		min = num[i];
		for(int j=i+1;  j<len; j++){
			if(num[j] < min){
				min = num[j];
				pos = j;
			}
		}
		exch(num[i] , num[pos]);
	}
}

//插入排序
// 1 2 5 6 4 7 8 0 
void insertSort(){
	for(int i=1; i<len;  i++){
		for(int j=i; j>0; j-- ){
			if(num[j-1] > num[j]){
				exch(num[j] , num[j-1]);
			}
			else break;
		}
	}
}

//折半插入排序
// 1 2 5 6 4 7 8 0 
void biInsertSort(){
	for(int i=1; i<len; i++){ //插第i个元素，第0个元素不用插 
		int lo = 0 , hi = i-1;
		int mid ;
		while(lo <= hi){
			mid = (lo + hi) / 2;
			if(num[mid] < num[i]) lo = mid + 1 ;
			if(num[mid] > num[i]) hi = mid - 1;

		} 
		//要一个一个交换过去 
		for(int j = i-1; j>hi; j--){
			exch(num[j] , num[j+1]);
		}
		
	}
}

//希尔排序
void shellSort(){
	int h = 1;
	while(h <= len/3) h = 3*h + 1;
	while(h >= 1){
		for(int i=h; i<len; i++){
			for(int j=i; j>=h; j-=h){ //这里要有j>=h,因为h数组头一个元素也要比
				if(num[j-h] > num[j]) exch(num[j-h] , num[j]);
				else break;
			}
		}
		h = h/3;
	}
}


//归并排序
int aux[maxn];//需要一个辅助数组
void merge(int lo,int mid, int hi){
	int p = lo;
	int q = mid+1;
	int cnt = lo;
	while(p<=mid && q<=hi){
		if(num[p] < num[q]) aux[cnt++] = num[p++];
		else aux[cnt++] = num[q++];
	}
	while(p<=mid) aux[cnt++] = num[p++];
	while(q<=hi) aux[cnt++] = num[q++];
	for(int i=lo; i<=hi; i++) num[i] = aux[i];
}
void mergeSort(int lo, int hi){
	if(lo >= hi) return;
	int mid = (lo+hi)>>1;
	mergeSort(lo , mid);
	mergeSort(mid+1 , hi);
	merge(lo , mid , hi);
}
、
//快速排序
int partition(int lo, int hi){
	int i=lo;
	int j=hi;
	while(true){
		while(i<=hi){
			if(num[i] <= num[lo]) i++;
			else break;
		}
		while(j>lo){
			if(num[j] >= num[lo]) j--;
			else break;
		}
		//注意，这里必须加一个判断，否则i<j时也交换，这样就错了
		if(i >= j) break;
		exch(num[i] , num[j]);
	}
	//最后key换到它应该在的位置，并返回这个位置，作为下一轮的切分点
	exch( num[j] , num[lo]);
	return j;
}

void quickSort(int lo, int hi){
	if(lo >= hi) return;
	int mid = partition(lo , hi);
	quickSort(lo , mid - 1);
	quickSort(mid+1, hi);
}

//冒泡排序
void buddle(){
	for(int i=len-1; i>0; i--){
		for(int j=0; j<=i; j++){
			if(num[j] < num[j-1]) exch(num[j] , num[j-1]);
		}
	} 
}


//堆排序

//下沉調節 事實上，sink函數適用於在頂元素被替代後的調整動作，而swim函數適用於末尾新插入元素調整位置
//一定要注意第三个参数N是当前选定的最后一个位置， 并不一直是数组末尾元素
void sink(int k, int N) {
	while(2*k <= N) {
		int j = 2*k;//J指向左孩子
		//比較一下左右孩子，J指向大的
		if(j < N && num[j] < num[j+1]) {
			j++;
		}
		if(num[k] > num[j]) { //如果父親結點大於大孩子，就算了
			break;
		}//如果父親結點小與大孩子，則需要交換
		exch(num[k] , num[j]);
		k = j;//繼續下沉交換
	}
}

//堆排序 ， 注意数组a从下标1开始，0号元素没有用
void heapSort() {
	int N = len-1;//N是最后一个元素下标
	for(int k = N/2; k>0; k--) {
		sink(k, N);
	}
	while(N > 1) { //不斷地冒頂，把頂部元素逐個安排到n-1,n-2,...,2,最後一個不用再安排
		exch(num[1], num[N--]);//冒頂到尾
		sink(1, N);//頂部元素下沉保持1~N-1有序，N是逐漸減少的
	}	
}

int main(){
	for(int i=0; i<len; i++){
		num[i] =  rand() % 150 + 1;
	}
	show();
	//selectSort();
	//insertSort();
	//shellSort();
	//mergeSort(0,len-1);
	//quickSort(0, len-1);
	//buddle();
	heapSort();
	show();
	return 0;
}

