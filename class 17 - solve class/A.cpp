#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e8 + 7)
#define N ((int)2e5 + 5)
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


int n , dpp[52][1005] , val[52] , cnt[52];

int call(int idx , int rem)
{
    if(rem < 0) return 0;
    if(idx > n){
        if(rem == 0) return 1;
        return 0;
    }
    if(dpp[idx][rem] != -1) return dpp[idx][rem];
    int ans = call(idx + 1 , rem);
    for(int i = 1 ; i<=cnt[idx] ; i++){
        ans = (ans + call(idx + 1 , rem - i*val[idx])) % MOD;
    }
    return dpp[idx][rem] = ans;
}

int main()
{
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int tot;
        cin>>n>>tot;
        for(int i = 1 ; i<=n ; i++) cin>>val[i];
        for(int i = 1 ; i<=n ; i++) cin>>cnt[i];
        memset(dpp,-1,sizeof dpp);
        cout<<"Case "<<caseno++<<": "<<call(1,tot)<<endl;
    }
    return 0;
}
