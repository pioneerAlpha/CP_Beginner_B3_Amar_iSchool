#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define err (1e-9)

using namespace std;

int arr[N];

int srch(int val , int lef , int rig)
{
    while(lef < rig){
        int mid = (lef + rig)/2;
        if(arr[mid] >= val) rig = mid;
        else lef = mid+1;
    }
    return lef;
}

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        int n , q;
        cin>>n>>q;
        for(int i = 1 ; i<=n ; i++) cin>>arr[i];
        arr[n+1] = MAX;
        sort(arr+1,arr+n+1);
        cout<<"Case "<<caseno++<<":\n";
        while(q--){
            int a , b;
            cin>>a>>b;
            cout<<srch(b+1,1,n+1) - srch(a,1,n+1)<<endl;
        }
    }
    return 0;
}
