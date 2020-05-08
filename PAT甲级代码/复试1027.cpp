#include<cstdio>
int main(){
	int x,y,z,x1,y1,z1;
	int carry=0;
	scanf("%d.%d.%d %d.%d.%d",&x,&y,&z,&x1,&y1,&z1);
	z=z+z1;
	carry=z/29;
	z1=z%29;
	y=y+y1+carry;
	carry=y/17;
	y1=y%17;
	x1=x+x1+carry;
	printf("%d.%d.%d",x1,y1,z1);
	return 0;
}
