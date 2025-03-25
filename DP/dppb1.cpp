#include <bits/stdc++.h>
# define sort(arr) sort(arr.begin(),arr.end())
# define loop1(i,a,n)  for(int i=a;i<n;i++)
# define loop2(i,a,n)  for(int i=a;i<=n;i++)
# define print(arr ,n)   for(int i=0;i<n;i++) cout<<arr[i]<<endl;
# define cout(n) cout<<n<<endl;
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int>dp(n+1,0);
    dp[0] = 1;
    int mod = 1e9 + 7;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(j <= i){
                dp[i] = (dp[i] + dp[i - j])%mod;
            }
        }
    }
    cout<<dp[n];
}