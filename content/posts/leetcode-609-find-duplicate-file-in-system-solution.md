
+++
authors = ["grid47"]
title = "Leetcode 609: Find Duplicate File in System"
date = "2024-09-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 609: Find Duplicate File in System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-duplicate-file-in-system/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for(auto path: paths) {
            stringstream ss(path);
            string root;
            string s;
            getline(ss, root, ' ');
            while(getline(ss, s, ' ')) {
                string fileName = root + '/' + s.substr(0, s.find('('));
                string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(')-1);
                mp[fileContent].push_back(fileName);
            }
        }

        for (auto file : mp) {
            if(file.second.size() > 1)
            result.push_back(file.second);
        }

        return result;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/609.md" >}}
---
{{< youtube 3GP6BA1oXQw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #611: Valid Triangle Number](https://grid47.xyz/posts/leetcode-611-valid-triangle-number-solution/) |
| --- |
