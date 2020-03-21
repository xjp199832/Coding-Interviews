//题目描述
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{ 1,2,4,7,3,5,6,8 }和中序遍历序列{ 4,7,2,1,5,3,8,6 }，则重建二叉树并返回。


#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



//思路：前序遍历第一个值是根节点，然后从后序遍历找到根节点位置，左边的数字是左子树，右边的数字是右子树。前序遍历紧跟着根节点的是左子树，后面的是右子树。这样分开了左右子树之后利用递归分别从左右子树中重复上述过程。
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int vinLength = vin.size();
		if (!vinLength)
			return NULL;

		vector<int> preLeft, vinLeft, preRight, vinRight;

		TreeNode* root = new TreeNode(pre[0]);

		int rootInorder = -1;
		for (int i = 0; i < vinLength; i++)
		{
			if (pre[0] == vin[i])
			{
				rootInorder = i;
				break;
			}
		}

		for (int i = 0; i < rootInorder; i++)
		{
			vinLeft.push_back(vin[i]);
			preLeft.push_back(pre[i + 1]);
		}

		for (int i = rootInorder + 1; i < vinLength; i++)
		{
			vinRight.push_back(vin[i]);
			preRight.push_back(pre[i]);
		}

		root->left = reConstructBinaryTree(preLeft, vinLeft);
		root->right = reConstructBinaryTree(preRight, vinRight);

		return root;
	}


	//TreeNode* ConstructTree(vector<int>::iterator preStart, vector<int>::iterator preEnd, vector<int>::iterator vinStart, vector<int>::iterator vinEnd)
	//{
	//	//前序遍历的第一个值是根节点的值
	//	int rootValue = *preStart;
	//	TreeNode* root = new TreeNode(rootValue);

	//	if (preStart == preEnd && vinStart == vinEnd && *preStart == *vinStart)
	//	{
	//		return root;
	//	}

	//	vector<int>::iterator vinRoot = vinStart;
	//	while (vinRoot <= vinEnd && *vinRoot != rootValue)
	//		++vinRoot;

	//	int leftLength = vinRoot - vinStart;
	//	vector<int>::iterator leftPreEnd = preStart + leftLength;
	//	if (leftLength > 0)
	//		root->left = ConstructTree(preStart + 1, leftPreEnd, vinStart, vinRoot - 1);
	//	if (leftLength < preEnd - preStart)
	//		root->right = ConstructTree(leftPreEnd + 1, preEnd, vinRoot + 1, vinEnd);
	//	return root;
	//}
};