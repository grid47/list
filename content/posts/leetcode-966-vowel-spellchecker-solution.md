
+++
authors = ["grid47"]
title = "Leetcode 966: Vowel Spellchecker"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 966: Vowel Spellchecker in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/vowel-spellchecker/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vowel;
        for(string w : wordlist) {
            string lower = tolow(w), devvowel = todev(w);
            cap.insert({lower, w});
            vowel.insert({devvowel, w});
        }

        for(int i = 0; i < queries.size(); i++) {
            
            if (words.count(queries[i])) continue;
            
            string lower = tolow(queries[i]), devvowel = todev(queries[i]);
            
            if(cap.count(lower))
                 queries[i] = cap[lower];
            else if(vowel.count(devvowel))
                 queries[i] = vowel[devvowel];
            else queries[i] = "";
        }
        return queries;

    }

    string tolow(string w) {
        for(char &c : w)
        c = tolower(c);
        return w;
    }

    string todev(string w) {
        w = tolow(w);
        for(char &c:w)
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c=='u')
            c = '#';
        return w;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/966.md" >}}
---
{{< youtube Twas2VoFXW4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #967: Numbers With Same Consecutive Differences](https://grid47.xyz/posts/leetcode-967-numbers-with-same-consecutive-differences-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}