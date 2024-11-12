
+++
authors = ["grid47"]
title = "Leetcode 2226: Maximum Candies Allocated to K Children"
date = "2024-03-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2226: Maximum Candies Allocated to K Children in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool can(vector<int>& candies, long long kids, int per) {
        long long cnt = 0;
        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] < per) continue;
            
            int tmp = candies[i];
            cnt+= tmp/per;
        }
        
        return cnt >= kids;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        
        long long sum = accumulate(candies.begin(), candies.end(), 0L);
        if(sum < k) return 0;
        
        int l = 1, r = *max_element(candies.begin(), candies.end());
        int ans = 0;
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(can(candies, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2226.md" >}}
---
{{< youtube Y2V4hLvjn10 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2231: Largest Number After Digit Swaps by Parity](https://grid47.xyz/posts/leetcode-2231-largest-number-after-digit-swaps-by-parity-solution/) |
| --- |
