// BFS

#include<iostream>

using namespace std;

#define sz 4

int vis[sz];        //0 denotes not seen till now, 1 denotes in process, 2 denotes fully visited
int bfs[sz];        // fully visited nodes are stored here
int tempQ[sz];      // in process nodes are stored here(a queue)
int front=0,rear=-1;  // for queue operation
// int adj[sz][sz]=
// {
// {0,1,-1,1,-1,-1,-1,-1,-1},
// {1,0,1,-1,-1,-1,-1,-1,-1},
// {-1,1,0,1,-1,-1,-1,1,1},
// {1,-1,1,0,1,-1,-1,-1,-1},
// {-1,-1,-1,1,0,1,1,-1,-1},
// {-1,-1,-1,-1,1,0,-1,-1,-1},
// {-1,-1,-1,-1,1,-1,0,-1,-1},
// {-1,-1,1,-1,-1,-1,-1,0,-1},
// {-1,-1,1,-1,-1,-1,-1,-1,0}};
int adj[sz][sz] = {
    {0,1,-1,1},
    {1,0,1,-1},
    {-1,1,0,1},
    {1,-1,1,0}
};


void BFS(int source)
{
    tempQ[++rear]=source;                                                                   // adds source element to queue
    int cnt=0;                                                                              //sets index of bfs to zero

    while(front<=rear)
    {
        cout<<endl<<"Looping With "<<"Front :"<<front<<" "<<"Rear :"<<rear<<endl;
        source=tempQ[front++];                                                             //get's new source (element) to start exploring
        bfs[cnt]= source;                                                                   //adds popped element to resultant array(bfs)

        for(int i=0;i<sz;i++)
        {
            cout<<"Traversing :"<<source<<endl;

            if((vis[i]==0) && (adj[source][i]>-1) && (i!=source))                           //checks if the node is not in processing or already visited && 
            {
                cout<<"Pushed For Processing:"<<i<<endl;
                tempQ[++rear]=i;                                                            //adds all neighbours to queue
                vis[i]=1;                                                                   // updates those node as in process hence those will not be added further
            }   
        }
        cout<<"Inserted Node "<<source<<" at "<<cnt<<"th Index(As It's Fully Visited)"<<endl<<endl;
        vis[source]=2;                                                                      // denotes fully explored
        cnt++;                                                                              //just to update index of resultant(BFS) array
    }
}


int main()
{
    for(int i=0;i<sz;i++)
        vis[i]=0;

    BFS(0);

    cout<<"Your Breadth First Search Result Is :";
    for (int i=0;i<sz;i++)
        cout<<bfs[i]<<"->";

    
}