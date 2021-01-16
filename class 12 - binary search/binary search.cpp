#include<bits/stdc++.h>
#define N ((int)2e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define err (1e-9)

using namespace std;

pair < int ,  int > arr[N];


int main()
{
    int n ;
    cin>>n;
    for(int i = 1 ; i<=n ; i++){
        cin>>arr[i].first;
        arr[i].second = i;
    }

    sort(arr+1,arr+n+1);

    int q;
    cin>>q;
    while(q--){
        int val;
        cin>>val;
        int lef = 1 , rig = n;
        while(lef < rig){
            int mid = (lef + rig)/2;
            if(arr[mid].first >= val) rig = mid;
            else lef = mid+1;
        }
        if(arr[lef].first == val) cout<<arr[lef].second<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
