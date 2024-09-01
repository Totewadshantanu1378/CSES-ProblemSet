#include <bits/stdc++.h>
using namespace std;
class segTree
{
    public:
    vector<int>seg;
    segTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int query(int ind, int low, int high, int l, int r)
    {
        // no overlap
        if (l > high || r < low)
            return INT_MAX;

        // completely overlap
        if (l <= low && r >= high)
            return seg[ind];

        // partially overlap
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);

        return min(left, right);
    }
    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

int main(){
     int n1,q;
    cin >> n1 >> q;
    int arr1[n1];
    for(int i=0;i<n1;i++) cin >> arr1[i];
    segTree sg1(n1);
    sg1.build(0,0,n1-1,arr1);
    
    while(q--){
        int type ;
        cin>>type;
        if(type == 2){
            int l,r;
            cin>>l>>r;
            cout<<sg1.query(0,0,n1-1,l-1,r-1)<<endl;
        }
        else{
            int k,u;
            cin>>k>>u;
            sg1.update(0,0,n1-1,k-1,u);
        }
    }
    
}