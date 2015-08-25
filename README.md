# LeetCode
LeetCode程序
##NO.1 Two Sum
* 解题思路：首先用一个结构数组记录整个数组的数以及其原本所在的位置，然后对这个数组进行升序排列，再对排序之后的数组同时从两头查找，一头一尾相加，所得结果如果和目标整数和相等则即为找到，将之前记录的原本位置输出即可，如果相加之后的和大于目标整数和，则将尾部指针向前移一个，继续执行判断指针所指位置两数之和。如果相加之后的和小于目标整数和，则将头部指针向后移一个，继续执行判断指针所指位置两数之和。直到找到两数之和等于目标整数和为止。
* 注：时间复杂度是O(n)，线性时间。其他一些方法可能会超时。之前我使用了C++的vector的find和distance函数来查找vector中的元素以及元素所在位置，发现超时了，可能跟这两个函数的效率有关。

##NO.2 Add Two Numbers
这道题主要还是熟悉C++的链表操作，不算难。
* 1.首先同时遍历两个链表，对应位置的整数值相加，得到加和，如果加和小于10，则直接记录在新的加和链表中，如果加和大于等于10，则取个位数的值记录在新的加和链表中，并用一个变量carrybit作为进位标记，判断加和是否大于等于10，如果是，则计算carrybit，加法的进位最多也只能是1。如果加和小于10，则carrybit为0。carrybit用于下一位的加和，初始为0。
* 2.之后两个链表总有一个先遍历完成，或同时遍历完成。如果某个先遍历完成，那么还需要对另一个未遍历完的链表继续遍历，操作和第一步类似，只是变成了只有一个链表的值，但依然需要考虑进位carrybit。
* 3.在最后遍历完成之后，还需要注意的是，必须判断进位carrybit是否不为0，如果不为0，还需要在加和链表中增加一位。对应的测试用例可以是9999+1。

##NO.3 Longest Substring Without Repeating Characters
这道题是考查字符串操作的题。在本题中，其实使用hash的方法就完全可以做到时间复杂度O(n)，并没有网上一些解题方法那么复杂，当然使用动态规划应该也是一种方法，只是我还没有研究。
* 1.本题中，需要查找最长不重复子串，使用一个hash数组存储出现过的字符在s串中的位置，初始都为-1。此外使用两个指针，start和end记录当前判断的子串的开始和结束，初始都为0。还需要初始length和maxlength的值为0，分别用于记录当前判断子串长度和最长不重复子串长度。
* 2.之后便从end=0开始遍历整个s串，读取end位置处的字符，判断其是否在当前判断的子串中，如果不在则将hash数组中对应位置的值修改成end，end指针加1，向右移一位继续判断，如果在当前判断的子串中，则计算start和end的距离，就是当前判断的子串的最长不重复长度了，和maxlength比较，更新maxlength。同时将start指针移至重复的那个字符所在位置的后一位，继续end加1进行判断。
* 3.这里需要注意的是在判断至最后一个字符时，则直接计算当前子串的长度，通过strlength-start进行计算，然后和maxlength比较，更新maxlength。
* 4.2中提及的判断end位置处的字符是否在当前判断的子串中，这里是根据hash[tempchar] < start来判断，tempchar表示end处的字符，之所以这么判断是因为：小于start说明在当前记录的子串中并未出现，这里不能只判断hash值为-1的情况，因为hash值可能是记录之前的子串时记录的出现过的字符位置，在当前子串实际并未出现。

##NO.4 Median of Two Sorted Arrays
这道题说白了就是一个合并排序，给定了两个已经排序好的数组进行合并排序。要实现时间复杂度是O(m+n)应该还是很容易的。两个数组的长度分别是m,n。
* 这道题的思路其实就是对两个数组同时进行遍历，使用两个指针进行操作，初始时均指向数组开始位置，然后读取指针位置处的数进行比较。
* 如果一大一小，则将更小的数放入一个新的数组mergenums中，也就是存放合并后的数组，并将其指针往后移一位。如果两数相等，则将两个数分别放入mergenums中，并将两个数组的指针均同时向后移一位。
* 遍历之后可能出现某一个数组并未遍历完，因此还需要判断两个指针的位置将未遍历完的数继续放入mergenums中去。
* 对于两个数组长度之和如果是奇数，那么中位数就是合并排序之后的中间位置的数，如果是偶数，则中位数就是合并排序之后的中间两个位置的数的平均值。

