/*
  Name:	KMP 
  CopyRight:
  Author: Cz
  Date: 2019/8/28 20:58:04
  Description:
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000002;
int Next[N];
char S[N], T[N];
int slen, tlen;

void getNext()
{
    int j, k;
    j = 0; k = -1; Next[0] = -1;
    while(j < tlen)
        if(k == -1 || T[j] == T[k])
            Next[++j] = ++k;
        else
            k = Next[k];

}
/*
返回模式串T在主串S中首次出现的位置
返回的位置是从0开始的。
若返回-1则没有找到匹配
*/
int KMP()
{
    int i = 0, j = 0;
    getNext();

    while(i < slen && j < tlen)
    {
        if(j == -1 || S[i] == T[j])
        {
            i++; j++;
        }
        else
            j = Next[j];
    }
    if(j == tlen)
        return i - tlen;
    else
        return -1;
}
/*
返回模式串在主串S中出现的次数
*/
int KMP_Count()
{
    int ans = 0;
    int i, j = 0;
    getNext();
    for(i = 0; i < slen; i++)
    {
        while(j > 0 && S[i] != T[j])
            j = Next[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            ans++;
            j = Next[j];
        }
    }
    return ans;
}

int main()
{
    
    int TT;
    int i, cc;
    cin>>TT;
    while(TT--)
    {
        cin>>S>>T;
        slen = strlen(S);
        tlen = strlen(T);
        cout<<"模式串T在主串S中首次出现的位置: "<<KMP()<<endl;
        cout<<"模式串T在主串S中出现的次数: "<<KMP_Count()<<endl;
    }
    return 0;
}
 
