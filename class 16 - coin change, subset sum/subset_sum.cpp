#include<bits/stdc++.h>
#define ll long long
#define N ((int)(1e5 + 5))
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e18 + 5)
#define MOD ((int)(1e9 + 3))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int n , dpp[105][N] , arr[105] ;

int call(int idx , int tot)
{
    if(tot < 0) return 0;
    if(idx > n){
        if(tot == 0) return 1;
        return 0;
    }
    if(dpp[idx][tot] != -1) return dpp[idx][tot];
    int ans = 0;
    ans = call(idx + 1 , tot ) | call(idx + 1 , tot - arr[idx]);
    return dpp[idx][tot] = ans;
}



int main()
{
    fastio;

    int n , suma , sumb;
    cin>>n>>suma>>sumb;
    int sum = 0;
    for(int i = 1 ; i<=n ; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    memset(dpp,-1,sizeof dpp);
    if(sum != suma + sumb) cout<<"NO\n";
    else if(call(1,suma)){
        cout<<"YES\n";
    }
    else cout<<"NO\n";

    return 0;
}
