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
       vector<int>a(n),b(n);

       for(auto &it:a){
          cin>>it;
       }
       for(auto &it:b){
          cin>>it;
       }
      
       for(int i=1;i<=n;i++){
           for(int page=0;page<=x;page++){
               int w = a[i-1];
               int val = b[i-1];
               int skip = dp[i-1][page];
               int pick = 0;
               if(w <= page){
                  pick = val + dp[i-1][page-w];
               }
               dp[i][page] = max(skip,pick);
           }
       }
    
       cout<<dp[n][x]<<endl;
}