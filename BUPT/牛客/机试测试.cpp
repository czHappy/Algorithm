/*
//B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;;
    double a,b;
    double profit = 0 , cost = 0;
    cin>>n;
    while(n--){
        cin>>a>>b;
        profit += (b - a) ;
        cost += a;
        
    }
    cout<<(int)(-100*profit / cost)<<endl;

    return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;
int dp[20];
int a[20];
int n;
void solve(){
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[1] + a[0] + a[2];
    if(n <= 3) return ;
    for(int i=3; i<n; i++){
        dp[i] = min(dp[i-1] + a[0] + a[i] , dp[i-2] + a[0] + a[i] + 2*a[1]);
    }
    cout<<dp[n-1]<<endl;
}


int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        dp[i] = 0;
    }
    sort(a , a+n);
    solve();
    
}*/
/*
#include<bits/stdc++.h>
using namespace std;

int a,b,k;

int main(){
    cin>>a>>b>>k;
    int n = a + b;
    int s = n;
    bool vis[100];
    int cnt = 0;
    memset(vis , 0 , sizeof vis);
    for(int i=0; i<n; i=(i+1)%n){
        if((i+1) % k == 0){
            vis[i] = 1;
            n--;
            cnt++;
        }
        if(cnt >= b) break; 
    }
    for(int i=0; i<s; i++) cout<<(vis[i] ? 'F' : 'M');
    cout<<endl;
}*/

#include<bits/stdc++.h>
using namespace std;

int n;
int a[20];
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    bool vis[20];
    sort(a , a+n);
    int left = 20;
    int cnt = 0;
    int pos = n - 1;
    int ans = 0;
    while(cnt < n){
        left = 20;
        pos = n - 1;
        cout<<"in1"<<endl;
        while(left > 0  && pos >= 0 ){
            cout<<"in2"<<endl;
            if(vis[pos] || left < a[pos]){
                pos--;
                continue;
            } 
            if(!vis[pos] && left >= a[pos]){
                left -= a[pos];
                vis[pos] = 1;
                pos--;
                cnt++;
            }
        }
        ans++;
    }
    cout<<ans<<endl;    
}