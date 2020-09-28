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
����ģʽ��T������S���״γ��ֵ�λ��
���ص�λ���Ǵ�0��ʼ�ġ�
������-1��û���ҵ�ƥ��
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
����ģʽ��������S�г��ֵĴ���
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
        cout<<"ģʽ��T������S���״γ��ֵ�λ��: "<<KMP()<<endl;
        cout<<"ģʽ��T������S�г��ֵĴ���: "<<KMP_Count()<<endl;
    }
    return 0;
}
 
