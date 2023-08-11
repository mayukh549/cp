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
#define mvout(mp) for(auto &e:mp){cout<<e.first<<endl; for(long long i =0 ; i<(e.second).size();i++){cout<<(e.second)[i]<<" ";} cout<<endl;} cout<<endl;
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
    string s ;
    ll q ;
    cin>>n>>s>>q;
    ll m = power(2,n);
    ll mans =m-1;
    m/=2;
    vll v1;
    map<ll,vll>mp;
    while(m>0){
        v1.pb(m);
        m/=2;


    }
    ll counter = 0;
    ll counter2 =0;

    //vout(v1);
    mans--;
    for(auto &e:v1){
        counter2 = counter;
        fr(i,e,0){

            if(mp[counter].size()==0){
                //cout<<counter<<endl;

                mp[counter].pb(1);
                mp[counter].pb(1);
                mp[counter].pb(counter2+e);
                if(s[counter]=='?'){
                    mp[counter2+e].pb(2);

                }else{
                     mp[counter2+e].pb(1);
                }
                counter++;
                mp[counter].pb(1);
                mp[counter].pb(1);
                mp[counter].pb(counter2+e);
                if(s[counter]=='?'){
                    mp[counter2+e].pb(2);
                    
                }else{
                     mp[counter2+e].pb(1);
                }
                i++;
                counter++;
                counter2++;
            }else{
                //cout<<counter<<"--->"<<mp[counter].size()<<counter2<<endl;
                mp[counter].pb(counter2+e);
                if(s[counter]=='?'){
                    mp[counter2+e].pb((mp[counter])[0]+(mp[counter])[1]);

                }else{
                     mp[counter2+e].pb((mp[counter])[s[counter]-'0']);
                }
                counter++;
                if(e==1) break;

                mp[counter].pb(counter2+e);
                if(s[counter]=='?'){
                    mp[counter2+e].pb((mp[counter])[0]+(mp[counter])[1]);

                }else{
                     mp[counter2+e].pb((mp[counter])[s[counter]-'0']);
                }
                i++;
                counter++;
                counter2++;

            }

        }
    }
    //mvout(mp);
    //cout<<q<<"l:"<<endl;

    while(q--){
        //cout<<"l"<<endl;
        ll n1;
        char s1;
        cin>>n1>>s1;
        s[n1-1]=s1;
        n1--;
        ll counter3 =0;
        //cout<<n1;
        while(n1<mans){
            if(counter3 >100000000000){
                cout<<"h";
                break;
            }
            
            ll s3 = (mp[n1])[2];
            //cout<<n1<<" "<<s3<<endl;
            if(s[n1]=='?'){
                (mp[s3])[(n1)%2]=(mp[n1])[0]+(mp[n1])[1];
                


                

            }else{
                     (mp[s3])[(n1)%2]=((mp[n1])[s[n1]-'0']);
                }
            n1=s3;
            counter3++;

        }
        //mvout(mp);
        //cout<<"---->"<<endl;
        if(s[mans]=='?'){
            cout<<(mp[mans])[0]+(mp[mans])[1]<<"\n";
        }else{
            cout<<((mp[mans])[s[mans]-'0'])<<"\n";

        }
        //cout<<s<<endl;


    }


    

} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }

}    