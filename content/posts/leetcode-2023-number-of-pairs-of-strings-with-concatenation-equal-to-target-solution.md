
+++
authors = ["grid47"]
title = "Leetcode 2023: Number of Pairs of Strings With Concatenation Equal to Target"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2023: Number of Pairs of Strings With Concatenation Equal to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Counting"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2023.md" >}}
---
{{< youtube dEwKOofWa3U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2024: Maximize the Confusion of an Exam](https://grid47.xyz/posts/leetcode-2024-maximize-the-confusion-of-an-exam-solution/) |
| --- |
