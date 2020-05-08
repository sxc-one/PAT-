#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxn=10010;
string str[maxn];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	sort(str,str+n);
	for(int i=0;i<n-1;i++){
		if((str[i]+str[i+1])>(str[i+1]+str[i])){
			swap(str[i],str[i+1]);
		}
	}
	string ans;
	for(int i=0;i<n;i++){
		ans+=str[i];
	}
	while(ans.size()!=0&&ans[0]=='0'){
		ans.erase(ans.begin());
	}
	if(ans.size()==0) cout<<'0'<<endl;
	else cout<<ans<<endl;
	return 0;
}
