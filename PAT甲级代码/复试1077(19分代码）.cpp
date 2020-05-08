#include<iostream>
using namespace std;
struct Node{
	string data;
	int left,right;
}node[25]; 
bool notroot[25]={false};
void post(int root){
	if(root==-1) return;
	if(node[root].left==-1&&node[root].right!=-1){
		cout<<"("<<node[root].data;
		post(node[root].right);
		cout<<")";
	}else{
		cout<<"(";
		post(node[root].left);
		post(node[root].right);
		cout<<node[root].data<<")";
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>node[i].data>>node[i].left>>node[i].right;
		if(node[i].left!=-1) notroot[node[i].left]=true;
		if(node[i].right!=-1) notroot[node[i].right]=true;
	}
	int i;
	for(i=1;i<=n;i++){
		if(notroot[i]==false) break;
	}
	post(i);
	return 0;
}
