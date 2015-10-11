#include<iostream>
using namespace std;
/*这道题如果想到了是很简单的，总是想不到如此好的方法。还是水平不行啊。
DFS的思路，主要是借助root->next来处理5->6的情况。
     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL
*/
struct TreeLinkNode 
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
/*************************在leetcode上直接提交以下代码即可******************************/ 
class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
        if(root == NULL)
        	return ;
        if(root->left != NULL)
        	root->left->next = root->right;
        // 借助root->next处理5连6的情况
        if(root->right != NULL && root->next != NULL)
        	root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
    }

    //这个是前序输入二叉树，代码提交时这个函数不必提交，这里只是为了测试方便
    //引用形式传参
    void CreateBiTree(TreeLinkNode* &T)//树的初始化
    {
       int val;
       cin >> val;
       //假设-1为空节点
       if(val == -1)
        T = NULL;
       else
       {
           T = new TreeLinkNode(val);
           CreateBiTree(T->left);
           CreateBiTree(T->right);
       }
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	Solution solu;
    TreeLinkNode* T;
    //引用形式传参
    solu.CreateBiTree(T);

  	solu.connect(T);

}