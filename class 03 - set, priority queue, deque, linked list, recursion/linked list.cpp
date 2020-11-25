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




int lef[N] , rig[N];

int main()
{

    int n , q;
    cin>>n>>q;
    for(int i = 1 ; i<=n ; i++){
        cin>>lef[i]>>rig[i];
    }

    while(q--){
        int typ;
        cin>>typ;
        if(typ == 3){
            int a;
            cin>>a;
            int cur = lef[a] , ans = 1;
            while(cur != -1){
                ans++;
                cur = lef[cur];
            }

            cur = rig[a];
            while(cur != -1){
                ans++;
                cur = rig[cur];
            }
            cout<<ans<<endl;
        }
        else{
            int a , b;
            cin>>a>>b;
            if(typ == 1){
                if(rig[a] == b){
                    rig[a] = -1;
                    lef[b] = -1;
                }
                else if(lef[a] == b){
                    lef[a] = -1;
                    rig[b] = -1;
                }
            }
            else{
                if(rig[a] == -1 && lef[b] == -1){
                    rig[a] = b;
                    lef[b] = a;
                }
            }
        }
    }

    /// O (n + q);

    return 0;
}
