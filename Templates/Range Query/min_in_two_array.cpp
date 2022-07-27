#include<bits/stdc++.h>
using namespace std;
#define UltraViolet ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

class SGTree{
    vector<int> seg;
    
public:
    SGTree(int n) {
        seg.resize(4 * n + 1);
    }
    void build(int in, int low, int high, int arr[]){
        if(low==high){
            seg[in] = arr[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*in + 1, low, mid, arr);
        build(2*in + 2, mid+1, high, arr);
        seg[in] = min( seg[2*in + 1] , seg[2*in + 2] );
    }

    int query(int in, int low, int high, int l, int r){
        // no overlaps
        // l r low high or low high l r
        if(r < low || l > high){
            return INT_MAX;
        }

        // Compelete Overlaps
        // low l r high
        if(low>=l && high<=r){
            return seg[in];
        }

        int mid = (low + high)/2;
        int left = query(2 * in + 1, low, mid, l, r);
        int right = query(2 * in + 2, mid+1, high, l, r);
        return min(left , right);
    }

    void update(int in, int low, int high, int i, int val){
        if(low == high){
            seg[in] = val;
            return;
        }

        int mid = (low + high)/2;
        if(i<=mid){
            update(2 * in + 1, low, mid, i, val);
        }else{
            update(2 * in + 2, mid+1, high, i, val);
        }
        seg[in] = min( seg[2*in + 1] , seg[2*in + 2] );
    }
};




void solve(){

    UltraViolet;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int n1; cin >> n1;
    int arr1[n1];
    for(int i=0; i<n1; i++) {
        cin >> arr1[i];
    }
    SGTree seg1(n1);
    seg1.build(0,0,n1-1,arr1);

    int n2; cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++) {
        cin >> arr2[i];
    }
    SGTree seg2(n2);
    seg2.build(0,0,n2-1,arr2);

    //  run for each query
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type==1){
            int l1,r1,l2,r2;
            cin >> l1 >> r1 >> l2 >> r2;
            int ans1 = seg1.query(0,0,n1-1,l1,r1);
            int ans2 = seg2.query(0,0,n2-1,l2,r2);
            cout << min( ans1 , ans2 ) << "\n";
        }else{
            int arrNO,i,val;
            cin >> arrNO >> i >> val;
            if(arrNO==1){
                seg1.update(0,0,n1-1,i,val);
                arr1[i]=val;
            }else{
                seg2.update(0,0,n2-1,i,val);
                arr2[i]=val;
            }
        }
    }
}

int main(){
    int t=1;
    // cin >> t;
    while(t--){solve();}
}