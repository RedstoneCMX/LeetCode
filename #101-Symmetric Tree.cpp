#include<iostream>
using namespace std;
/*这道题是关于二叉树的题，判断一棵二叉树是否是对称二叉树，非常基础的题，递归思路。
*/
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*************************在leetcode上直接提交以下代码即可******************************/ 
class Solution 
{
	public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
        	return 1;   	
       	return check(root->left,root->right);
  	}

    bool check(TreeNode *leftNode, TreeNode *rightNode)
    {
    	if(leftNode == NULL && rightNode == NULL)
    		return 1;
    	else if(leftNode != NULL && rightNode != NULL)
        {
        	if(leftNode->val == rightNode->val)
        	{
        		if(check(leftNode->left,rightNode->right))
        			return check(leftNode->right,rightNode->left);
        		else
        			return 0;
        	}
        	else
        		return 0;
        		
        }

        return 0;
    }


    //这个是前序输入二叉树，代码提交时这个函数不必提交，这里只是为了测试方便
    //引用形式传参
    void CreateBiTree(TreeNode* &T)//树的初始化
    {
       int val;
       cin >> val;
       //假设-1为空节点
       if(val == -1)
        T = NULL;
       else
       {
           T = new TreeNode(val);
           CreateBiTree(T->left);
           CreateBiTree(T->right);
       }
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	Solution solu;
    TreeNode* T1;
    //引用形式传参
    solu.CreateBiTree(T1);

    bool bo = solu.isSymmetric(T1);
    cout << bo << endl;
}