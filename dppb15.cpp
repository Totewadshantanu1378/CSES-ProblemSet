#include <bits/stdc++.h>
# define sort(arr) sort(arr.begin(),arr.end())
# define loop1(i,a,n)  for(int i=a;i<n;i++)
# define loop2(i,a,n)  for(int i=a;i<=n;i++)
# define print(arr ,n)   for(int i=0;i<n;i++) cout<<arr[i]<<endl;
// # define cout(n) cout<<n<<endl;
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    vector<ll>nums(n);
    for(auto &it:nums){
        cin>>it;
    }
    int size = 0;
     vector<int>dp(n);
        for (int x : nums) {
            int i = 0, j = size;
            while (i != j) {
                int m = (i + j) / 2;
                if (dp[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            dp[i] = x;
            if (i == size) ++size;
        }
    // vector<ll>dp(nums.size(),1);
    //     ll maxi = 0;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         for(int prev=0;prev<i;prev++){
    //             // int incl;
    //              if(nums[prev] < nums[i]){
    //                 dp[i] = max(dp[i] , dp[prev] + 1);
    //              }
    //         }
    //         maxi = max(maxi,dp[i]);
    //     }
        
    cout<<size<<endl;
}