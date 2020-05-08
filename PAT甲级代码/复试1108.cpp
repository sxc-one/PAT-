#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,num=0;
	char s[100],ss[100];
	double ans=0,k;
	scanf("%d",&n);
	while(n--){
		cin>>s;
		sscanf(s,"%lf",&k);
		sprintf(ss,"%.2f",k);
		bool flag=true;
		for(int i=0;s[i]!='\0';i++){
			if(s[i]!=ss[i]){
				flag=false;
				break;
			}
		}
		if(flag==false||k<-1000||k>1000) printf("ERROR: %s is not a legal number\n",s);
		else{
			num++;
			ans+=k;
		}
	}
	if(num==0)
        printf("The average of 0 numbers is Undefined");
    else if(num==1)
        printf("The average of 1 number is %.2f",ans);
        else printf("The average of %d numbers is %.2f",num,ans/num);
    return 0;
}
