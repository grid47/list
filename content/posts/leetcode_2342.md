
+++
authors = ["Crafted by Me"]
title = "Leetcode 2342: Max Sum of a Pair With Equal Sum of Digits"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2342: Max Sum of a Pair With Equal Sum of Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        
        map<int, int> mp;
        
        int ans = -1;
        
        for(int x: nums) {
            int sum = 0;
            int tmp = x;
            while(tmp > 0) {
                sum += (tmp % 10);
                tmp /= 10;
            }
            if(mp.count(sum)) {
                ans = max(ans, x + mp[sum]);
                mp[sum] = max(x, mp[sum]);
            } else {
                mp[sum] = x;
            }
        }
        
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube uOPtnfVSFuQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2343: Query Kth Smallest Trimmed Number](https://grid47.xyz/posts/leetcode_2343) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

