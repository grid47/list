
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1090: Largest Values From Labels"
date = "2021-11-04"
description = "Solution to Leetcode 1090"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-values-from-labels/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        multimap<int, int> s;
        unordered_map<int, int> m;
        for(int i = 0; i < values.size(); i++) 
            s.insert({values[i], labels[i]});
        int res = 0;
        for(auto it = rbegin(s); it != rend(s) && numWanted > 0; it++) {
            if(++m[it->second] <= useLimit) {
                res += it->first;
                --numWanted;                
            }
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

