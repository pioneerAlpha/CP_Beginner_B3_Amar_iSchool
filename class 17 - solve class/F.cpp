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

int n, dpp[105][100005], val[105], cnt[105];

int call(int idx, int rem)  /// call(idx , rem) = minimum number of coins of type idx needed to make rem
{
    if(rem < 0) return MAX; /// rem cannot be made
    if(idx > n)
    {
        if(rem == 0) return 0; /// minimum number of coins to make 0 is 0
        return MAX;
    }
    if(dpp[idx][rem] != -1) return dpp[idx][rem];
    int ans = MAX;
    if(call(idx + 1, rem) <= cnt[idx+1]) ans = 0;  /// we don't need coin of type idx to make rem
    else
    {
        ans = call(idx, rem - val[idx]) + 1;
        if(ans > cnt[idx]) ans = MAX;
    }
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
        for(int i = 1 ; i<=n ; i++) cin>>cnt[i];
        cnt[n+1] = 0;

        /// "base case" goes here:
        for(int rem = 1 ; rem<=tot ; rem++) dpp[n+1][rem] = MAX;
        dpp[n+1][0] = 0;
        /// base case done

        for(int idx = n ; idx > 0 ; idx--)
        {
            for(int rem = 0 ; rem <= tot ; rem++)
            {
                int ans = MAX;
//                if(call(idx + 1, rem) <= cnt[idx+1]) ans = 0;  /// we don't need coin of type idx to make rem
                if(dpp[idx + 1][rem] <= cnt[idx+1]) ans = 0;  /// we don't need coin of type idx to make rem
                else
                {
//                    ans = call(idx, rem - val[idx]) + 1;
                    if(rem - val[idx] >= 0){
                        ans = dpp[idx][rem - val[idx]] + 1;
                        if(ans > cnt[idx]) ans = MAX;
                    }
                }
                dpp[idx][rem] = ans;
            }
        }

        int ans = 0;
//        for(int i = 1 ; i<=tot ; i++) if(call(1,i) <= cnt[1]) ans++;
        for(int i = 1 ; i<=tot ; i++) if(dpp[1][i] <= cnt[1]) ans++;

        cout<<"Case "<<caseno++<<": "<<ans<<endl;


    }
    return 0;
}
