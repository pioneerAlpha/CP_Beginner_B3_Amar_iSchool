#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

vector < pair < int , int > > vec[N];

pair < int , int > dfs(int n , int par)
{
    pair < int , int > ans = {0,n};
    for(auto p:vec[n]){
        int a = p.first , c = p.second ;
        if(a != par){
            pair < int , int > tmp = dfs(a,n);
            tmp.first += c;
            ans = max(ans , tmp);
        }
    }
    return ans;
}

int main()
{
    int n ;
    cin>>n;
    for(int i = 1 ; i<n ; i++){
        int a , b , c;
        cin>>a>>b>>c;
        vec[b].push_back({a,c});
        vec[a].push_back({b,c});
    }
    int a = dfs(1,0).second;
    pair < int , int > ans = dfs(a,0);
    return 0;
}
