
+++
authors = ["Yasir"]
title = "Leetcode 1487: Making File Names Unique"
date = "2020-10-02"
description = "Solution to Leetcode 1487"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/making-file-names-unique/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string, int> mp;
        
        for(int i = 0; i < names.size(); i++) {
            
            if(mp.count(names[i])) {
                int k = mp[names[i]];
                while(mp.count(names[i] + "(" + to_string(k) + ")")) {
                    k++;
                    mp[names[i]]++;
                }
                mp[names[i]]++;
                names[i] = names[i] + "(" + to_string(k) + ")";
            }

            mp[names[i]] = 1;
        }
        return names;
    }
};
{{< /highlight >}}

