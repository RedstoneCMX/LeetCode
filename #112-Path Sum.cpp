#include<iostream>
using namespace std;
/*这道题是关于二叉树的题，递归思路，也就是DFS的思路。
这里递归需要判断的是左右子树都为空的时候才是叶子节点，才能进行sum的最终判断。
这道题和257题求解二叉树的路径类似。
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
	int mysum;
	bool bo;
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
    	mysum = sum;
    	bo = false;
    	getpathsum(root,0);
    	return bo;
    }

    void getpathsum(TreeNode* root, int getsum)
    {
    	if(root == NULL || bo)
    		return ;
   		
   		getsum += root->val;
		if(root->left == NULL && root->right == NULL)
		{
			if(getsum == mysum)
			{
				bo = true;
				return ;
			}
				
		}
		else
		{
			getpathsum(root->left,getsum);
			getpathsum(root->right,getsum);
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

    cout << "请输入sum: " << endl;
    int sum;
    cin >> sum;
    bool bo = solu.hasPathSum(T,sum);

   	cout << bo << endl;
}