#include<bits/stdc++.h>
#define ll long long
#define N ((int)(2e5 + 5))
#define MAX ((int)1e9 + 5)
#define MOD ((int)(1e9 + 7))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

vector < int > vec;

int arr[N];

int okk(int rng , int n)
{
    vec.clear();
    int cur = 0;
    for(int i = 1 ; i<=n ; i++){
        if(cur < arr[i]){
            vec.push_back(arr[i]);
            cur = arr[i] + rng;
        }
    }
    return vec.size();
}

int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    sort(arr + 1 , arr + n + 1);
    int lef = 0 , rig = MAX;
    while(lef < rig){
        int mid = (lef + rig)/2;
        if(okk(mid,n) <= 3) rig = mid;
        else lef = mid+1;
    }
    okk(lef,n);
    cout<<setprecision(5)<<fixed;
    cout<<lef/2.0<<endl;
    while(vec.size() < 3) vec.push_back(MAX);
    for(int a:vec) cout<<a + lef/2.0<<" ";
    return 0;
}
