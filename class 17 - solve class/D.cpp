#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e8 + 7)
#define N ((int)1e5 + 5)
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

int n, dpp[105][N], val[105];

int call(int idx, int rem)
{
    if(rem < 0) return 0;
    if(idx > n)
    {
        if(rem == 0) return 1;
        return 0;
    }
    if(dpp[idx][rem] != -1) return dpp[idx][rem];
    int ans = call(idx + 1 , rem) | call(idx + 1 , rem - val[idx]) ;
    return dpp[idx][rem] = ans;
}



int main()
{
    fastio;
    int t, caseno = 1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i = 1 ; i<=n ; i++) cin>>val[i];
        memset(dpp,-1,sizeof dpp);
        ll ans = 0;
        for(int i = 1 ; i<N ; i++) if(call(1,i)) ans += i;
        cout<<ans<<endl;
    }
    return 0;
}
