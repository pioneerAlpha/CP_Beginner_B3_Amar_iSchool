#include<bits/stdc++.h>
#define ll long long
#define N ((int)(1e5 + 5))
#define MAX ((int)1e9 + 5)
#define MOD ((int)(1e9 + 7))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);


int arr[N] , pre[N];

vector < int > pos;

int srch(int val)
{
    int lef = 0 , rig = pos.size();
    while(lef < rig){
        int mid = (lef + rig)/2;
        if(pos[mid] > val) rig = mid;
        else lef = mid+1;
    }
    return lef;
}

int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++){
        cin>>arr[i];
        pre[i] = pre[i-1] + arr[i];
    }
    if(pre[n] % 3 != 0){
        cout<<"0\n";
        return 0;
    }
    int x = pre[n]/3;
    ll ans = 0;

    for(int i = 1 ; i<n ; i++){
        if(pre[i] == x*2) pos.push_back(i);
    }
    for(int i = 1 ; i<n ; i++){
        if(pre[i] == x) ans += pos.size() - srch(i);
    }
    cout<<ans<<endl;
    return 0;
}
