
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2942: Find Words Containing Character"
date = "2016-10-11"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

