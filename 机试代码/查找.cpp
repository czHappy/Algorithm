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


int a[105];
int b;
int n,m;

bool find(int x){
    int lo = 0 , hi = n - 1;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(a[mid] < x) lo = mid + 1;
        else if(a[mid] > x) hi = mid - 1;
        else return 1;
    }
    return 0;
}

int main(){

    while(cin>>n){
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a , a + n);
        cin>>m;
        for(int i=0; i<m; i++){
            cin>>b;
            if(find(b)) cout<< "YES" <<endl;
            else cout<< "NO" << endl;
        }

    }
    return 0;
}