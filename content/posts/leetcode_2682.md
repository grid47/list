
+++
authors = ["Crafted by Me"]
title = "Leetcode 2682: Find the Losers of the Circular Game"
date = "2017-06-30"
description = "In-depth solution and explanation for Leetcode 2682: Find the Losers of the Circular Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> rcvd(n, 0);
        int i = 0;
        int cnt = 1;
        rcvd[0] = 1;
        while(rcvd[i] == 1) {
            i = (i + cnt * k) % n;            
            if(rcvd[i] == 1) break;
            rcvd[i] = 1;
            cnt++;
        }
        vector<int> ans;
        for(int j = 0; j < n; j++) {
            // cout << rcvd[j] << " ";
            if(rcvd[j] == 0) ans.push_back(j + 1);            
        }

        return ans;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2683: Neighboring Bitwise XOR](https://grid47.xyz/posts/leetcode_2683) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

