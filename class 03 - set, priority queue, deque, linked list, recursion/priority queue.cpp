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





int main()
{
    priority_queue < pair < int , int > > pqq;
    fastio;
    int q;
//    return 0;
    cin>>q;
    while(q--){
        int typ;
        cin>>typ;
        if(typ == 1){
            int tkk , ord;
            cin>>tkk>>ord;
            pqq.push({-ord,tkk});
        }
        else{
            int a;
            if(!pqq.empty()) a = -pqq.top().first;
            else a = -1;
            cout<<a<<endl;
            pqq.pop();
        }
    }

    return 0;
}
