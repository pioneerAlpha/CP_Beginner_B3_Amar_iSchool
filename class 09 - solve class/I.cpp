#include<bits/stdc++.h>
#define N ((int)5e3 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

int dis[2][N];

bool vis[2][N];

vector < pair < int , int > > vec[N];

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        for(int i = 1 ; i <= n ; i++) vec[i].clear();
        while(m--){
            int a , b , w;
            cin>>a>>b>>w;
            vec[b].push_back({a,w});
            vec[a].push_back({b,w});
        }
        for(int i = 1 ; i<=n ; i++){
            dis[0][i] = MAX;
            dis[1][i] = MAX+1;
            vis[0][i] = vis[1][i]  = 0;
        }
        /// dis[0][i] = shortest path of i
        /// dis[1][i] = 2nd best shortest path of i
        dis[0][1] = 0;
        priority_queue < pair < int , pair < int , int > > > pqq;
        pqq.push({0,{0,1}});
        while(!pqq.empty()){
            pair < int , int > p = pqq.top().second;
            pqq.pop();
            int idx = p.first , node = p.second;
            if(vis[idx][node]) continue;
            vis[idx][node] = 1;
            for(auto p:vec[node]){
                int b = p.first , c = p.second;
                int val = dis[idx][node] + c;
                if(val < dis[0][b]){
                    dis[1][b] = dis[0][b];
                    dis[0][b] = val;
                    pqq.push({-dis[1][b],{1,b}});
                    pqq.push({-dis[0][b],{0,b}});
                }
                else if(val > dis[0][b]){
                    if(val < dis[1][b]){
                        dis[1][b] = val;
                        pqq.push({-dis[1][b],{1,b}});
                    }
                }
            }
        }
        cout<<"Case "<<caseno++<<": "<<dis[1][n]<<endl;
    }
    return 0;
}
