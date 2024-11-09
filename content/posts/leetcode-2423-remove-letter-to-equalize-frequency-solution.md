
+++
authors = ["grid47"]
title = "Leetcode 2423: Remove Letter To Equalize Frequency"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2423: Remove Letter To Equalize Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-letter-to-equalize-frequency/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> mp;
        map<int, int> mp2;
        for(auto c: word)  mp[c]++;
        
        for(auto m: mp)  mp2[m.second]++;
        
        
        if(mp2.size() > 2) return false;
        map<int, int>::iterator it1 = mp2.begin();
        map<int, int>::iterator it2 = mp2.begin();
        it2++;
        
        if(mp2.size() == 1){
            if(mp.size() == 1 || it1->first == 1) return true;
            return false;
        }
       
        
        if(it1->first == 1 && it1->second == 1) return true;
        if(it1->first == it2->first-1 && it2->second == 1) return true;
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2423.md" >}}
---
{{< youtube wXKif4MwAtI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2424: Longest Uploaded Prefix](https://grid47.xyz/posts/leetcode-2424-longest-uploaded-prefix-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
