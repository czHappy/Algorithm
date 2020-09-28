/*
  Name:�����㷨��ϼ� 
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
int num[maxn];//�������� 
const int len = 15;//���ִ�С 
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


//ѡ������
//����˼�룺ÿ��ѡ��һ����Сֵ���ڵ�ǰλ���ϣ�һ��һ�����
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

//��������
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

//�۰��������
// 1 2 5 6 4 7 8 0 
void biInsertSort(){
	for(int i=1; i<len; i++){ //���i��Ԫ�أ���0��Ԫ�ز��ò� 
		int lo = 0 , hi = i-1;
		int mid ;
		while(lo <= hi){
			mid = (lo + hi) / 2;
			if(num[mid] < num[i]) lo = mid + 1 ;
			if(num[mid] > num[i]) hi = mid - 1;

		} 
		//Ҫһ��һ��������ȥ 
		for(int j = i-1; j>hi; j--){
			exch(num[j] , num[j+1]);
		}
		
	}
}

//ϣ������
void shellSort(){
	int h = 1;
	while(h <= len/3) h = 3*h + 1;
	while(h >= 1){
		for(int i=h; i<len; i++){
			for(int j=i; j>=h; j-=h){ //����Ҫ��j>=h,��Ϊh����ͷһ��Ԫ��ҲҪ��
				if(num[j-h] > num[j]) exch(num[j-h] , num[j]);
				else break;
			}
		}
		h = h/3;
	}
}


//�鲢����
int aux[maxn];//��Ҫһ����������
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
��
//��������
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
		//ע�⣬��������һ���жϣ�����i<jʱҲ�����������ʹ���
		if(i >= j) break;
		exch(num[i] , num[j]);
	}
	//���key������Ӧ���ڵ�λ�ã����������λ�ã���Ϊ��һ�ֵ��зֵ�
	exch( num[j] , num[lo]);
	return j;
}

void quickSort(int lo, int hi){
	if(lo >= hi) return;
	int mid = partition(lo , hi);
	quickSort(lo , mid - 1);
	quickSort(mid+1, hi);
}

//ð������
void buddle(){
	for(int i=len-1; i>0; i--){
		for(int j=0; j<=i; j++){
			if(num[j] < num[j-1]) exch(num[j] , num[j-1]);
		}
	} 
}


//������

//�³��{�� ���ϣ�sink�����m������Ԫ�ر��������{����������swim�����m���ĩβ�²���Ԫ���{��λ��
//һ��Ҫע�����������N�ǵ�ǰѡ�������һ��λ�ã� ����һֱ������ĩβԪ��
void sink(int k, int N) {
	while(2*k <= N) {
		int j = 2*k;//Jָ������
		//���^һ�����Һ��ӣ�Jָ����
		if(j < N && num[j] < num[j+1]) {
			j++;
		}
		if(num[k] > num[j]) { //������H�Y�c��춴��ӣ�������
			break;
		}//������H�Y�cС�c���ӣ��t��Ҫ���Q
		exch(num[k] , num[j]);
		k = j;//�^�m�³����Q
	}
}

//������ �� ע������a���±�1��ʼ��0��Ԫ��û����
void heapSort() {
	int N = len-1;//N�����һ��Ԫ���±�
	for(int k = N/2; k>0; k--) {
		sink(k, N);
	}
	while(N > 1) { //�����ð픣���픲�Ԫ���������ŵ�n-1,n-2,...,2,����һ�������ٰ���
		exch(num[1], num[N--]);//ð픵�β
		sink(1, N);//픲�Ԫ���³�����1~N-1����N����u�p�ٵ�
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

