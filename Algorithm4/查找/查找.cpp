/*
  Name: ���� 
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
˳����� ���Ӻ���ǰɨ�裬�ҵ��˾ͷ����±꣬�Ҳ�������0
�۰���ң��������ֲ��� 
�ֿ���ң���֮�����򣬿������򣬲���ʱ�ȶԿ���������ж���ȷ��key���ڵĿ飬���ڿ��ڽ���˳��ɨ��
������������ʵ�����Ƕ��� 
�����������˶��������������³���״�ṹ������
ƽ��������������ϸ�ƽ��ĺ����
 
*/ 

typedef struct Seqlist{
	int elem[1000];//����� ��С���� ��ʼ�±�Ϊ0 
	int len; //�Ѿ��õĳ��� 
}Seqlist;
//�۰���� 
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

