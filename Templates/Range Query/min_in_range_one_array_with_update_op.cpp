#include<bits/stdc++.h>
using namespace std;
#define UltraViolet ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void build(int in, int low, int high, int arr[], int seg[]){
    if(low==high){
        seg[in] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    build(2*in + 1, low, mid, arr, seg);
    build(2*in + 2, mid+1, high, arr, seg);
    seg[in] = min( seg[2*in + 1] , seg[2*in + 2] );
}

int query(int in, int low, int high, int l, int r, int seg[]){
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
    int left = query(2 * in + 1, low, mid, l, r, seg);
    int right = query(2 * in + 2, mid+1, high, l, r, seg);
    return min(left , right);
}

void update(int in, int low, int high, int i, int val, int seg[]){
    if(low == high){
        seg[in] = val;
        return;
    }

    int mid = (low + high)/2;
    if(i<=mid){
        update(2 * in + 1, low, mid, i, val, seg);
    }else{
        update(2 * in + 2, mid+1, high, i, val, seg);
    }
    seg[in] = min( seg[2*in + 1] , seg[2*in + 2] );
}


void solve(){

    UltraViolet;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int seg[2 * n];
    build(0,0,n-1,arr,seg);
    //  run for each query
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type==1){
            int l,r; cin >> l >> r;
            cout << query(0,0,n-1,l,r,seg) << "\n";
        }else{
            int i,val; cin >> i >> val;
            update(0,0,n-1,i,val,seg);
            arr[i] = val;
        }
    }
}

int main(){
    int t=1;
    // cin >> t;
    while(t--){solve();}
}

// Run for this TestCase

// 6
// 2 0 1 5 4 3
// 3
// 1 1 2
// 2 1 6
// 1 1 2