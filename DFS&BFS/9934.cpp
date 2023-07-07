#include<bits/stdc++.h>
using namespace std;
int k,n[1024];
vector<int> ret[12];
void go(int s, int e, int level){
	if(s>e) return;
	if(s==e) {
		ret[level].push_back(n[s]); 
		return;
	}
	int mid=(s+e)/2;
	ret[level].push_back(n[mid]);
	go(s,mid-1,level+1);
	go(mid+1,e,level+1);
	return;
}

int main(){
	cin>>k;
	int _end=(int)pow(2,k)-1;
	for(int i=0; i<_end; i++){
		cin>>n[i];
	}
	go(0,_end,0);
	for(int i=0;i<k;i++){
		for(int j:ret[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
}
