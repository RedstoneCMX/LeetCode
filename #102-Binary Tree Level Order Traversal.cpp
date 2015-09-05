#include<iostream>
#include<vector>
using namespace std;
/*这道题是关于二叉树的题，递归思路，其实就是深度优先搜索DFS。
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
	vector<vector<int> > lorder;
public:
    vector<vector<int> > levelOrder(TreeNode* root) 
    {
        getorder(root,0);
        return lorder;
    }

    void getorder(TreeNode* T, int level)
    {
    	if(T == NULL)
    		return ;
    	if(level == lorder.size())
    	{
    		vector<int> v;
    		lorder.push_back(v);
    	}

    	lorder[level].push_back(T->val);
    	getorder(T->left,level + 1);
    	getorder(T->right,level + 1);
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
  	vector<vector<int> > lo;
  	lo = solu.levelOrder(T1);
  	
  	int size = lo.size();
  	for(int i = 0; i < size; i++)
  	{
  		int size2 = lo[i].size();
  		for(int j = 0; j < size2; j++)
  			cout << lo[i][j] << " ";
  		cout << endl;
  	}
}