
+++
authors = ["Crafted by Me"]
title = "Leetcode 480: Sliding Window Median"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 480: Sliding Window Median in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window","Heap (Priority Queue)"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sliding-window-median/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> win(nums.begin(), nums.begin() + k);
        
        auto mid = next(win.begin(), k/2);
        vector<double> ans;


        for(int i = k; ; i++) {
            
            double med =  ((double)*mid + (double)*prev(mid, 1 - k%2)) / 2;
            ans.push_back(med);
            
            if(i == nums.size()) return ans;
            
            win.insert(nums[i]);
            if(nums[i] < *mid) // mutiset insertion happens from upper end
                mid--;

            if(nums[i - k] <= *mid)
                mid++;
            win.erase(win.lower_bound(nums[i - k]));

        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/480.md" >}}
---
{{< youtube KJ2EYhMQ1R0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #481: Magical String](https://grid47.xyz/posts/leetcode_481) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
