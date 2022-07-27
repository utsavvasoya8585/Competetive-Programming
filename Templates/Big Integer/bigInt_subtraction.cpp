// jay swaminarayan //
// UTSAV VASOYA //
#include<iostream>
#include<vector>
#include<map>
#include<string.h>
#include<cmath>
#include<set>
#include <iomanip>
#include<algorithm>
using namespace std;
#define int long long
#define vi vector<int>
#define pb push_back
#define mk mak_pair
#define pi (3.141592653589)
#define float double
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rep(i,a,b) for(int i=a;i<b;i++)
// All func 
int fastpower(long a,long b,int n=1000000007){ long res=1; while(b>0){ if((b&1)!=0){ res = (res%n * a%n)%n ;} a = (a%n * a%n)%n; b=b>>1;} return res;}
int checkPrime(int n) { bool prime[n+1]; memset(prime, true, sizeof(prime)); for(int p=2; p*p<=n; p++) { if (prime[p] == true) { for (int i=p*p; i<=n; i += p) prime[i] = false; } } int cprime=0; for(int p=2; p<=n; p++) if(prime[p]) cprime++; return cprime;}
int gcd(int a, int b){  int c = a % b;  while(c != 0)  {    a = b;    b = c;    c = a % b;  }  return b;}
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

string subtraction(string a,string b){
    vi x,y;
    rep(i,0,a.length()) x.pb(a[i]-'0');
    rep(i,0,b.length()) y.pb(b[i]-'0');
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    vi ans;
    int len = y.size();
    rep(i,0,len){
        if(x[i]<y[i]){
            x[i+1]--;
            ans.pb(10+x[i]-y[i]);
        }else ans.pb(x[i]-y[i]);
    }
    if(x.size()>len){
        rep(i,len,x.size()){
            if(x[i]<0)  x[i+1]--,ans.pb(10*x[i]);
            else ans.pb(x[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    string str="";
    int in=0;
    while(ans[in]==0) in++;
    rep(i,in,ans.size()) str+=(ans[i]+'0');
    return str;
}

int32_t main(){
fast
// just chill chill just chill
    string a,b;
    cin >> a >> b;
    cout << subtraction(a,b);

return 0;
}
