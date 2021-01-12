#include<bits/stdc++.h>
#define N ((int)3e4 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

vector < pair < int , int > > vec[N];

int dis[2][N];

pair < int , int > dfs(int n ,int par , int idx)
{
    pair < int , int > ans = {0,n};
    for(auto p:vec[n]){
        int a = p.first , b = p.second;
        if(a != par){
            dis[idx][a] = dis[idx][n] + b;
            pair < int , int > tmp = dfs(a,n,idx);
            tmp.first += b;
            ans = max(ans , tmp);
        }
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
        for(int i = 0 ; i<n ; i++) vec[i].clear();
        for(int i = 1 ; i<n ; i++){
            int a , b , w;
            cin>>a>>b>>w;
            vec[a].push_back({b,w});
            vec[b].push_back({a,w});
        }
        dis[0][0] = 0;
        int a = dfs(0,-1,0).second;
        dis[0][a] = 0;
        int b = dfs(a,-1,0).second;
        dis[1][b] = 0;
        dfs(b,-1,1);
        cout<<"Case "<<caseno++<<":\n";
        for(int i = 0 ; i<n ; i++) cout<<max(dis[0][i] , dis[1][i])<<endl;
    }
    return 0;
}
