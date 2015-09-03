#include<iostream>
using namespace std;
/*这道题是链表操作的题，其实和第26题基本一样，只是一个是数组，一个是链表，这里链表的操作的话也还是比较简单的，只需要在开头设置两个指针，
一个before一个behind，然后循环将behind指向与前面节点值不一样的节点，也就是跳过相同值的节点，之后则将before的next指向behind，
这样就将中间重复的值的节点删去了。之后将before设置为当前的behind，继续执行相同的操作，删除下一个重复值的节点。
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
        ListNode *before = head;
        ListNode *behind = head;
        while(behind != NULL)
        {
        	for( ;behind->next != NULL && behind->val == behind->next->val;behind = behind->next);
        	behind = behind->next;
        	before->next = behind;
        	before = behind;
        }

        return head;
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