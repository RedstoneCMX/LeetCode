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
这是一道关于括号匹配的题，基本思路其实就是通过栈的思想来做，这里不仅使用stack实现，同时也通过vector来实现了栈的功能。
* 一个个读取括号字符串中的字符，然后在将字符压入栈之前判断即将加入栈中的字符与栈首的字符串是否是括号匹配，如果匹配则将栈首的字符退出栈，继续读取字符进行判断操作。
* 最后栈为空则说明括号全部匹配成功，返回1，否则返回0。

##NO.21 Merge Two Sorted Lists
这又是一道关于链表的题，主要还是熟悉链表操作，就是合并排序，比较简单。

##NO.22 Generate Parentheses
这又是一道括号匹配的题目，和第20题不一样，第20题是判断括号匹配是否合法的题，而这道题正好想法，需要将所有合法的括号匹配情况列出来。这里需要说明的是该问题解的个数就是卡特兰数，但是现在不是求个数，而是要将所有合法的括号排列打印出来。
```cpp
令h(0)=1,h(1)=1，catalan数满足递推式[1]：
h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0) (n>=2)
例如：h(2)=h(0)*h(1)+h(1)*h(0)=1*1+1*1=2
h(3)=h(0)*h(2)+h(1)*h(1)+h(2)*h(0)=1*2+1*1+2*1=5
```
这道题的基本思想就是递归。假设在位置k我们还剩余left个左括号和right个右括号，如果left>0，则我们可以直接打印左括号，而不违背规则。能否打印右括号，我们还必须验证left和right的值是否满足规则，如果left>=right，则我们不能打印右括号，因为打印会违背合法排列的规则，否则可以打印右括号。如果left和right均为零，则说明我们已经完成一个合法排列，可以将其打印出来。

##NO.23 Merge k Sorted Lists
* 这又是一道链表的题，对多个已排序的链表进行合并，一开始的时候使用的算法是对这k个链表同时查找当前位置的这k个值的最小值，然后将对应链表指针往下一个移。直到最后指针全部指向链表尾部空处。结果发现超时，算法时间复杂度为O(N^2)。
* 查了一下网上的方法，采用归并排序可将链表排序的时间复杂度缩减到的O(NlgN)。
* 所以借鉴归并排序的方法，自顶向下，先递归的对链表的前半部分和后半部分进行归并排序，最后再merge。

##NO.24 Swap Nodes in Pairs
这又是一道链表的题，将相邻两个节点进行交换，不能是值的交换，必须做到两个节点的交换。不难，但是不能被指针指来指去弄晕了。

##NO.25 Reverse Nodes in k-Group
这又是一道链表的题，是第24题的升级版，有点难度。
* 采用的思路是递归，这里为了方便起见，对这个链表的头部添加了一个无用的-1节点。
* 在链表头部记录一个指针pos_ret，并pre_before = pos_ret，然后下一个位置再记录一个before，遍历k次得到要反转的尾部指针behind，然后将before和behind两个位置的指针反转，之后递归进行操作，此时k变为k-1，继续反转，直到k=2时停止。
* 然后再将pos_ret指针移至k次，至下一次操作。这里要注意如果pos_ret指针后面的节点个数小于k，不必反转。

##NO.26 Remove Duplicates from Sorted Array
这道题比较简单，去除重复数字，计算非重复数字的个数newlen，同时在原数组上前newlen个位置记录这newlen个非重复数字，不使用新的数组去接收。
* 解题思路很简单，首先初始newlen为0，之后只需要对原数组进行一次遍历，每次比较当前位置的数与前一个位置的数是否相同，
      * 如果不相同更新nums[newlen]的值为当前位置的值，newlen加1；
      * 如果相同则不进行任何操作，继续遍历执行。
* 时间复杂度为O(N)。

