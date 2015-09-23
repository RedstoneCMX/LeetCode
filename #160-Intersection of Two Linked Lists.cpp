#include<iostream>
using namespace std;
/*这道题其实还算比较简单的，但是要求时间复杂度O(n)，空间复杂度O(1)还是有点意思的。
其实也比较容易想到解决方法：
1.首先需要遍历一遍两个链表，求出两个链表的节点个数。
2.之后用两个指针prevA, prevB指向两个链表头部，将节点个数多的链表的指针移至和另个链表 从指针位置到尾部的节点个数相同的位置。
因为如果要有相同的节点个数和节点值，首先个数是必须要相等的。这一步将节点个数多的链表的部分给过滤掉，方便接下来的比较。
3.然后开始两个指针进行遍历移动，初始的时候给定一个指针getintersect，存放最终结果的指针，初始指向任意两个链表移动指针任意一个，
节点值相同则指针都往后移一个，节点值不同则首先将两个移动指针往后移一个，然后将getintersect指向其中任一个，更新结果指针。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA == NULL || headB == NULL)
            return NULL;
        
        int lenA = getlength(headA);
        int lenB = getlength(headB);

        ListNode* prevA = headA;
        ListNode* prevB = headB;
        if(lenA < lenB)
        {
            int diff = lenB - lenA;
            while(prevB && diff--)
                prevB = prevB->next;
        }
        if(lenA > lenB)
        {
            int diff = lenA - lenB;
            while(prevA && diff--)
                prevA = prevA->next;
        }

        ListNode* getintersect = prevA;//初始化
        while(prevA && prevB)
        {
            if(prevA->val == prevB->val)
            {
                prevA = prevA->next;
                prevB = prevB->next;
            }
            else
            {
                prevA = prevA->next;
                prevB = prevB->next;
                getintersect = prevA;
            }
        }

        return getintersect;

    }
    //求链表节点个数
    int getlength(ListNode* head)
    {
        ListNode* prev = head;
        if(prev == NULL)
            return 0;
        int count = 0;
        while(prev)
        {
            prev = prev->next;
            count++;
        }
        return count;
    }
   
};
/*************************在leetcode上直接提交以上代码即可******************************/ 
int main()
{
	int n1 = 0, n2 = 0;
	ListNode l1(-1), l2(-1);
	cout << "请输入链表1的整数个数："<<endl;
	cin >> n1;
	cout<<"请输入链表1的所有整数："<<endl;
	ListNode *prev1 = &l1;
	for(int i = 0; i < n1; i++)
	{
		int temp;
		cin >> temp;
		prev1->next = new ListNode(temp);
		prev1 = prev1->next;
		
	}

	ListNode *pl1 = l1.next;

	cout<<"请输入链表2的整数个数："<<endl;
	cin >> n2;
	cout<<"请输入链表2的所有整数："<<endl;
	ListNode *prev2 = &l2;
	for(int i =0; i < n2; i++)
	{
		int temp;
		cin >> temp;
		prev2->next = new ListNode(temp);
		prev2 = prev2->next;
	}

	ListNode *pl2 = l2.next;

	Solution solu;
	ListNode *getintersect = solu.getIntersectionNode(pl1,pl2);
	while(getintersect != NULL)
	{
		cout << getintersect->val<< endl;
		getintersect = getintersect->next;		
	}

	return 0;
}
