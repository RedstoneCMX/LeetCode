#include<iostream>
using namespace std;
/*这又是一道链表的题，将相邻两个节点进行交换，不能是值的交换，必须做到两个节点的交换。不难，但是不能被指针指来指去弄晕了。
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
    ListNode* swapPairs(ListNode* head) 
    {
    	if(head == NULL)
    		return NULL;
        ListNode* pre_before = head;
        ListNode* before = head;
        ListNode* behind = head->next;
        
        while(behind != NULL)
        {
            if(pre_before == head)
                head = behind;
            else
        	   pre_before->next = behind;
        	before->next = behind->next;
            behind->next = before;

        	pre_before = before;
            before = before->next;
        	if(before == NULL)
        		break;
        	behind = before->next;
        }

        return head;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	ListNode l(-1);
	int n;
	cin >> n;
	ListNode *prev = &l;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		prev->next = new ListNode(temp);
		prev = prev->next;
	}
	Solution solu;
	ListNode *swapresult = solu.swapPairs(l.next);
	while(swapresult != NULL)
	{
		cout << swapresult->val << endl;
		swapresult = swapresult->next;
	}
}