#include<bits/stdc++.h>
using namespace std;
int k,visited[10];
vector<char> v;
char a[9];
string s,N,n;

void go(int x,int cnt){
	if(cnt==k){
		string str;
		for(char a : v) str+=a;
		N=max(N,str);
		n=min(n,str);
	}
	for(int i=0;i<10;i++){
		if(visited[i])continue;
		if(a[cnt]=='>'){
			if(i<x){
				visited[i]=1;
				v.push_back('0'+i);
				go(i,cnt+1);
				v.pop_back();
				visited[i]=0;
			}
		}
		if(a[cnt]=='<'){
			if(i>x){
				visited[i]=1;
				v.push_back('0'+i);
				go(i,cnt+1);
				v.pop_back();
				visited[i]=0;
			}
		}
	}
}
int main(){
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	for(int i=0;i<=k;i++){
		n+="9";
		N+="0";
	}
	for(int i=0;i<10;i++){
		visited[i]=1;
		v.push_back('0'+i);
		go(i,0);
		v.pop_back();
		visited[i]=0;
	}
	cout<<N<<"\n"<<n;
}
