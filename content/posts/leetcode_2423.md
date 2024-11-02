
+++
authors = ["Crafted by Me"]
title = "Leetcode 2423: Remove Letter To Equalize Frequency"
date = "2017-03-15"
description = "Solution to Leetcode 2423"
tags = [
    
]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

