#include<iostream>
#include<vector>
using namespace std;
/*这道题比较简单，主要就注意加1之后的进位问题。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int size = digits.size();
        vector<int> plusdigits;
        int *array_digits = new int[size+1];
        int carrybit = 0;//进位
        int i, j;
        for(i = size-1,j = 0; i >=0; i--,j++)
        {
        	if(i == size-1)
        	{
        		array_digits[j] = (digits[i] + 1) % 10;
        		carrybit = (digits[i] + 1) / 10;
        	}
        	else
        	{
        		array_digits[j] = (digits[i] + carrybit) % 10;
        		carrybit = (digits[i] + carrybit) / 10;
        	}   		
        }
        if(carrybit != 0)
        {
        	array_digits[j] = carrybit;
        	j++;
        }   	
        int plussize = j;
        for(int k = plussize - 1; k >= 0; k--)
        	plusdigits.push_back(array_digits[k]);
        return plusdigits;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cin >> n;
	vector<int> digits;
	for(int i = 0; i < n; i++)
	{
		int temp_digit;
		cin >> temp_digit;
		digits.push_back(temp_digit);
	}
	Solution solu;
	vector<int> plusdigits;
	plusdigits = solu.plusOne(digits);
	for(int i = 0; i < plusdigits.size(); i++)
	{
		cout << plusdigits[i] << endl;
	}
}