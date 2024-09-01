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
    cin>>n>>k;
    vector<ll>a(n);
    // unordered_map<int,int>mp;
    loop1(i,0,n){
        cin>>a[i];
    }
    sort(a);
    int sum = 0,ans = 0;
    int j = n -1;
    int i = 0;
    while(i <= j){
       if(a[i] + a[j] > k){
           ans++;
           j--;
       }
       else{
           ans++;
           i++;
           j--;
       }
    }
    cout<<ans;
}
