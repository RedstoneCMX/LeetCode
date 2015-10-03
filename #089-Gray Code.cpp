#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
/*这道题首先必须了解格雷码是怎么表示的，一个很简单的自然二进制转格雷码的方法是：
从最右边一位起，依次将每一位与左边一位异或(XOR)，作为对应格雷码该位的值，最左边一位不变(相当于左边是0)。
比如011，转成格雷码之后就是010。其实就是011 XOR 001。
可以看出上述提到的这种转化方法其实就是 i XOR i/2。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    vector<int> grayCode(int n) 
    {
        vector<int> result;
        int pown = pow(2, n);
        for(int i = 0; i < pown; i++)
        {
        	int gray = i ^ (i/2);
        	result.push_back(gray);
        }

        return result;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cin >> n;
	Solution solu;
	vector<int> graycode = solu.grayCode(n);
	for(int i = 0;i < graycode.size(); i++)
		cout << graycode[i] << endl;
	return 0;
}