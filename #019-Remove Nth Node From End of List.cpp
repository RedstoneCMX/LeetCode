#include<iostream>
using namespace std;
/*这是一道关于链表的题，容易题，还是主要是熟悉链表的操作
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
     	ListNode *start1 = head;
     	int len = 0;
     	while(start1 != NULL)
     	{
     		start1 = start1->next;
     		len++;
     	}

     	int sn = len - n + 1;
     	ListNode *start2 = head;
     	ListNode *pre_start2 = head;
     	for(int i = 1; i < sn; i++)
     	{
     		pre_start2 = start2;
     		start2 = start2->next;
     	}

     	if(start2 == pre_start2)
     		return start2->next;
		else
			pre_start2->next = start2->next;
		     		
     	return head;   
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n = 0;
	ListNode l(-1);
	cout << "请输入链表的整数个数: "<< endl;
	cin >> n;
	cout<<"请输入链表1的所有整数: "<<endl;
	ListNode *prev = &l;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		prev->next = new ListNode(temp);
		prev = prev->next;
	}

	ListNode *pl = l.next;
	cout << "请输入需要移除的位置: "<< endl;
	int pos;
	cin >> pos;
	Solution solu;

	ListNode *left = solu.removeNthFromEnd(pl,pos);

	while(left != NULL)
	{
		cout << left->val<< endl;
		left = left->next;		
	}
}