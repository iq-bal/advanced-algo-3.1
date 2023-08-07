// this implementation was used in lab by Noyon sir
#include <iostream>
#include <climits>

using namespace std;

const int v=5,e=5; 

bool vis[v]; 

void dijkstra(int g[][v],int source,int distance[]){
	distance[source]=0;

	for (int j = 0; j < v; ++j)
	{
		for (int i = 0; i < v; ++i)
		{
			if(g[source][i]!= INT_MAX && g[source][i]+distance[source]<distance[i]){
				distance[i] = g[source][i] + distance[source];
			}
		}
		vis[source]= true;
		int min_ = INT_MAX; 
		for (int i = 0; i < v; ++i)
		{
			if(!vis[i] && distance[i]<min_){
				source = i; 
				min_ = distance[i];
			}
		}
	}
}


int main(int argc, char const *argv[])
{ 
	int g[v][v];
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			g[i][j]= INT_MAX; 
		}
	}
	for (int i = 0; i < e; ++i)
	{
		int v1,v2,c;
		cin>>v1>>v2>>c;
		g[v1][v2]=c;
	 	g[v2][v1]=c;

	}
	int source;
	cin>>source; 
	int distance[v]; 
	for (int i = 0; i < v; ++i)
	{
		distance[i] = INT_MAX; 
	}
	dijkstra(g,source,distance); 
	for (int i = 0; i < v; ++i)
	{
		cout<< distance[i]<< " ";
	}
	return 0;
}