#include<cstdio>
char hh[4]={'W','T','L'};
int bisai[4];
int main(){
	double ans=1.0,x;
	for(int i=0;i<3;i++){
		double max=0;
		for(int j=0;j<3;j++){
			scanf("%lf",&x);
			if(x>max) {
				max=x;
				bisai[i]=j;
		}
	}
	printf("%c ",hh[bisai[i]]);
	ans*=max;
}
	
printf("%.2f",(ans*0.65-1)*2);
return 0;
}
