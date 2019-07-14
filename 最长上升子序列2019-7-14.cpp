//题目要求：
//给定一个无序的整数数组，找到其中最长上升子序列的长度。

//时间复杂度O(nlog2n),空间复杂度O(n)
//按顺序访问原数列，将访问到的元素逐一放到新的序列中去，遇到比新序列中元素小的数就更新新序列，否则就继续向新序列中放新的元素
//这样，新更新进来的小的元素相当于之前的小的元素，后增加的新元素就相当于跟在原先小的元素之后的元素，最终生成的数列长度即为最短上升子序列

//https://leetcode-cn.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int> & nums)
    { 
        vector<int> arr;
        for(auto num : nums)
        {
            if(arr.empty() || num > arr.back())
            {
                arr.push_back(num);
            }
            else
            {
                *(lower_bound(arr.begin(), arr.end(), num)) = num;
            }
        }
        return arr.size();
    }
};
