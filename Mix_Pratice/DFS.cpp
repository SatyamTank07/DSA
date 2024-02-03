// DFS

#include<iostream>

using namespace std;

#define sz 4

int vis[sz];        //0 denotes not seen till now, 1 denotes in process, 2 denotes fully visited
int dfs[sz];        // fully visited nodes are stored here for DFS
int tempS[sz];      // in process nodes are stored here(a Stack)
int top=-1;         //for stack operation

int adj[sz][sz] = {
    {0,1,-1,1},
    {1,0,1,-1},
    {-1,1,0,1},
    {1,-1,1,0}
};


void DFS(int source)
{
    tempS[++top]=source;  // adds source element to Stack
    int cnt=0;            //sets index of DFS to zero

    while(top>-1)
    {
        source=tempS[top--];    //gets new source (element) to start exploring
        dfs[cnt]= source;       //adds popped element to resultant array(dfs)

        for(int i=0;i<sz;i++)
        {

            if((vis[i]==0) && (adj[source][i]>-1) && (i!=source))                           //checks if the node is not in processing or already visited && 
            {
                tempS[++top]=i;                                                            //adds all neighbours to Stack
                vis[i]=1;                                                                   // updates those node as in process hence those will not be added further
            }   
        }
        vis[source]=2;                                                                      // denotes fully explored
        cnt++;                                                                              //just to update index of resultant(DFS) array
    }
}



int main()
{
    for(int i=0;i<sz;i++)
        vis[i]=0;

    DFS(0);

    cout<<"Your Depth First Search Result Is :";
    for (int i=0;i<sz;i++)
        cout<<dfs[i]<<"->";

    
}