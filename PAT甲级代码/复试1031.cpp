#include<cstdio>
#include<cstring>
int main(){
	bool flag=true;
    int n,b,num[40],count=0;
    scanf("%d%d",&n,&b);
    while(n!=0){
    	num[count++]=n%b;
    	n/=b;
	}
	for(int i=0;i<=count/2;i++){
		if(num[i]!=num[count-i-1]){
			flag=false;
			break;
		}
	}
	if(flag==true) printf("Yes\n");
	else printf("No\n");
	for(int i=count-1;i>=0;i--){
		printf("%d",num[i]);
		if(i!=0) printf(" ");
	}
	return 0;
}
