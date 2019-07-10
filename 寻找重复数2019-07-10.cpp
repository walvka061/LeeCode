//题目要求：
//给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n /之间（包括 1 和 n），
//可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

//时间复杂度O(n),空间复杂度O(1)
//通过寻找环来确定相同值的位置
//先找到环的入口，再让一个下标在环中循环，另一个下标进入环即可
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        i = nums[i];
        j = nums[nums[j]];
        
        while(nums[i]!=nums[j])
        { 
            i = nums[i];
            j = nums[nums[j]];
        };
        
        i = nums[0];
        j = nums[j];
        
        while(i!=j)
        {
            i = nums[i];
            j = nums[j];
        }
        
        return i;
    }
};
