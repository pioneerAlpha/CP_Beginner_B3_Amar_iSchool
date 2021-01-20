#include<bits/stdc++.h>
#define ll long long
#define N ((int)(2e5 + 5))
#define MAX ((int)2e9 + 5)
#define MOD ((int)(1e9 + 7))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);


bool sqr[N];

int arr[N];

int root(int n) /// x <= sqrt(n)
{
    int lef = 0 , rig = 32000;
    while(lef < rig){
        int mid = (lef + rig + 1)/2;
        if(mid*mid <= n) lef = mid;
        else rig = mid-1;
    }
    return lef;
}

int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i = 1 ; i<=n ; i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    int cnt = 0;
    for(int i = 1 ; i<=n ; i++){
        int a = root(arr[i]);
        if(a*a == arr[i]){
            cnt++;
            sqr[i] = 1;
        }
    }
    ll ans = 0;
    if(cnt > n/2){
        int x = cnt - n/2;
//        priority_queue < int > pqq;

        for(int i = n ; i>0 && x>0; i--){
            if(sqr[i] == 1){
                if(arr[i] > 0) ans++;
                else ans += 2;
                x--;
            }
        }
    }
    else{
        int x = n/2 - cnt;
        priority_queue < int > pqq;
        for(int i = 1 ; i<=n ; i++){
            if(!sqr[i]){
                int a = root(arr[i]);
                int dec = arr[i] - a*a;
                int inc = (a+1)*(a+1) - arr[i];
                int val = min(inc, dec);
                pqq.push(-val);
            }
        }
        while(x--){
            int a = -pqq.top();
            ans += a;
            pqq.pop();
        }
    }
    cout<<ans<<endl;
    return 0;
}
