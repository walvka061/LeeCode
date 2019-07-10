//题目要求：
//给定一个整数数组 nums，按要求返回一个新数组 ：counts。
//数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

//时间复杂度O(nlogn),空间复杂度O(n),因为要分配一块与匹配对象相符长度的空间
//通过归并排序来得到右侧比当前左侧选中的数小的个数，迭代来获得最终结果
//ivan_allen原创 https://leetcode-cn.com/u/ivan_allen

class Solution {
public:
    using pii = pair<int, int>; //别名 <number, index>
    vector<int> countSmaller(vector<int>& nums) {
        vector<pii> v;
        v.reserve(nums.size());//预留出足够的空间，而不是使用resize重新分配空间
        
        for (int i = 0; i < nums.size(); ++i) {
            v.emplace_back(nums[i], i);//C++11中加入，省去了构造函数和拷贝构造函数的过程，直接在容器中构造对象
        }
        
        vector<int> res(v.size());
        merge_sort(v, 0, v.size(), res);
        return res;
    }
    
    void merge_sort(vector<pii>& nums, int lo, int hi, vector<int>& res) {
        if (hi - lo <= 1) return; // 元素个数 <= 1 终止。
        int mid = lo + (hi - lo >> 1);
        merge_sort(nums, lo, mid, res);//迭代，缩小比较对
        merge_sort(nums, mid, hi, res);
        
        int right = mid;
        
        // 对于左半区间中的每个元素 left，统计右侧比它小的元素的个数
        for (int left = lo; left < mid; ++left) {
            while (right != hi && nums[left] > nums[right]) ++right;
            res[nums[left].second] += right - mid;//找到小的数就可以了
        }
        
        inplace_merge(nums.begin() + lo, nums.begin() + mid, nums.begin() + hi);//偷了个懒，用inplace_merge直接排序，重新排列数组
    }
};
