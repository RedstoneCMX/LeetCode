#include<iostream>
using namespace std;
/*这个题比较朴素的算法就是对于一个二叉树求解左右子树的深度，然后比较两个左右子树的深度是否超过1，如果超过直接返回false。
否则继续判断左子树是否是平衡二叉树，如果不是直接返回false。如果是则继续判断右子树。整个过程都是递归的思想。
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
private:
	int mydepth;
public:
    bool isBalanced(TreeNode* root) 
    {
    	if(root == NULL)
    		return 1;
    	mydepth = 0;
    	getDepth(root->left,0);
    	int depth1 = mydepth;
    	mydepth = 0;
    	getDepth(root->right,0);
    	int depth2 = mydepth;
    	if(abs(depth2 - depth1) > 1)
    		return 0;
    	if(!isBalanced(root->left))
    		return 0;
    	return isBalanced(root->right);

    }

    	
    void getDepth(TreeNode* root, int depth)
    {
    	if(root == NULL)
    		return ;
    	depth++;
    	if(root->left == NULL && root->right == NULL)
    	{
    		if(mydepth < depth)
    		{
    			mydepth = depth;
    			return ;
    		}
    	}
    	else
    	{
    		getDepth(root->left,depth);
    		getDepth(root->right,depth);
    		return ;
    	}

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
    TreeNode* T;
    //引用形式传参
    solu.CreateBiTree(T);

    bool bo = solu.isBalanced(T);

   	cout << bo << endl;
}