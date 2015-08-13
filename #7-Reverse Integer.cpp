#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
////////////////////////////解题思路///////////////////////////////////////////////////////
/*这道题比较简单，但是简单题也会有陷阱。
这道题主要就是要考虑到int的溢出情况，溢出则输出0。对于int类型，范围是-2^31 - 2^31-1。
*/
////////////////////////////解题思路///////////////////////////////////////////////////////

/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int reverse(int x) 
    {
        vector<int> cx;
        int temp_num = 0;

        const int max = 0x7fffffff;  //int最大值,2^31-1 
        const int min = 0x80000000;  //int最小值,-2^31 
        while(x)
        {
        	temp_num = x % 10;

        	cx.push_back(temp_num);
        	x = x / 10;
        }

        int count = cx.size();
        long long rx = 0;
        for(int i = 0; i < count; i++)
        {
        	long long temp_rnum = cx[i] * pow(10,(count - i - 1));
        	rx += temp_rnum;

        	if (rx > max || rx < min)   //溢出处理  
            {  
                rx = 0;    
                return rx;  
            }  
        }
        return rx;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/

int main()
{
	int x = 0;
	cin >> x;

	Solution solu;
	int rx = solu.reverse(x);

	cout << rx <<endl;
}