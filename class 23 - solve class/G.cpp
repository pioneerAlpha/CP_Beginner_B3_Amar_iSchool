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
    cin>>t;
    while(t--){
         int n , k;
         cin>>n>>k;
         ll ans = 1LL*n*k/(n-1);
         if(ans % n == 0) ans--;
         ll y = ans / n;
         if(ans - y != k) ans--;
         cout<<ans<<endl;
    }
    return 0;
}
