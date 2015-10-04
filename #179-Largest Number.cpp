#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
/*这个题主要就是利用sort函数，最关键的就是编写比较函数Comp，规则也很简单，将两个数a,b进行拼接，有两种拼接方式，
一种是ab，一种是ba，只需要比较这两种拼接方式哪一种能够使得拼接之后的数较大。但是这里不能通过以下方式进行：
比如ab拼接方式，a乘以10的x次方，x是b的位数，然后再和b相加，这样看似没问题，其实可能造成拼接之后的数溢出，超过int范围。
因此有两种解决办法:
1.一种是全部转换为一位一位的数，存入一个数组，然后一个个比较两个数组的数。
2.转换成string，然后拼接再比较。这种方法比较简单。
*/
/*************************在leetcode上直接提交以下代码即可******************************/

/*
void getdigits(vector<int>& digits, int num)
{
	if(num == 0)
    	digits.push_back(0);
    while(num)
    {
    	int digit = num % 10;
    	digits.push_back(digit);
    	num = num / 10;
    }

    return ;
}

//sort排序的比较函数
bool Comp(const int &a,const int &b)
{
    vector<int> digits_a;
    vector<int> digits_b;
    getdigits(digits_a, a);
   	getdigits(digits_b, b);
    vector<int> digits_ab;
    vector<int> digits_ba;
    for(int i = digits_a.size()-1; i >= 0; i--)
    	digits_ab.push_back(digits_a[i]);
    for(int i = digits_b.size()-1; i >= 0; i--)
    	digits_ab.push_back(digits_b[i]);

    for(int i = digits_b.size()-1; i >= 0; i--)
    	digits_ba.push_back(digits_b[i]);
    for(int i = digits_a.size()-1; i >= 0; i--)
    	digits_ba.push_back(digits_a[i]);

    int sumsize = digits_a.size() + digits_b.size();
    for(int i = 0; i < sumsize; i++)
    {
    	if(digits_ab[i] > digits_ba[i])
    		return true;
    	else if(digits_ab[i] < digits_ba[i])
    		return false;
    }

    return false;

}
*/
//sort排序的比较函数
bool Comp(const int &a,const int &b)
{
    stringstream sstra, sstrb;
    sstra << a;
    sstrb << b;
    string strab = sstra.str() + sstrb.str();
    string strba = sstrb.str() + sstra.str();
    return strab > strba;
}
class Solution 
{
public:
    string largestNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),Comp);

        string largestnum = "";
        int size = nums.size();
        stringstream sstr;
        for(int i = 0; i < size; i++)
        {
        	sstr.str("");
        	sstr << nums[i];
        	largestnum += sstr.str();
        }
        if(largestnum[0] == '0')
        	return "0";
        return largestnum;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	cout << "请输入整数个数: " << endl;
	int n;
	cin >> n;
	vector<int> nums;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	Solution solu;
	string largestnum = solu.largestNumber(nums);
	cout << largestnum << endl;

	return 0;
}