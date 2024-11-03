
+++
authors = ["Crafted by Me"]
title = "Leetcode 2405: Optimal Partition of String"
date = "2018-04-03"
description = "In-depth solution and explanation for Leetcode 2405: Optimal Partition of String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/optimal-partition-of-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkBit(int &flag, int &n) {
        return flag & (1<< n);
    }

    void setBit(int &flag, int & n) {
        flag |= (1<<n);
    }

    int partitionString(string s) {
        int flag = 0, ans = 1;
        for(auto c: s) {
            int n = c - 'a';
            if(checkBit(flag, n)) {
                flag = 0;
                ans++;
            }
            setBit(flag, n);
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube 1Zx7gEznzfI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2406: Divide Intervals Into Minimum Number of Groups](https://grid47.xyz/posts/leetcode_2406) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

