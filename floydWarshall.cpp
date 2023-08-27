#include <iostream>


using namespace std;

const int INF = INT_MAX; 
const int N = 1e3;
int graph[N][N];
int pred[N][N]; 

void initializeGraph(){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(i==j)	graph[i][j]=0;
			else		graph[i][j] = INF; 
		}
	}
}

bool detectNegativeCycle(int v, int e){
	int d[v][v];
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			d[i][j] = graph[i][j];
		}
	}

	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			for (int k = 0; k < v; ++k)
			{
				if(d[j][i]+d[i][k]<d[j][k]){
					d[j][k] = d[j][i] + d[i][k]; 
				}
			}
		}
	}

	for (int i = 0; i < v; ++i)
	{
		if(d[i][i]<0){
			return true; 
		}
	}
	return false; 
}




int main(){
	initializeGraph();
	int v,e;
	cin>>v>>e;
	for (int i = 0; i < e; ++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		graph[u][v]=w;
	}
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			cout<< graph[i][j] << " ";
		}
		cout<< endl; 
	}
	cout<< endl; 
	if(detectNegativeCycle(v,e)) cout<< "Negative cycle exists" << endl; 
	else	cout<< "No Negative cycle exists" << endl; 

	return 0;
}