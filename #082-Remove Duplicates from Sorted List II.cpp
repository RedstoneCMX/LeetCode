#include<iostream>
using namespace std;
/*这道题和第83题其实是属于相似题，第83题是删除重复值，重复值留一个，而这道题所有重复值节点全部删除，不留任何有重复值的节点。
为了方便起见，在链表头部添加一个无用节点-1，初始时before指针指向-1，behind指针指向head，循环判断behind指针是否为空，分两种情况讨论：
1.behind的下一节点不空且behind节点的值与下一节点的值不等或者下一节点为空，则直接将before和behind两个指针往后移一个位置即可。
2.如果不是第1种情况，则循环查找，直至behind指针指到非重复值的节点位置，然后将before指针的next指向behind。
3.然后重复操作1和2步骤即可，直至behind为空。
最终的返回结果是最初的before指针的next。这里用一个result指针记录了。
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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL)
        	return NULL;
        ListNode *before = new ListNode(-1);
        before->next = head;
        ListNode *result = before;
        ListNode *behind = head;
        while(behind != NULL)
        {
        	if((behind->next != NULL && behind->val != behind->next->val) || behind->next == NULL )
        	{
        		before = behind;
        		behind = behind->next;
        		continue;
        	}
        	for( ;behind->next != NULL && behind->val == behind->next->val;behind = behind->next);
        	behind = behind->next;
        	before->next = behind;
        }

        return result->next;
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
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		prev->next = new ListNode(num);
		prev = prev->next;
	}

	Solution solu;
	ListNode *result = solu.deleteDuplicates(l.next);

	while(result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
}