#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
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

int expc , arr[17] , dpp[17][(1<<16) + 2] , sum[(1<<16) + 2];

int call(int mask, int k)
{
    if(k == 0)
    {
        if(mask == 0) return 1;
        return 0;
    }
    if(dpp[k][mask] != -1) return dpp[k][mask];
    int ans = 0;

    /// iterate over all the masks
    /// O (3 ^ n)
    for(int sub = mask; sub > 0; sub = (sub-1) & mask)
    {

        if(sum[sub] == expc)
        {
            int tmp = mask ^ sub;
            if(call( tmp, k-1 )) ans = 1;
        }

    }
    return dpp[k][mask] = ans;
}

/// O(k*2^n) : number of state
/// O( k * 3^n)

int main()
{
    int n, k ;
    cin>>n>>k;
    for(int i = 0 ; i<n ; i++) cin>>arr[i];

    for(int mask = 0 ; mask < (1<<n) ; mask++ )  /// O(2^n)
    {
        for(int i = 0 ; i<n ; i++)   /// O(n)
        {
            if( (mask & (1<<i)) != 0 ) sum[mask] += arr[i];
        }
    } /// O (n * 2^n )

    if(sum[(1<<n) - 1] % k != 0)
    {
        cout<<"no\n";
        return 0;
    }
    expc = sum[(1<<n) - 1]/k;
    memset(dpp,-1,sizeof dpp);
    if(call((1<<n) - 1, k)) cout<<"yes\n";
    else cout<<"no\n";

    return 0;


}
