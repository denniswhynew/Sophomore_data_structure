#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
string str;
ifstream ffin("dictionary.txt");
ofstream fout("dictionary.txt");
int LR=-1;//§PÂ_¥ª¥k
struct tree{
    int Tplus;
    char treech;
    tree *right;
    tree *left;
};
void C(char f)
{
    char ch;
    string ss;
    while(ffin.get(ch))
    {
        if(ch==f)
        {
            ffin.get();
            ffin>>ss;
            fout<<ss;
            break;
        }
    }
}
void F(tree*node,string str,int LR)
{
    if(node->treech!=NULL)
    {
        fout<<node->treech<<str<<endl;
    }
    if(!LR)
        str+='0';
    if(LR)
        str+='1';
    F(node->left,str,0);
    F(node->right,str,1);
}
void E(tree* node)
{
    if(node==NULL)
        return;
    E(node->left);
    E(node->right);
    delete node;
}
int main()
{
    char latter;
    int num=0,addnum=0;
    vector<char> content;
    vector<int> times;
    vector<tree> address;
    ifstream fin("file.txt");
    while(fin.get(latter))
    {
        bool isinvactor=false;
        for(int i=0;i<num;i++)
        {
            if(content[i]==latter)
            {
                times[i]++;
                isinvactor=true;
                break;
            }
        }
        if(!isinvactor)
        {
            content.push_back(latter);
            times.push_back(1);
            num++;
        }
    }
    //hear is for sorting
    for(int i=0;i<num;i++)
    {
        int temp;
        char ch;
        for(int j=0;j<num-1;j++)
        {
            if(times[j]>times[j+1])
            {
                temp=times[j];
                ch=content[j];
                times[j]=times[j+1];
                content[j]=content[j+1];
                times[j+1]=temp;
                content[j+1]=ch;
            }
        }
    }
    /* ****************************/
    tree *root=NULL,*now;
    //building tree
    while(!(num==0&&addnum==1))
    {
        tree *t=new tree;
        bool isin=false;
        if(times[num]<=*address[addnum].Tplus)
        {
            tree *d=new tree;
            t->right=d;
            d->treech=content[num];
            d->left=NULL;
            d->right=NULL;
            num--;
            times.pop_back();
            content.pop_back();
        }
        if(times[num]<=*address[addnum].Tplus)
        {
            tree *d=new tree;
            t->left=d;
            d->treech=content[num];
            d->left=NULL;
            d->right=NULL;
            num--;
            times.pop_back();
            content.pop_back();
        }
        if(times[num]>*address[addnum].Tplus)
        {
            isin=true;
            tree *d=new tree;
            t->right=d;
            d->treech=NULL;
            d->right=address[addnum];
            d->left=NULL;
            delete address[addnum];
            addnum--;
            address.pop_back();
        }
        if(times[num]>*address[addnum].Tplus)
        {
            isin=true;
            tree *d=new tree;
            t->left=d;
            d->treech=NULL;
            d->left=address[addnum];
            d->right=NULL;
            delete address[addnum];
            addnum--;
            address.pop_back();
        }
        address.push_back(&t);
        addnum++;
        t->Tplus=t->left->Tplus+t->right->Tplus;
    }
    //»s§@¦r¨å
    F(root,str,LR);
    //§R°£
    E(root);
    //À£ÁY
    char cc;
    while(fin.get(cc))
    {
        C(cc);
    }
}
