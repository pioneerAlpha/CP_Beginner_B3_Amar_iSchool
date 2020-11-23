#include<bits/stdc++.h>
#define ll long long
#define N ((int)(15e4 + 5))
#define MOD ((int)(1e9 + 7))
#define endl "\n"


using namespace std;




int main()
{
    queue < int > que;
    /// to declare : queue < data > name;
    int q;
    cin>>q;
    while(q--){
        int typ;
        cin>>typ;
        if(typ == 1){
            int neww;
            cin>>neww;
            que.push(neww);
            /// to insert: name.push(value);
        }
        else{
            if(que.empty()) cout<<"-1\n";
            else{
                int a = que.front();
                cout<<a<<endl;
                que.pop();
            }
        }
    }
}
