#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
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

int dpp[N],  arr[N], aux[N];

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int n, L;
        cin>>n;
        for(int i = 1 ; i <= n ; i++) cin>>arr[i];
        cin>>L;
        dpp[0] = 0;
        aux[0] = -MAX;
        for(int i = 1 ; i<=n ; i++) aux[i] = MAX;
        for(int i = 1 ; i<=n ; i++)
        {
            int lef = 0, rig = n;
            while(lef < rig)
            {
                int mid = (lef + rig + 1)/2;
                if(aux[mid] < arr[i]) lef = mid;
                else rig = mid - 1;
            }
            dpp[i] = lef + 1;
            if(aux[dpp[i]] > arr[i])
            {
                aux[dpp[i]] = arr[i];
            }
        }
        int ans = MAX;
        for(int i = 1 ; i<=n ; i++)
        {
            if(dpp[i] >= L) ans = min(ans, arr[i]);
        }
        if(ans == MAX) ans = -1;
        cout<<ans<<endl;
    }
    return 0;
}
