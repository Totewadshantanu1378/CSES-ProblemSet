#include<bits/stdc++.h>
using namespace std;

vector<int> cal_Z_val(string s){
    int n = s.length();
    vector<int>z(n+1 , 0);
    int l = 0,r = 0;
    for(int i=1;i<n;i++){
        if(i < r){
            z[i] = min(r - i , z[i - l]);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
        {
            z[i]++;
        }
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
void solve(){
    string s;
    cin>>s;
    vector<int>z = cal_Z_val(s);
    int n = s.length();

    vector<int>ans;
    for(int i=0;i<n;i++){
        if(z[i + 1] + i + 1 == n){
            ans.push_back(i + 1);
        }
    }
    int m = ans.size();
    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
        // cout<<0;
    }
}
int main(){
   solve();
   
   return 0;
}