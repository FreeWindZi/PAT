#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;

int n;
int pre[maxn] = { 0 }, in[maxn] = { 0 };

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* createTree(int preL, int preR, int inL, int inR){
	if (preL > preR)
	{
		return NULL;
	}

	int k = inL;
	for (; k <= inR; k++)
	{
		if (in[k] == pre[preL])
		{
			break;
		}
	}
	int leftNum = k - inL;
	Node* root = new Node;
	root->data = pre[preL];
	root->left = createTree(preL + 1, preL + leftNum , inL, k - 1);
	root->right = createTree(preL + leftNum + 1, preR, k + 1, inR);
	return root;
}

Node* createMirrorTree(int preL, int preR, int inL, int inR){
	if (preL > preR)
	{
		return NULL;
	}

	int k = inL;
	for (; k <= inR; k++)
	{
		if (in[k] == pre[preL])
		{
			break;
		}
	}
	int leftNum = k - inL;
	Node* root = new Node;
	root->data = pre[preL];
	root->left = createMirrorTree(preL + leftNum + 1, preR, k + 1, inR);
	root->right = createMirrorTree(preL + 1, preL + leftNum, inL, k - 1);
	
	return root;
}

int num = 0;
bool tree = true;
void judgeTree(Node* root){
	if (root == NULL)
	{
		return;
	}

	if (root->data != pre[num++])
	{
		tree = false;
		return;
	}
	judgeTree(root->left);
	judgeTree(root->right);
}

void postOrder(Node* root){

	if (root == NULL)
	{
		return;
	}
	postOrder(root->left);
	postOrder(root->right);

	printf("%d", root->data);
	num++;
	if (num < n)
	{
		printf(" ");
	}

}

int main(){


	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &pre[i]);
		in[i] = pre[i];
	}
	sort(in, in + n);
	Node* root = createTree(0, n - 1, 0, n - 1);
	judgeTree(root);
	if (tree)
	{
		printf("YES\n");
		num = 0;
		postOrder(root);
		return 0;
	}
	Node* mirrorRoot = createMirrorTree(0, n - 1, 0, n - 1);
	num = 0;
	judgeTree(mirrorRoot);
	if (tree)
	{
		printf("YES\n");
		num = 0;
		postOrder(mirrorRoot);
		return 0;
	}

	printf("NO");
	return 0;
}