#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e8 + 7)
#define N ((int)1e3 + 5)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
//#define int ll


using namespace std;



/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int dpp[N][(1<<10) + 2] , arr[N] , brr[N] , vis[(1<<10) + 2] , n;

int call(int idx , int val)
{
    if(idx > n){
        if(vis[val]) return 0;
        return 1;
    }
    if(dpp[idx][val] != -1) return dpp[idx][val];
    int ans = (call(idx + 1 , val) + call(idx + 1 , val ^ arr[idx])) % MOD;
    return dpp[idx][val] = ans;
}

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof vis);
        int  m;
        cin>>n>>m;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];
        for(int i = 1 ; i<=m ; i++){
            int a;
            cin>>a;
            vis[a] = 1;
        }
        memset(dpp,-1,sizeof dpp);
        cout<<"Case "<<caseno++<<": "<<call(1,0)<<endl;

    }
    return 0;
}
