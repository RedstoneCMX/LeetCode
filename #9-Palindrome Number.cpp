#include<iostream>
#include<sstream>
#include<string>
using namespace std;
/*这个题就是一个判断int整数是否是回文整数。有两种解决方法。
1.直接对这个整数进行反转，就和第7题Reverse Integer一样，先求整数的反转整数，然后判断反转之后的整数是否和原整数相等。
这里需要注意的是反转之后可能会出现整数溢出的情况，因此需要判断整数溢出的情况，而反转整数如果溢出说明原整数肯定不是回文整数，
因为如果是回文整数，既然原整数未溢出，回文整数也必然未溢出。
2.第二种方法就是将该整数转换成字符串，然后通过讨论字符串长度，分奇数偶数两种情况进行考虑，判断其回文性。
*/

/*
//////在leetcode上直接提交以下代码即可
class Solution 
{
	public:
    bool isPalindrome(int x) 
    {
    	if(x < 0)
            return 0;
        long long rx = 0;
        const int max = 0x7fffffff;  //int最大值,2^31-1 
        const int min = 0x80000000;  //int最小值,-2^31 
        int x2 = x;
        while(x2 != 0)
        {
        	int temp_num = x2 % 10;
        	x2 = x2 / 10;
        	rx = rx * 10 + temp_num;
        	if(rx > max || rx < min)
        		return 0;
        }
        
        if(x == rx)
        	return 1;
        else
        	return 0;
    }
};*/
//////在leetcode上直接提交以上代码即可

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    bool isPalindrome(int x) 
    {
    	
    	if(x < 0)
    		return 0;
    	stringstream str;
		str << x;
		string strx = str.str();
        int len = strx.length();
        int mid = len / 2;
        int i = 0;
        if(len % 2 == 1){
        	for(i = 0; i<= mid && strx[mid+i] == strx[mid-i];i++);
        	if(i == mid + 1)
        		return 1;
        	else
        		return 0;
        }		
        else
        {
        	int mid2 = mid - 1;
        	for(i = 0; i < mid && strx[mid + i] == strx[mid2 - i]; i++);
        	if(i == mid)
        		return 1;
        	else 
        		return 0;
        }
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/

int main()
{
	int x = 0;
	cin >> x;
	Solution solu;
	bool bo = solu.isPalindrome(x);

	cout << bo << endl;
}