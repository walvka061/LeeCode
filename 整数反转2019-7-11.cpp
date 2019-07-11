//题目要求：
//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

//时间复杂度O(n),空间复杂度O(1)

//https://leetcode-cn.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int data_buf=0;
        long long rev = 0;
        while (x != 0) {
            data_buf = x % 10;
            x /= 10;
            rev = rev * 10 + data_buf;
            if (rev > 0x7fffffff || rev < (signed int)0x80000000)
            {
                return 0;
            }
        }
        return rev;
    }
};


//coxue原创https://leetcode-cn.com/problems/two-sum/solution/cyu-yan-ti-jie-zheng-shu-fan-zhuan-by-coxue/
int reverse(int x)
{
    int a;
    int i;
    long c=0;
    
    for(i=0;i<20;i++)
    {
        a=x%10;
        x=x/10;
        c=a+c*10;
       if( c>0x7fffffff || c<(signed int)0x80000000)
       {
           return 0;
       }
        if(x==0)
            break;
    }

 
        return c;

}
