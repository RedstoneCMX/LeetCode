#include<iostream>
#include<vector>
using namespace std;
/*这道题是链表操作的题，求一个链表是否是回文。有两种解决办法。
1.遍历一遍链表，并将节点的值存入数组中，然后对数组进行判断，这样就和判断回文串一样了。这种方法时间复杂度是O(n)，空间复杂度也是O(n)
2.将链表从中间断开，分成两个链表，对后半段链表进行翻转，然后遍历两个链表依次比较节点的值。
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
    // bool isPalindrome(ListNode* head) 
    // {
    // 	if(head == NULL)
    // 		return 1;
    //     vector<int> nums;
    //     while(head)
    //     {
    //     	nums.push_back(head->val);
    //     	head = head->next;
    //     }

    //     int size = nums.size();
    //     for(int i = 0, j = size-1; i < j; i++, j--)
    //     {
    //     	if(nums[i] != nums[j])
    //     		return 0;
    //     }

    //     return 1;
    // }

    bool isPalindrome(ListNode* head)
    {
    	int count = 0;
    	ListNode* p1 = head;
    	while(p1)
    	{
    		count++;
    		p1 = p1->next;
    	}
    	if(count <= 1)
    		return 1;
    	int mid = count / 2;
    	ListNode* first = head;
    	ListNode* last = head;
    	while(--mid)
    		last = last->next;
    	ListNode* firstend = last;
    	//判断是奇数还是偶数，偶数不必跳过中间节点
    	if(count % 2 == 0)
    		last = last->next;
    	//奇数可直接跳过中间节点
    	else
    		last = last->next->next;
    	//分离前半段链表
    	firstend->next = NULL;
    	//处理后半段链表，进行翻转
    	ListNode* before = last;
    	ListNode* behind = last->next;
    	before->next = NULL;
    	while(behind)
    	{
    		ListNode* temp = behind->next;
    		behind->next = before;
    		before = behind;
    		behind = temp;
    	}

    	last = before;
    	//最后得到的就是first和last两个链表
    	while(first && last)
    	{
    		if(first->val != last->val)
    			return 0;
    		else
    		{
    			first = first->next;
    			last = last->next;
    		}
    	}

    	return 1;

    	
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
	bool bo = solu.isPalindrome(l.next);

	cout << bo << endl;
}