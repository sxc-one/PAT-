#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
struct Node{
	int lchild,rchild;
}node[maxn];
bool notroot[maxn];
int n,last;
bool BFS(int root){
	queue<int>q;
	q.push(root);
	while(n){
		int now=q.front();
		q.pop();
		if(now==-1) return false;
		n--;
		last=now;
		q.push(node[now].lchild);
		q.push(node[now].rchild);
	}
	return true;
}
int change(char str[]){
	int i=0,len=strlen(str),id=0;
	if(str[0]=='-') return -1;
	while(i<len){
		id=id*10+str[i]-'0';
		i++;
	}
	return id;
}
int main(){
	int root,lchild,rchild;
	char l[5],r[5];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %s",l,r);
		lchild=change(l);
		node[i].lchild=lchild;
	    notroot[lchild]=true;
		rchild=change(r);
		node[i].rchild=rchild;
		notroot[rchild]=true;
	}
	for(int i=0;i<n;i++){
		if(notroot[i]==false){
			root=i;
			break;
		}
	}
	bool flag=BFS(root);
	if(flag==false)printf("NO %d",root);
	else printf("YES %d",last);
	return 0;
}

