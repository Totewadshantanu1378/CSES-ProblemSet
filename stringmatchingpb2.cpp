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
       int search(string pat, string txt)
        {
            //code here
            vector<int>lps = LPS(pat);
            int m = pat.size();
            int n = txt.size();
            int ans = 0;
            int i=0,j = 0;
            while(i < n){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                }
                else{
                    if(j == 0) i++;
                    else j = lps[j - 1];
                }
                
                if(j == m){
                    ans++;
                    j = lps[j-1];
                }
            }
            return ans;
            
        }
        int main(){
            string pat;
            string txt;
            cin>>pat>>txt;
            cout<<search(txt,pat)<<endl;
        }