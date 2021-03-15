#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(1e5 + 5))

using namespace std;

ll pwr[205]; /// pwr[i] = 10^i % mod;

int main()
{
    fastio;
    int t , caseno = 1;
    cin>>t;
    while(t--){
        string str;
        int mod;
        cin>>str>>mod;
        mod = abs(mod);
        int n = str.length();
        pwr[0] = 1 % mod;
        for(int i = 1 ; i<=n ; i++) pwr[i] =( 10 * pwr[i-1] ) % mod;
        int ans = 0;

        for(int i = n - 1 , p = 0; i >= 0 ; i-- , p++){
            if(str[i] == '-') break;

            int d = str[i] - '0';
            ans = (ans + d * pwr[p]) % mod;
        }
        cout<<"Case "<<caseno++<<": ";
        if(ans == 0) cout<<"divisible\n";
        else cout<<"not divisible\n";
    }
    return 0;
}
