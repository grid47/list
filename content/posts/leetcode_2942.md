
+++
authors = ["Yasir"]
title = "Leetcode 2942: Find Words Containing Character"
date = "2016-10-08"
description = "Solution to Leetcode 2942"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-words-containing-character/description/)

---

**Code:**

{{< highlight html >}}
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

