#include<bits/stdc++.h>
#define N ((int)3e4 + 5)
#define MAXL ((ll)1e18 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

vector < pair < int , int > > vec[N];

bool vis[N];

ll dis[N];

void dijkstra(int src , int n)
{
    for(int i = 1 ; i<=n ; i++) dis[i] = MAXL , vis[i] = 0;
    dis[src] = 0;
    priority_queue < pair < ll , int > > pqq;
    pqq.push({0,src});
    while(!pqq.empty()){
        int a = pqq.top().second;
        pqq.pop();
        if(vis[a]) continue;
        vis[a] = 1;
        for(auto p:vec[a]){
            int b = p.first , c = p.second;
            if(dis[b] > dis[a] + c){
                dis[b] = dis[a] + c;
                pqq.push({-dis[b],b});
            }
        }
    }
}


int main()
{

    fastio;

    int t , caseno = 1;

    t = 1;
    while(t--){
        ll tot;
        int n , m  , k , p;
        cin>>n>>m>>tot>>k>>p;
        tot *= 60;
        while(p--){
            int a;
            cin>>a;
            vis[a] = 1;
        }
        while(m--){
            int a, b, c;
            cin>>a>>b>>c;
            c *= 60;
            if(vis[b]) c += k;
            vec[a].push_back({b,c});
        }
        dijkstra(1,n);
        if(dis[n] > tot) dis[n] = -1;
        cout<<dis[n]<<endl;
    }

    return 0;
}
