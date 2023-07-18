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
    
    map<ll,ll>mp;

    //cout<<mp.size();

    
    fr(i,n,0){
        map<ll,ll>mp1;
        if(n%(i+1)==0){
            mp[n/(i+1)]++;
            mp[i+1];
        }
        ll counter =0;
        

        for(auto &e:mp){
            if(counter>=26){
                break;
            }

            if(-e.F+i>=0){
                if(a[-e.F+i]>=0){
                    mp1[a[-e.F+i]]++;

                }

            }else{
                break;
            }
            counter++;
        }
        fr(i1,26,0){
            if(mp1[i1]==0){
                cout<<(char)('a'+i1);
                a.pb(i1);


                break;
            }

        }



    }

    cout<<"\n";


    

} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

}    // make ----> new node 
// find ----> parent of the group 
// union ----> a,b (either A under b ---> (then a has become the new parent of the b group) or b under a (b has become the new parent under for the a group also))

int parent[N];
int size[N];
// multiset<ll>sizes;
void make(int v){
	parent[v]=v;
	// sizes.insert(1);
}

int find( int v){
	if(v==parent[v]) return v;
	return parent[v]=find(parent[v]);

}
// the tree shoul be more branched than long a long trees are 
// diificult to find the root node and time consuming aslo 
// when we use the find opration each node we are traversing should we connnected to 
// the root node so. (path compression )
// orrr alwaays insert small tree in a big tree(size or rank)
// void merge(int a ,int b){
// 	sizes.erase(sizes.find(size[a]));// erase function use iterator not the value as it will result in removal of all the values equal to i t 

// 	size.erase(sizes.find(size[b]));
// 	sizes.insert(size[a]+size[b]);

// }
void Union(int a , int b){
	a =  find(a);
	b =find(b);
	if(a!=b){
		// Uno=ion by size
		if(size[a]<size[b]){
			swap(a,b);
		}
		parent[b]=a;
		// merge(a,b);
		size[a]+=size[b];
	}


}
//O(alpha(n))==>apha(n)==>for reasonable value of of n alpha(n)<=4