##NO.5 Longest Palindromic Substring
这道题是经典的求最长回文子串的题。朴素算法很容易想到，但是时间复杂度是O(n^2)，会超时。这里使用的是manacher算法，时间复杂度可降为O(n)。
* 大家都知道,求回文串时需要判断其奇偶性,也就是求aba和abba的算法略有差距。然而,这个算法做了一个简单的处理,很巧妙地把奇数长度回文串与偶数长度回文串统一考虑,也就是在每个相邻的字符之间插入一个分隔符,串的首尾也要加,当然这个分隔符不能再原串中出现,一般可以用‘#’或者‘$’等字符。这样一来,原来的奇数长度回文串还是奇数长度,偶数长度的也变成以‘#’为中心的奇数回文串了。
* 这里我们用一个辅助数组help记录以每个字符为中心的最长回文半径,也就是 help[i]记录以s[i]字符为中心的最长回文串半径。help[i]最小为 1,此时回文串为 s[i]本身。我们可以证明help[i]-1就是以s[i]为中心的回文串在原串当中的长度：首先help[i]记录的是扩展之后的字符串s[i]的最长回文串半径，则对应其回文串长度应该是2help[i]-1，而实际回文串长度若为a，则2a+1 = 2help[i]-1，因此得出a = help[i]-1。
* 之后依次从前往后求得help数组就可以了,这里用到了DP(动态规划)的思想,也就是求help[i]的时候,前面的help[]值已经得到了,我们利用回文串的特殊性质可以进行一个大大的优化。为了防止求help[i]向两边扩展时可能数组越界,我们需要在数组最前面和最后面加一个特殊字符,令 P[0]='$'最后位置默认为'\0'不需要特殊处理。此外,我们用MaxId变量记录在求i之前的回文串中,延伸至最右端的位置,同时用id记录取这个MaxId的id值。通过下面这句话,算法避免了很多没必要的重复匹配。
```cpp
if(MaxId>i){help[i]=Min(help[2*id-i],MaxId-i);}
```

* j=2id-i即为i关于id的对称点,根据对称性,help[j]的回文串也是可以对称到i这边的,但是如果help[j]的回文串对称过来以后超过MaxId的话,
超出部分就不能对称过来了,所以这里help[i]为的下限为两者中的较小者,help[i]=Min(p[2*id-i],MaxId-i)。这样的话，在查找i的最长回文子串时就可以直接跳过help[i]个字符，再进行回文串的匹配，可以避免很多重复的比较。

##NO.6 ZigZag Conversion
这道题是关于Z字形的题，用一个字符串数组ans[rows]来存储通过Z字形排列之后的每一行，最后一拼接就是最终结果。
* 用一个变量count表示正向还是反向读取row。当通过遍历输入的字符串s，row初始为0，然后用ans[row]记录当前行的字符串串接结果，row加上count，直至加到row超过numRows，count变成-1，即反向增1，也就是减1。
* 继续添加串接ans[row]，直至row小于0，再将count变为1，即正向增1，也就是加1。通过这样遍历完整个字符串之后，ans这个字符串数组也就构造成功。
* 最后只需要将ans的每一个字符串拼接即可。

还有一些方法，在源代码中我还提供了一种方法，是我自己想的，但是有些复杂，不提倡使用。

##NO.7 Reverse Integer
这道题比较简单，就是一个整数反转的问题，但是简单题也会有陷阱，也不能小瞧。
这道题主要就是要考虑到int的溢出情况，溢出则输出0。对于int类型，范围是-2^31 - 2^31-1。

##NO.8 String to Integer
这个题就是一个字符串转int的问题，看起来虽然简单，但是有很多细节问题需要注意。
* 空格跳过;
* 正数负数的判断;
* 超出int范围的判断;
* 非数字字符的判断，如果在正负号之后还出现了非数字字符，那么就直接break，只输出之前合法的数字字符构成的数字。

##NO.9 Palindrome Number
这个题就是一个判断int整数是否是回文整数。有两种解决方法。
* 直接对这个整数进行反转，就和第7题Reverse Integer一样，先求整数的反转整数，然后判断反转之后的整数是否和原整数相等。这里需要注意的是反转之后可能会出现整数溢出的情况，因此需要判断整数溢出的情况，而反转整数如果溢出说明原整数肯定不是回文整数，因为如果是回文整数，既然原整数未溢出，回文整数也必然未溢出。
* 第二种方法就是将该整数转换成字符串，然后通过讨论字符串长度，分奇数偶数两种情况进行考虑，判断其回文性。

