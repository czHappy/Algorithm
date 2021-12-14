/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/11 22:49:34
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
#include<cstring>
#include<stdio.h>
using namespace std;
typedef long long ll;

int main(){

	string s = "345";
	cout<<stoi(s , 0 , 10)<<endl;
	
	s="345.56781234556678909876543";
	cout<<stoi(s , 0 , 10)<<endl;
	cout<<stof(s , 0)<<endl;
	cout<<stold(s)<<endl;
	double num = stold(s,0);
	printf("%.10lf\n",num);
	return 0;
}

