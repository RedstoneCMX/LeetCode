#include<iostream>
#include<stack>
using namespace std;
/*这道题的思路是用另外一个单调stack来记录最小值就可以了，这个stack是单调的，栈顶元素最小。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class MinStack 
{
private:
	stack<int> s;
	stack<int> mins;
public:
    void push(int x) 
    {
    	if(mins.empty() || mins.top() >= x)
    		mins.push(x);
       	s.push(x); 
    }

    void pop() 
    {
        int top = s.top();
        if(top == mins.top())
        	mins.pop();
        s.pop();
    }

    int top() 
    {
        return s.top();
    }

    int getMin() 
    {
       return mins.top();
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	MinStack mins;
	mins.push(3);
	mins.push(2);
	mins.push(4);
	mins.push(1);
	cout << mins.top() << endl;
	cout << mins.getMin() << endl;
	mins.pop();
	cout << mins.top() << endl;
	return 0;
}