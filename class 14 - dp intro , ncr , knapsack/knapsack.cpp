#include<bits/stdc++.h>
#define ll long long
#define N ((int)(1e5 + 5))
#define MAX ((int)1e9 + 5)
#define MAXL ((ll)1e18 + 5)
#define MOD ((int)(1e9 + 7))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);


ll dpp[105][100005] ;

int vol[105] , pro[105] , n;

ll call(int idx , int rem)
{
    if(rem < 0) return -MAXL;
    if(dpp[idx][rem] != -1) return dpp[idx][rem];
    if(idx > n) return dpp[idx][rem] = 0;
    ll ans = -MAXL;
    if(rem >= vol[idx]){
        int tmp = rem - vol[idx];
        ans = pro[idx] + call(idx + 1 , tmp);
    }
    ans = max( ans , call(idx + 1 , rem) );
    return dpp[idx][rem] = ans;
}

/// O (n*cap)



int main()
{
    int cap;
    cin>>n>>cap;
    for(int i = 1 ; i<=n ; i++) cin>>pro[i]>>vol[i];
    memset(dpp,-1,sizeof dpp);
    cout<<call(1,cap)<<endl;
    return 0;
}
