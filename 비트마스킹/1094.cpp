#include<bits/stdc++.h>
using namespace std;
int x;
int bitcount(int x){
	if(x==0){
		return 0;
	}
	return x%2+bitcount(x/2);
}
int main(){
	cin>>x;
	cout<<bitcount(x);
}
