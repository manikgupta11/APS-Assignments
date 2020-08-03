#include<bits/stdc++.h>
using namespace std;

vector<int>g[100000];

int time1=1;

void addedge(int u, int v)  {
        g[u].push_back(v);
        g[v].push_back(u);
 
    }

void articulationfn(int s,bool root,bool visited[], bool articulation[], int low[], int d[], int parent[])
{
    visited[s]=true;
    low[s]=time1;
    d[s]=time1;
    time1++;
  
    int children=0;

    for (auto itr = g[s].begin(); itr != g[s].end(); ++itr) 
    {
        int v = *itr;

        if(visited[v]==true)
        {
            if(d[v]<low[s])
            {
                low[s]=d[v];
            }

        }
        if(visited[v]==false)
        {    
            parent[s]=v;
            children++;
            articulationfn(v,false,visited, articulation, low, d, parent);

            if(d[s]<=low[v] && root==false)
            {
                articulation[s]=true;
            }
           
            if(low[v] < low[s])
            {
                low[s]=low[v];
            }
            
        }
        if(children>1 && root==true)
        {
            articulation[s]=true;
        }

    }

}
void initializer(bool visited[], bool articulation[], int low[], int d[], int parent[], int n)
{   low={0};
     d={0};
     parent={0};
    for(int i=0; i<n; i++)
    {
      //  g[i].clear();
        //time1=1;
        visited[i]=false;
        articulation[i]=false;


    }
}
int main()
{ 

int n=7,m=8;  
bool visited[n];
bool articulation[n];
int low[n];
int d[n];
int parent[n];
initializer(visited, articulation, low, d, parent, n);
  
// addedge(0,1);
// addedge(1,2);
// addedge(0,2);
// addedge(0,3);
// addedge(3,4);

addedge(0,1);
addedge(1,2);
addedge(0,2);
addedge(1,3);
addedge(1,4);
addedge(1,6);
addedge(3,5);
addedge(4,5);

// addedge(0,1);
// addedge(1,2);
// addedge(2,3);

    for(int i=0; i<n; i++)
    {
        if(visited[i]==false) articulationfn(i,true,visited, articulation, low, d, parent);

    }
    
    for(int i=0; i<n; i++)
    {
        if(articulation[i]==true)
        {
            cout<<i<<" ";
        }
    }

}