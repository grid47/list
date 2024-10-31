
+++
authors = ["Crafted by Me"]
title = "Leetcode 811: Subdomain Visit Count"
date = "2022-08-13"
description = "Solution to Leetcode 811"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

