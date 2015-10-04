#include<iostream>
using namespace std;
/*这个题还算简单，熟悉链表操作即可，是206题的升级版。
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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
    	if(m == n)
    		return head;
        ListNode* before = head;
        int start = 1;
        while(start++ < m-1)
        	before = before->next;

        ListNode* mbefore;
        ListNode* mhead;
        if(m == 1)
        	mbefore = head;
        else
        	mbefore = before->next;
        mhead = mbefore;
        ListNode* mbehind = mbefore->next;
        int mn = n - m;
        while(mn--)
    	{
    		ListNode* temp = mbehind->next;
    		mbehind->next = mbefore;
    		mbefore = mbehind;
    		mbehind = temp;
    	}

    	if(m == 1)
    	{
    		mhead->next = mbehind;
    		return mbefore;
    	}
    	
		mhead->next = mbehind;
		before->next = mbefore;
    	
    	return head;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	cout << "输入链表整数的个数: " << endl;
	int len;
	cin >> len;
	ListNode l(-1);
	ListNode *prev = &l;
	cout << "输入链表各整数: " << endl;
	for(int i = 0; i < len; i++)
	{
		int num;
		cin >> num;
		prev->next = new ListNode(num);
		prev = prev->next;
	}
	cout << "请输入m: " << endl;
	int m;
	cin >> m;
	cout << "请输入n: " << endl;
	int n;
	cin >> n;
	Solution solu;
	ListNode* result = solu.reverseBetween(l.next,m,n);

	while(result)
	{
		cout << result->val << endl;
		result = result->next;
	}
	return 0;
}