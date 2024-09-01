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
       cin>>n;
      
       vector<vector<int>>dp(n,vector<int>(n));
       vector<string>a(n);
       loop1(i,0,n){
          cin>>a[i];
       }
      if(a[0][0] == '*')
      dp[0][0] = 0;
      else
      dp[0][0] =1;

      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0){
                continue;
            }
            if(a[i][j] == '*')
             dp[i][j] = 0;
            else{
                int ans1 = (i > 0)?dp[i-1][j]:0;
                int ans2 = (j > 0)?dp[i][j-1]:0;
                dp[i][j] = (ans1 + ans2)%mod;            }
        }
      }
       cout<<dp[n-1][n-1]<<endl;
}