##NO.27 Remove Element
这道题其实也比较简单，题目意思就是要删除数组中为某个值的所有元素，同时计算删除了这些元素之后的数组长度newlen，并在原数组上的前newlen个位置记录所有未删除的元素，顺序不定。
* 基本思路也很简单，首先遍历一遍数组，求得newlen，并用一个数组pos[]记录所有需要删除的元素的位置。
* 之后再从数组的newlen位置开始遍历，直至数组末尾，判断当前位置的值是否是要删除的元素，如果是则跳过，如果不是则将newlen位置之前的需要删除的元素位置的值更新为该值。这里使用之前记录了删除元素位置的pos[]数组。
* 时间复杂度为O(N)

##NO.28 Implement strStr()
这道题是典型的模式串匹配的题，主要有两种解法:
* 一种是暴力求解，直接从原串第一个字符开始和模式串第一个字符匹配，匹配成功则原串第二个字符与模式串第二个字符匹配，如果匹配失败则将原串第二个字符串与模式串第二个字符匹配，依次进行下去。时间复杂度是O(mn)
* 另外一种高效的算法就是KMP算法。时间复杂度为O(m+n)

##NO.29 Divide Two Integers
* 这道题并不简单，一开始想的方法是直接用被除数减除数，直到减至小于除数，或者直接用除数去一个一个加，直到被除数被超过，这样会超时。
* 为了提高效率，初始的时候令sum等于除数，然后循环增加sum，每次都增加一倍，同时count也增加一倍，直到sum+sum大于了被除数，然后将被除数减去sum，再执行相同的操作。

##NO.31 Next Permutation
这道题就是一道字典序排列的题。其实可以求解全排列问题，把升序的排列（当然，也可以实现为降序）作为当前排列开始，然后依次计算当前排列的下一个字典序排列。
* 对当前排列从后向前扫描，找到一对为升序的相邻元素，记为i和j（i < j）。
* 如果不存在这样一对为升序的相邻元素，则所有排列均已找到，算法结束；
* 否则，重新对当前排列从后向前扫描，找到第一个大于i位置的元素k，交换i和k的值，然后对从j开始到结束的子序列反转，则此时得到的新排列就为下一个字典序排列。
* 这种方式实现得到的所有排列是按字典序有序的。

##NO.35 Search Insert Position
这道题非常简单，数组是有序数组，只需要遍历一遍数组，判断当前值是否等于target或者大于target即可返回其位置值。如果都不满足，
说明target比nums中所有数都大，直接插入数组尾部，因为返回size。

##NO.36 Valid Sudoku
这道题是关于数独的题，就是判断输入的不完整数独是否合法，并不需要其是否有解，其实就是分三种情况来判断：
* 1.判断每行不是空的格的数字是否是在1-9，并且没有重复。
* 2.判断每列不是空的格的数字是否是在1-9，并且没有重复。
* 3.判断每个九宫格的格的数字是否是在1-9，并且没有重复。

##NO.58 Length of Last Word
这道题非常简单，但要注意的是输入的时候，不能用cin，因为cin是以空格分开的。需要使用getline进行输入。

##NO.61 Rotate List
这道题是链表操作的题，和旋转数组那道题(189题)类似，只是这里是对链表进行旋转。这里对输入的k值进行了处理，首先求出链表的节点个数，然后将k对节点个数len取余，因为如果输入的k值超过了链表的实际节点个数，实际上只需要轮转k%len次即可。

##NO.66 Plus One
这道题比较简单，主要就注意加1之后的进位问题。

##NO.67 Add Binary
这道题比较简单，和第66题类似，只不过这里是算二进制的加法，并且是以字符串形式输入，还是要考虑进位的问题。

