#include<bits/stdc++.h>
#define N ((int)1e4 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

int dis[2][N];

bool vis[N];

vector < pair < int , int > > vec[2][N];

struct edg{
    int a , b , w;
}arr[5*N];


void dijkstra(int idx , int src , int n)
{
    //cout<<"dij \n"<<idx<<" "<<src<<" "<<n<<endl;
    for(int i = 1 ; i<=n ; i++) dis[idx][i] = MAX , vis[i] = 0;
    priority_queue < pair < int , int > > pqq;
    pqq.push({0,src});
    dis[idx][src] = 0;
    while(!pqq.empty()){
        int a = pqq.top().second;
        pqq.pop();
        if(vis[a]) continue;
        vis[a] = 1;
        //cout<<a<<" "<<dis[idx][a]<<endl;
        for(auto p:vec[idx][a]){
            int b = p.first , c = p.second;
            int val = dis[idx][a] + c;
            if(dis[idx][b] > val){
                //cout<<"upp : "<<c<<" "<<val<<" "<<b<<endl;
                dis[idx][b] = val;
                pqq.push({-val,b});
            }
        }
    }
    //cout<<"dij end \n";
}

int main()
{
//    //cout<<(int)((1LL<<31)-1);
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , m , src,  des , tot;
        cin>>n>>m>>src>>des>>tot;
        for(int i = 1 ; i <= n ; i++) vec[0][i].clear() , vec[1][i].clear();
        for(int i = 1 ; i<=m ; i++){
            int a , b , w;
            cin>>a>>b>>w;
            arr[i] = {a,b,w};
            vec[0][a].push_back({b,w});
            vec[1][b].push_back({a,w});
        }
        dijkstra(0,src,n);

//        for(int i = 1 ; i<=n ; i++) cout<<i<<" "<<dis[0][i]<<endl;

        dijkstra(1,des,n);
//        for(int i = 1 ; i<=n ; i++) cout<<i<<" "<<dis[1][i]<<endl;
        int ans = -1;
        for(int i = 1 ; i <= m ; i++){
            int u = arr[i].a , v = arr[i].b , w = arr[i].w;
            if(dis[0][u] <= tot - w - dis[1][v]){
                ans = max(ans , w);
                //cout<<u<<" "<<v<<" "<<w<<"\n"<<dis[0][u] << " " << dis[1][v]<<endl;
            }
        }
        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
