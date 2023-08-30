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

ll power(ll x, ll n)
{
    ll result = 1;
    while (n > 0) {
        if (n & 1 == 1) // y is odd
        {
            result = result * x;
        }
        x = x * x;
        n = n >> 1; // y=y/2;
    }
    return result;
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
    ll m;
    cin>>n>>m;
    m++;
    // cout<<n<<m<<endl;
    //     fr(i,39216,0){
    //     cout<<i<<" "<<(n^i)<<endl;
    //     if((i+1)%32768==0){

    //         cout<<"--"<<endl;;
    //     }

    // }

    ll a[30]={0};
    ll b[30]={0};
    ll counter =29;
    ll n1 = n;
    fr(i,30,0){
        b[counter]=n1%2;
        n1/=2;
        counter--;

    }
    //vout(b);
    //cout<<power(2,1)<<endl;
    ll s31 =0;
    while(power(2,s31)<=n){
        //cout<<"k"<<endl;
        //cout<<s31<<endl;
        s31++;

    }
    if(n>m){
        //cout<<"k"<<endl;
        cout<<0<<endl;
        return;
    }
    s31=power(2,s31);
    //cout<<s31<<endl;
    ll s1 = m/s31;
    ll s2 = m%s31;
    //cout<<s2<<endl;
    if(s2<n+1 && s1>0){
        //cout<<"l"<<endl;
        cout<<s31*s1<<endl;
        //return;
    }else{
        ll n5 =n;
        n=s2;
        counter =29;
        n1 = n;

    fr(i,30,0){
        a[counter]=n1%2;
        n1/=2;
        counter--;

    }
    // vout(a);
    // vout(b);
    ll c1= 0;
    fr(i,30,0){
        if(b[i]==1&&a[i]==0){
            a[i]=1;
            c1++;
            //break;
        }
        if((b[i]==0&&a[i]==1 && c1>0)){
            a[i]=0;
        }

    }
    //vout(a);
    ll s9 =1;
    ll ans =0;
    counter = 29;
    ufr(i,30,0){
        ans+=(a[counter]*s9);
        s9*=2;
        counter--;

    }
    cout<<s31*(s1)+(n5^ans)<<endl;



    }

    //cout<<endl;


    

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