#include<bits/stdc++.h>
using namespace std;
int visited[100004];
int cnt[100004];
int main(){
	int n,m;
	cin>>n>>m;
	if(n==m){
		puts("0"); puts("1");
		return 0;
	}
	visited[n]=1;
	cnt[n]=1;
	queue<int> q;
	q.push(n);
	while(q.size()){
		int now = q.front();
		q.pop();
		for(int next : {now-1,now+1,now*2}){
			if(0<=next&&next<=100004){
				if(!visited[next]){
					q.push(next);
					visited[next]=visited[now]+1;
					cnt[next]+=cnt[now];
				}else if(visited[next]==visited[now]+1){
					cnt[next]+=cnt[now];
				}
			}
		}
	}
	cout<<visited[m]-1<<'\n';
	cout<<cnt[m];
}