##NO.10 Regular Expression Matching
这个题是一个关于正则表达式匹配的问题，这里只是匹配'.'和'\*'两种通配符。解题思路主要是递归，其实就是DFS，深度优先搜索的思想。
<br/>根据下一个字符是否是'\*'分情况判断。
* 1.如果是p的下一个'\*'，则当前s和p相等或者p='.'情况下，依次判断s和p[2]之后的字符串是否match；
* 2.如果p的下一个字符不是'*'，只需判断当前字符是否相等，或者p[cur]='.'且s不为空，递归处理s[1]和p[1]之后的字符串；

这里需要注意的一个地方是，题目中的测试用例中，isMatch("ab", ".\*") → true，这里可能会产生困惑，其实这里".\*"，'\*'是用来作用于'.'，
意思是说可以有0个或多个'.'，而'.'可以匹配任意单个字符。因此"ab"一定是匹配".\*"的。

##NO.11 Container With Most Water
这道题算是一道数学题，如果穷举所有可能的情况，时间复杂度是O(n^2)，会超时。
* 这道题的O(n)算法类似于two sum那道题，在height两头分别设一个指针，然后计算area，如果height[i] <= height[j]，那么i++。
* 如果height[i] > height[j]，那么j--。
* 因为在这里如果height[i] <= height[j]，移指针j的话，只会使得面积减少，决定盛水的高度是最矮的那个高度，而此时如果再移j指针，只会使得j-i宽度减少，那么面积肯定减少，因此需要j++，同理height[i] > height[j]的情况。

##NO.12 Integer to Roman
这道题是阿拉伯数字转罗马数字。首先罗马的单个基本数字共有7个，I(1), V(5), X(10), L(50), C(100), D(500), M(1000)
<br/>组合规则：
<br/>(1)基本数字Ⅰ、X、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。
<br/>(2)不能把基本数字 V、L、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。
<br/>(3)V 和 X 左边的小数字只能用Ⅰ。
<br/>(4)L 和 C 左边的小数字只能用X。
<br/>(5)D 和 M 左边的小数字只能用C。
<br/>有两种解法。
* 1.第一种就是把所有小数字在前的组合也作为基本数字，再做一个对应的数值表就可以解决问题了。对输入的需要转换的数字num从最大的基本数字1000开始比较，如果大于等于则添加一个对应的基本数字字符至结果字符串中，并将num减去对应的基本数字的值，然后继续判断。到小于这个基本数字就将基本数字降至更小的基本数字继续判断。
* 2.第二种方法就是将1-9，10-90，100-900，1000-3000这几个段内的数字全部用罗马数字表示并记录数组中。之后对输入的需要转换的数字num每次截取其低位的数字，并使用一个变量digit记录当前位数，找到对应该数字的罗马数字的表示，添加到结果字符串最最前面。然后将num除去低位数字，继续判断。

##NO.13 Roman to Integer
这道题是罗马数字转阿拉伯数字，相对于阿拉伯数字转罗马数字容易些。思路很简单，从前往后遍历罗马数字，如果某个数比前一个数小，则把该数加入到结果中；反之，则在结果中两次减去前一个数并加上当前这个数。

##NO.14 Longest Common Prefix
这道题是一个最长相同前缀匹配的题。
<br/>解题思路是，先对整个string数组预处理一下，求一个最小长度（最长前缀肯定不能大于最小长度）。然后以第1个字符串作为参照，将最小长度作为初始长度，将最小长度的字符串作为初始字符串，从第二个字符串开始和第一个字符串进行匹配，直到找到相同前缀停止，然后将最长前缀字符串lcprefix更新，最小长度minlen更新，i++，匹配下一个字符串。

##NO.15 3sum
这是一道求解三个数的和为0的题。是twosum那道题的升级版吧，但还是有些不同的。
* 1.因为要求3个数，如果我们固定其中1个数，再用求“和为某值的2个数的组合”的解法，就能把剩下的2个数求出来。
* 2.因此，先对数组进行升序排列，这样整个数组的数就由小到大排列。i的取值由0至n-3，对每一个i，我们求当num[i]是解当中的其中一个数时，其他的2个数。
* 3.设有指针p指向数组头(实际只要p从i+1开始)，q指向数组尾，sum = num[i]+num[p]+num[q]，因为num[i]是一定在解中的，所以
    * 如果sum < 0，因为num[q]已经不能增大，所以说明num[p]太小了，这时p需要向后移动，找一个更大的数。
    * 同理，sum > 0，说明num[q]太大了，需要q向前移动。
    * 当sum == 0时，说明找到了一个解。但找到了一个解，并不说明解中有num[i]的所有解都找到了，因此p或q还需要跳过那些nums[p]与前一个相同以及nums[q]与后一个相同的值的情况，这样可以去掉重复的情况，继续移动寻找其他的解，同时这里还需要直到p==q为止。
