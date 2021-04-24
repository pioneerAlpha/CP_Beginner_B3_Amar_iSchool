#include<bits/stdc++.h>
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
#define N ((int)2e2 + 9)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"


typedef long long ll;
typedef unsigned long long ull;

/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/


int phi[N];

int main()
{
    /// N <= 1e6
//    sieve(N);
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) phi[i] = i;
    for(int j = 2 ; j<=n ; j++)
    {
        if(phi[j] == j)
        {
            for(int i = j ; i <= n ; i += j)
            {
                phi[i] /= j;
                phi[i] *= j-1;
            }
        }
    } /// O (n * ln (n) )
}

