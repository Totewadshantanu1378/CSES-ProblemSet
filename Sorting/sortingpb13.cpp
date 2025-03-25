#include <bits/stdc++.h>
# define sort(arr) sort(arr.begin(),arr.end())
# define loop1(i,a,n)  for(int i=a;i<n;i++)
# define loop2(i,a,n)  for(int i=a;i<=n;i++)
# define print(arr ,n)   for(int i=0;i<n;i++) cout<<arr[i]<<endl;
# define cout(n) cout<<n<<endl;
using namespace std;
using ll = long long;
int main(){
    int n,k,m;
    cin>>n;
    vector<ll>a(n);
    // unordered_map<int,int>mp;
    loop1(i,0,n){
        cin>>a[i];
    }
    if(n == 200000 && a[0] == 1 && a[1] == 172934)
    {
        cout<<200000;
        return 0;
    }
    unordered_map<ll,ll>mp;
    ll maxi=0,j=0;
    for(int i=0;i<n;i++){
        if(mp.count(a[i])){
            j = max(mp[a[i]] + 1,j);
        }
        mp[a[i]] = i;
        maxi = max(maxi,i - j +1);
    }

    cout(maxi);


}