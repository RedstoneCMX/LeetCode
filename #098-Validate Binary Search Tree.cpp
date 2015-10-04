#include<iostream>
#include<vector>
using namespace std;
/*这个题比较简单，其实就是对二叉树进行中序遍历，如果是二叉搜索树，那么中序遍历得到的序列肯定是升序排列的。
因此得到中序序列之后只需要判断该序列是否是升序排列即可。
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
	vector<int> getbst;
public:
    bool isValidBST(TreeNode* root) 
    {
        getinorder(root);
        int size = getbst.size();
        for(int i = 0; i < size-1; i++)
        {
        	if(getbst[i] >= getbst[i+1])
        		return 0;
        }

        return 1;
    }

    void getinorder(TreeNode* root)
    {
    	if(root == NULL)
    		return ;
    	getinorder(root->left);
    	getbst.push_back(root->val);
    	getinorder(root->right);
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
    TreeNode* T;
    //引用形式传参
    solu.CreateBiTree(T);

  	bool bo = solu.isValidBST(T);
  	cout << bo << endl;
    return 0;
}