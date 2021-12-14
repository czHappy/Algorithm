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

int n,m;//������ ���� 
vector<int> G[maxn];//��ͼ 
int sccCount;//ǿ��ͨ�����ĸ��� 
int id;//��¼���ʴ��� 
bool onStack[maxn];//��¼�õ��Ƿ���ջ�� 
int ids[maxn];//��¼�ö�������һ�α����ʵ��� 
int low[maxn];//lowֵ 
stack<int> stak;//ջ 
int color[maxn];//color[i]��ʾi��Ϳ�ɵ���ɫ
int sz[maxn];//sz[i]��ʾǿ��ͨ����i�Ĵ�С 
//��һ�����dfs ���dfs������Ϻ󣬸ý���idֵ����lowֵ ˵���õ�һ��scc 
void dfs(int u){
    stak.push(u);//��ջ 
    onStack[u] = 1;//��� 
    ids[u] = low[u] = id++;//��¼���ʴ��� ��  lowֵ 
    for(int i=0; i<G[u].size(); i++){ //���������ڽӵ� 
        int v = G[u][i];
        if(!ids[v]){
            dfs(v);//���û�з��ʹ������dfs 
            low[u] = min(low[u], low[v]);//���ڵ��¼��С��low�ӽ��
        } 
        else if(onStack[v]) low[u] = min(low[u] , ids[v]);//������ʹ��ˣ�������ջ��
        //����ݸ���  ջ������ʵ������ʹ����SCC�������� 
    }
    //������������������ջ���Ǹ�  ��SCC�Ѿ��γ� 
    //��Ϊ���ܴ������SCC���ɵĵ� 
    if(ids[u] == low[u]){
        sccCount++;//��һ��SCC 
        while(true){
            int tp = stak.top();
            stak.pop();
            color[tp] = sccCount; 
            sz[sccCount]++;//size���� 
            onStack[tp] = 0;//ջ���ȡ�� 
            low[tp] = ids[u];//lowֵͬһ���³�u�� ��ҪҲ�� 
            if(tp == u) break;//��u�˲�Ҫ�ٵ��� 
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


//��������ͼ������ͼ��ȡ�����DFS����

 /*
 int n,m;
vector<int> G[maxn];//ԭͼ
vector<int> reG[maxn];//����ͼ
bool vis[maxn];//���ʱ��
stack<int> order;//����ͼ���������˳��

int col[maxn];//����Ⱦɫ
int cnt;//ǿ��ͨ�����ĸ���
int sz[maxn];///ÿ��ǿ��ͨ�����Ĵ�С
//��ʼ��
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

//����DFS   R��ʾ�ǲ��Ǳ�������ͼ ����� �� ����ҪȾɫ������Ҫ��ջ ������ҪȾɫ ����Ҫ��ջ
void dfs(vector<int> G[] , int s, bool  R){
    vis[s] = 1;
    if(!R){
        col[s] = cnt;//���������Ⱦɫ��cnt
        sz[cnt]++;//����ɫ��ͨ ����size++
    }
    for(int i=0; i< G[s].size(); i++){
        int v = G[s][i];
        if(!vis[v]) dfs(G,v,R);
    }
    if(R) order.push(s);//�����ջ
} 
//��ȡ����ͼ�������������
void getOrder(){
    rep(i,1,n){
        if(!vis[i]) dfs(reG , i, 1);
    }
    
}
//��ǿ��ͨ���� ����order����˳��dfsԭͼ
void getSCC(){
    MS(vis , 0);
    while(!order.empty()){
        int u = order.top();
        order.pop();
        if(!vis[u]){
            cnt++;//����һ����UΪ�������µ�ǿ��ͨ���� 
            dfs(G , u , 0);
        }
    }
}
//��ӡ���
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
