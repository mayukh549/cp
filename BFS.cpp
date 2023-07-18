vll g[N];
ll vis[N];
ll level[N];
bool isvalid(ll x , ll y){
	return x>=0 && y>=0 && x<=8 && y<=80;
}


vector<pair<ll,ll>>movements={
	{-1,0},{1,0},{0,1},{0,-1}

}

//(x,y)==present location;

// for(auto movement : movements){
// 	int x1 = movement.first+x;
// 	int y1 = movement.second +y;
	
// }
void bfs(int source){
	queue<ll>q;
	q.push(source);
	vis[source]=1;
	while(!q.empty()){
		ll cur_v=q.front();
		q.pop();
		for(ll children : g[cur_v]){
			q.push(child);
			vis[child]=1;
			level[child]=level[cur_v]+1;
		}
	}
}

int entering(){
	int n ;
	cin>>n;
	fr(i,n,0){
		cin>>x>>y;
		g[x].pb(x);
		g[y].pb(y);
	}
	bfs(1);
}