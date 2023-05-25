// DFD,BFS,MIN_COST,SHORTEST PATH(DIJKASTRA)
#include<stdio.h>
#include <limits.h>
#include <stdbool.h>
int queue[100];
int front=0,back=0;
int vis[20];
int cost[10][10];
int V=10;
//<-----------------Input Vertices------------------>
void vertices(){
	int v;
	printf("Enter the vertices:");
	scanf("%d",&v);
	V=v;
}
void dijkstra(int src,int graph[V][V]);
void printSolution(int dist[]);
int minDistance(int dist[],bool sptSet[]);
//<-----------BFS(breadth-fir10st search)code----------->
void push(int var)
{
    queue[back]=var;
    back++;
}
void pop()
{
    queue[front]=0;
    front++;
}
void bfs(int s,int graph[10][10]){
	int visited[20]={0};
	push(s+1);
    visited[s+1]=1;
    while(front!=back)
    {
        int current=queue[front];
        printf("%d ",current);
        pop();
        int i;
         for(i=0;i<V;i++)
        {
            if((graph[current-1][i]!=0)&&(visited[i+1]==0))
            {
                visited[i+1]=1; // marking visisted
                push(i+1);
            }
        }
    }
}
//<-----------DFS(depth-first search) code------------>
void DFS(int i,int graph[V][V]) 
{ 
    int j; 
    printf("%d ",i); 
    vis[i]=1; 
    for(j=0;j<V;j++) 
        if(!vis[j]&&graph[i][j]>=1) 
            DFS(j,graph); 
}
//<-----------minimum cost spanning tree------------->
void minimumcost(int cost[10][10])
{
    int visited[10]={0},i,j,no_e=1,min,a,b,min_cost=0;
    visited[0]=1; // visited first node
    printf("Minimum Spanning Tree:");
    while(no_e<V)
    {
        min=1000;
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        if(visited[b]==0)    //if node is not visited
        {
            printf("\n%d to %d  cost=%d",a,b,min);
            min_cost=min_cost+min;
            no_e++;
        }
        visited[b]=1;
        cost[a][b]=cost[b][a]=1000;// initialize with maximum value
    }
    printf("\nMinimum Cost is: %d\n",min_cost);
}
//<-----------Shorteest path algorithm(dijkstra's algorithm)-------->
int minDistance(int dist[],bool sptSet[])
{
	int min=INT_MAX,min_ind,v;
	for(v=0;v<V;v++)
		if(sptSet[v]==false&&dist[v]<=min)
			min=dist[v],min_ind=v;
	return min_ind;
}
void printSolution(int dist[])
{
	int i;
	printf("Vertex \t\t Distance from Source\n");
	for(i=0;i<V;i++)
		printf("%d \t\t\t\t %d\n",i,dist[i]);
}
void dijkstra(int src,int graph[V][V])
{
	int dist[V],i; 
	bool sptSet[V];
	for(i=0;i<V;i++)
		dist[i]=INT_MAX,sptSet[i]=false;
	dist[src]=0;
	int count,v;
	for(count=0;count<V-1;count++){
		int u=minDistance(dist,sptSet);
		sptSet[u]=true;
		for(v=0;v<V;v++)
			if(!sptSet[v]&&graph[u][v]&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v])
				dist[v]=dist[u]+graph[u][v];
	}
	printSolution(dist);
}
void main()
{
	vertices();
	int graph[V][V];
	int ch,s,i,j,sa,n1,w;
	printf("Enter value in adjancy matrix value:\n");
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&w);
			graph[i][j]=w;
			cost[i][j]=w;
			if(cost[i][j]==0)
              cost[i][j]=1000;
		}
	}
	while(1){
		printf("\n\nEnter 1 for Breadth First Search");
		printf("\nEnter 2 for Depth First Search");
		printf("\nEnter 3 for Minimum Cost Spanning Tree");
		printf("\nEnter 4 for Shortest Path Algorithm");
		printf("\nEnter 5 for Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
					printf("ENTER THE SOURCE VERTEX :");
					scanf("%d",&s);
					bfs(s,graph);
					break;
			case 2: 
					for(i=0;i<V;i++) 
			        vis[i]=0;
			        printf("ENTER THE SOURCE VERTEX :");
					scanf("%d",&s);
			    	DFS(s,graph);
					break;
			case 3: 
					minimumcost(cost);
					break;
			case 4:
					printf("ENTER THE SOURCE VERTEX BETWEEN 0 AND %d : \n",V);
	  				scanf("%d",&n1);
					dijkstra(n1,graph);
					break;
			case 5:
					printf("Thanks!");

		    		return;
			default:
					printf("Invalid choice!\n");
			}
		}
}