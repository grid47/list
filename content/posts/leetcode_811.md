
+++
authors = ["Yasir"]
title = "Leetcode 811: Subdomain Visit Count"
date = "2022-08-09"
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

{{< highlight html >}}
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