##NO.69 Sqrt(x)
这道题如果直接从0到x遍历其平方求解必然会超时，这里主要采用的是两种方法，二分法和牛顿迭代法。
* 1.二分法就不用说了，时间复杂度是O(logn)
* 2.牛顿迭代法：
      * 计算x2 = n的解，令f(x)=x2-n，相当于求解f(x)=0的解。首先取x0，如果x0不是解，做一个经过(x0,f(x0))这个点的切线，与x轴的交点为x1。
      * 同样的道理，如果x1不是解，做一个经过(x1,f(x1))这个点的切线，与x轴的交点为x2。以此类推。以这样的方式得到的xi会无限趋近于f(x)=0的解。
      * 判断xi是否是f(x)=0的解有两种方法：一是直接计算f(xi)的值判断是否为0，二是判断前后两个解xi和xi-1是否无限接近。
      * 可求得迭代公式xi+1= (xi + n/xi) / 2

##NO.70 Climbing Stairs
这道题其实很常见，一般的解法有两种，一种是递归求解，一种是动态规划。
* 递归的求解方法很容易超时。
* 而动态规划的解法效率高，典型的空间换时间。状态转移方程非常简单：
```cpp
nums[i] = nums[i-1]+nums[i-2];
```

##NO.80 Remove Duplicates from Sorted Array II
这道题方法还比较简单，使用一个指针pos记录当前更新的位置，然后使用一个变量count来记录当前连续相同的数的个数。
初始时pos=1，count=1。然后从i=1~i=size-1进行遍历：
* 如果nums[i]等于nums[i-1]则count++，并且判断count如果小于3则更新nums[pos]=nums[i]，并pos++。
* 如果nums[i]不等于nums[i-1]，说明进入了下一个数的判断了，那么此时count更新为1.nums[pos]=nums[i]，并pos++。

##NO.82 Remove Duplicates from Sorted List II
这道题和第83题其实是属于相似题，第83题是删除重复值，重复值留一个，而这道题所有重复值节点全部删除，不留任何有重复值的节点。为了方便起见，在链表头部添加一个无用节点-1，初始时before指针指向-1，behind指针指向head，循环判断behind指针是否为空，分两种情况讨论：
* 1.behind的下一节点不空且behind节点的值与下一节点的值不等或者下一节点为空，则直接将before和behind两个指针往后移一个位置即可。
* 2.如果不是第1种情况，则循环查找，直至behind指针指到非重复值的节点位置，然后将before指针的next指向behind。

然后重复操作1和2步骤即可，直至behind为空。最终的返回结果是最初的before指针的next。这里用一个result指针记录了。

##NO.83 Remove Duplicates from Sorted List
这道题是链表操作的题，其实和第26题基本一样，只是一个是数组，一个是链表，这里链表的操作的话也还是比较简单的，只需要在开头设置两个指针，一个before一个behind，然后循环将behind指向与前面节点值不一样的节点，也就是跳过相同值的节点，之后则将before的next指向behind，这样就将中间重复的值的节点删去了。之后将before设置为当前的behind，继续执行相同的操作，删除下一个重复值的节点。

##NO.88 Merge Sorted Array
这道题和之前做过的两个有序链表合并(第21题)以及找两个有序数组的中位数(第4题)其实也差不多，只是这里可能涉及到更多的C++ vector的操作。因为这里是在其中一个数组的基础上添加进另一个有序数组，需要在该数组上进行插入删除等操作。

##NO.89 Gray Code
这道题首先必须了解格雷码是怎么表示的，一个很简单的自然二进制转格雷码的方法是：
从最右边一位起，依次将每一位与左边一位异或(XOR)，作为对应格雷码该位的值，最左边一位不变(相当于左边是0)。
比如011，转成格雷码之后就是010。其实就是011 XOR 001。
可以看出上述提到的这种转化方法其实就是 i XOR i/2。

##NO.92 Reverse Linked List II
这个题还算简单，熟悉链表操作即可，是206题的升级版。

##NO.94 Binary Tree Inorder Traversal
这个题就是求解二叉树的中序遍历。

##NO.100 Same Tree
这道题是关于二叉树的题，非常基础的题，递归思路。这道题主要就是熟悉二叉树的相关操作，这里给出了一个前序输入二叉树的函数。

##NO.101 Symmetric Tree
这道题是关于二叉树的题，判断一棵二叉树是否是对称二叉树，非常基础的题，递归思路。

