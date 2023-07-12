#include<bits/stdc++.h>
using namespace std;
int N,K,ret;
int check[52];
string s;
int count(int mask){
	int cnt=0;
	for(int word:check){
		if(word&&(word&mask)==word){
			cnt++;
		}
	}
	return cnt;
}
int go(int idx, int k, int mask){
	if(k<0) return 0;
	if(idx==26) return count(mask);
	int ret=go(idx+1,k-1,mask|(1<<idx));
	if(idx!='a'-'a'&&idx!='n'-'a'&&idx!='t'-'a'&&idx!='i'-'a'&&idx!='c'-'a'){
		ret=max(ret,go(idx+1,k,mask));
	}
	return ret;
}
int main(){
	cin>>N>>K;

	for(int i=0;i<N;i++){
		cin>>s;
		for(int j=0;j<s.size();j++){
			check[i]|=1<<(int)(s[j]-'a');
		}
	}
	
	cout<<go(0,K,0);
}


