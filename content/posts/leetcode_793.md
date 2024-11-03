
+++
authors = ["Crafted by Me"]
title = "Leetcode 793: Preimage Size of Factorial Zeroes Function"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 793: Preimage Size of Factorial Zeroes Function in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    long count5(long x) {
        long cnt = 0;
        while(x > 0) {
            cnt += x / 5;
            x /= 5;
        }
        return cnt;
    }
    
    long bigWithK(int k) {
        // if(k == -1) return -1;
        long l = 1, r = LLONG_MAX - 1;
        long ans = -1;
        while(l <= r) {
            long mid = l + (r - l + 1) / 2;
            long cnt = count5(mid);
            if(cnt > k) {
                ans = mid;
                r = mid - 1;
            } else {
                // ans = mid;
                l = mid + 1;
            }
        }
        // cout << ans << " ";
        return ans;
    }
    
    int preimageSizeFZF(int k) {
        if(k == 0) return 5;
        long a1 = bigWithK(k);
        long a2 = bigWithK(k - 1);        
        return a1 - a2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/793.md" >}}
---
{{< youtube sUrsII_fvJE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #794: Valid Tic-Tac-Toe State](https://grid47.xyz/posts/leetcode_794) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

