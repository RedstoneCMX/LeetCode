#include<iostream>
using namespace std;
/*这道题是链表操作的题，就是删除指定值的节点，比较简单。为方便起见，在链表头部添加了一个额外的节点-1。
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
    ListNode* removeElements(ListNode* head, int val) 
    {
    	if(head == NULL)
    		return head;
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        ListNode* before = prev;
        ListNode* behind = prev->next;
        while(behind != NULL)
        {
        	if(behind->val == val)
        	{
        		before->next = behind->next;
        		behind = before->next;
        	}
        	else
        	{
        		before = behind;
        		behind = behind->next;
        	}
        }

        return prev->next;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	cout << "输入链表整数的个数: " << endl;
	int n;
	cin >> n;
	ListNode l(-1);
	ListNode *prev = &l;
	cout << "输入链表各整数: " << endl;
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		prev->next = new ListNode(num);
		prev = prev->next;
	}

	cout << "输入val值: " << endl;
	int val;
	cin >> val;
	Solution solu;
	ListNode *result = solu.removeElements(l.next, val);

	while(result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
}