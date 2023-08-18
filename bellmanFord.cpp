#include <iostream>
#include <vector>

using namespace std;

struct edge{
  int u,v,c;
  edge(int u,int v, int c): u(u),v(v),c(c){}
};

const int INF = 2e9; 

int main(){
  int n,m;
  cin>>n>>m; 
  vector<edge> g;
  for (int i = 0; i < m; ++i)
  {
    int u,v,c;
    cin>>u>>v>>c;
    g.push_back(edge(u,v,c)); 
  }
  int source;
  cin>>source;
  vector<int>d(n,INF);
  d[source]=0; 
  vector<int>p(n,-1); 
  int x; 
  for (int i = 0; i < n; ++i)
  {
    x=-1; 
    for (int j = 0; j < m; ++j)
     {
        if( d[g[j].u] <INF && d[g[j].u] + g[j].c  < d[g[j].v]){
            d[g[j].v] =  d[g[j].u] + g[j].c ;
            p[g[j].v] = g[j].u; 
            x = g[j].v; 
        }
     } 
  }
  if(x==-1) cout<<"No Negative weighted cycle from "<< source <<endl; 
  else{
    int y = x;
    for (int i = 0; i < n; ++i)
    {
      y = p[y];
    }
    vector<int>path; 
    int curr = y; 
    while(true){
      path.push_back(curr);
      if(curr==y && path.size()>1){
        break;
      }
      curr = p[curr];
    }
    reverse(path.begin(),path.end());
    cout<< "Negative weighted cycle: "<<endl;
    for (int i = 0; i < path.size(); ++i)
    {
      cout<< path[i]<< " ";
    }
    cout<< endl; 
  }
  return 0;
}
