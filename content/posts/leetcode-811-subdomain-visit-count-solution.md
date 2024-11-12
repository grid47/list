
+++
authors = ["grid47"]
title = "Leetcode 811: Subdomain Visit Count"
date = "2024-08-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 811: Subdomain Visit Count in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subdomain-visit-count/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count;

        for(auto cp: cpdomains) {
            int i = cp.find(" ");
            int n = stoi(cp.substr(0, i));
            string s = cp.substr(i + 1);
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == '.')
                    count[s.substr(i + 1)] += n;
            }
            count[s] += n;
        }
        vector<string> res;
        for(auto it: count)
        res.push_back(to_string(it.second) + " " + it.first);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/811.md" >}}
---
{{< youtube oe_eXlH5dUM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #813: Largest Sum of Averages](https://grid47.xyz/posts/leetcode-813-largest-sum-of-averages-solution/) |
| --- |
