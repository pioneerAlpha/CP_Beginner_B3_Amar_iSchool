#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

vector < pair < int , int > > vec[N];

int col[N];

vector < int > grp[2];

bool dfs(int n , int c)
{
    col[n] = c;
    for(auto p:vec[n]){
        int a = p.first , b = p.second;
        if(col[a] == -1){
            dfs(a,c^b);
        }
        else{
            if(col[a] != (c^b)) return 0;
        }
    }

    return 1;

}

int main()
{

    int n , m;
    cin>>n>>m;
    while(m--){
        int a, b , c;
        cin>>a>>b>>c;  /// c = 0 , if a and b has to in the same group , c = 1 otherwise
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }
    memset(col,-1,sizeof col);
    for(int i = 1 ; i<=n ; i++){
        if(col[i] == -1) dfs(i,1);
    }
    return 0;

}
