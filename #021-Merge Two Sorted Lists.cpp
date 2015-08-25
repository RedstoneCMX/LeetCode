#include<iostream>
using namespace std;
/*这又是一道关于链表的题，就是合并排序，比较简单。
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode mergeresult(-1);
    	ListNode *prev = &mergeresult;
    	while(l1 != NULL && l2 != NULL)
    	{
    		if(l1->val > l2->val)
    		{
    			prev->next = new ListNode(l2->val);
    			prev = prev->next;
    			l2 = l2->next;
    		}
    		else if(l1->val < l2->val)
    		{
    			prev->next = new ListNode(l1->val);
    			prev = prev->next;
    			l1 = l1->next;
    		}
    		else
    		{
    			prev->next = new ListNode(l1->val);
    			prev = prev->next;
    			prev->next = new ListNode(l2->val);
    			prev = prev->next;
    			l1 = l1->next;
    			l2 = l2->next;
    		}
    	}

    	while(l1 != NULL)
    	{
    		prev->next = new ListNode(l1->val);
			prev = prev->next;
			l1 = l1->next;
    	}

    	while(l2 != NULL)
    	{
    		prev->next = new ListNode(l2->val);
			prev = prev->next;
			l2 = l2->next;
    	}

    	return mergeresult.next;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/ 
int main()
{
	int n1 = 0, n2 = 0;
	ListNode l1(-1), l2(-1);
	cout << "请输入链表1的整数个数："<<endl;
	cin >> n1;
	cout<<"请输入链表1的所有整数："<<endl;
	ListNode *prev1 = &l1;
	for(int i = 0; i < n1; i++)
	{
		int temp;
		cin >> temp;
		prev1->next = new ListNode(temp);
		prev1 = prev1->next;
		
	}

	ListNode *pl1 = l1.next;

	cout<<"请输入链表2的整数个数："<<endl;
	cin >> n2;
	cout<<"请输入链表2的所有整数："<<endl;
	ListNode *prev2 = &l2;
	for(int i =0; i < n2; i++)
	{
		int temp;
		cin >> temp;
		prev2->next = new ListNode(temp);
		prev2 = prev2->next;
	}

	ListNode *pl2 = l2.next;

	Solution solu;
	ListNode *mergeresult = solu.mergeTwoLists(pl1,pl2);

	while(mergeresult != NULL)
	{
		cout << mergeresult->val<< endl;
		mergeresult = mergeresult->next;		
	}
}