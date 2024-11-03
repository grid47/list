
+++
authors = ["Crafted by Me"]
title = "Leetcode 2653: Sliding Subarray Beauty"
date = "2017-07-29"
description = "In-depth solution and explanation for Leetcode 2653: Sliding Subarray Beauty in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sliding-subarray-beauty/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<int> cnt;
    
    int no(int x) {
        int sum = 0;
        for(int i = 0; i <= 50; i++) {
            sum += cnt[i];
            if(sum >= x)
                return i - 50;
        }
        return 0;
    }
    
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        cnt.resize(101, 0);
        
        vector<int> ans;
        
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            cnt[nums[i] + 50]++;            
        }
        ans.push_back(no(x));

        for(int i = k; i < n; i++) {
            cnt[nums[i] + 50]++;
            cnt[nums[i - k] + 50]--;
            
            ans.push_back(no(x));
        }
        
        return ans;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2654: Minimum Number of Operations to Make All Array Elements Equal to 1](https://grid47.xyz/posts/leetcode_2654) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

