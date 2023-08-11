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
#define mout(mp) for(auto &e:mp){cout<<e.first<<" "<<e.second<<endl;} cout<<endl;
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
vll v1;

ll f1(ll a[] ,ll b[],map<ll,ll>mp1,map<ll,ll>mp2,ll e,ll n,ll sum1){
    if(e<0){
        return 10000000000 ;
    }
    //ll sum1 = 0;

    v1.pb(sum1);
    ll sum69 =sum1;
    //cout<<sum1<<endl;

    ll s1 = min(f1(a,b,mp1,mp2,e-1,n,sum1),sum1);
    ll s2 =a[e];
    a[e]= b[e];
    b[e]=s2;
    sum1-=(mp1[e]+mp2[e]);
    ll s9 =mp1[e];
    ll s20 = mp2[e];
    ll sum2 =0;
        fr(j,n,0){
            if(j!=e)sum2+=(b[e]+b[j])*(b[e]+b[j]);

        }
        sum1+=sum2;
    mp2[e]=sum2;
    sum2 =0;
        fr(j,n,0){
            if(j!=e)sum2+=(a[e]+a[j])*(a[e]+a[j]);

        }
    mp1[e]=sum2;

    sum1+=sum2;
        


    ll s3 = min(f1(a,b,mp1,mp2,e-1,n,sum1),sum1);
    mp1[e]=s9;
    mp2[e]=s20;
    s2 =a[e];
    a[e]= b[e];
    b[e]=s2;
    sum1=sum69;
    return max(s1,s3);




}

void solve(){
    ll n ;
    cin>>n;
    ll a[n];
    ll b[n];

    fr(i,n,0){
        cin>>a[i];
    }
    fr(i,n,0){
        cin>>b[i];
    }
    map<ll,ll>mp;
    ll sum1 = 0;
    fr(i,n,0){
        ll sum = 0;

        fr(j,n,0){
            if(j!=i)sum+=(a[i]+a[j])*(a[i]+a[j]);

        }
        //sum1+=sum;
        mp[i]=sum;
    }
    ll sum2 = 0;

    map<ll,ll>mp2;
    fr(i,n,0){
        ll sum = 0;

        fr(j,n,0){
            if(j!=i)sum+=(b[i]+b[j])*(b[i]+b[j]);

        }
        //sum2+=sum;
        mp2[i]=sum;
    }
    fr(i,n,0){
        fr(j,n,i+1){
            sum1+=(a[i]+a[j])*(a[i]+a[j]);
            sum1+=(b[i]+b[j])*(b[i]+b[j]);

        }
    }
    mout(mp);
    mout(mp2);
    cout<<f1(a,b,mp,mp2,n-1,n,sum1)<<endl;
    Sort(v1);
    cout<<v1[0]<<"\n";
    v1.clear();

    

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