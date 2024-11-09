
+++
authors = ["grid47"]
title = "Leetcode 2226: Maximum Candies Allocated to K Children"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2231: Largest Number After Digit Swaps by Parity](https://grid47.xyz/posts/leetcode-2226-maximum-candies-allocated-to-k-children-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
