#include <bits/stdc++.h>
# define sort(arr) sort(arr.begin(),arr.end())
# define loop1(i,a,n)  for(int i=a;i<n;i++)
# define loop2(i,a,n)  for(int i=a;i<=n;i++)
# define print(arr ,n)   for(int i=0;i<n;i++) cout<<arr[i]<<endl;
# define cout(n) cout<<n<<endl;
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    bitset<100001>temp;
    temp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int x;
        cin>>x;
        temp |= (temp << x);
    }
    vector<int>ans;
    for(int i=0;i<100001;i++){
        if(temp[i])
        {
            ans.push_back(i);
        }    
    }
    cout<<ans.size() - 1<<endl;
    for(int i=1;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    solve();
}