
+++
authors = ["grid47"]
title = "Leetcode 2007: Find Original Array From Doubled Array"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2007: Find Original Array From Doubled Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "z40B-Mr9_qk"
youtube_upload_date="2021-09-18"
youtube_thumbnail="https://i.ytimg.com/vi/z40B-Mr9_qk/maxresdefault.jpg"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2007.md" >}}
---
{{< youtube z40B-Mr9_qk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2008: Maximum Earnings From Taxi](https://grid47.xyz/leetcode/solution-2008-maximum-earnings-from-taxi/) |
| --- |