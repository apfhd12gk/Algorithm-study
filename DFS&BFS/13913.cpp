#include<bits/stdc++.h>
using namespace std;
#define prev aaa
int n,m,ret,visited[200004],prev[200004]; 
vector<int> v;
int main(){
	cin>>n>>m;
	visited[n]=1;
	queue<int> q;
	q.push(n);
	while(q.size()){
		int now=q.front();
		q.pop();
		if(now==m){
			ret=visited[m];
			break;
		}
		for(int next : {now-1,now+1,now*2}){
			if(next>=0&&next<=200004){
				if(!visited[next]){
					q.push(next);
					visited[next]=visited[now]+1;
					prev[next]=now;
				}
				
			}
			
		}
		
	}
	for(int i=m;i!=n;i=prev[i]){
		v.push_back(i);
	}
	v.push_back(n);
	cout<<ret-1<<'\n';
	reverse(v.begin(),v.end());
	for(int i:v)cout<<i<<" ";
}
