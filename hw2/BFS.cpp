#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
{
    ifstream fin("input_hw2.dat");
    int times,x,y,x_of_start,y_of_start,x_of_end,y_of_end;
    fin>>times;
    for(int k=1;k<=times;k++)
    {
        cout<<k<<endl;
        int num=6;
        bool ends=false;
        fin>>x>>y;
        int mapin[x+2][y+2],output[x+2][y+2];
        //ªì©l¤Æ°}¦C
        for(int i=0;i<x+2;i++)
        {
            for(int j=0;j<y+2;j++)
            {
                mapin[i][j]=1;
                output[i][j]=1;
            }
        }
        //¿é¤J°}¦C
        for(int i=1;i<x+1;i++)
        {
            for(int j=1;j<y+1;j++)
            {
                fin>>mapin[i][j];
                output[i][j]=mapin[i][j];
                if(mapin[i][j]==2)
                {
                    x_of_start=i;
                    y_of_start=j;
                }
                if(mapin[i][j]==3)
                {
                    x_of_end=i;
                    y_of_end=j;
                }
            }
        }
        if(mapin[x_of_start][y_of_start+1]==0)//up
           mapin[x_of_start][y_of_start+1]=num;

        if(mapin[x_of_start][y_of_start-1]==0)//down
            mapin[x_of_start][y_of_start-1]=num;

        if(mapin[x_of_start-1][y_of_start]==0)//left
            mapin[x_of_start-1][y_of_start]=num;

        if(mapin[x_of_start+1][y_of_start]==0)//right
            mapin[x_of_start+1][y_of_start]=num;
        while(!ends)
        {
            bool a=true;
            for(int i=1;i<x+1;i++)
            {
                for(int j=1;j<y+1;j++)
                {
                    if(mapin[i][j]==num&&mapin[i][j+1]==0)//up
                       {mapin[i][j+1]=num+1;a=false;}

                    else if(mapin[i][j]==num&&mapin[i][j+1]==3)
                       {ends=true;}

                    if(mapin[i][j]==num&&mapin[i][j-1]==0)//down
                       {mapin[i][j-1]=num+1;a=false;}

                    else if(mapin[i][j]==num&&mapin[i][j-1]==3)
                       {ends=true;}

                    if(mapin[i][j]==num&&mapin[i-1][j]==0)//left
                       {mapin[i-1][j]=num+1;a=false;}

                    else if(mapin[i][j]==num&&mapin[i-1][j]==3)
                       {ends=true;}

                    if(mapin[i][j]==num&&mapin[i+1][j]==0)//right
                       {mapin[i+1][j]=num+1;a=false;}

                    else if(mapin[i][j]==num&&mapin[i+1][j]==3)
                       {ends=true;}
                }
            }
            num++;
            if(a)break;
        }
        ends=false;num--;
        while(!ends)
        {
            if(mapin[x_of_end][y_of_end+1]==num)//up
            {
                output[x_of_end][y_of_end+1]=5;
                y_of_end+=1;
            }

            else if(mapin[x_of_end][y_of_end-1]==num)//down
            {
                output[x_of_end][y_of_end-1]=5;
                y_of_end-=1;
            }

            else if(mapin[x_of_end-1][y_of_end]==num)//left
            {
                output[x_of_end-1][y_of_end]=5;
                x_of_end-=1;
            }

            else if(mapin[x_of_end+1][y_of_end]==num)//right
            {
                output[x_of_end+1][y_of_end]=5;
                x_of_end+=1;
            }

            else
                ends=true;
            num--;
        }

        if(output[x_of_start][y_of_start+1]==5||output[x_of_start][y_of_start-1]==5||output[x_of_start-1][y_of_start]==5||output[x_of_start+1][y_of_start]==5)
        {
            cout<<"yes"<<endl;
            for(int i=1;i<x+1;i++)
            {
                for(int j=1;j<y+1;j++)
                {
                    cout<<output[i][j];
                }
                cout<<endl;
            }
        }
        else
            cout<<"no"<<endl;
    }
}
