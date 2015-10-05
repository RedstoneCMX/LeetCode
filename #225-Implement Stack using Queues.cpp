#include<iostream>
#include<queue>
using namespace std;
/*这个题是使用队列实现栈的功能。队列是先进先出，而栈是后进先出。主要思路就是使用两个队列来实现，q和assist_q。
1.对于push操作直接对队列q进行push操作即可。
2.对于pop操作，首先判断q中是否有元素，如果为空则对assist_q进行操作，将assist_q中的元素push到q中，直到剩下最后一个，
然后再pop出assist_q最后一个元素。如果q不为空则将q中的元素push到assist_q中，直到剩下最后一个，然后pop出q的最后一个元素。
3.对于top操作，首先判断q是否为空，如果不为空则返回q的back元素，如果为空则返回assist_q的back元素。
4.对于为空判断需要判断两个队列是否都为空。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Stack 
{
private:
	queue<int> q;
	queue<int> assist_q;
public:
    // Push element x onto stack.
    void push(int x) 
    {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() 
    {
    	if(q.empty())
    	{
    		int qsize = assist_q.size();
    		while(--qsize)
	        {
	        	q.push(assist_q.front());
	        	assist_q.pop();
	        }
	        assist_q.pop();
	        return ;
    	}

    	int qsize = q.size();
		while(--qsize)
        {
        	assist_q.push(q.front());
        	q.pop();
        }
        q.pop();
        return ;
        
    }

    // Get the top element.
    int top() 
    {
    	if(!q.empty())
        	return q.back();
        return assist_q.back();
    }

    // Return whether the stack is empty.
    bool empty() 
    {
        return q.empty() && assist_q.empty();
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.top() << endl;

	s.pop();
	cout << s.top() << endl;
	cout << s.empty() << endl;

	return 0;
}