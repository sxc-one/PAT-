#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
const int maxn=510;
struct Sta{
	double price,dis;
}sta[maxn];
bool cmp(Sta a,Sta b){
	return a.dis<b.dis;
}
int main(){
	int n;
	double cmax,d,davg;
	scanf("%lf%lf%lf%d",&cmax,&d,&davg,&n);
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&sta[i].price,&sta[i].dis);
	}
	sta[n].price=0;
	sta[n].dis=d;
	sort(sta,sta+n+1,cmp);
	if(sta[0].dis!=0) printf("The maximum travel distance = 0.00\n");
	else{
		int now=0;
		double ans=0,nowtank=0,max=cmax*davg;
		while(now<n){
			int k=-1;
			double pricemin=10000;
			for(int i=now+1;i<=n&&sta[i].dis-sta[now].dis<=max;i++){
				if(sta[i].price<pricemin){
					pricemin=sta[i].price;
					k=i;
					if(pricemin<sta[now].price){
						break;
					}
				}
			}
			if(k==-1) break;
			double need=(sta[k].dis-sta[now].dis)/davg;
			if(pricemin<sta[now].price) {
				if(nowtank<need){
					ans+=(need-nowtank)*sta[now].price;
					nowtank=0;
				}else{
					nowtank-=need;
				}
			}else{
				ans+=(cmax-nowtank)*sta[now].price;
				nowtank=cmax-need;
			}
			now=k;
		}
		if(now==n){
			printf("%.2f\n",ans);
		}else{
			printf("The maximum travel distance = %.2f\n",sta[now].dis+max);
		}
	}
	return 0;
} 
