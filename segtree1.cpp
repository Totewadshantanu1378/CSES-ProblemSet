#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
class segTree
{
    public:
    vector<ll>seg;
    segTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind, int low, int high, ll arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        ll mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
    }
    ll query(int ind, int low, int high, int l, int r)
    {
        // no overlap
        if (l > high || r < low)
            return 0;

        // completely overlap
        if (l <= low && r >= high)
            return seg[ind];

        // partially overlap
        ll mid = (low + high) >> 1;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);

        return (left+ right);
    }
    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        ll mid = (low + high) >> 1;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
    }
};

int main(){
    int n1,q;
    cin >> n1 >> q;
    ll arr1[n1];
    for(int i=0;i<n1;i++) cin >> arr1[i];
    segTree sg1(n1);
    sg1.build(0,0,n1-1,arr1);

    while(q--){
        ll l1,r1;
        cin>>l1>>r1;
        cout<<sg1.query(0,0,n1-1,l1 - 1,r1 -1)<<endl;
    }
}