#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include<cstdlib>
using namespace std;
void Build_Fail(int len);
void KMP(int slen, int plen);
int failure[100]={-1};
char s[100], p[100];
int main()
{
    ifstream fin("input_hw1_2.dat");
    int z=0,k; fin >> k; fin.get();
    while(z!=k)
    {
        ++z;
        fin.getline(s,sizeof(s));
        fin.getline(p,sizeof(s));
        cout<<z<<endl;
        Build_Fail(strlen(p));
        KMP(strlen(s), strlen(p));
        //fin.get();
    }
}
void Build_Fail(int len)
{
    for(int i=1,j=-1;i<len;i++)
    {
        while(j>=0&&p[j+1]!=p[i]) j=failure[j];
        if(p[j+1]==p[i]) j++;
        failure[i]=j;
    }
}
void KMP(int slen, int plen)
{
    int key=0;
    for(int i = 0, j = -1; i < slen; i++)
    {
        while(j >= 0 && p[j+1] != s[i])  j = failure[j];
        if(p[j+1] == s[i])  j++;
        if(j == plen-1)
        {
            cout << i-plen+1 << endl<<endl;
            key++;
            break;
        }
    }
    if(!key)
    cout<<"Not found!"<<endl<<endl;
}
