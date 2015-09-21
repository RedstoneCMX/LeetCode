#include<iostream>
using namespace std;
/*这个题比较简单，链表翻转的题，熟悉链表操作即可。
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
    ListNode* reverseList(ListNode* head) 
    {
    	if(head == NULL)
    		return head;
        //处理链表，进行翻转
    	ListNode* before = head;
    	ListNode* behind = head->next;
    	before->next = NULL;
    	while(behind)
    	{
    		ListNode* temp = behind->next;
    		behind->next = before;
    		before = behind;
    		behind = temp;
    	}

    	return before;
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
	ListNode* result = solu.reverseList(l.next);

	while(result)
	{
		cout << result->val << endl;
		result = result->next;
	}
	return 0;
}