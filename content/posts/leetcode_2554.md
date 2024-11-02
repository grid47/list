
+++
authors = ["Crafted by Me"]
title = "Leetcode 2554: Maximum Number of Integers to Choose From a Range I"
date = "2016-11-04"
description = "Solution to Leetcode 2554"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    unordered_map<int, bool> mp;
    
    int maxCount(vector<int>& ban, int n, int mxS) {
        // this->n = n;
        for(int x: ban)
            mp[x] = true;

        // memset(memo, -1, sizeof(memo));
        // memo.resize(n + 1);
        // return dp(1, mxS);
        int cnt = 0;
        for(int i = 1; i < n + 1; i++) {
            if(!mp.count(i) && mxS >= i) {
                cnt++;
                mxS -= i;
            }
            if(mxS < 0) break;
        }
        return cnt;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

