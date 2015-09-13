#include<iostream>
using namespace std;
/*这道题是链表操作的题，和旋转数组那道题(189题)类似，只是这里是对链表进行旋转。
这里对输入的k值进行了处理，首先求出链表的节点个数，然后将k对节点个数len取余，
因为如果输入的k值超过了链表的实际节点个数，实际上只需要轮转k%len次即可。
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
    ListNode* rotateRight(ListNode* head, int k) 
    {
    	int len = 0;
    	ListNode* prev = head;
    	ListNode* last = prev;
    	while(prev != NULL)
    	{
    		len++;
    		last = prev;
    		prev = prev->next;
    		
    	} 

    	if(len <= 1)
    		return head;

    	int kk = k % len; //如果输入的k值超过了链表的实际节点个数，实际上只需要轮转k%len次即可

    	int prek = len - kk;

    	ListNode* prev2 = head;
    	while(--prek)
    		prev2 = prev2->next;
    	
    	last->next = head;

    	ListNode* result = prev2->next;
    	prev2->next = NULL;

    	return result;

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

	cout << "输入k值: " << endl;
	int k;
	cin >> k;
	Solution solu;
	ListNode *result = solu.rotateRight(l.next, k);

	while(result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
}