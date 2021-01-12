#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

vector < pair < int , int > > vec[N];

int col[N] , vis[N] , loc[N] , arr[N];

bool dfs(int n , int c)
{
    vis[n] = 1;
    col[n] = c;
    for(auto p:vec[n]){
        int a = p.first , b = p.second^c;
        if(vis[a]){
            if(col[a] != b) return 0;
        }
        else if(!dfs(a,b)) return 0;
    }
    return 1;
}

int main()
{
    fastio;
    int n , m;
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++){
        cin>>loc[i];
        loc[i] = !loc[i];
    }
    for(int i = 1 ; i <= m ; i++){
        int a;
        cin>>a;
        while(a--){
            int b;
            cin>>b;
            if(arr[b] == 0) arr[b] = i;
            else{
                vec[i].push_back({arr[b],loc[b]});
                vec[arr[b]].push_back({i,loc[b]});
            }
        }
    }
    for(int i = 1 ; i<=m ; i++){
        if(!vis[i]){
            if(!dfs(i,0)){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    return 0;
}
