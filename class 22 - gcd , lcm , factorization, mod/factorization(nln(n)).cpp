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

vector < int > fac[N]; /// fac[0] , fac[1] , fac[2] , ... ,


int main()
{
//    fastio;

    ll n ; /// n = 100;
    cin>>n;


    for(int i = 1 ; i<=n ; i++){
        for(int j = i ; j <= n ; j += i){ /// j = i , 2i , 3i, 4i, 5i , ..
            /// j is a multiplier of i => i is a divisor of j
            fac[j].push_back(i);
        }
    } /// O ( n * ln(n) )

    for(int i = 1 ; i<=n ; i++){
        cout<<" factoring "<<i<<endl;
        for(int a:fac[i]) cout<<a<<" ";
        cout<<endl;
    }

    return 0;
}
