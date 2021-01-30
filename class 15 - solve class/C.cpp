#include<bits/stdc++.h>
#define ll long long
#define N ((int)(1e5 + 5))
#define MAX ((int)2e9 + 5)
#define MOD ((int)(1e9 + 3))
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);


using namespace std;

// fastio
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int dpp[205][205][205] , arr[5][205];

int call(int red , int grn , int blu)
{
    if(red < 0 || grn < 0 || blu < 0) return -MAX;
    if(dpp[red][grn][blu] != -1) return dpp[red][grn][blu];
    int ans = 0;
    ans = max(call(red-1,grn-1,blu) + arr[0][red]*arr[1][grn] , ans);
    ans = max(call(red-1,grn,blu-1) + arr[0][red]*arr[2][blu] , ans);
    ans = max(call(red,grn-1,blu-1) + arr[2][blu]*arr[1][grn] , ans);
    return dpp[red][grn][blu] = ans;
}

int main()
{
    int siz[5];
    cin>>siz[0]>>siz[1]>>siz[2];
    for(int i = 0 ; i<3 ; i++){
        for(int j = 1 ; j<=siz[i] ; j++) cin>>arr[i][j];
        sort(arr[i]+1, arr[i] + siz[i] + 1);
    }
    memset(dpp,-1,sizeof dpp);
    cout<<call(siz[0] , siz[1] , siz[2])<<endl;
    return 0;
}
