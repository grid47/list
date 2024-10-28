
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2064: Minimized Maximum of Products Distributed to Any Store"
date = "2019-03-06"
description = "Solution to Leetcode 2064"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

