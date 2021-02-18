#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e8 + 7)
#define N ((int)2e5 + 5)
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

int arr[N] , last[N];

vector < int > vec[N];

int main()
{
    fastio;
    int t , caseno = 1;
    t = 1;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];
        memset(last,-1,sizeof last);
        for(int i = 1 ; i<=n ; i++){
            int lef = 1 , rig = n;
            while(lef < rig){
                int mid = (lef + rig)/2;
                if(last[mid] < arr[i]) rig = mid;
                else lef = mid + 1;
            }
            last[lef] = arr[i];
            vec[lef].push_back(arr[i]);
        }
        for(int i = 1 ; i<=n ; i++){
            if(vec[i].size() == 0) break;
            for(int a:vec[i]) cout<<a<<" ";
            cout<<endl;
        }
    }
    return 0;
}
