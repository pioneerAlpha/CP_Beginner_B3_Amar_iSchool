#include<bits/stdc++.h>
#define MAX ((int)2e9 + 5)
#define MAXL ((ll)1e16 + 5)
#define pi acos(-1)
#define MOD ((int)1e9 + 7)
#define N ((int)1e5 + 5)
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

string str;

int n , dpp[N];

int call(int idx)
{
    if(idx >= n) return 1;
    if(dpp[idx] != -1) return dpp[idx];
    int ans = call(idx + 1);
    if(str[idx] == 'u' || str[idx] == 'n'){
        if(str[idx+1] == str[idx]){
            ans = (ans + call(idx + 2) ) % MOD;
        }
    }
    return dpp[idx] = ans;
}

int main()
{
    int t, caseno = 1;
    t = 1;
    while(t--)
    {

        cin>>str;
        n = str.length();
        for(int i = 0 ; i<n ; i++){
            if(str[i] == 'w' || str[i] == 'm'){
                cout<<"0\n";
                return 0;
            }
        }
        memset(dpp,-1,sizeof dpp);
        cout<<call(0)<<endl;

    }
    return 0;
}

