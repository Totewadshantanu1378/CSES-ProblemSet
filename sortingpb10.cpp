#include <bits/stdc++.h>
# define sorte(arr) sort(arr.begin(),arr.end())
# define loop1(i,a,n)  for(int i=a;i<n;i++)
# define loop2(i,a,n)  for(int i=a;i<=n;i++)
# define print(arr ,n)   for(int i=0;i<n;i++) cout<<arr[i]<<endl;

using namespace std;
using ll = long long;
int main(){
    ll n,k,m;
    cin>>n;
    vector<ll>a(n);
    // unordered_map<int,int>mp;
    loop1(i,0,n){
        cin>>a[i];
    }
    sorte(a);
    int ans = 0;
    unordered_map<int,int>mp;
    ll sum = 0;
    for(int i=0;i<n;i++){
       sum += a[i];
       if(a[i+1] > sum + 1){
          ans = sum + 1;
          break;
       }
    }
    if(a[0] != 1){
        cout<<1;
    }
    else if(ans == 0){
        cout<<(sum + 1);
    }
    else{
        cout<<ans;
    }

}