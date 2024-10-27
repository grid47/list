
+++
authors = ["Yasir"]
title = "Leetcode 1023: Camelcase Matching"
date = "2022-01-09"
description = "Solution to Leetcode 1023"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/camelcase-matching/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        vector<bool> res;
        
        for(string q: queries) {
            
            bool ret = match(q, pattern);
            
            res.push_back(ret);
        }

        return res;
    }
    
    bool match(string q, string p) {
        
        int j = 0;
        
        for(int i = 0; i < q.size(); i++) {
            
            if(j < p.size()&&q[i] == p[j]) {
                j++;
                continue;
            }else if(q[i] >= 'A' && 
               q[i] <= 'Z')
                return false;               
               
        }
        
        return j == p.size();
        
    }

};
{{< /highlight >}}

