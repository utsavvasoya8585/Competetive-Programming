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

string divisionByTwo(string s){
    vi x;
    vi ans;
    rep(i,0,s.length()) x.pb(s[i]-'0');
    int rem=0;
    rep(i,0,s.length()){
        if(rem){
            rem = rem*10 + x[i];
            ans.pb(rem/2);
            rem = rem%2;
        }else{
            if(x[i]<2) rem+=x[i],ans.pb(0);
            else ans.pb(x[i]/2),rem = x[i]%2;
        }
    }
    string str="";
    rep(i,0,ans.size()) if(!(i==0 && ans[i]==0)) str+=(ans[i]+'0');
    return str;
}

int32_t main(){
fast
// just chill chill just chill
    string s; cin >> s;
    string ans = divisionByTwo(s);
    cout << ans << "\n";
return 0;
}
