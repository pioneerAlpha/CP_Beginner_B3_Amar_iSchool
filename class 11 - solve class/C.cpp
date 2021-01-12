#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

int ans[N] , dep[N]; /// dep[i] = maximum depth of subtree i

vector < pair < int , int > > vec[N];

void dfs(int n , int par) /// subtree of n
{
    int case1 = 0 , mx1 = 0, mx2 = 0;
    for(auto p:vec[n]){
        int a = p.first;
        if(a != par){
            dfs(a,n);
            case1 = max(case1 , ans[a]);
            dep[a] += p.second;
            if(dep[a] > mx2){
                mx2 = dep[a];
                if(mx2 > mx1) swap(mx1,mx2);
            }
        }
    }
    ans[n] = max(case1 , mx1 + mx2);
    dep[n] = mx1;
}

int main()
{
    fastio;
    int n ;
    cin>>n;
    for(int i = 1 ; i<n ; i++){
        int a , b ;
        cin>>a>>b;
        vec[a].push_back({b,1});
        vec[b].push_back({a,1});
    }
    int root ,q;
    cin>>root>>q;
    dfs(root , 0);
    while(q--){
        int s;
        cin>>s;
        cout<<ans[s]<<endl;
    }
    return 0;
}
