#include<bits/stdc++.h>
using namespace std;
int cnt=1,n,num=666;
string s;
int main(){
	cin>>n;
	while(true){
		if(n==cnt)break;
		num++;
		s=to_string(num);
		if(s.find("666")!=string::npos){
			cnt++;
		}
		
		
	}
	cout<<num;
}
