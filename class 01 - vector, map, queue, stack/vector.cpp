#include<bits/stdc++.h>
#define ll long long
#define N ((int)(15e4 + 5))
#define MOD ((int)(1e9 + 7))
#define endl "\n"


using namespace std;



/// to declare: vector < data_type > name;
/// to insert: name.push_back(value);

int arr[N];

int main()
{
    vector < int > vec;
    int n;
    cin>>n;
    for(int i = 0 ; i<n ; i++){
        int a;
        cin>>a;
        vec.push_back(a);
    }
    for(int i = 0 ; i<n ; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    cout<<vec.size()<<endl;

    /// to erase i'th element: name.erase(name.begin() + i-1 )
    vec.erase(vec.begin() + 2);
    for(int i = 0 ; i<vec.size() ; i++){
        cout<<vec[i]<<" ";
    }

    cout<<endl;

    /// to erase last element:
    vec.erase(vec.end()-1);
    vec.pop_back();
    return 0;
}
