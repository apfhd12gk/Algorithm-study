#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int flag;
		stack<int> stk;
		cin>>s;
		for(int j=0;j<s.size();j++){
			if(s[j]=='('){
				stk.push(s[j]);
			}
			if(s[j]==')'){
				if(stk.size()>0&&stk.top()=='('){
					stk.pop();
				}else stk.push(s[j]);
				
			}
			
		}
		if(stk.size()>0){
			cout<<"NO\n";
		}else cout<<"YES\n";
	}
	
}
