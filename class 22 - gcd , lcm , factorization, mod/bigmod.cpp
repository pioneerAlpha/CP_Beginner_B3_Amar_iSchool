#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e8 + 7)
#define N ((int)1e6 + 5)
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

int bigmod(int a , int n , int p) /// returns (a ^ n) % p
{
    if(n == 0) return 1;
    int ans = bigmod(a, n / 2  , p);
    ans = 1LL*ans*ans % p;
    if(n & 1) ans = 1LL*ans*a % p;
    return ans;
}

int main()
{
//    fastio;

    while(1){
        int a , n , p;
        cin>>a>>n>>p;
        cout<<bigmod(a,n,p)<<endl; /// O ( logn )
    }

    return 0;
}
