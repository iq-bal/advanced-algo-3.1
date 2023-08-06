#include <iostream>
#include<vector>
#include<queue>

using namespace std;


const int N = 1e3;
vector<int> g[N];
bool vis[N];
int color[N]={-1};

bool isBipartite(int source){
	queue<int>q;
	q.push(source);
	color[source]= 0; 
	while(!q.empty()){
		int d = q.front();
		q.pop();
		if(!vis[d]){
			vis[d]=true;
			for(int child: g[d]){
				if(color[child]==color[d]) return false;
				if(color[child]==-1){
					color[child]= 1- color[d];
					q.push(child);
				}
			}
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