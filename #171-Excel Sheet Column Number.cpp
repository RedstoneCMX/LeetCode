#include<iostream>
using namespace std;
/*这道题比较简单，和168题正好相反，这里是title转number，比168题还更简单，类似于字符串转int。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int titleToNumber(string s) 
    {
        int len = s.length();
        int t2n = 0;
        for(int i = 0; i < len; i++)
        {
        	t2n = t2n * 26 +  (s[i] - 65 + 1);
        }

        return t2n;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	string s;
	cin >> s;
	Solution solu;
	int t2n = solu.titleToNumber(s);
	cout << t2n << endl;
	return 0;
}