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

int dpp[N] , pre[N] , arr[N] , aux[N] , idx[N];

int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++) cin>>arr[i];
    dpp[0] = 0;
    pre[0] = 0;
    aux[0] = -MAX;
    idx[0] = 0;
    for(int i = 1 ; i<=n ; i++) aux[i] = MAX;
    for(int i = 1 ; i<=n ; i++){
        int lef = 0 , rig = n;
        while(lef < rig){
            int mid = (lef + rig + 1)/2;
            if(aux[mid] < arr[i]) lef = mid;
            else rig = mid - 1;
        }
        dpp[i] = lef + 1;
        pre[i] = idx[lef];
        if(aux[dpp[i]] > arr[i]){
            aux[dpp[i]] = arr[i];
            idx[dpp[i]] = i;
        }
    }
    int ans = 0 , last;
    for(int i = 1 ; i<=n  ; i++){
        if(ans < dpp[i]){
            ans = dpp[i];
            last = i;
        }
    }
    cout<<ans<<endl;
    vector < int > lis;
    while(last > 0){
        lis.push_back(last);
        last = pre[last];
    }
    reverse(lis.begin(),lis.end());
    for(int i:lis) cout<<arr[i]<<" ";
    return 0;
}