##NO.102 Binary Tree Level Order Traversal
这道题是关于二叉树的题，递归思路，其实就是深度优先搜索DFS。

##NO.104 Maximum Depth of Binary Tree
这道题是关于二叉树的题，递归思路，也就是DFS的思路，还比较简单。
用一个变量maxdepth记录最大深度，每次二叉树遍历至某一个叶子节点便判断当前记录的depth和maxdepth的值的大小，更新maxdepth即可。

##NO.107 Binary Tree Level Order Traversal II
这道题是关于二叉树的题，递归思路，其实就是深度优先搜索DFS。
和102题类似，我这里就是将102题的思路搬过来了，然后对将数组反过来输出到另一个数组中。似乎这样不妥，应该还有其他方法。

##NO.110 Balanced Binary Tree
这个题比较朴素的算法就是对于一个二叉树求解左右子树的深度，然后比较两个左右子树的深度是否超过1，如果超过直接返回false。
否则继续判断左子树是否是平衡二叉树，如果不是直接返回false。如果是则继续判断右子树。整个过程都是递归的思想。

##NO.111 Minimum Depth of Binary Tree
这道题是关于二叉树的题，递归思路，也就是DFS的思路。这里递归需要判断的是左右子树都为空的时候才是叶子节点，才能进行depth的最终判断。这道题和112,257题类似。

##NO.112 Path Sum
这道题是关于二叉树的题，递归思路，也就是DFS的思路。这里递归需要判断的是左右子树都为空的时候才是叶子节点，才能进行sum的最终判断。这道题和257题求解二叉树的路径类似。

##NO.118 Pascal's Triangle
这个题比较简单，就是求解帕斯卡三角形，最简单的动态规划思路。
状态转移方程：pascaltriangle[i][j]=pascaltriangle[i-1][j-1]+pascaltriangle[i-1][j]

##NO.119 Pascal's Triangle II
* 这道题并没有想象中那么简单，一开始使用组合数来做，也就是每一行对应都有一个组合数的通项公式，第n行第k个是CnK。这里n和k都是从0开始。这样做毫无悬念的溢出了，换成了uint64_t都没用。
* 之后在网上看到一个非常巧妙的方法，很不错，而且空间复杂度是O(k)。就是在一个数组上进行操作，对于产生一个新的行用从后往前的方法来更新。每次都是getrow[j] = getrow[j-1] + getrow[j]。

##NO.125 Valid Palindrome
这个题主要就是判断回文串，但是是有干扰字符的回文串，如果先对字符串进行预处理，除去非字母数字的话会出现超时，因为字符串可能会很长，而实际上它并不是回文串。因此不能对其进行预处理，应该直接对其进行操作，从头部尾部往中间查找匹配，非字母数字的跳过。

##NO.136 Single Number
这个题非常简单的方法就是将所有数进行异或，出现两次的数进行异或就变成0了，只出现一次的数最终就会留下。

##NO.137 Single Number II
这道题是136题的升级版，比136更难一些，而且并不能像136题那样直接做异或就能求出那个单数。
这里的非单数出现的次数为3，主要思路是将每个数以二进制形式来做，从第一位到第32位，
将每一个数相同的二进制位的1的数量求出来，如果求出的1的数量是3的倍数，说明那个单数对应的这一位是0，
如果不是3的倍数，那么那个单数对应的这一位就是1。

##NO.144 Binary Tree Preorder Traversal
这个题就是求解二叉树的前序遍历。

##NO.145 Binary Tree Postorder Traversal
这个题就是求解二叉树的后序遍历。

