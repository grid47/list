
+++
authors = ["Crafted by Me"]
title = "Leetcode 1023: Camelcase Matching"
date = "2021-01-13"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

