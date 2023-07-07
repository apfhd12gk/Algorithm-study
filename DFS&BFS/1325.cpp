#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10004];
int n,m,mx,a,b,ret[10004],visited[10004];
int dfs(int here){
	visited[here]=1;
	int ret=1;
	for(int there:adj[here]){
		if(!visited[there]){
			ret+=dfs(there);
		}
	}
	return ret;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		fill(&visited[0],&visited[0]+10004,0);
		ret[i]=dfs(i);
		mx=max(mx,ret[i]);
	}
	for(int i=1;i<=n;i++){
		if(mx==ret[i]){
			cout<<i<<' ';
		}
	}
}
