
+++
authors = ["Crafted by Me"]
title = "Leetcode 2023: Number of Pairs of Strings With Concatenation Equal to Target"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2023: Number of Pairs of Strings With Concatenation Equal to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> freq;
        for(auto num : nums) if(num.size() < target.size()) freq[num]++;

        int res = 0;
        for(auto [s, frq]: freq) {
            if(target.find(s) == 0) {
                if(s + s == target) 
                res += frq * (frq - 1);
                else
                res  += frq * freq[target.substr(s.size())];
            }
        }
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube dEwKOofWa3U >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2024: Maximize the Confusion of an Exam](https://grid47.xyz/posts/leetcode_2024) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

