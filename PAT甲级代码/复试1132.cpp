#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	int n;
	scanf("%d",&n);
	while(n--){
		cin>>str;
	    int a=stoi(str);
	    int b=stoi(str.substr(0,str.size()/2));
	    int c=stoi(str.substr(str.size()/2,str.size()/2));
	    if(b!=0&&c!=0&&a%(b*c)==0) printf("Yes\n");
	    else if(b==0||c==0) printf("No\n");
	    else printf("No\n");
}
	return 0;
}
