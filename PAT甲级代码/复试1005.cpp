#include<cstdio>
#include<cstring>
struct Stu{
	char name[12];
	char pass[12];
	bool flag;
}stu[1010];
void change(Stu &stu,int &count){
	int len=strlen(stu.pass);
	for(int i=0;i<len;i++){
		if(stu.pass[i]=='1'){
			stu.pass[i]='@';
			stu.flag=true;
		}else if(stu.pass[i]=='0'){
			stu.pass[i]='%';
			stu.flag=true;
		}else if(stu.pass[i]=='l'){
			stu.pass[i]='L';
			stu.flag=true;
		}else if(stu.pass[i]=='O'){
			stu.pass[i]='o';
			stu.flag=true;
		}
	}
	if(stu.flag==true) count++;
}
int main(){
	int n,count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s%s",stu[i].name,stu[i].pass);
		change(stu[i],count);
	}
	if(count==0){
		if(n==1){
			printf("There is 1 account and no account is modified");
		}else{
			printf("There are %d accounts and no account is modified",n);
		}
	}else{
		printf("%d\n",count);
		for(int i=0;i<n;i++){
			if(stu[i].flag){
				printf("%s %s\n",stu[i].name,stu[i].pass);
			}
		}
	}
	return 0;
}
