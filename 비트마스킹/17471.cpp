#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
vector<int> adj[11];
int n,m,num,a[11],color[11],visited[11],ret=INF;
pair<int ,int> dfs(int here, int value){
	visited[here]=1;
	pair<int,int>ret={1,a[here]};
	for(int there:adj[here]){
		if(color[there]!=value) continue;
		if(visited[there])continue;
		pair<int,int>_temp = dfs(there,value);
		ret.first+=_temp.first;
		ret.second+=_temp.second;
	}
	return ret;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>num;
			adj[i].push_back(num);
			adj[num].push_back(i);
		}
	}
	for(int i=1;i<(1<<n)-1;i++){
		fill(visited, visited+11,0);
		fill(color, color+11,0);
		int idx1=-1, idx2=-1;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				color[j+1]=1; idx1=j+1; 
			}else{
				idx2=j+1;
			}
		}
		pair<int,int> comp1=dfs(idx1,1);
		pair<int,int> comp2=dfs(idx2,0);
		if(comp1.first+comp2.first==n) ret=min(ret,abs(comp1.second-comp2.second));
	}
	cout<<(ret==INF?-1:ret);
}