##NO.160 Intersection of Two Linked Lists
这道题其实还算比较简单的，但是要求时间复杂度O(n)，空间复杂度O(1)还是有点意思的。
其实也比较容易想到解决方法：
* 1.首先需要遍历一遍两个链表，求出两个链表的节点个数。
* 2.之后用两个指针prevA, prevB指向两个链表头部，将节点个数多的链表的指针移至和另个链表 从指针位置到尾部的节点个数相同的位置。
因为如果要有相同的节点个数和节点值，首先个数是必须要相等的。这一步将节点个数多的链表的部分给过滤掉，方便接下来的比较。
* 3.然后开始两个指针进行遍历移动，初始的时候给定一个指针getintersect，存放最终结果的指针，初始指向任意两个链表移动指针任意一个，节点值相同则指针都往后移一个，节点值不同则首先将两个移动指针往后移一个，然后将getintersect指向其中任意一个，更新结果指针。

##NO.168 Excel Sheet Column Title
这道题比较简单，其实就和将int转成字符串类似，只是这里1->A,...26->Z。
这里需要注意的是，求模的时候要对n减一再求模，因为是从1开始的，1->A,...,26->Z。和NO.258 Add Digits类似。

##NO.169 Majority Element
这道题比较简单，思路很简单，就是对数组进行一个升序排列即可，然后找到出现次数最多的数，时间复杂度为O(n)。

##NO.171 Excel Sheet Column Number
这道题比较简单，和168题正好相反，这里是title转number，比168题还更简单，类似于字符串转int。

##NO.179 Largest Number
这个题主要就是利用sort函数，最关键的就是编写比较函数Comp，规则也很简单，将两个数a,b进行拼接，有两种拼接方式，
一种是ab，一种是ba，只需要比较这两种拼接方式哪一种能够使得拼接之后的数较大。但是这里不能通过以下方式进行：
比如ab拼接方式，a乘以10的x次方，x是b的位数，然后再和b相加，这样看似没问题，其实可能造成拼接之后的数溢出，超过int范围。
因此有两种解决办法:
* 1.一种是全部转换为一位一位的数，存入一个数组，然后一个个比较两个数组的数。
* 2.转换成string，然后拼接再比较。这种方法比较简单。

##NO.189 Rotate Array
这道题比较简单，提倡多种方法求解。目前使用的就是利用vector相关操作，按照规则做一遍实现的。

##NO.190 Reverse Bits
简单题，和求解十进制的整数反转类似。但是这里需要注意的一个问题是，这里必须循环32次，即使一个数的二进制表示，高位全是0在进行反转的时候高位变成了低位可以使得以前的低位变成高位。比如1011，应该完整表示为32位0000 0000 0000 0000 0000 0000 0000 1011，反转为1101 0000 0000 0000 0000 0000 0000 0000。而不能单纯的只是反转1011为1101。

##NO.191 Number of 1 Bits
这道题比较简单，就是求一个整数转化为二进制之后1的个数。按照求解一个整数的二进制表示法进行计算，得到1则计数加1即可。

##NO.198 House Robber
这道题是一道动态规划的题，之前还没怎么做过动态规划的题。这题算比较简单，状态转移方程为:
```cpp
maxV[i] = max(maxV[i-2]+nums[i], maxV[i-1]);
```

##NO.202 Happy Number
这道题还是比较简单。按照题目意思进行计算判断是否为happy number，如果是happy number最终会得到1，如果计算出现了之前的数则说明进入了无限循环中，没有1。

##NO.203 Remove Linked List Elements
这道题是链表操作的题，就是删除指定值的节点，比较简单。为方便起见，在链表头部添加了一个额外的节点-1。

##NO.204 Count Primes
* 这道题若是使用最直观简单的算法去实现时间复杂度将会是O(n^2)。最直观简单的算法就是循环遍历比n小的数，判断其是不是素数，
而判断是不是素数又需要从2到sqrt(i)进行遍历，判断是否有可以整除i的。
* 解题方法就在提示埃拉托斯特尼筛法Sieve of Eratosthenes中，
我们从2开始遍历到根号n，先找到第一个质数2，然后将其所有的倍数全部标记出来，然后到下一个质数3，
标记其所有倍数，依次类推，直到根号n，此时数组中未被标记的数字就是质数。我们需要一个n-1长度的bool型数组来记录每个数字是否被标记，长度为n-1的原因是题目说是小于n的质数个数，并不包括n。

