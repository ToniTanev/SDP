#ifndef __VECTORFORTREE_H
#define __VECTORFORTREE_H

#include <vector>

using Vector = std::vector<TreeNode*>;

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode() {left = nullptr; right = nullptr;}
	TreeNode(int _data, TreeNode* _left, TreeNode* _right) : data(_data), left(_left), right(_right) {}
}

void createVector(TreeNode*& curr, Vector& res)
{
	if(curr == nullptr)
	{
		return;
	}

	res.push_back(curr);
	createVector(curr->left, res);
	createVector(curr->right, res);
}

void sortVector(Vector& v)
{
	for(int i = 0; i < v.size() - 1; i++)
		for(int j = i + 1; j < v.size(); j++)
		{
			if(v[i]->data < v[j]->data)
			{
				TreeNode* tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
}

#endif