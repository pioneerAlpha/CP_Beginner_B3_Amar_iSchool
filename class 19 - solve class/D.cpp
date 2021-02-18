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

int dpp[N];
ll  arr[N];


int main()
{
    fastio;
    int t;
    t = 1;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];

        for(int i = 1 ; i<=n ; i++)
        {
            int ans = 0;
            for(int j = 1 ; j < i ; j++){
                if(abs(arr[j]) < abs(arr[i]) && arr[j]*arr[i] < 0) ans = max(dpp[j] , ans);
            }
            dpp[i] = ans + 1;
        }
        int ans = 0;
        for(int i = 1 ; i<=n ; i++)
        {
            ans = max(ans , dpp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
