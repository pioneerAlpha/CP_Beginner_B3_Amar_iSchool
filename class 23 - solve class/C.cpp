#include<bits/stdc++.h>
#define N ((int)1e6 + 5)
#define MOD ((int)1e9 + 7)
#define ll long long
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAX ((int)1e6 + 5)
#define endl "\n"

using namespace std;



int main()
{
    fastio;
    int t;
    t = 1;
    while(t--){
        ll n;
        cin>>n;
        ll ans = 1;
        for(ll i = 2 ; i<=10 ; i++) ans = ans*(i/__gcd(i,ans));
        ans = n/ans;
        cout<<ans<<endl;
    }
    return 0;
}
