#include<bits/stdc++.h>
using namespace std;
int T,N,M,A,B,cnt;
vector<int> adj[1004];
int visited[1004];
void dfs(int here){
	visited[here]=1;
	for(int there : adj[here]){
		if(!visited[there]){
			dfs(there);
		}
	}
	return;
}
int main(){
	cin>>T;
	for(int i=0;i<T;i++){
		for(int j=0;j<1004;j++)adj[j].clear();
		fill(visited,visited+1004,0);
		cnt=0;
		cin>>N>>M;
		for(int j=0;j<M;j++){
			cin>>A>>B;
			adj[A].push_back(B);
			adj[B].push_back(A);
		}
		for(int j=1;j<=N;j++){
			if(!visited[j]){
				dfs(j);
				cnt++;
			}
		}
		if(M==N-1&&cnt==1){
			cout<<"tree\n";
		}else {cout<<"graph\n";}
		
		
	}
}