* 4.之后i++，以下一个位置作为固定位置，继续进行查找操作，但是这里也有一个去重操作，当前固定位置如果和前一个固定位置的数值相同则直接跳过，因为这样求解出来的组合肯定是和前一个固定位置相同的。

##NO.16 3Sum Closest
这道题和上一道题类似，这里是求解与目标和最接近的三个数的组合的和。
* 思路和上一题类似，也是固定一个位置，然后从这个位置的下一个位置开始作为start，数组末尾作为end，查找另外两个数，通过twosum那道题的思路。
* 这里需要使用两个变量，一个记录已经查找过的三个数组合的和与目标和的最小差值，取值为正数，一个是记录最小差值对应的三个数组合的和。初始状态最小差值closest取一个最大值，对应和closestsum初始为0即可。
* 然后计算sum = nums[i] + nums[p] + nums[q];
      * 如果sum > target，计算与targe的差值sum-target，并将其与最小差值closest比较，如果比closest小则更新closest为sum-target，同时更新closestsum = sum。
      * 如果sum < target，计算与target的差值，target-sum，并将其与最小差值closest比较，如果比closest小则更新closest和closestsum。
      * 如果sum == target则直接返回target即可。
* 最后返回closestsum即为最终结果。

##NO.17 Letter Combinations of a Phone Number
这道题我主要还是用比较基础的方法，通过循环来求解。最直观的思路是播了多少位号码，就用多少个for循环，遍历每位号码对应的字符串。还有一种比较好的办法是通过递归，使用DFS深度优先搜索来做。
* 1.这里我是通过先将第一个数字对应的字符分割开来，作为初始的字符结合结果lc，然后将这个结果和剩下的数字对应的字符串进行组合，遍历从第二个开始的数字对应的字符串，和lc的字符组合，得到组合结果，更新lc。然后继续下一个数字对应的字符串进行组合。直至最后。
* 2.深度优先搜索DFS。深度优先搜索时间复杂度O(n!)，一般提高其效率的方法是剪枝。
* 3.两种方法的时间复杂度，应该都是O(n!)。

##NO.18 4Sum
这是一道求解四个数的和为某个目标数的题。是3sum那道题的升级版。思路其实也和3sum那道题基本相同。
* 1.因为要求4个数，如果我们固定其中2个数，再用求“和为某值的2个数的组合”的解法，就能把剩下的2个数求出来。
* 2.因此，先对数组进行升序排列，这样整个数组的数就由小到大排列。通过两个循环来固定前面2个数，i的取值由0至n-4，对每一个i，我们求当num[i]是解当中的其中一个数时，再设定j为解当中的第二个数，j从i+1到n-3取值。其他的2个数的确定，设有指针p指向数组头(实际只要p从j+1开始)，q指向数组尾，sum = num[i]+num[j]+num[p]+num[q]，因为num[i]和sum[j]是一定在解中的，所以:
      * 如果sum < 0，因为num[q]已经不能增大，所以说明num[p]太小了，这时p需要向后移动，找一个更大的数。
      * 同理，sum > 0，说明num[q]太大了，需要q向前移动。
      * 当sum == 0时，说明找到了一个解。
* 但找到了一个解，并不说明解中有num[i]和num[j]的所有解都找到了，因此p或q还需要跳过那些nums[p]与前一个相同以及nums[q]与后一个相同的值的情况，这样可以去掉重复的情况，继续移动寻找其他的解，同时这里还需要直到p==q为止。
* 3.之后继续i和j循环以下一个位置作为固定位置，继续进行查找操作，但是这里也有两个去重操作，num[i]和num[j]去除前面相同的值，遇到就跳过即可，防止求解到相同的组合对。
* 4.时间复杂度是O(n^3)。

##NO.19 Remove Nth Node From End of List
这是一道关于链表的题，容易题，还是主要是熟悉链表的操作。

##NO.20 Valid Parentheses
这是一道关于括号匹配的题，基本思路其实就是通过栈的思想来做，这里通过vector来实现栈的功能。
* 一个个读取括号字符串中的字符，然后在将字符压入栈之前判断即将加入栈中的字符与栈首的字符串是否是括号匹配，如果匹配则将栈首的字符退出栈，继续读取字符进行判断操作。
* 最后栈为空则说明括号全部匹配成功，返回1，否则返回0。
