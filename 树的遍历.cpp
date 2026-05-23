#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

void pre(TreeNode* root){
	if(root==nullptr){
		return;
	}
	cout<<root->val<<" ";
	pre(root->left);
	pre(root->right);
}

int main()
{
	
	return 0;
}