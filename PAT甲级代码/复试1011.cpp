#include<cstdio>
char id[100010][16];
int min=0,max=10000000;
int main(){
	int n,hh,mm,ss,x,y,time;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s%d:%d:%d",id[i],&hh,&mm,&ss);
		time=hh*3600+mm*60+ss;
		if(time<max) {
			max=time;
			x=i;
		}
		scanf("%d:%d:%d",&hh,&mm,&ss);
		time=hh*3600+mm*60+ss;
		if(time>min) {
			min=time;
			y=i;
		}
	}
	printf("%s %s",id[x],id[y]);
	return 0;
}
