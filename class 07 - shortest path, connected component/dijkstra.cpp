#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define MAX ((int)1e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

int dis[N];

bool vis[N];

vector < pair < int , int > > vec[N];

void dijkstra(int src , int n)
{
    memset(vis,0,sizeof vis);
    for(int i = 1 ; i<=n ; i++) dis[i] = MAX;
    dis[src] = 0;
    priority_queue < pair < int , int > > pqu;
    pqu.push({0,src});
    while(!pqu.empty()){  /// O(m*log(m))
        int a = pqu.top().second;
        pqu.pop();
//        if(vis[a]) continue;
//        vis[a] = 1;
        for(auto p:vec[a]){  /// O(m*log(m))
            int b = p.first , c = p.second;
            int val = dis[a] + c;
            if(dis[b] > val){
                dis[b] = val;
                pqu.push({-dis[b],b});
            }
        }
    }

    /// O (m*log(m))
}



int main()
{
    fastio;
    int n , m;
    cin>>n>>m;
    while(m--){
        int a , b  , c;
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }
    return 0;
}
