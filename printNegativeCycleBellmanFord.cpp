#include<iostream>
#include<vector>
#include<set>
#include <unordered_map>


using namespace std;

struct Edge {
    int a, b, cost;
    Edge(int a,int b, int cost): a(a), b(b), cost(cost) {}
};
int n, m, v;
vector<Edge> edges;
const int INF = 1000000000;
void Bellman()
{
    set<int>s;
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges)
            if (d[e.a] < INF)
                if (d[e.b] > d[e.a] + e.cost) {
                    d[e.b] = max(-INF, d[e.a] + e.cost);
                    p[e.b] = e.a;
                    x = e.b;
                    s.insert(x);
        }
    }

    if (x == -1)
        cout << "No negative cycle";
    else {
        unordered_map<int,bool> printed;
     for(int i: s){
            if(printed[i])  continue;
            int y = i;
            for(int j=0; j<n; j++){
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
            //reverse(path.begin(),path.end());
            cout << "The Cycle Contains " << path.size()-1 << " node" << endl;
            for(int j=0; j< (int)path.size(); j++){
                cout<< path[j]<< " ";
                printed[path[j]] = true;
            }
            cout<< endl;
     }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v,c;
        cin>>u>>v>>c;
        edges.push_back(Edge(u,v,c));
    }
    cin>>v;
    Bellman();
    return 0;
}