##NO.205 Isomorphic Strings
这道题有点和242题同字母异序词的方法类似。也是使用一个hash表来处理。对于两个字符串s，t。
* 首先hash数组初始化为0，然后对s进行遍历，如果对应hash[s[i]]为0，说明对应的hash值还未更新，那么就可以将其更新为t[i]进行标记。
在后续中s字符串中若出现了相同的字符，则直接可得到其对应的hash值，将该hash值和当前的t[i]进行比较，如果相等则继续遍历，如果不等则说明不满足要求，直接输出false。
* 这里对s进行了操作之后，还需要对t进行相同的操作，并且hash数组需要重新初始化为0。
* 之所以要这么做是因为可能出现s是ab，t是aa这样的情况，也就是说s出现的不同字符数比t多，这样更新hash数组的话会出现a和b对应的值都为a，这样还是会返回true，而事实上是false。而如果换成对t遍历，则可以解决这个问题。

##NO.206 Reverse Linked List
这个题比较简单，链表翻转的题，熟悉链表操作即可。

##NO.217 Contains Duplicate
这道题非常简单，就是对数组进行一个排序，然后依次遍历排序后的数组，出现了重复数字即输出1，遍历完成之后若还没有重复，则最后输出0。时间复杂度是O(n)。

##NO.219 Contains Duplicate II
这道题本来是简单的，但是一开始使用的方法超时，时间复杂度有O(n*k)，之后换了一种方法，使用了STL中的set容器。写这个程序是首次学习C++ STL的set容器。
* 首先定义一个长度最大为k的滑动窗口，用一个set维护窗口内的数字判断是否出现重复，使用两个指针start和end标记滑动窗口的两端，
初始都是0，然后end不断进行扩展，扫描元素判断是否出现重复元素，直到发现end-start>k,就开始移动start，并且在set中移除start位置的元素。
* 然后进行下一轮的比较。如果end扫描到数组末尾还没有发现重复元素，那就可以返回false。

##NO.220 Contains Duplicate III
这道题是219题的升级版，方法类似。
* 首先定义一个长度最大为k的滑动窗口，用一个set维护窗口内的数字是否有相差在t内。
* 使用两个指针start和end标记滑动窗口的两端，初始都是0，然后end不断进行扩展，每次扩展就判断nums[end]和set中的元素。
* 查找nums[end]-t的lower_bound（二叉搜索树实现的？），第一个大于等于的元素，然后判断差值是否小于等于t，这样判断就能包括在-t~t的差值范围。
* 然后判断end-start>k, 就开始移动start，并且在set中移除start位置的元素。
* 然后进行下一轮的比较。如果end扫描到数组末尾还没有发现差值小于t的两个元素，那就可以返回false。

##NO.223 Rectangle Area
这个题应该算比较简单的数学题，但是我都没能想出来，竟然稍微看了一眼别人的博客，哎。。。
* 这个题就是求两个矩形的所有覆盖面积，重点就是求解两个矩形的相交面积，如果有相交就要减去相交的面积。
* 求解相交面积就要求解相交的矩形的两个对角点，左下角和右上角：
```cpp
int iA = max(A, E), iB = max(B, F);
int iC = min(C, G), iD = min(D, H);
```
这样(iA, iB)就是左下角的点，(iC, iD)就是右上角的点。
* 判断是否有相交的面积就是判断(iC, iD)是否在(iA, iB)的右上角，也就是iC>iA 且iD>iB，然后减去相交的面积即可。

##NO.226 Invert Binary Tree
这道题是关于二叉树的题，左右倒置二叉树，非常基础的题，递归思路，交换左右子树。

