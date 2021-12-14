/*11 12 13 14 15
16 17 18 19 20
1  2  3  4   5
6  7  8  9  10
21 22 23 24 25 */

/*
假设对图片上任意点(x,y)，绕一个坐标点(rx0,ry0)逆时针旋转a角度后的新的坐标设为(x0, y0)，有公式：

    x0= (x - rx0)*cos(a) - (y - ry0)*sin(a) + rx0 ;

    y0= (x - rx0)*sin(a) + (y - ry0)*cos(a) + ry0;

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


int main(){
    int num[10][10];
    int bak[10][10];
    int a,b,x,y;
    while(cin>>num[1][1]){
        
        for(int i=2;i<6;i++) cin>>num[1][i];
        for(int i=2; i<6; i++){
            for(int j=1; j<6; j++){
                cin>>num[i][j];
            }
        }

        cin>>a>>b>>x>>y;

        for(int i=1; i<6; i++){
            for(int j=1; j<6; j++){
                if(i>=x && i<x+b && j>=y && j<y+b){
                    if(a == 2){
                        int x0 = x + y - j + b - 1;
                        int y0 = i - x + y;
                        bak[x0][y0] = num[i][j];
                    }
                    else{
                        int x0 = j - y + x;
                        int y0 = x + y + b - i - 1;
                        bak[x0][y0] = num[i][j];
                    }
                }
                else{
                    bak[i][j] = num[i][j];
                }
            }
            
        }
        for(int i=1; i<6; i++){
                for(int j=1; j<6; j++){
                    if(j != 1) cout<<" ";
                    cout<<bak[i][j];
                }
                cout<<endl;
            }
    }
    return 0;
}

