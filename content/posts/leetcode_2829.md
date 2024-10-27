
+++
authors = ["Yasir"]
title = "Leetcode 2829: Determine the Minimum Sum of a k-avoiding Array"
date = "2017-01-29"
description = "Solution to Leetcode 2829"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0;
        vector<int> vis(51, 0);
        int i = 1;
        while(n > 0 && i <= k) {
            if(!vis[i] && !vis[k - i]) {
                n--;                
                sum += i;
                vis[i] = true;
            }
            i++;
        }
        while(n--) {
            sum += i++;
        }
        return sum;
    }
};
{{< /highlight >}}

