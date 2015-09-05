#include<iostream>
using namespace std;
/*这道题是关于二叉树的题，非常基础的题，递归思路。这道题主要就是熟悉二叉树的相关操作，这里给出了一个前序输入二叉树的函数。
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
	public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL && q == NULL)
        	return 1;
        if((p == NULL && q != NULL) || (p != NULL && q == NULL))
        	return 0;
        if(p->val == q->val)
        {
        	if(isSameTree(p->left,q->left))
        		return isSameTree(p->right,q->right);
        	else
        		return 0;
        }
        else
        	return 0;
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

    //指针形式传参
    /*
    void CreateBiTree(TreeNode* *T)//树的初始化
    {
       int val;
       cin >> val;
       if(val == -1)
        (*T) = NULL;
       else
       {
           (*T) = new TreeNode(val);
           CreateBiTree(&((*T)->left));
           CreateBiTree(&((*T)->right));
       }
    }*/
};

/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	Solution solu;
    TreeNode* T1, *T2;
    //引用形式传参
    solu.CreateBiTree(T1);
    solu.CreateBiTree(T2);
    //指针形式传参
    //solu.CreateBiTree(&T1);
    //solu.CreateBiTree(&T2);

    bool bo = solu.isSameTree(T1, T2);
    cout << bo << endl;

}