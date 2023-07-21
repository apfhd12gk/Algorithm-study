#include<bits/stdc++.h>
using namespace std;
int n,ret,cnt,d[200004];
string s;
stack<int> stk;
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			stk.push(i);
		}
		else if(stk.size()){
			d[i]=d[stk.top()]=1;
			stk.pop();
		}
	}
	for(int i=0;i<n;i++){
		if(d[i]){
			cnt++;
			ret=max(ret,cnt);
		}else cnt=0;
	}
	cout<<ret;
}
