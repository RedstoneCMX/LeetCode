#include<iostream>
#include<vector>
using namespace std;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution 
{
private:
	vector<int> preordertree;
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        getpreorder(root);
        return preordertree;
    }

    void getpreorder(TreeNode* root)
    {
    	if(root == NULL)
    		return ;
    	preordertree.push_back(root->val);
    	getpreorder(root->left);
    	getpreorder(root->right);
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
int main()
{
	Solution solu;
    TreeNode* T;
    //引用形式传参
    solu.CreateBiTree(T);

    vector<int> preordertree;
    preordertree = solu.preorderTraversal(T);

    int size = preordertree.size();
    for(int i = 0; i < size; i++)
    	cout << preordertree[i] << endl;
    return 0;
}