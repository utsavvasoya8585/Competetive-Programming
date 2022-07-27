#include <iostream>
#include<vector>
using namespace std;
#define int long long
#define vi vector<int>
#define pb push_back
#define mk mak_pair
#define pi (3.141592653589)
#define float double
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
// All func 
int fastpower(long a,long b,int n=1000000007){ long res=1; while(b>0){ if((b&1)!=0){ res = (res%n * a%n)%n ;} a = (a%n * a%n)%n; b=b>>1;} return res;}
int checkPrime(int n) { bool prime[n+1]; memset(prime, true, sizeof(prime)); for(int p=2; p*p<=n; p++) { if (prime[p] == true) { for (int i=p*p; i<=n; i += p) prime[i] = false; } } int cprime=0; for(int p=2; p<=n; p++) if(prime[p]) cprime++; return cprime;}
int gcd(int a, int b){  int c = a % b;  while(c != 0)  {    a = b;    b = c;    c = a % b;  }  return b;}
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

string addBig(string a,string b){
    vi x,y;
    rep(i,0,a.size()) x.pb(a[i]-'0');
    rep(i,0,b.size()) y.pb(b[i]-'0');
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    int len = min(x.size(),y.size()),carry=0;
    vi ans;
    rep(i,0,len){
        int val = x[i] + y[i] + carry;
        carry = val/10;
        ans.pb(val%10);
    }
    if(x.size()>len){
        rep(i,len,x.size()){
            int val = x[i] + carry;
            carry = val/10;
            ans.pb(val%10);
        }
    }
    if(y.size()>len){
        rep(i,len,y.size()){
            int val = y[i] + carry;
            carry = val/10;
            ans.pb(val%10);
        }
    }
    while(carry){
        ans.pb(carry%10);
        carry/=10;
    }
    reverse(ans.begin(),ans.end());
    string str="";
    rep(i,0,ans.size()) str+=(ans[i]+'0');
    return str;
}

int32_t main(){
fast
// just chill chill just chill
    string a,b; cin >> a >> b;
    cout << addBig(a,b);
return 0;
}
