#include<cstdio>
struct Student{
	char name[11];
	char id[11];
	char gender;
	int grade;
}stu[105];
int main(){
	int n,min=-1,max=110,x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %c %s %d",stu[i].name,&stu[i].gender,stu[i].id,&stu[i].grade);
		if(stu[i].gender=='F'){
			if(stu[i].grade>min){
				min=stu[i].grade;
				x=i;
			}
		}else{
			if(stu[i].grade<max){
				max=stu[i].grade;
				y=i;
			}
		}
	}
	if(min!=-1) printf("%s %s\n",stu[x].name,stu[x].id);
	else printf("Absent\n");
	if(max!=110) printf("%s %s\n",stu[y].name,stu[y].id);
	else printf("Absent\n");
	if(min==-1||max==110) printf("NA\n");
	else printf("%d",stu[x].grade-stu[y].grade);
	return 0;
}
