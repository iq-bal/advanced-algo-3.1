#include <iostream>
#include<vector>
#include<queue>

using namespace std;


const int N = 1e3;
vector<int> g[N];
int color[N];


bool isBipartite(int source){
	memset(color , -1  , sizeof color);
	queue<int>q;
	q.push(source);
	color[source]= 0; 
	while(!q.empty()){
		int d = q.front();
		q.pop();
		for(int child: g[d]){
			if(color[child]==-1){
				color[child]= 1- color[d];
				q.push(child);
			}
			else if(color[child]==color[d]) return false;
		}
	}
	return true; 
}

int main(){
	int v,e;
	cin>>v>>e;
	while(e--){
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	if(isBipartite(0)){
		cout<< "bipartite"<< endl;
	}
	else{
		cout<<"not bipartite"<< endl; 
	}
}