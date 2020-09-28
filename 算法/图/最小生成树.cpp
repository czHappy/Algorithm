/*
  Name:��С������ 
  CopyRight:
  Author: Cz
  Date: 2019/8/27 20:27:50
  Description:
*/
/*
//prim�㷨
//�㷨��Ҫ
1. �ص㣺�Ӷ�����չ��С��������ѡ�߼ӵ�
2. �ʺϳ���ͼ ʱ�临�Ӷ�(V^2) 
3. α�� 
void prim(G,T){
	T = null;
	U = {w} ;
	while(V != U){
		for(u : U)
			for(v : V)
				if(u,v) is the shortest edge in all edges which vertex coming from the two set respectively.
				then
					T = T union {{u,v}} //�߼ӵ�����ȥ
					U = U union u; //�������U���� 
	}
}
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
#define rep(i,s,e) for(int i=s; i<=e; i++)
const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 0x7fffffff;
const int maxn = 2e2+10;
int dx[4] = {0, 0, 1, -1};
int dy[4]  = {1, -1, 0 , 0};

int dis[maxn];//��¼ÿ�����㵽S���ϵ����бߵĳ���
int vis[maxn];//���Ƿ���S����
int G[maxn][maxn];//��ͼ �ڽӾ���洢����Ϊprim�㷨�ʺ϶����٣��߶��ͼ 
int x,y,w;
int sum;
int n,m;
void Prim(int s){
    memset(vis , 0 , sizeof vis);
    vis[s] = 1;
    //s����S���ϣ���ʼ��һ��dis
    rep(i,1,n){
        dis[i] = G[i][s];
    }
    //����Ҫѡn-1����
    rep(i , 1 ,  n-1){
        int minx=inf;
        int index;
        //��dis���ҳ�һ����С��
        rep(j,1,n){  //ʵ���Ͽ��Զ��Ż� 
            if(!vis[j] && dis[j] < minx){
                minx = dis[j];
                index = j;
            }
        }
        //������㱻����S���� ��Ϊ������㵽S���ϵı���С
        vis[index] = 1;
        sum += minx;//��С�������ܳ����ϸñߵ�ֵ
        //�����������ļ��룬ʹ������V-S���㵽S���ϵľ��뷢���˱仯
        rep(j , 1, n){
            if(!vis[j] && G[index][j] < dis[j]){
                dis[j] = G[index][j];
            }
        }
    }
}
int main(){
    while(cin>>n){
        if(n == 0) break;
        rep(i,1,n)
        rep(j,1,n)
        if(i==j) G[i][j] =  0;
        else G[i][j] = inf;
        sum = 0;
        rep(i,1,n*(n-1)/2){
            cin>>x>>y>>w;
            G[x][y] = w;
            G[y][x] = w;
        }

        Prim(1);
        cout<<sum<<endl;

    }
    return 0;
}



//��³˹�����㷨 Kruskal
/*
1. �ص㣺ѡ�߼ӵ㷨��ÿ��ѡ��С�ıߣ����γɻ��ͼ���
2. �ʺϱ߱Ƚ��ٵ�ϡ��ͼ
3. ���ò��鼯���жϻ� 
4. �ѱ�����ʱ�临�Ӷ�ElogE,�����öѴ��EҲ��ElogE,֮��ֻ��Ҫɨ��һ��E��
���帴�Ӷ���O(ElogE)
 
void Kruskal(V,T){
	T = V;
	nums = n;
	while(nums > 1){
		find the shortest edge(u,v) from E
		if v and u are subordinate to different conecttion components
		then  
			T = T union {(u , v)};
			nums--; 
	}
} 


int n;//����
int m;//������
int fa[maxn];//���ڵ�
//�ѱ߰��մ�С��������
struct node{
    int u,v,w; 
}edge[M];

bool cmp(node a, node b){
    return a.w < b.w;
}

//���鼯��������
void init(){
    rep(i,1,n){
        fa[i] = i;
    }
}
int find(int x){
    if(x != fa[x]){
        return fa[x] = find(fa[x]);
    }
    return fa[x];
}
void merge(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
        fa[fx] = fa[fy];
    }
}

int main(){
    int x,y,w;
    ios::sync_with_stdio(false);
    while(cin>>n){
        if(n  == 0) break;
        m = (n-1)*n/2;
        int sum = 0;
        init();
        rep(i , 1, m){
            cin>>x>>y>>w;
            edge[i].u = x;
            edge[i].v = y;
            edge[i].w = w;
        }
        sort(edge+1,  edge+1+m,cmp);//�ѱߴ�С����
        //��С����ɸ�� ���� ��������
        rep(i,1,m){
            node cur = edge[i];
            int u = cur.u;
            int v = cur.v;
            int w = cur.w;
        //���u,v����ͬһ�����ϣ��ڼ���uv������γɻ�
            if(find(u) != find(v)){
                sum += w;
                merge(u,v);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
*/ 



