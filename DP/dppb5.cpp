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
      
       vector<int>dp(n+1,1e9);
       vector<int>a(n);
       dp[0] = 0;
       for(int i=1;i<=n;i++){
          string str = to_string(i);
          for(auto it:str){
            int dig = it - '0';
            if(dig != 0){
                dp[i] = min(dp[i],1 + dp[i - dig]);
            }
          }
       }

       cout<<dp[n];

}