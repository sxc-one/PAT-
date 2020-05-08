#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
int z1[maxn],z2[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int nc,np;
	scanf("%d",&nc);
	for(int i=0;i<nc;i++){
		scanf("%d",&z1[i]);
	}
	scanf("%d",&np);
	for(int i=0;i<np;i++){
		scanf("%d",&z2[i]);
	}
	int ans=0;
	sort(z1,z1+nc,cmp);
	sort(z2,z2+np,cmp);
	for(int i=0;i<nc&&i<np;i++){
		if(z1[i]>0&&z2[i]>0) ans+=z1[i]*z2[i];
	}
	sort(z1,z1+nc);
	sort(z2,z2+np);
	for(int i=0;i<nc&&i<np;i++){
		if(z1[i]<0&&z2[i]<0) ans+=z1[i]*z2[i];
	}
	printf("%d\n",ans);
	return 0;
}
