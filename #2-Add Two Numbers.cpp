#include<iostream>
using namespace std;

////////////////////////////解题思路///////////////////////////////////////////////////////
/*这道题主要还是熟悉C++的链表操作，不算难。
1.首先同时遍历两个链表，对应位置的整数值相加，得到加和，如果加和小于10，则直接记录在新的加和链表中，
如果加和大于等于10，则取个位数的值记录在新的加和链表中，并用一个变量carrybit作为进位标记，判断加和是否大于等于10，
如果是，则计算carrybit，加法的进位最多也只能是1。如果加和小于10，则carrybit为0。carrybit用于下一位的加和，初始为0。
2.之后两个链表总有一个先遍历完成，或同时遍历完成。如果某个先遍历完成，那么还需要对另一个未遍历完的链表继续遍历，操作和第一步类似，
只是变成了只有一个链表的值，但依然需要考虑进位carrybit。
3.在最后遍历完成之后，还需要注意的是，必须判断进位carrybit是否不为0，如果不为0，还需要在加和链表中增加一位。对应的测试用例可以是9999+1。
*/
////////////////////////////解题思路///////////////////////////////////////////////////////

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
    	ListNode addresult(-1);
    	ListNode *prev = &addresult;
    	int carrybit = 0;
    	while(l1 != NULL && l2 != NULL)
    	{
    		int tempnum = l1->val + l2->val + carrybit;
    		carrybit = tempnum / 10;
    		if(tempnum >= 10)
    			tempnum = tempnum % 10;
    		
    		prev->next = new ListNode(tempnum);
    		prev = prev->next;

    		l1 = l1->next;
    		l2 = l2->next;

    	}
    	//如果l1先结束，继续添加l2的数字，同时要记得将进位加上
    	if(l1 == NULL)
    	{	
    		
    		while(l2 != NULL)
    		{
    			int tempnum = l2->val + carrybit;
	    		carrybit = tempnum / 10;
	    		if(tempnum >= 10)
	    			tempnum = tempnum % 10;
	    		prev->next = new ListNode(tempnum);
	    		prev = prev->next;
	    		l2 = l2->next;
    		}

    	}
    	//如果l2先结束，继续添加l1的数字，同时要记得将进位加上
    	if(l2 == NULL)
    	{
    		while(l1 != NULL)
    		{

    			int tempnum = l1->val + carrybit;
	    		carrybit = tempnum / 10;
	    		if(tempnum >= 10)
	    			tempnum = tempnum % 10;
	    		prev->next = new ListNode(tempnum);
	    		prev = prev->next;
	    		l1 = l1->next;
    		}
    	}
    	
		if(carrybit != 0)
		{
			prev->next = new ListNode(carrybit);
			//prev = prev->next;
		}
    

        return addresult.next;
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
	ListNode *addresult = solu.addTwoNumbers(pl1,pl2);

	while(addresult != NULL)
	{
		cout << addresult->val<< endl;
		addresult = addresult->next;		
	}


}
