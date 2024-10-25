
+++
authors = ["Yasir"]
title = "Leetcode 854: K-Similar Strings"
date = "2022-06-26"
description = "Solution to Leetcode 854"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-similar-strings/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int kSimilarity(string s1, string s2) {
        queue<string> q;
        q.push(s1);
        int level = 0;
        
        unordered_set<string> seen;
        seen.insert(s1);
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {

                string node = q.front(); q.pop();

                if(node == s2) return level;
                
                for(auto nbr : next(node, s2))
                    if(seen.find(nbr) == seen.end()) {
                        seen.insert(nbr);
                        q.push(nbr);
                    }

            }
            level++;
        }
        return level;
    }
    
    unordered_set<string> next(string a, string b) {
        int i = 0;
        for(; i < a.size(); i++)
            if(a[i] != b[i]) break;
        
        unordered_set<string> res;
        for(int j = i + 1; j < a.size(); j++)
            if(a[j] == b[i]) {
                swap(a[i], a[j]);
                res.insert(a);
                swap(a[i], a[j]);
            }
        return res;
    }
};
{{< /highlight >}}

