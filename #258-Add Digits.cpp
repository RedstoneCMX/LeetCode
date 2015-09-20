#include<iostream>
using namespace std;
/*简单题，如果仅仅就按照题目的意思的思路去写，这个题其实确实非常简单，没有什么难点。而题目建议能否不使用循环和递归，
在O(1)的时间复杂度内完成。其实就是一个找规律的题。
输入：1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
结果：1, 2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2 
根据上面的尝试，我们可以发现，这里是有规律的。 
即结果满足，（num-1）%9+1 
*/
/*************************在leetcode上直接提交以下代码即可******************************/
/*class Solution 
{
public:
    int addDigits(int num) 
    {
    	int add = num;
        while(num / 10)
        {
        	int temp_num = num;
        	add = 0;
        	while(temp_num)
        	{
        		add = add + temp_num % 10;
        		temp_num = temp_num / 10;
        	}

        	num =add;
        }

        return add;
    }
};*/
class Solution 
{
public:
    int addDigits(int num) 
    {
    	int add = (num - 1) % 9 + 1;
    	return add;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int num;
	cin >> num;
	Solution solu;
	int add_digit = solu.addDigits(num);
	cout << add_digit << endl;
	return 0;
}