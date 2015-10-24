#include<iostream>
using namespace std;
/*这又是一道关于链表的题，链表的插入排序，也比较简单，新建一个链表，然后遍历原链表，将遍历到的节点的数一个个插入新的链表中。
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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode* sortlist;
     	if(head == NULL)
     		return head;
     	sortlist = new ListNode(head->val);
     	head = head->next;
     	while(head)
     	{
     		int val = head->val;
     		ListNode* insertpos = sortlist;
     		ListNode* preinsertpos= sortlist;
     		ListNode* insertelement = new ListNode(val);
     		while(insertpos)
     		{
     			if(val < insertpos->val)
     			{
     				if(insertpos == preinsertpos)
     				{
     					insertelement->next = sortlist;
     					sortlist = insertelement;
     				}
     				else
     				{
     					preinsertpos->next = insertelement;
     					insertelement->next = insertpos;
     				}
  					break;
     			}
     			else
     			{
     				if(insertpos == preinsertpos)
     					insertpos = insertpos->next;
     				else
     				{
     					insertpos = insertpos->next;
     					preinsertpos = preinsertpos->next;
     				}
     			}
     		}

     		if(insertpos == NULL)
     		{
     			preinsertpos->next = insertelement;
     		}

     		head = head->next;
     	}

     	return sortlist;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/ 
int main()
{
	int n = 0;
	ListNode l(-1);
	cout << "请输入链表的整数个数: "<< endl;
	cin >> n;
	cout<<"请输入链表的所有整数: "<<endl;
	ListNode *prev = &l;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		prev->next = new ListNode(temp);
		prev = prev->next;
	}

	Solution solu;
	ListNode* sortlist = solu.insertionSortList(l.next);

	while(sortlist)
	{
		cout << sortlist->val << endl;
		sortlist = sortlist->next;
	}

	return 0;
}