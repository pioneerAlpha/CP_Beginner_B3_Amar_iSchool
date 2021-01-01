#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;


vector < int > vec[N];

struct edg{
    int a , b , w;
}arr[N];

int dis[N];

void bfs(int src , int n)
{
    for(int i = 1 ; i <= n ; i++) dis[i] = -1;
    dis[src] = 0;
    queue < int > que;
    que.push(src);
    while(!que.empty()){
        int a = que.front();
        que.pop();
        for(int b:vec[a]){
            if(dis[b] == -1){
                dis[b] = dis[a] + 1;
                que.push(b);
            }
        }
    }
}

int main()
{
    freopen("path.in","r",stdin);
//    //cout<<(int)((1LL<<31)-1);
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , m , src,  L , K;
        cin>>n>>m>>src>>L>>K;
        for(int i = 1 ; i<=n ; i++) vec[i].clear();
        for(int i = 1 ; i<=m ; i++){
            int a , b , w;
            cin>>a>>b>>w;
            arr[i] = {a,b,w};
            vec[b].push_back(a);
            vec[a].push_back(b);
        }
        bfs(src , n);
//        for(int i = 1 ; i<=n ; i++) cout<<i<<" "<<dis[i]<<endl;
        int ans = 0;
        for(int i = 1 ; i<=m ; i++){
            int a = arr[i].a , b = arr[i].b , w = arr[i].w;
            if(dis[a] < K || dis[b] < K) ans = max(ans , w);
        }
        cout<<ans<<endl;
//        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
