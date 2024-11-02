
+++
authors = ["Crafted by Me"]
title = "Leetcode 2559: Count Vowel Strings in Ranges"
date = "2016-10-30"
description = "Solution to Leetcode 2559"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-vowel-strings-in-ranges/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        int n = words.size();
        vector<int> cnt(n, 0), ans(q.size(), 0);
        set<char> ch = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < n; i++) {
            if(ch.count(words[i][0]) && ch.count(words[i][words[i].size() -1]))
                cnt[i] = 1;
            if(i > 0) cnt[i] += cnt[i - 1];
        }
        for(int i= 0; i < q.size(); i++) {
            ans[i] = cnt[q[i][1]] - ((q[i][0] > 0)? cnt[q[i][0] - 1]: 0);
        }
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

