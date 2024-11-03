
+++
authors = ["Crafted by Me"]
title = "Leetcode 2090: K Radius Subarray Averages"
date = "2019-02-12"
description = "In-depth solution and explanation for Leetcode 2090: K Radius Subarray Averages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-radius-subarray-averages/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> psum(n, 0);
        vector<int> avg(n, 0);
        psum[0] = nums[0];
        for(int i = 1; i < n; i++)
            psum[i] = psum[i - 1] + nums[i];
        
        for(int i = 0; i < n; i++) {
            if(i - k < 0 || i + k >= n) {
                avg[i] = -1;
            } else {
                avg[i] = (psum[i + k] - ((i - k) == 0? 0: psum[i - k - 1])) / (2 * k + 1);
            }
        }
        return avg;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

