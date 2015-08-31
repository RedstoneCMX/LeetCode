#include<iostream>
using namespace std;
/*这道题并不简单，一开始想的方法是直接用被除数减除数，直到减至小于除数，或者直接用除数去一个一个加，直到被除数被超过，这样会超时。
为了提高效率，初始的时候令sum等于除数，然后循环增加sum，每次都增加一倍，同时count也增加一倍，直到sum+sum大于了被除数，然后将被除数减去sum，
再执行相同的操作。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int divide(int dividend, int divisor) 
    {
    	
    	if(dividend == 0 || divisor == 0)
    		return 0;
    	int max = 0x7fffffff;
    	int min = 0x80000000;
    	int negflag = 0;

    	long ldividend = dividend, ldivisor = divisor;
    	if((ldividend > 0 && ldivisor <0)||(ldividend < 0 && ldivisor > 0))
    		negflag = 1;	
    	
    	ldividend = abs(ldividend);
        ldivisor = abs(ldivisor);
        long result = 0;
        long count = 0;
        long sum = 0;
        while(ldividend >= ldivisor)
        {
            count = 1;
            sum = ldivisor;
            while(sum + sum <= ldividend)
            {
                sum += sum;
                count += count;
            }     
        	ldividend -= sum;
            result += count;
        }

        if(negflag == 1)
        	result = -result;

        if(result > max)
        	return max;
        else if(result < min)
        	return min;
        return result;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int dividend, divisor;
	cin >> dividend;
	cin >> divisor;
	Solution solu;

	int result = solu.divide(dividend, divisor);

	cout << result << endl;
}