#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
/*这道题是关于二叉树的题，递归思路，也就是DFS的思路，最近写这种二叉树的DFS写的有点顺。
这里递归需要判断的是左右子树都为空的时候才是叶子节点，才能将路径添加至最终的结果路径容器中去。
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
	vector<string> btp;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
        	return btp;
        getbinarytreepaths(root,"");
        return btp;
    }

    void getbinarytreepaths(TreeNode* root, string str)
    {
    	if(root == NULL)
    		return ;

    	stringstream sstr;
		sstr << root->val;
		if(str == "")
			str = sstr.str();
		else
		{
			str += "->";
			str += sstr.str();
		}

    	if(root->left == NULL && root->right == NULL)
    	{

    		btp.push_back(str);
    		return;
    	}
    	else
    	{    		
    		getbinarytreepaths(root->left,str);
    		getbinarytreepaths(root->right,str);
    		
    	}

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
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	Solution solu;
  	TreeNode* T1;
  	//引用形式传参
  	solu.CreateBiTree(T1);
  	vector<string> btp = solu.binaryTreePaths(T1);
  	int size = btp.size();
  	for(int i = 0; i < size; i++)
  		cout << btp[i] << endl;
  	return 0;
}