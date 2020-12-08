#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n , k;
    cin>>n>>k;
    vector < int > vec;
    int cnt = 0;
    for(int i = 0 ; n > 0 ; i++){
        if(n&(1<<i)){
            cnt++;
            if(i > 0) vec.push_back(1<<i);
            n -= 1<<i;
        }
    }

    if(cnt > k) cout<<"NO\n";
    else{
        while(cnt < k && vec.size() > 0){
            int a = vec.back();
            vec.pop_back();
            if(a > 2){
                vec.push_back(a/2);
                vec.push_back(a/2);
            }
            cnt++;
        }
        if(cnt < k) cout<<"NO\n";
        else{
            cout<<"YES\n";
//            for(int i = 0 ; i<vec.size() ; i++){
//                int a = vec[i];
//            }
            for(int a:vec){
                cout<<a<<" ";
                k--;
            }
            while(k--){
                cout<<"1 ";
            }
            cout<<endl;
        }
    }
    return 0;
}
