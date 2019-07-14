//题目要求：
//给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

//时间复杂度O(n),空间复杂度O(1)
//通过拼接字符串来实现字符串比较

//https://leetcode-cn.com/problems/largest-number/

作者：ivan_allen
链接：https://leetcode-cn.com/problems/two-sum/solution/179-zui-da-shu-ji-yu-stl-by-ivan_allen/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            auto aa = to_string(a);
            auto bb = to_string(b);
            return aa + bb > bb + aa;
        });
        
        return accumulate(nums.begin(), nums.end(), string(), [](std::string a, int b) {
            if (a == "0") {
                return to_string(b);
            }
            return std::move(a) + to_string(b);
        });
    }
};


