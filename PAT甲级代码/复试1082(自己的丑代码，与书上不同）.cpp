#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
int d[maxn];
char number[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char digit[5][5]={"Shi","Bai","Qian","Wan","Yi"};
int main() {
	int n;
	cin>>n;
	if(n==0){
		cout<<"ling";
		return 0;
	} 
	if(n<0){
		printf("Fu ");
		n=-n;
	}
	int len=0;
	while(n!=0){
		d[len++]=n%10;
		n/=10;
	}
	bool flag=false,wan=false;
	for(int i=len-1;i>=0;i--){
		if(d[i]!=0){
			if(i==4||i==5||i==6||i==7) wan=true;
			if(flag==true){
				printf(" ling");
				flag=false;
			}
			printf("%s%s",i==len-1?"":" ",number[d[i]]);
			if(i%4!=0){
				printf(" %s",digit[i%4-1]);
			}
		}else{
			flag=true;
		}
		if(i%4==0&&i!=0){
			if(i==4&&!wan) continue;
			printf(" %s",digit[i/4+2]);
		}
	}
	return 0;
}

