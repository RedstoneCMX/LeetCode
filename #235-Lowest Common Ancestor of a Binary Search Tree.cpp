#include<iostream>
using namespace std;
/*这个题比较简单，是关于二叉搜索树的题目，查找任意两个节点的最近的祖先。
根据二叉搜索树的特点，左子树的数小于根节点的数，根节点的数小于右子树的数，使用递归思路，只需要判断当前根节点的值和需要判断的两个节点的值大小即可：
1.若根节点值都大于p和q节点的值，那么将根节点的左子树作为下一次查找的根节点继续查找。
2.若根节点值都小于p和q节点的值，那么将根节点的右子树作为下一次查找的根节点继续查找。
3.否则就说明p和q分别在当前根节点的左右两侧，则此时的根节点就是最近的祖先了。
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
	TreeNode* lca;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        getlowestCommonAncestor(root, p, q);
        return lca;
    }

    void getlowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
    	if(root == NULL)
    		return ;
    	if(root->val > p->val && root->val > q->val)
    	{
    		getlowestCommonAncestor(root->left, p, q);
    	}
    	else if(root->val < p->val && root->val < q->val)
    	{
    		getlowestCommonAncestor(root->right, p, q);
    	}
    	else
    	{
    		lca = root;
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
    
    TreeNode* lca = solu.lowestCommonAncestor(T,T->left,T->right);

    return 0;
}