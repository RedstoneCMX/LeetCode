#include<iostream>
#include<stack>
using namespace std;
/*这个题是使用栈实现队列的功能。队列是先进先出，而栈是后进先出。主要思路就是使用两个栈来实现，一个栈s用来接收数据，一个栈assist_s辅助操作。
1.对于push操作直接对栈s进行push操作即可。
2.对于pop操作，首先判断assist_s中是否有元素，如果有则从assist_s中pop即可，如果为空则先将s中的元素从栈顶push到assist_s中，直到为空。
然后再对assist_s进行pop操作。
3.对于peek操作，和pop操作类似，只是不必对assist_s进行pop操作。
4.对于为空判断需要判断两个栈是否都为空。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Queue 
{
private:
	stack<int> s;
	stack<int> assit_s;
public:
    // Push element x to the back of queue.
    void push(int x) 
    {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) 
    {
        if(!assit_s.empty())
        	assit_s.pop();
        else
        {
        	while(!s.empty())
        	{
        		assit_s.push(s.top());
        		s.pop();
        	}
        	assit_s.pop();
        }
    }

    // Get the front element.
    int peek(void) 
    {
        if(!assit_s.empty())
        	return assit_s.top();   
        else
        {
        	while(!s.empty())
        	{
        		assit_s.push(s.top());
        		s.pop();
        	}
        	return assit_s.top();
        } 
    }

    // Return whether the queue is empty.
    bool empty(void) 
    {
        return s.empty()&&assit_s.empty();
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.peek() << endl;

	q.pop();
	cout << q.peek() << endl;
	cout << q.empty() << endl;

	return 0;
}