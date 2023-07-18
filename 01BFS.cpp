vector<pair<ll,ll>>g[N];
vector<ll>lev(N,INF);
ll n,m;
ll bfs(){
	deque<ll>q;
	q.pb(1);
	lev[1]=0;
	while(!q.empty){
		ll cur_v =q.front();
		q.pop();
		for(auto child : q[cur_v]){
			ll child_v=child.F;
			ll wt = child.S;
			if(lev[cur_v]+wt<lev[child_v]){
				lev[child_v]=lev[cur_v]+1;
				if(wt==1){
					q.pb(child_v);

				}else{
					q.push_front(child_v);
				}
			}
		}
	}
	return lev[n]==INF?-1:lev[n];


}