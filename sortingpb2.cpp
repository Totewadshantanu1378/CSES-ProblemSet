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
    cin>>n>>m>>k;
    vector<ll>a(n),b(m);
    // unordered_map<int,int>mp;
    loop1(i,0,n){
        cin>>a[i];
    }
    loop1(i,0,m){
        cin>>b[i];
    }
    sort(a);
    sort(b);
    int j = 0;
    int cnt = 0;
    int i = 0;
    while(i < n && j <m){
        if(a[i] + k >= b[j] && b[j] >= a[i] - k){
            cnt++;
            i++;
            j++;
        }
        else if(a[i] + k < b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    cout<<cnt<<endl;

}