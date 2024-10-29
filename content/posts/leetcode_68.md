
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 68: Text Justification"
date = "2024-08-23"
description = "Solution to Leetcode 68"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/text-justification/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        const int n = words.size();
        int begin = 0, len = 0;
        for (int i = 0; i < n; ++i) {
            if (len + words[i].size() + (i - begin) > maxWidth) {
                res.emplace_back(connect(words, maxWidth, begin, i, len, false));
                begin = i;
                len = 0;
            }
            len += words[i].size();
        }
        res.emplace_back(connect(words, maxWidth, begin, n, len, true));
        return res;
    }
private:
    string connect(const vector<string>& words, int maxWidth, int begin, int end, int len, bool is_last) {

        string s;
        int n = end - begin;
        for (int i = 0; i < n; ++i) {
            s += words[begin + i];
            addSpaces(i, n - 1, maxWidth - len, is_last, &s);
        }

        if (s.size() < maxWidth) {
            s.append(maxWidth - s.size(), ' ');
        }

        return s;
    }
    void addSpaces(int i, int spaceCnt, int maxWidth, bool is_last, string *s) {
        if (i < spaceCnt) {
            int spaces = is_last ? 1 : maxWidth / spaceCnt + (i < maxWidth % spaceCnt);
            s->append(spaces, ' ');
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/68.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

