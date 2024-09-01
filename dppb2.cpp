#include <bits/stdc++.h>
# define loop1(i,a,n)  for(int i=a;i<n;i++)
# define loop2(i,a,n)  for(int i=a;i<=n;i++)
# define print(arr ,n)   for(int i=0;i<n;i++) cout<<arr[i]<<endl;
// # define cout(n) cout<<n<<endl;
using namespace std;
using ll = long long;

int main(){
       int n ,x;
       cin>>n>>x;

       vector<int>dp(x+1,1e9),a(n);
       loop1(i,0,n){
          cin>>a[i];
       }

       dp[0] = 0;

       for(int i=1;i<=x;i++){
           for(int j=0;j<n;j++)
           {
               if(a[j] <= i){
                  dp[i] = min(dp[i] , dp[i - a[j]] + 1);
               }
           }
       }
       cout<<(dp[x] == 1e9?-1:dp[x])<<endl;
}