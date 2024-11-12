
+++
authors = ["grid47"]
title = "Leetcode 2064: Minimized Maximum of Products Distributed to Any Store"
date = "2024-04-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2064: Minimized Maximum of Products Distributed to Any Store in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool isPossible(vector<int>& qnty, int mid, int m, int n) {

        int cnt = 0;
            
        for(int i = 0; i < m; i++) {
            if(qnty[i] <= mid) {
                cnt++;
                continue;
            }
            // if(mid == 1) cout << qnty[i];
            int num = qnty[i];
            cnt++;
            while(num > mid) {
                cnt++;
                num -= mid;
            }
        }
        // cout << mid << " " << cnt << " " << n << "\n";
        
        return (cnt <= n);
    }
    
    int minimizedMaximum(int n, vector<int>& qnty) {
        
        int m = qnty.size();
        
        int ans = *max_element(qnty.begin(), qnty.end());
        
        int l = 1, r = ans - 1;
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            // cout << mid << " ";
            if(isPossible(qnty, mid, m, n)) {
                // cout << mid << " ";
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2064.md" >}}
---
{{< youtube J6D5xPSlGHY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2068: Check Whether Two Strings are Almost Equivalent](https://grid47.xyz/posts/leetcode-2068-check-whether-two-strings-are-almost-equivalent-solution/) |
| --- |
