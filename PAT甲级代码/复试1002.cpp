#include<cstdio>
struct poly{
	int exp;
	double co;
}poly[1001];
double ans[2001];
int main(){
	int count=0;
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%lf",&poly[i].exp,&poly[i].co);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int exp;
		double co;
		scanf("%d%lf",&exp,&co);
		for(int j=0;j<n;j++){
			ans[exp+poly[j].exp]+=co*poly[j].co;
		}
	}
	for(int i=0;i<2001;i++){
		if(ans[i]!=0) count++;
	}
	printf("%d",count);
	for(int i=2000;i>=0;i--){
		if(ans[i]!=0) printf(" %d %.1f",i,ans[i]);
	}
	return 0;
}