##NO.228 Summary Ranges
* 这个题还是比较简单的，遍历数组即可，出现相同或者连续的整数便继续往后遍历，直到出现当前整数和下一个整数相差超过1则停止遍历，
并将一头一尾的整数以a->b的字符串形式存入string容器中，如果一头一尾整数相同则只存入该整数对应的字符串。之后便继续往下遍历。
时间复杂度为O(n)。
* 这里主要是对整数转字符串的操作需要注意一下，这里我使用了stringstream来进行操作。在C++中可以使用stringstream来很方便的进行类型转换，字符串串接，不过注意重复使用同一个stringstream对象时要先继续清空，而清空很容易想到是clear方法，而在stringstream中这个方法实际上是清空stringstream的状态（比如出错等），真正清空内容需要使用.str("")方法。

##NO.231 Power of Two
这道题是目前写过的最短的程序了。判断一个整数n是否是2的n次方，一个非常巧妙和简单方法是，将n减去1，
然后将减去1之后的数与n进行与操作，若结果为0，则说明是2的n次方。
其原理是：一个数若是2的n次方，表示成二进制，则是100...00,如果减去1就是111...11，比n少一位，若两个数进行与操作，则得到的结果肯定为0。

##NO.234 Palindrome Linked List
这道题是链表操作的题，求一个链表是否是回文。有两种解决办法。
* 1.遍历一遍链表，并将节点的值存入数组中，然后对数组进行判断，这样就和判断回文串一样了。这种方法时间复杂度是O(n)，空间复杂度也是O(n)。
* 2.将链表从中间断开，分成两个链表，对后半段链表进行翻转，然后遍历两个链表依次比较节点的值。这种方法时间复杂度是O(n)，空间复杂度是O(1)。

##NO.235 Lowest Common Ancestor of a Binary Search Tree
这个题比较简单，是关于二叉搜索树的题目，查找任意两个节点的最近的祖先。
根据二叉搜索树的特点，左子树的数小于根节点的数，根节点的数小于右子树的数，使用递归思路，只需要判断当前根节点的值和需要判断的两个节点的值大小即可：
* 1.若根节点值都大于p和q节点的值，那么将根节点的左子树作为下一次查找的根节点继续查找。
* 2.若根节点值都小于p和q节点的值，那么将根节点的右子树作为下一次查找的根节点继续查找。
* 3.否则就说明p和q分别在当前根节点的左右两侧，则此时的根节点就是最近的祖先了。

##NO.237 Delete Node in a Linked List
这道题是链表操作的题，比较简单。但是这里有一个疑问，链表或者二叉树初始化时，
通过传参至一个函数或方法中去初始化，到底传参传普通参数还是引用或指针的指针呢？好像直接传指针的普通参数也可以啊。
<br/>
疑问解答：
* void f(NODE \*S)传了一个指针参数，这个参数是一个临时的变量在栈中，因此它的改变是不会改变指针的值(即实参的值)，但是由于是一个指针它可以改变S所指向的变量的值通过\*S或S->。
* void f(NODE\* &S)传了一个指针参数，但是是引用类型（其实引用类型就是为了代替C中的指针使其少用指针）引用类型相当于一个别名和操作实参是一样的，其改变会反映到实参因此这个指针值本身是可以改变的可以指向另一变量，当然可以通过它修改它所指向的对象的值。

##NO.238 Product of Array Except Self
这道题给定我们一个数组，让我们返回一个新数组，对于每一个位置上的数是其他位置上数的乘积，
并且限定了时间复杂度O(n)，并且不让我们用除法。如果让用除法的话，那这道题就应该属于Easy，而且事实上有些元素可能为0，做除法并不是好方法。
那么我们只能另辟蹊径。我们可以先遍历一遍数组，每一个位置上存之前所有数字的乘积。
那么一遍下来，最后一个位置上的数字是之前所有数字之积，是符合题目要求的，只是前面所有的数还需要在继续乘。
我们这时候再从后往前扫描，每个位置上的数在乘以后面所有数字之积，对于最后一个位置来说，由于后面没有数字了，所以乘以1就行。

