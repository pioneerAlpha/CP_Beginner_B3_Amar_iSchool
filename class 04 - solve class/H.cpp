#include<bits/stdc++.h>

using namespace std;

int arr[505][505];

int main()
{
    int n , m;
    cin>>n>>m;
    int ans = 0;
    vector < int > vec;
    for(int i = 1  ; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++) cin>>arr[i][j];
        ans ^= arr[i][1];
        vec.push_back(1);
    }
    if(ans == 0){
        for(int i = 1 ; i<=n ; i++){
            bool flag = 0;
            for(int j = 2 ; j<=m ; j++){
                if(arr[i][j] != arr[i][1]){
                    vec[i-1] = j;
                    flag = 1;
                    ans ^= arr[i][1]^arr[i][j];
                    break;
                }
            }
            if(flag) break;
        }
    }

    if(ans == 0) cout<<"NIE\n";
    else{
        cout<<"TAK\n";
        for(int a:vec) cout<<a<<" ";
        cout<<endl;
    }
    return 0;
}
