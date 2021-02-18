#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
#define N ((int)1e3 + 5)
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

int dpp[2][N],  arr[N];

void LIS(int cur , int n)
{
    for(int i = 1 ; i<=n ; i++)
    {
        int ans = 0;
        for(int j = 1 ; j < i ; j++)
        {
            if(arr[j] < arr[i]) ans = max(dpp[cur][j], ans);
        }
        dpp[cur][i] = ans + 1;
    }
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];

        LIS(0,n);
        reverse(arr+1,arr+n+1);
        LIS(1,n);
        int ans = 0;
        for(int i = 1 ; i<=n ; i++)
        {
            ans = max(ans, dpp[1][i] + dpp[0][n-i+1] - 1); /// the initial index "i" is now at "n-i+1" , because we reversed the array
        }
        cout<<ans<<endl;
    }
    return 0;
}
