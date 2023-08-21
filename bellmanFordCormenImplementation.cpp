#include <iostream>
#include <vector>

using namespace std;

struct edge{
	int u,v,c;
	edge(int u, int v, int c): u(u), v(v), c(c) {}
};

bool bellmanFord(vector<edge> &g, vector<int> &d){
	int v = d.size();
	for (int i = 0; i < v-1; ++i)
	{
		for (int j = 0; j < g.size(); ++j)
		{
			if( d[g[j].u]!=INT_MAX && d[g[j].u]+ g[j].c < d[g[j].v] ){
				d[g[j].v]= d[g[j].u]+ g[j].c ;
			}
		}
	}
	for (int j = 0; j < g.size(); ++j)
	{
		if( d[g[j].u]!=INT_MAX && d[g[j].u]+ g[j].c < d[g[j].v] ){
			return false; 
		}
	}
	return true; 
}

int main(){
	int n,e;
	cin>>n>>e;
	vector<edge> g;
	for (int i = 0; i < e; ++i)
	{
		int u, v, c;
		cin>>u>>v>>c;
		g.push_back(edge(u,v,c));
	}
	vector<int> d(n,INT_MAX); 
	int s;
	cin>>s; 
	d[s]=0; 
	if(!bellmanFord(g,d))	{ cout<< "Graph has negative weighted cycle"<<endl; return 0;}
	for (int i = 0; i < n; ++i)
	{
		cout<< d[i]<< " "; 
	}
	return 0; 
}