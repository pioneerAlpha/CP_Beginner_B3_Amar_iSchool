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
        int k , n , a , b;
        cin>>k>>n>>a>>b;
        int lef = -1 , rig = n;
        while(lef < rig){
            int mid = (lef + rig + 1)/2;
            ll val = 1LL*mid*(a-b) + 1LL*n*b;
            if(val < k) lef = mid;
            else rig = mid-1;
        }
        cout<<lef<<endl;
//        cout<<"Case "<<caseno++<<":\n";
    }
    return 0;
}
