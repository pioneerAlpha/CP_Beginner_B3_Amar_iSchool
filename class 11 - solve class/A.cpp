#include<bits/stdc++.h>
#define N ((int)5e4 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

vector < int > vec[N];

int par[N];

void dfs(int n , int p)
{
    par[n] = p;
    for(int a:vec[n]){
        if(a != p) dfs(a,n);
    }
}

int main()
{
    fastio;
    int n , r1 , r2 ;
    cin>>n>>r1>>r2;
    for(int i = 1 ; i<=n ; i++){
        if(i != r1){
            int p;
            cin>>p;
            vec[i].push_back(p);
            vec[p].push_back(i);
        }
    }
    dfs(r2,0);
    for(int i = 1 ; i <= n ; i++) if(i != r2) cout<<par[i]<<" ";
    cout<<endl;
    return 0;
}
