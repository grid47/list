
+++
authors = ["Yasir"]
title = "Leetcode 451: Sort Characters By Frequency"
date = "2023-08-05"
description = "Solution to Leetcode 451"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-characters-by-frequency/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(bucket[i].size())
                res.append(bucket[i]);
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

