#include<iostream>
using namespace std;
/*这又是一道链表的题，是第24题的升级版，有点难度。采用的思路是递归，这里为了方便起见，对这个链表的头部添加了一个无用的-1节点。
在链表头部记录一个指针pos_ret，并pre_before = pos_ret，然后下一个位置再记录一个before，遍历k次得到要反转的尾部指针behind，然后将before和behind两个位置的指针反转，
之后递归进行操作，此时k变为k-1，继续反转，直到k=2时停止。
然后再将pos_ret指针移至k次，至下一次操作。这里要注意如果pos_ret指针后面的节点个数小于k，不必反转。
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
	private:
	ListNode* ret;
	ListNode* pos_ret;
	public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
    	if(head == NULL || k == 1)
    		return head;
    	pos_ret = new ListNode(-1);
    	pos_ret->next = head;
    	ret = pos_ret;
    	while(pos_ret != NULL)
    	{
    		reverse(k);
    		int k2 = k;

    		while(pos_ret != NULL && k2--)
    			pos_ret = pos_ret->next;
    	}
    	
    	return ret->next;
    }

    void reverse(int k)
	{
		ListNode* pre_before = pos_ret;
    	ListNode* behind = pos_ret;
    	int k2 = k; 
        while(behind != NULL && k2--)
        	behind = behind->next;
        if(k2 > -1)
        	return ;
        ListNode* before = pos_ret->next;
        pre_before->next = before->next;
        before->next = behind->next;
        behind->next = before;
        if(k == 2)
        	return ;
        reverse(k-1);
	}
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	ListNode l(-1);
	int n;
	cout << "请输入链表整数个数: " << endl; 
	cin >> n;
	ListNode *prev = &l;
	cout << "请输入链表各个整数: " << endl;
	for(int i = 0; i < n; i++)
	{
		int temp; 
		cin >> temp;
		prev->next = new ListNode(temp);
		prev = prev->next;
	}
	cout << "请输入k值: " << endl;
	int k;
	cin >> k;
	Solution solu;
	ListNode *reverseresult = solu.reverseKGroup(l.next, k);
	while(reverseresult != NULL)
	{
		cout << reverseresult->val << endl;
		reverseresult = reverseresult->next;
	}
}