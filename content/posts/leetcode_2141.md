
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2141: Maximum Running Time of N Computers"
date = "2018-12-20"
description = "Solution to Leetcode 2141"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
