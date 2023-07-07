#include<bits/stdc++.h>
using namespace std;
int n,m,num;
vector<int> adj[54];
int dfs(int idx,int m){
	int ret=0;
	int child=0;
	
	for(int there: adj[idx]){
		if(there==m) continue;
		ret+=dfs(there,m);
		child++;
	}
	if(child==0) return 1;
	return ret;
}
int main(){
	int root;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		if(num==-1)root=i;
		adj[num].push_back(i);
	}
	cin>>m;
	if(m==root){
		cout<<0; return 0;
	}
	cout<<dfs(root,m);
	return 0;
}
