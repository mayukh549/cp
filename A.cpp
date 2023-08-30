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
    
    vll a;
    ll counter =0 ;
    if(n<=2){
        ll s1;
        ll s2;
        cin>>s1>>s2;

        cout<<max((s1+s2)%M,(s1*s2)%M)<<endl;
        return;
    }

    fr(i,n,0){
        ll s1;
        cin>>s1;
        if(s1==1){
            counter++;
        }else{
            a.pb(s1);
        }



    }


    fr(i,counter/3,0){
        a.pb(3);
        //cout<<counter;
        


    }
    //cout<<counter%3<<endl;


    Sort(a);

    ll s1 =1;

    ll s5 = 1;
    //vout(a);
    fr(i,a.size(),0){
                s5=((s5%M)*(a[i]%M))%M;
        s5=s5%M;

    }
    //cout<<s5;
    s5=((s5%M)*((counter%3)%M))%M;;
    s5=s5%M;
    //cout<<s5<<endl;
    
    if(counter%3==1){

   
       
            a[0]=(a[0]%M+1)%M;
            a[0]%=M;
            counter--;
            //Sort(a);
            //vout(a);


        
    }
    //vout(a);


    
    fr(i,a.size(),0){
        s1=((s1%M)*(a[i]%M))%M;
        s1=s1%M;
        //cout<<M<<endl;


    }
    //cout<<s1<<endl;

    cout<<max(s1,s5)<<endl;

    

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