##NO.242 Valid Anagram
这道题使用hash是非常简单的，而且时间复杂度为O(n)。
* 首先既然题目已经明说了只有小写字母，那么就定义一个hash表，长度是26，初始全为0，然后遍历第一个字符串，并更新hash表的值，
从i = 0开始，hash[s[i]-97]++。然后遍历第二个字符串t，hash[t[i]-97]--。
* 两个字符串都遍历完之后，hash表也更新完了，如果两个字符串是同字母异序词，那么最终hash表的值肯定还都是0。那么只需要遍历这个hash表，只要出现了值不为0的情况就返回0，说明就不是同字母异序词。否则则返回1。

##NO.257 Binary Tree Paths
这道题是关于二叉树的题，递归思路，也就是DFS的思路，最近写这种二叉树的DFS写的有点顺。
这里递归需要判断的是左右子树都为空的时候才是叶子节点，才能将路径添加至最终的结果路径容器中去。

##NO.258 Add Digits
简单题，如果仅仅就按照题目的意思的思路去写，这个题其实确实非常简单，没有什么难点。而题目建议能否不使用循环和递归，在O(1)的时间复杂度内完成。其实就是一个找规律的题。
```cpp
输入：1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
结果：1, 2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2 
```
根据上面的尝试，我们可以发现，这里是有规律的。即结果满足，（num-1）%9+1。 

##NO.260 Single Number III
这道题是136题的升级版，有多种方法，这里介绍两种：
* 1.将数组进行升序排列，然后就很容易查找非重复的数了。
* 2.另外一种方法就是使用位操作，首先先所有的数求一个异或值，就像136题一样，然后最终得到的肯定就是那两个单数的异或值。
然后求解digitone = result & (~(result-1))得到从低位到高位的第一个为1的位的值，也就是如果result为0110，经过该运算得到的是0010。
之后遍历将digitone和nums中的数进行与操作，结果非0和0区分开来进行异或，这样就可以将那两个单数区分开来，因为其他人任何数都是逢双出现，
那么和digitone与操作肯定结果一致，肯定就落到相同的区块进行异或了，最终肯定会异或除去。而只有这两个单数会根据digitone区分开来，一个为0，另一个非0。

##NO.263 Ugly Number
这道题比较简单。
只需要对num分别除去含2，3，5的因子，若最后是1，说明num就只有2，3，5这三个素数因子。
对于除去含2，3，5的因子，就是直接循环判断num是否被2整除，若是则继续除去2，直到不被2整除，再进行3和5的因子的除去操作。

##NO.264 Ugly Number II
这个题是Ugly Number的升级版，求解第n个丑陋数。
* 最直接的朴素算法是从1开始遍历，判断是不是丑陋数，直到第n个丑陋数。这种方法会超时，因为非丑陋数很多，直接从1开始遍历，遍历次数太多，而且判断丑陋数也要占一部分时间。
* 比较好的一种算法是使用一个数组，用于从小到大顺序存储n个丑数，数组中的首项为1，即第一个丑数为1。设置三个变量index1、index2、index3存储下标，初始值都为0，找出数组uglyNumbers[index1]\*2、uglyNumbers[index2]\*3、uglyNumbers[index3]\*5的最小值，最小值即为下一个丑数，同时更新最小值对应的下标，下标加1，如果多个数字同时为最小值，则它们的下标都要加1。

##NO.268 Missing Number
这道题非常简单，就是找到那个0~n那个缺失的数字，首先求解0~n的所有数的和，然后再求解整个nums数组的和，两者相减就得到那个缺失的数字了。

##NO.283 Move Zeroes
这道题本来是简单的，但是今天不知道怎么了，脑子锈掉了，这么简单的题都做了半天。
昨天，学长还说他面试面了这题，这要是我面试岂不是完全跪了，这么简单的题都做不出来了。哎。。。
这道题最简单的思路就是直接在当前数组操作，用一个标记pos，初始为0，将非0的数全部移到前面，移完之后再将0补全，直到pos = size-1。
泪奔啊，这么简单的题啊。
