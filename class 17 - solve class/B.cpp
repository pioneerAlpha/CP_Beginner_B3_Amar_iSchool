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

int n, dpp[105][10005], val[105];

int call(int idx, int rem)
{
    if(rem < 0) return 0;
    if(idx > n)
    {
        if(rem == 0) return 1;
        return 0;
    }
    if(dpp[idx][rem] != -1) return dpp[idx][rem];
    int ans = ( call(idx + 1 , rem) + call(idx , rem - val[idx]) ) % MOD;
    return dpp[idx][rem] = ans;
}



int main()
{
    int t, caseno = 1;
    cin>>t;
    while(t--)
    {
        int tot;
        cin>>n>>tot;
        for(int i = 1 ; i<=n ; i++) cin>>val[i];
//        memset(dpp,-1,sizeof dpp);
        /// "base case" goes here:
        for(int rem = 1 ; rem <= tot ; rem++) dpp[n+1][rem] = 0;
        dpp[n+1][0] = 1;
        /// "base case" done

        for(int idx = n ; idx > 0 ; idx--){
            for(int rem = 0 ; rem <= tot ; rem++){
//                int ans = ( call(idx + 1 , rem) + call(idx , rem - val[idx]) ) % MOD;
                int ans = dpp[idx + 1][rem];
                if(rem - val[idx] >= 0) ans = (ans + dpp[idx][rem - val[idx]])  % MOD;
                dpp[idx][rem] = ans;
            }
        }

//        cout<<"Case "<<caseno++<<": "<<call(1,tot)<<endl;
        cout<<"Case "<<caseno++<<": "<<dpp[1][tot]<<endl;
    }
    return 0;
}
