#include<iostream>
using namespace std;
/*这道题是链表操作的题，比较简单。但是这里有一个疑问，链表或者二叉树初始化时，
通过传参至一个函数或方法中去初始化，到底传参传普通参数还是引用或指针的指针呢？好像直接传指针的普通参数也可以啊。
*/
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    void deleteNode(ListNode* node) 
    {
        int nextval = node->next->val;
        node->val = nextval;
        node->next = node->next->next;
        return ;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
    cout << "输入链表整数的个数: " << endl;
    int n;
    cin >> n;
    ListNode *l = new ListNode(-1);
    ListNode *prev = l;
    cout << "输入链表各整数: " << endl;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        prev->next = new ListNode(num);
        prev = prev->next;
    }

    cout << "输入节点位置: " << endl;
    int k;
    cin >> k;
    ListNode* node = l;
    while(k--)
        node = node->next;

    Solution solu;
    solu.deleteNode(node);

    l = l->next;
    while(l != NULL)
    {
        cout << l->val << endl;
        l = l->next;
    }
}