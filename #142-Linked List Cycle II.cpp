#include<iostream>
using namespace std;
/*这道题是141题的升级版，不仅仅是要判断链表有环，还要找到环入口的地方。
首先判断是否有环和141题方法一样，只是fast和slow相等的时候break即可。
之后就定义两个指针，一个cycle初始指向head，一个gocycle初始指向fast，
嵌套两层循环，首先初始gocycle = fast，然后再嵌套一层循环，对gocycle进行操作:
gocycle = gocycle->next，并判断cycle是否等于gocycle，如果相等则直接返回cycle，即为入口节点。
如果等于fast，说明已经绕了一圈，还是没有和cycle相遇，说明cycle不是入口节点，break。返回到第一层循环，
对cycle = cycle->next，然后再继续第二层循环，知道找到一个cycle能够是环中的一个节点，说明就是入口节点。
这个方法貌似还是不太好，目前还没有想到更好的方法，还需深究。
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
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL)
            return false;
        ListNode* fast;
        ListNode* slow;

        slow = head;
        fast = head->next;
        while(true)
        {
            if(fast == NULL)
                return NULL;
            fast = fast->next;
            if(fast == NULL)
                return NULL;
            if(fast == slow)
                break;
            fast = fast->next;
            if(fast == NULL)
                return NULL;
            if(fast == slow)
                break;
            slow = slow->next;

            if(fast == slow)
                break;
        }

        ListNode* cycle = head;
        ListNode* gocycle = fast;
        while(true)
        {
            gocycle = fast;
            while(true)
            {
                gocycle = gocycle->next;
                if(gocycle == cycle)
                    return cycle;
                if(gocycle == fast)
                    break;
            }
            cycle = cycle->next;
        }
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
	return 0;
}