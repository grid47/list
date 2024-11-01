
+++
authors = ["Crafted by Me"]
title = "Leetcode 2829: Determine the Minimum Sum of a k-avoiding Array"
date = "2017-02-03"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

