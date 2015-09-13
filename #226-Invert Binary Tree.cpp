#include<iostream>
using namespace std;
/*这道题是关于二叉树的题，左右倒置二叉树，非常基础的题，递归思路，交换左右子树。
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
    TreeNode* invertTree(TreeNode* root) 
    {
        getinvertTree(root);
        return root;
    }

    void getinvertTree(TreeNode* &root)
    {
    	if(root == NULL)
    		return ;
    	TreeNode* tempnode = root->left;
    	root->left = root->right;
    	root->right = tempnode;

    	getinvertTree(root->left);
    	getinvertTree(root->right);
    	return ;
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
    //这个是前序遍历输出二叉树，代码提交时这个函数不必提交，这里只是为了测试方便
    void preorder(TreeNode* T)
    {
    	if(T == NULL)
    		return ;
    	cout << T->val << " ";
    	preorder(T->left);
    	preorder(T->right);
    	return ;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	Solution solu;
    TreeNode* T1;
    //引用形式传参
    solu.CreateBiTree(T1);

    TreeNode* invertt = solu.invertTree(T1);

   	solu.preorder(invertt);
   	cout << endl;
}