#include<bits/stdc++.h>
using namespace std;
vector<int>temp,ans;
int main(){
	int d,n;
	cin>>d>>n;
	ans.push_back(d);
	for(int x=0;x<n-1;x++){
		temp.clear();
		int i=0;
	    while(i<ans.size()){
	    	temp.push_back(ans[i]);
	    	int len=0,j=i;
		    while(j<ans.size()){
			   if(ans[i]==ans[j]) len++;
			   else break;
			   j++;
		}
		temp.push_back(len);
		i=j;
	}
	ans=temp;
	}
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]);
	}
	return 0;
}
/*#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	string str;
	int n,k;
	cin>>str>>n;
	for(int i=1;i<n;i++){
		string s="";
		for(int j=0;j<str.size();j=k){
			for(k=j;k<str.size()&&str[k]==str[j];k++);
			s+=str[j]+to_string(k-j);
		}
		str=s;
	}
	cout<<str;
	return 0;
}	*/













