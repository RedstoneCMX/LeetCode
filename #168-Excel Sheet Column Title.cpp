#include<iostream>
using namespace std;
/*这道题比较简单，其实就和将int转成字符串类似，只是这里1->A,...26->Z。
这里需要注意的是，求模的时候要对n减一再求模，因为是从1开始的，1->A,...,26->Z。和NO.258 Add Digits类似。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    string convertToTitle(int n) 
    {
        string ctt = "";
        while(n)
        {
        	int digit = (n-1) % 26;
        	ctt = (char)(digit + 65) + ctt;
        	n = (n-1) / 26;
        }

        return ctt;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cin >> n;
	Solution solu;
	string ctt = solu.convertToTitle(n);
	cout << ctt << endl;
	return 0;
}