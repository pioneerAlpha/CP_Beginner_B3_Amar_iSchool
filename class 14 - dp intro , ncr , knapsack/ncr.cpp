#include<bits/stdc++.h>
#define ll long long
#define N ((int)(1e5 + 5))
#define MAX ((int)1e9 + 5)
#define MOD ((int)(1e9 + 7))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);


int dpp[105][105];

int ncr(int n , int r)
{
    if(r < 0 || n < 0) return 0;
    if(dpp[n][r] != -1) return dpp[n][r];
    int ans;
    if(r > n) ans = 0;
    else if(r == 0) ans = 1;
    else ans = ncr(n-1,r) + ncr(n-1,r-1) ;
    return dpp[n][r] = ans;
}

/// O ( N * N * 4);

int main()
{
    memset(dpp,-1,sizeof dpp);
    int n , r;
    cin>>n>>r;
    cout<<ncr(n,r)<<endl;
}
