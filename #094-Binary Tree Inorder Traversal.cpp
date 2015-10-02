#include<iostream>
#include<vector>
using namespace std;
/*这个题就是求解二叉树的中序遍历。
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
	vector<int> inordertree;
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        getinorder(root);
        return inordertree;
    }

    void getinorder(TreeNode* root)
    {
    	if(root == NULL)
    		return ;
    	getinorder(root->left);
    	inordertree.push_back(root->val);
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

    vector<int> inordertree;
    inordertree = solu.inorderTraversal(T);

    int size = inordertree.size();
    for(int i = 0; i < size; i++)
    	cout << inordertree[i] << endl;
    return 0;
}