#include<iostream>
using namespace std;
/*这道题是关于二叉树的题，递归思路，也就是DFS的思路。
这里递归需要判断的是左右子树都为空的时候才是叶子节点，才能进行depth的最终判断。
这道题和112,257题类似。
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
	int mindepth;
public:
    int minDepth(TreeNode* root) 
    {
    	if(root == NULL)
    		return 0;
    	mindepth = 0x7fffffff;
        getminDepth(root,0);
        return mindepth;
    }

    void getminDepth(TreeNode* root, int depth)
    {
    	if(root == NULL)
    		return ;
    	depth++;
    	if(root->left == NULL && root->right == NULL)
    	{
    		if(mindepth > depth)
    		{
    			mindepth = depth;
    			return ;
    		}
    	}
    	else
    	{
    		getminDepth(root->left,depth);
    		getminDepth(root->right,depth);
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
  	int mindepth = solu.minDepth(T);
  	cout << mindepth << endl;
  	return 0;
}