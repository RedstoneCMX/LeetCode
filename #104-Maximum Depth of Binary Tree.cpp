#include<iostream>
using namespace std;
/*这道题是关于二叉树的题，递归思路，也就是DFS的思路，还比较简单。
用一个变量maxdepth记录最大深度，每次二叉树遍历至某一个叶子节点便判断当前记录的depth和maxdepth的值的大小，更新maxdepth即可。
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
	int maxdepth;
public:
    int maxDepth(TreeNode* root) 
    {
        setmaxdepth();
        getmaxdepth(root,0);
        return maxdepth;
    }

    void getmaxdepth(TreeNode* root, int depth)
    {
    	if(root == NULL)
    	{
    		if(depth > maxdepth)
    			maxdepth = depth;
    		return ;
    	}

    	else
    	{
    		depth++;
    		getmaxdepth(root->left,depth);
    		getmaxdepth(root->right,depth);
    		return ;
    	}
    }

    void setmaxdepth()
    {
    	maxdepth = 0;
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
  	int maxdepth = solu.maxDepth(T1);
  	cout << maxdepth << endl;
  	return 0;
}