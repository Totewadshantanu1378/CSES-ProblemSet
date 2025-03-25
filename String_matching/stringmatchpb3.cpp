#include<bits/stdc++.h>
 using namespace std;
 vector<int>LPS(string s){
            int n = s.size();
            vector<int>lps(n);
            for(int i=1;i<n;i++){
                int j = lps[i-1];
                while(j > 0 && s[i] != s[j]){
                    j = lps[j - 1];
                }
                if(s[i] == s[j])
                 j++;
                
                lps[i] = j;
            }
            return lps;
   }
  
  int main(){
    string s;
    cin>>s;
    vector<int>lps=LPS(s);
    vector<int>ans;
    int j = lps[lps.size() - 1];
    while(j > 0){
        ans.push_back(j);
        j = lps[j-1];
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    cout << ans[i] << " ";

  }


