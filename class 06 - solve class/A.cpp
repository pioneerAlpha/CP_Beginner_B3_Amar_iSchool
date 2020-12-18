#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;

bool vis[105];

vector < pair < int , int > > vec[105];

int dfs(int n , int pre)
{
    if(vis[n]) return 0;
    vis[n] = 1;
    int ans = 0;
    for(auto p:vec[n]){
        int a = p.first;
        if(a != pre) ans += dfs(a,n) + p.second;
    }
    return ans;
}

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1 ; i<=n ; i++) vec[i].clear();
        for(int i = 0 ; i<n ; i++){
            int a , b, c;
            cin>>a>>b>>c;
            vec[a].push_back({b,0});
            vec[b].push_back({a,c});
        }
        memset(vis,0,sizeof vis);
        int ans =  dfs(1,vec[1][1].first) ;
        memset(vis,0,sizeof vis);
        ans = min( ans , dfs(1,vec[1][0].first) );
        cout<<"Case "<<caseno++<<": "<<ans<<endl;
    }
    return 0;
}
