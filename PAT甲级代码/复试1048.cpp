#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
const int maxn=1010;
struct Moon{
	double kucun;
	double price,danjia;
}moon[maxn];
bool cmp(Moon a,Moon b){
	return a.danjia>b.danjia;
}
int main(){
	int n;
	double d;
	scanf("%d%lf",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%lf",&moon[i].kucun);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&moon[i].price);
		moon[i].danjia=moon[i].price/moon[i].kucun;
	}
	sort(moon,moon+n,cmp);
	double ans=0;
	for(int i=0;i<n;i++){
		if(moon[i].kucun>=d) {
			ans+=d/moon[i].kucun*moon[i].price;
			break;
		}
		else{
			ans+=moon[i].price;
			d-=moon[i].kucun;
		}
	}
	printf("%.2f",ans);
	return 0;
} 
