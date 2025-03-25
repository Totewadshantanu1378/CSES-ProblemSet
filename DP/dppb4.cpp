#include <bits/stdc++.h>
# define loop1(i,a,n)  for(int i=a;i<n;i++)
# define loop2(i,a,n)  for(int i=a;i<=n;i++)
# define print(arr ,n)   for(int i=0;i<n;i++) cout<<arr[i]<<endl;
// # define cout(n) cout<<n<<endl;
using namespace std;
using ll = long long;
int mod = 1e9 + 7;

int main(){
       int n ,x;
       cin>>n>>x;
      
       vector<vector<int>>dp(n+1,vector<int>(x+1,0));
       vector<int>a(n);
       loop1(i,0,n){
          cin>>a[i];
       }

       loop1(i,0,n){
          dp[i][0] = 1;
       }

       for(int i=n-1;i>=0;i--){
          for(int sum = 1;sum<=x;sum++){
             int skip = dp[i+1][sum];
             int pick = 0;
             if(a[i] <= sum){
                pick = dp[i][sum - a[i]];
             }

             dp[i][sum] = (pick + skip)%mod;
          }
       }
       cout<<dp[0][x]<<endl;
}