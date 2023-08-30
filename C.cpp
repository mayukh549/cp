#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int > vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long > pll;
typedef vector<pair<ll,ll>> vpll;
#define fr(i,n,a) for(long long i=a; i<n; i++)
#define ufr(i,n,a) for(long long i=n-1; i>=a; i--)
#define vin(v) int n; cin>>n;vector<int>v; for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}  
#define ain(a) int n; cin>>n; ll a[]; for(int i=0;i<n;i++){cin>>a[i];}
#define vout(v) for(auto &e:v){cout<<e<<" ";} cout<<endl;
#define mout(mp) for(auto &e:mp){cout<<e.first<<" "<<e.second;} cout<<endl;
#define mvout(mp) for(auto &e:mp){cout<<e.first<<endl; for(long long i =0 ; i<(e.second).size();i++){cout<<(v.second)[i]<<" ";} cout<<endl;} cout<<endl;
#define Sort(a) sort(a.begin(),a.end())
#define Sorta(a,n) sort(a,a+n)
#define pb push_back 
#define F first
#define S second 
const ll M = 1000000000+7;




int countdigits(ll x){
    ll y=x;
    int c=0;
    while(y>0){
        c++;
        y=y/10;
    }
    return c;
}

ll power(ll a,ll b){
    ll ans = 1;
    for(ll i = 0 ; i<b;i++){
        ans*=a;
        ans = ans%(1000000000+7);

    }
    return ans;

}
ll binarysearch(ll a[],ll x,ll n){
    ll s=0;
    ll e=n-1;
    while(s<=e){
        ll mid = (s+e)/2;
        if(a[mid]==x){
            return mid;

        }
        else if(a[mid]>x){
            e=mid-1;
        }
        else
            s=mid+1;
    }
    return -1;

}

vi decimaltobinary(ll num){
    vi binary_value;
    for(int i = 32;i>=0;--i){
        if((num>>i)>0){
            binary_value.push_back((num>>i)&1);
        }
    }
    return binary_value;
    


}
ll binarytodecimal(vi b){
    ll ans = 0;
    for(ll i = 0 ; i<b.size();i++){
        ans = ans + b[b.size()-1-i]*power(2,i);


    }
    return ans;

}
ll factorial(string n){
    ll ans =1;
    ll k = 2;
    ll counter=0;
    for(ll i = n.length()/2+1; i<=n.length();i++){
        if(counter==0){
            ans=ans*i;
        }
        if(ans%k==0 && k<=n.length()/2){
            ans=ans/k;
            ans =ans%(1000000000+7);
            k++;
            i-=1;
            counter = 1;
        }else{
            ans =ans%(1000000000+7);
            counter =0;
        }
        

    }
    return ans;

}


/*stringstream str;
                         --------->string to integer 
     
  str <<n[i] ; int x1; str >> x1;
 */
// __builtin_popcount(decimal)--->counts number of set bits
/*
int n = nums.size();
int subset_ct = 1<<n; ---------->length to subset of set nums
*/
// (char)('a'+1)----->b

void solve(){
    ll n;
    cin>>n;
    ll s2 = 1;
    fr(i,n,0){
        cout<<s2<<" ";
        s2*=64;

    }
    cout<<endl;
    cout.flush();
    ll ans;
    cin>>ans;
    ll counter = 0;
    //cout<<ans;
    ll ans1=0;
    vll v;
    ll s1 =1;
    while(ans>0){
        if(counter>=6){
            //cout<<ans1<<endl;
            v.pb(ans1);
            ans1=0;
            s1=1;
            counter=0;
        }
        //cout<<s1<<" "<<ans%2<<" "<<s1*(ans%2)<<" "<<ans1<<endl;
        ans1+=(s1*(ans%2));
        ans/=2;
        s1*=2;
        counter++;


    }
    v.pb(ans1);
    vout(v);

    

} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

}    