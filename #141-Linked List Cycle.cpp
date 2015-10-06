#include<iostream>
using namespace std;
/*这个题要求不能开额外的空间，即空间复杂度是o(1)。
该问题是经典面试问题，其标准解法是用两个指针，一快一慢，如果在快的指针能够追上慢的指针，则有环，否则无环。
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
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL)
        	return false;
        ListNode* fast;
        ListNode* slow;

        slow = head;
        fast = head->next;
        while(true)
        {
        	if(fast == NULL)
        		return false;
        	fast = fast->next;
        	if(fast == NULL)
        		return false;
        	if(fast == slow)
        		return true;
        	fast = fast->next;
        	if(fast == NULL)
        		return false;
        	if(fast == slow)
        		return true;
        	slow = slow->next;

        	if(fast == slow)
        		return true;
        }
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

	
	Solution solu;
	bool bo = solu.hasCycle(l.next);

	cout << bo << endl;
	return 0;
}