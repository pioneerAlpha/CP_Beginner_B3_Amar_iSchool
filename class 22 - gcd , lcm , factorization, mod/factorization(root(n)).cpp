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


int main()
{
//    fastio;

    ll n ;
    cin>>n;
//    n = 1000000;
    vector < int > fac;
    for(ll i = 1 ; i*i <= n ; i++){
        if( n % i == 0 ){
            fac.push_back(i);
            if(i * i != n) fac.push_back(n / i);
        }
    } /// O ( root (n) )
    cout<<fac.size()<<endl;


    for(int a:fac) cout<<a<<" ";

    return 0;
}
