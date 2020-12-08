#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"

using namespace std;


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        string strx , stry;
        cin>>strx>>stry;
        int lenx = strx.length() , leny = stry.length() , ans = 0;
        while(1){
            if(strx[lenx] == '1' && stry[leny] == '1'){
                break;
            }
            if(strx[lenx] == '0' && stry[leny] == '1'){
                ans++;
                lenx--;
            }
            else{
                lenx--;
                leny--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
