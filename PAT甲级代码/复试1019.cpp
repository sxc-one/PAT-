#include<cstdio>
int main(){
	char str[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	printf("#");
	int num;
	for(int i=0;i<3;i++){
		scanf("%d",&num);
			printf("%c%c",str[num/13],str[num%13]);
	}
	return 0;
}
