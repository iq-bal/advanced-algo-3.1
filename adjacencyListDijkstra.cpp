#include <iostream>
#include<queue>
#include <set>

using namespace std;

const int N=1e3;

vector<pair<int,int>> g[N];
vector<int>distance(N,INT_MAX);

void dijkstra(int source){
	set<pair<int,int>> q;
	q.insert({0,source});
	// distance[source]=0;
	while(q.size()>0){
		
	}
}

int main(){
	int v,e;
	cin>>v>>e;
	while(e--){
		int v1,v2,c;	cin>>v1>>v2>>c;
		g[v1].push_back({v2,c});
		g[v2].push_back({v1,c});
	}

	return 0;
}