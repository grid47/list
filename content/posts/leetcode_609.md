
+++
authors = ["Crafted by Me"]
title = "Leetcode 609: Find Duplicate File in System"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 609: Find Duplicate File in System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #610: Triangle Judgement](https://grid47.xyz/posts/leetcode_610) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

