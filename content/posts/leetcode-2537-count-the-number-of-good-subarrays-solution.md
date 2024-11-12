
+++
authors = ["grid47"]
title = "Leetcode 2537: Count the Number of Good Subarrays"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2537: Count the Number of Good Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-good-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0, tmp = 0;
        
        int n = nums.size();
        
        map<int, int> mp, cnt;
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            tmp += (cnt[nums[i]]);
            cnt[nums[i]]++;            
            while(j <= i && tmp >= k) {
                res+= (n - i);
                cnt[nums[j]]--;
                tmp -= cnt[nums[j]];
                j++;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2537.md" >}}
---
{{< youtube X4wzXCe1wvs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2540: Minimum Common Value](https://grid47.xyz/posts/leetcode-2540-minimum-common-value-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
