
+++
authors = ["Crafted by Me"]
title = "Leetcode 2141: Maximum Running Time of N Computers"
date = "2018-12-23"
description = "In-depth solution and explanation for Leetcode 2141: Maximum Running Time of N Computers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-running-time-of-n-computers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool mx(int n, vector<int>& bat, long long mid) {

        long long net = 0;
        for(int i = 0; i < bat.size(); i++) {
            net += min((long long)bat[i], mid);
        }

        return net >= mid * n;
    }
    long long maxRunTime(int n, vector<int>& bat) {
        long long sum = accumulate(bat.rbegin(), bat.rend(), 0L);

        long long l = 0, r = sum / n, ans = 0;
        while(l <= r) {
            long long mid = l + (r - l + 1) / 2;
            if (mx(n, bat, mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

