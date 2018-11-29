#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 35;
int post[maxn], in[maxn];
int n;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data){
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

Node* createTree(int postL, int postR, int inL, int inR){
	if (postL > postR)
	{
		return NULL;
	}
	int k = inL;
	for (; k <= inR; k++)
	{
		if (in[k] == post[postR])
		{
			break;
		}
	}
	Node* root = createNode(post[postR]);
	int leftNum = k - inL;
	root->left = createTree(postL, postL + leftNum - 1, inL, k - 1);
	root->right = createTree(postL + leftNum, postR - 1, k + 1, inR);
	return root;
}

void clearTree(Node* root){
	if (root->left != NULL)
	{
		clearTree(root->left);
	}
	if (root->right != NULL)
	{
		clearTree(root->right);
	}
	delete root;
	root = NULL;
}

int main(){

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}
	Node* root = createTree(0, n - 1, 0, n - 1);

	queue<Node*> q;
	q.push(root);
	int num = 0;
	while (!q.empty())
	{
		Node* now = q.front();
		q.pop();
		num++;
		printf("%d", now->data);
		if (num < n)
		{
			printf(" ");
		}
		if (now->left != NULL)
		{
			q.push(now->left);
		}
		if (now->right != NULL)
		{
			q.push(now->right);
		}
	}
	clearTree(root);
	return 0;
}