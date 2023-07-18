// make ----> new node 
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
