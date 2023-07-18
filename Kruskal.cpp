// make a tree from a graph with smallest weight connected edges
// sort the aedges in incresing order and then add the eges one by one in the graph and they should not form a cycle
// if it forms a cylcle ignore the edge
//using DSU
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
void kruskal(){
	int n,m;
	cin>>n>>m;
	vector<pair<ll,pair<ll,ll>>>edges;
	fr(i,m,0){
		int u,v,wt;
		cin>>u>>v>>wt;
		edges.pb({wt,{u,v}});

	}
	Sort(edges);
	fr(i,n+1,1){
		make(i);
	}
	int total_cost=0;
	for(auto &edge :edges){
		int wt = edges.first;
		int u = (edges.second).first;
		int v =edges.second.second;
		if(find(u)=find(v)) continue;
		Union(u,v);
		total_cost+=wt;
	}

}