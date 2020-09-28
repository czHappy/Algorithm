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
#define rep(i,s,e) for(int i=s; i<=e; i++
const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 0x7fffffff;
const int maxn = 5e3+10;
int dx[4] = {0, 0, 1, -1};
int dy[4]  = {1, -1, 0 , 0};

int n,m;//顶点数 边数 
vector<int> G[maxn];//存图 
int sccCount;//强连通分量的个数 
int id;//记录访问次序 
bool onStack[maxn];//记录该点是否在栈上 
int ids[maxn];//记录该顶点是哪一次被访问到的 
int low[maxn];//low值 
stack<int> stak;//栈 
int color[maxn];//color[i]表示i被涂成的颜色
int sz[maxn];//sz[i]表示强连通分量i的大小 
//从一点出发dfs 如果dfs调用完毕后，该结点的id值等于low值 说明得到一个scc 
void dfs(int u){
    stak.push(u);//入栈 
    onStack[u] = 1;//标记 
    ids[u] = low[u] = id++;//记录访问次序 和  low值 
    for(int i=0; i<G[u].size(); i++){ //遍历所有邻接点 
        int v = G[u][i];
        if(!ids[v]){
            dfs(v);//如果没有访问过则继续dfs 
            low[u] = min(low[u], low[v]);//父节点记录最小的low子结点
        } 
        else if(onStack[v]) low[u] = min(low[u] , ids[v]);//如果访问过了，并且在栈上
        //则回溯更新  栈的作用实际上是使各个SCC互不干涉 
    }
    //如果这个顶点是最早入栈的那个  则SCC已经形成 
    //认为他能代表这个SCC缩成的点 
    if(ids[u] == low[u]){
        sccCount++;//下一个SCC 
        while(true){
            int tp = stak.top();
            stak.pop();
            color[tp] = sccCount; 
            sz[sccCount]++;//size增加 
            onStack[tp] = 0;//栈标记取消 
            low[tp] = ids[u];//low值同一更新成u的 不要也行 
            if(tp == u) break;//到u了不要再弹了 
        }
    }
}

void tarjan(){
    id = 0;
    sccCount=0;
    MS(ids , 0);
    MS(sz , 0);
    rep(i , 1, n){
        if(!ids[i]) dfs(i);
    }
    int idx;
    int maxx = -1;
    rep(i,1,n){
        if(sz[i] > maxx){
            idx = i;
            maxx = sz[i];
        }
    }
    cout<<sz[idx]<<endl;
    
    rep(i,1,n){
        if(color[i] == idx){
            cout<<i<<" ";
        }
    }
    cout<<endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int u,v,w;
    rep(i,1,m){
        cin>>u>>v>>w;
        G[u].push_back(v);
        if(w == 2) 
            G[v].push_back(u);
    }
    tarjan();
    return 0;
}


//遍历有向图的逆序图，取逆后序DFS遍历

 /*
 int n,m;
vector<int> G[maxn];//原图
vector<int> reG[maxn];//逆向图
bool vis[maxn];//访问标记
stack<int> order;//逆向图的逆序访问顺序

int col[maxn];//顶点染色
int cnt;//强连通分量的个数
int sz[maxn];///每个强连通分量的大小
//初始化
void init(){
    rep(i,1,n){
        G[i].clear();
        reG[i].clear();
        vis[i] = 0;
        col[i] = 0;  
        sz[i] = 0;
    } 
    while(!order.empty()) order.pop();
    cnt = 0;
}

//复用DFS   R表示是不是遍历逆向图 如果是 则 不需要染色并且需要入栈 否则需要染色 不需要入栈
void dfs(vector<int> G[] , int s, bool  R){
    vis[s] = 1;
    if(!R){
        col[s] = cnt;//把这个顶点染色成cnt
        sz[cnt]++;//该颜色连通 分量size++
    }
    for(int i=0; i< G[s].size(); i++){
        int v = G[s][i];
        if(!vis[v]) dfs(G,v,R);
    }
    if(R) order.push(s);//逆序进栈
} 
//获取反向图的逆序遍历序列
void getOrder(){
    rep(i,1,n){
        if(!vis[i]) dfs(reG , i, 1);
    }
    
}
//求强连通分量 按照order序列顺序dfs原图
void getSCC(){
    MS(vis , 0);
    while(!order.empty()){
        int u = order.top();
        order.pop();
        if(!vis[u]){
            cnt++;//产生一个以U为主导的新的强连通分量 
            dfs(G , u , 0);
        }
    }
}
//打印结果
void solve(){
    int mx = -1, color = 1;
    rep(i , 1, n){
        if(sz[i] > mx){
            mx = sz[i];
            color = i;
        }
    }
    cout<<mx<<endl;
    rep(i , 1, n){
        if(col[i] == color){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main(){ 
    int u,v,x;
    while(cin>>n>>m){
        init();
        rep(i,1,m){
            cin>>u>>v>>x;
            G[u].push_back(v);
            reG[v].push_back(u);
            if(x==2){
                G[v].push_back(u);
                reG[u].push_back(v);
            }
        }
        getOrder();
        getSCC();
        solve();
    }
    return 0;
}
 
 
 */ 
