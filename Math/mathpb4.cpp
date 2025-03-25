#include <bits/stdc++.h>
# define sort(arr) sort(arr.begin(),arr.end())
# define loop1(i,a,n)  for(int i=a;i<n;i++)
# define loop2(i,a,n)  for(int i=a;i<=n;i++)
# define print(arr ,n)   for(int i=0;i<n;i++) cout<<arr[i]<<endl;
# define cout(n) cout<<n<<endl;
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    ll cnt = 0;
    loop2(i,1,sqrt(n)){
        ll temp;
        if(n % i == 0){
            temp = n / i;
            cnt++;
            if(n % temp == 0 && temp != i)
             cnt++;
        }
    }
    cout(cnt);
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}