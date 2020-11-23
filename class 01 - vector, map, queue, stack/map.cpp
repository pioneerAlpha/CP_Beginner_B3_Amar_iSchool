#include<bits/stdc++.h>
#define ll long long
#define N ((int)(15e4 + 5))
#define MOD ((int)(1e9 + 7))
#define endl "\n"


using namespace std;



/// to declare: map < data1 , data2 > name;

int main()
{
    map < int , int > mmm; /// -2*10^9 to 2*10^9
    int q;
    cin>>q;
    while(q--){
        int typ , val;
        cin>>typ>>val;
        if(typ == 1) mmm[val] = 1; /// 32
        else if(typ == 2) mmm[val] = 0;  /// 32
        else{
            if(mmm[val] == 1) cout<<"yes\n";  /// 32
            else cout<<"no\n";
        }
    }
}
