
+++
authors = ["grid47"]
title = "Leetcode 2942: Find Words Containing Character"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2942: Find Words Containing Character in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "gJCrdytYtDY"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/find-words-containing-character/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            if (check(words[i], x)) result.push_back(i);
        }
        return result;
    }
private:
    bool check(string& word, char x) {
        for (auto& c : word) {
            if (c == x) return true;
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2942.md" >}}
---
{{< youtube gJCrdytYtDY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2943: Maximize Area of Square Hole in Grid](https://grid47.xyz/leetcode/solution-2943-maximize-area-of-square-hole-in-grid/) |
| --- |
