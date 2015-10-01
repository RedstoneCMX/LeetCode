#include<iostream>
using namespace std;
/*这道题是关于二叉树的题，递归思路，其实就是深度优先搜索DFS。
和102题类似，我这里就是将102题的思路搬过来了，然后对将数组反过来输出到另一个数组中。似乎这样不妥，应该还有其他方法。
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        getorder(root,0);
        vector<vector<int> > lorderb;
        int size = lorder.size();
        for(int i = size-1; i >= 0; i--)
        {
        	lorderb.push_back(lorder[i]);
        }

        return lorderb;
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
  	lob = solu.levelOrderBottom(T1);
  	
  	int size = lob.size();
  	for(int i = 0; i < size; i++)
  	{
  		int size2 = lob[i].size();
  		for(int j = 0; j < size2; j++)
  			cout << lob[i][j] << " ";
  		cout << endl;
  	}
}