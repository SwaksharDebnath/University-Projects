#include<bits/stdc++.h>
#include<fstream>
using namespace std;
typedef struct passenger
{
    string name;
    int milage;
    int years;
    int sequence;
    int prior;
}passenger;

vector<passenger>p;
vector<passenger>p2;

void calc_prior(int s)
{
    for(int i=0;i<s;++i)
    {
        p[i].prior = (p[i].milage/1000)+p[i].years - p[i].sequence;
    }
}

void heap_up(int n)
{
    int parent;
    if(n>1)
    {
        parent=n/2;
        if(p[n].prior>p[parent].prior)
        {
            passenger temp;
            temp=p[parent];
            p[parent]=p[n];
            p[n]=temp;
            parent=n;
        }
        heap_up(parent);
    }

}

void heap_down(int parent)
{
    int lchild, n=p.size(),flag=0;
    lchild=2*parent;
    while(lchild<=n && flag==0)
    {
        if(lchild+1<=n && p[lchild].prior<p[lchild+1].prior)
        {
            lchild=lchild+1;
        }
        if(p[parent].prior<p[lchild].prior)
        {
            passenger temp;
            temp=p[parent];
            p[parent]=p[lchild];
            p[lchild]=temp;
            parent=lchild;
        }
        else
            flag=1;
    }
}

void finallsit(int n)
{
    if(n>=1)
    {
        p2.push_back({p[1].name,p[1].milage,p[1].years,p[1].sequence,p[1].prior});
        p.erase(p.begin()+1);
        n=n-1;
        for(int i=n/2;i>=1;--i)
            heap_down(i);
        //heap_down(n/2);
        finallsit(n);
    }

}

int main()
{

    string n;
    int m,y,s,pr=0,x,c=0;
    p.push_back({"0",0,0,0,0});
    ifstream fin;
    fin.open("file.txt");
    if(fin.is_open())
    {
        while(getline(fin,n))
        {
            fin>>m>>y>>s;
            fin.ignore();
            p.push_back({n,m,y,s,pr});

            //cout<<"sf"<<endl;
            c = 1;
        }

    }
    else
        cout<<"File could not open!"<<endl;
    fin.close();


    cout<<"---------------------Resolving Overbooked Flight---------------------"<<endl;
    cout<<endl<<"Loading Initial Waiting List..."<<endl<<endl;
    system("Pause");
    if(c == 0)
        cout<<endl<<"The list is empty!!!"<<endl;
    else
    {

        cout<<endl<<"   NAME-----------MILAGE---YEARS---SEQUENCE"<<endl;


        for(int i=1;i<p.size();++i)
        {
            cout<<i<<"."<<p[i].name<<"       "<<p[i].milage<<"   "<<p[i].years<<"       "<<p[i].sequence<<endl;
        }

        cout<<endl<<endl<<"Loading Final Waiting List..."<<endl<<endl;
        system("Pause");
        cout<<endl<<"   NAME-----------MILAGE---YEARS---SEQUENCE---PRIORITY VALUE"<<endl;

        x = p.size();

        calc_prior(x);


        //heap_up(x-1);

        for(int i=(x-1)/2;i>=1;--i)
            heap_down(i);

        for(int i=0;i<p.size();++i)
        {
            cout<<i+1<<"."<<p[i].name<<"       "<<p[i].milage<<"   "<<p[i].years<<"       "<<p[i].sequence<<"           "<<p[i].prior<<endl;
        }
        system("Pause");
        finallsit(x-1);

        for(int i=0;i<p2.size();++i)
        {
            cout<<i+1<<"."<<p2[i].name<<"       "<<p2[i].milage<<"   "<<p2[i].years<<"       "<<p2[i].sequence<<"           "<<p2[i].prior<<endl;
        }
    }



}

