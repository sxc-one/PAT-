#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 50;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
int pre[maxn], post[maxn];    // ���򡢺���
int n;      // ������
bool isUnique = true;   // �������Ƿ�Ψһ

// ��ǰ��������������������Ϊ[preL, preR]��������������Ϊ[postL, postR]
// create�������ع������Ķ������ĸ�����ַ
node* create(int preL, int preR, int postL, int postR) {
    if(preL > preR) {
        return NULL;    // ����
    }
    node* root = new node;
    root->data = pre[preL];     // �����
    // �ں����������ҵ��������еĵڶ������,���±�Ϊk;numLeftΪ(��)����������
    int k, numLeft = 0;
    for(k = postL; k < postR; k++) {
        numLeft++;      // (��)������������1
        if(post[k] == pre[preL + 1]) {      // �ں����������ҵ��������еĵڶ������
            break;
        }
    }
    if(k == postR - 1) isUnique = false;    // ����ڶ��������ں������ڶ������,˵����Ψһ
    root->lchild = create(preL + 1, preL + numLeft, postL, k);      // ����������
    root->rchild = create(preL + numLeft + 1, preR, k + 1, postR - 1);      // ����������
    return root;    // ���ظ����
}
vector<int> in;     // ����
void inOrder(node* root) {      // �������
    if(!root) return;
    inOrder(root->lchild);
    in.push_back(root->data);   // ��������������
    inOrder(root->rchild);
}
int main() {
    scanf("%d", &n);    // ���������
    for(int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);   // ��������
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &post[i]);  // �������
    }
    node* root = create(0, n - 1, 0, n - 1);    //����
    inOrder(root);  // ��ȡ��������
    printf(isUnique ? "Yes\n" : "No\n");    // �����Ƿ�Ψһ��������Yes��No
  /*  for(int i = 0; i < in.size(); i++) {    // �����������
        printf("%d", in[i]);
        printf((i + 1 < in.size()) ? " " : "\n");   // �������һ���������,��������ո�
    }*/
    printf("%d",root->data);
    return 0;
}
