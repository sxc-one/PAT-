#include<cstdio>
#include<cstring>
const int maxn=1010;
double e[maxn];
int main(){
	int count=0;
	memset(e,0,sizeof(e));
	int n,exp;
	double co;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%lf",&exp,&co);
		e[exp]+=co;
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%lf",&exp,&co);
		e[exp]+=co;
	}
	for(int i=0;i<maxn;i++){
		if(e[i]!=0) count++;
	}
	printf("%d",count);
	for(int i=1000;i>=0;i--){
		if(e[i]!=0) printf(" %d %.1f",i,e[i]);
	}
	return 0;
}
