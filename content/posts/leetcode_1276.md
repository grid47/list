
+++
authors = ["Yasir"]
title = "Leetcode 1276: Number of Burgers with No Waste of Ingredients"
date = "2021-05-01"
description = "Solution to Leetcode 1276"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> ans;
    map<int, map<int, bool>> mp;
    bool dp(int tmt, int chs, int one, int two) {
        if(tmt <= 0 || chs <= 0) {
            if(tmt == 0 && chs == 0) {
                ans = {one, two};
                return true;
            }
            return false;
        }
        
        if(mp.count(tmt) && mp[tmt].count(chs)) return mp[tmt][chs];
        
        if(tmt >= 4 && chs >= 1) {
            if(dp(tmt - 4, chs -1, one + 1, two))
                return mp[tmt][chs] = true;
            if(dp(tmt - 2, chs -1, one, two + 1))
                return mp[tmt][chs] = true;
        } else if(tmt >= 2 && chs >= 1) {
            if(dp(tmt - 2, chs -1, one, two + 1))
                return mp[tmt][chs] = true;            
        }
        return mp[tmt][chs] = false;
    }
    
    vector<int> numOfBurgers(int tmt, int chs) {
        ans = {};
        // dp(tmt, chs, 0, 0);
        int net = chs;
        int jumbo = (tmt - 2 * chs ) / 2;
 
        if(((tmt - 2 * chs ) < 0) || ((tmt - 2 * chs ) % 2) || (net - jumbo < 0)) return ans;
        
        return {jumbo, net - jumbo};
    }
};
{{< /highlight >}}

