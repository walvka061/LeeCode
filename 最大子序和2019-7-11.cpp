//题目要求：
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

//时间复杂度O(n),空间复杂度O(1)
//使用一个buf来存储当前和，如果当前和小于0，那么找到下一个正数来重新作为起始点（正数肯定是大于负数的对吧，在这个过程中已经开始寻找一个正和的数据串）
//使用另一个buf来存储当前最大和，最终返回它就行
//这就是动态规划么。。。

//https://leetcode-cn.com/problems/maximum-subarray/
/*
dp[i] = max(dp[i-1]+nums[i], nums[i])
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int num_buf = nums[0];
        int ans = nums[0];
        int i = 0;
        
        for(i=1;i<nums.size();i++)
        {
            if(num_buf>0)
            {
                num_buf = num_buf + nums[i];
            }
            else
            {
                num_buf = nums[i];
            }
            
            ans = max(ans, num_buf);
        }
        
        return ans;
    }
};
