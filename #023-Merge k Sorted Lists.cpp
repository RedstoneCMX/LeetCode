#include<iostream>
#include<vector>
using namespace std;
/*这又是一道链表的题，对多个已排序的链表进行合并，一开始的时候使用的算法是对这k个链表同时查找当前位置的这k个值的最小值，
然后将对应链表指针往下一个移。直到最后指针全部指向链表尾部空处。结果发现超时，算法时间复杂度为O(N^2)。
查了一下网上的方法，采用归并排序可将链表排序的时间复杂度缩减到的O(NlgN)。
所以借鉴归并排序的方法，自顶向下，先递归的对链表的前半部分和后半部分进行归并排序，最后再merge。
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
    		else
    		{
    			prev->next = new ListNode(l1->val);
    			prev = prev->next;
    			l1 = l1->next;
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

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
    	int size = lists.size();
    	if(size == 0)
    		return NULL;
    	if(size == 1)
    		return lists[0];

        int mid = (size - 1)/2;
        vector<ListNode*> before_lists;
        vector<ListNode*> last_lists;
        before_lists.assign(lists.begin(),lists.begin() + mid + 1);
        last_lists.assign(lists.begin() + mid + 1 ,lists.begin() + size);
        ListNode *l1 = mergeKLists(before_lists);
        ListNode *l2 = mergeKLists(last_lists);
        return mergeTwoLists(l1,l2); 

    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int k;
	cin >> k;
	vector<ListNode*> lists;

	for(int i = 0; i < k; i++)
	{
		int n;
		cout << "输入链表"<< i + 1 << "整数的个数: " << endl;
		cin >> n;
		ListNode l(-1);
		ListNode *prev = &l;
		for(int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			prev->next = new ListNode(temp);
			prev = prev->next;
		}

		lists.push_back(l.next);
	}

	Solution solu;
	ListNode *mergekresult = solu.mergeKLists(lists);

	while(mergekresult != NULL)
	{
		cout << mergekresult->val<< endl;
		mergekresult = mergekresult->next;		
	}
}