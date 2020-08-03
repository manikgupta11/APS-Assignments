#include<bits/stdc++.h>
using namespace std;

#define mx 100005

vector<int>g[mx];
int visited[mx];
bool articulation[mx];
int low[mx],d[mx],parent[mx];
int t;

void articulating(int s,bool root)
{
    t++;
    low[s]=d[s]=t;
    visited[s]=1;
    int child=0;

    for(int i=0; i<g[s].size(); i++)
    {
        int v=g[s][i];

        if(visited[v])
        {
            low[s]=min(low[s],d[v]);
        }
        if(!visited[v])
        {
            parent[s]=v;
            articulating(v,false);

            if(d[s]<=low[v]&&!root)
            {
                articulation[s]=true;
            }
            low[s]=min(low[s],low[v]);
            child++;
        }
        if(child>1&&root)
        {
            articulation[s]=true;
        }

    }

}
void setting()
{
    for(int i=0; i<mx; i++)
    {
        g[i].clear();
        visited[i]=articulation[i]=low[i]=d[i]=parent[i]=0;
        t=0;
    }
}
int main()
{

    setting();
    int n=7,m=8;
   // scanf("%d%d",&n,&m);
   // int u,v;
    // while(m--)
    // {
    //     scanf("%d%d",&u,&v);
    //     g[u].push_back(v);
    //     g[v].push_back(u);
    // }
g[0].push_back(1);
g[1].push_back(0);
g[1].push_back(2);
g[2].push_back(1);
g[2].push_back(0);
 g[0].push_back(2);
 g[1].push_back(3);
 g[3].push_back(1);
 g[1].push_back(4);
 g[4].push_back(1);
  g[1].push_back(6);
 g[6].push_back(1);
  g[5].push_back(3);
 g[3].push_back(5);
   g[5].push_back(4);
 g[4].push_back(5);

    for(int i=0; i<n; i++)
    {
        if(visited[i]==0) articulating(i,true);

    }
    int co=0;
    for(int i=0; i<n; i++)
    {
        if(articulation[i])
        {
            cout<<i<<" ";
        }
    }
   // printf("%d",co);

}