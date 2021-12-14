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
#define MS(x,i) memset(x,i,sizeof(x))
#define rep(i,s,e) for(int i=s; i<=e; i++)
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define debug printf("debug......\n");
#define pfd(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
const double eps=1e-8;
const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 0x7fffffff;
const int maxn = 2e2+10;
int dx[4] = {0, 0, 1, -1};
int dy[4]  = {1, -1, 0 , 0};

// STL UNIQUE
/*
template <class ForwardIterator>
  ForwardIterator unique (ForwardIterator first, ForwardIterator last)
{
  if (first==last) return last;

  ForwardIterator result = first;
  while (++first != last)
  {
    if (!(*result == *first))  // or: if (!pred(*result,*first)) for version (2)
      *(++result)=*first;
  }
  return ++result;
}

*/

/*
int main(){
    int a[10] = {1,2,2,2,3,3,4,6,6,7};
    //unique(a,a+10)
    int pos = unique(a,a+10) - a;
    for(int i=0; i<pos; i++) cout<<a[i]<<endl;
    return 0;
}*/

// MY UNIQUE
//[) int a[10] = {1,2,2,2,3,3,4,6,6,7};
int unique(int a[], int first, int last){
   if(first == last) return last ;
   int result = first;
   while(++first != last){
       if(!(a[result] == a[first])) a[++result] = a[first];
       cout<<"first = "<<first<<" pre = "<<result<<endl;
       for(int i=0; i<10; i++) cout<<a[i]<<" ";
   }
   return ++result;
}
int main(){
    int a[10] = {1,2,2,2,3,3,4,6,6,7};
    int st = 0;
    int ed = 10;
    int j = unique(a , st, ed);
    for(int i=0; i<10; i++) cout<<a[i]<<endl;

    return 0;
}