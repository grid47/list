
+++
authors = ["Crafted by Me"]
title = "Leetcode 2007: Find Original Array From Doubled Array"
date = "2018-05-05"
description = "Solution to Leetcode 2007"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-original-array-from-doubled-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& chg) {
        
        if(chg.size() % 2) return vector<int>{};
        
        sort(chg.begin(), chg.end());
        map<int, int> mp;
        for(int i = 0; i < chg.size(); i++)
            mp[chg[i]]++;
        vector<int> ans;
        
        int i = 0;

        while((ans.size() < chg.size() / 2) && i < chg.size()) {
            
            if(chg[i] == 0) {
                if(mp[chg[i]] >= 2) {
                    mp[chg[i]] -= 2;
                    ans.push_back(chg[i]);                    
                }
                i++;
                continue;
            }
            
            if((mp.count(chg[i]) && mp.count(chg[i] * 2))) {
                ans.push_back(chg[i]);
                
                if(mp[chg[i]] == 1)
                mp.erase(chg[i]);
                else
                mp[chg[i]]--;
                
                if(mp[chg[i] * 2] == 1)
                mp.erase(chg[i] * 2);
                else
                mp[chg[i] * 2]--;                
                
                // cout << chg[i]     << " " << mp[chg[i]    ] << "\n";                
                // cout << chg[i] * 2 << " " << mp[chg[i] * 2] << "\n";
            }
            
            i++;
        }
        
        return ans.size() == chg.size() / 2? ans: vector<int>{};
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

