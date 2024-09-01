#include <bits/stdc++.h>
# define sort(arr) sort(arr.begin(),arr.end())
# define loop1(i,a,n)  for(int i=a;i<n;i++)
# define loop2(i,a,n)  for(int i=a;i<=n;i++)
# define print(arr ,n)   for(int i=0;i<n;i++) cout<<arr[i]<<endl;

using namespace std;
using ll = long long;
int main(){
    ll n,k,m;
    cin>>n;
    vector<pair<ll,ll>>a;
    // unordered_map<int,int>mp;
    loop1(i,0,n){
        ll s,e;
        cin>>s>>e;
        a.push_back({s,1});
        a.push_back({e,-1});
    }
    sort(a);
    ll cnt = 0;
    ll maxi = 0;
    for(int i=0;i<a.size();i++){
        cnt += a[i].second;
        maxi = max(maxi,cnt);
    }
    cout<<maxi;
}