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

/// iteratvie
//int gcd(int a , int b)
//{
//    if(a > b) swap(a,b);
//    if(a == 0) return b;
//    while(1){
//        int mod = b % a;
//        if(mod == 0) return a;
//        /// from here
//        b = a;
//        a = mod;
//    }
//}


/// recursive

int gcd(int a,  int b)
{
    if(a > b) swap(a,b);
    if(a == 0) return b;
    return gcd(a, b % a);
}

ll lcm(int a , int b)
{
    ll ans = a / __gcd(a,b);
    ans *= b;
    return ans;
}

int main()
{
//    fastio;

    ll n , gcd = 0;
    ll lcm = 1;
    cin>>n;
    for(int i = 1 ; i<=n ; i++){
        ll a;
        cin>>a;
        gcd = __gcd( gcd , a );
        lcm = (a / __gcd(lcm , a)) * lcm;
    }

    cout<<gcd<<" "<<lcm<<endl;

    return 0;
}
