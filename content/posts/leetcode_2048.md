
+++
authors = ["Crafted by Me"]
title = "Leetcode 2048: Next Greater Numerically Balanced Number"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2048: Next Greater Numerically Balanced Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/next-greater-numerically-balanced-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> base = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666 };
    int nextBeautifulNumber(int n) {
        int res = 1224444;
        
        string s = to_string(n);
        for(auto it: base) {
            string ss = to_string(it);
            if(ss.size() < s.size()) continue;
            if(ss.size() > s.size()) res = min(res, it);
            else {
                do {
                    if(ss > s) {
                        res = min(res, stoi(ss));
                    }
                } while(next_permutation(ss.begin(), ss.end()));
            }
        }
        return res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2049: Count Nodes With the Highest Score](https://grid47.xyz/posts/leetcode_2049) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

