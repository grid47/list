
+++
authors = ["grid47"]
title = "Leetcode 966: Vowel Spellchecker"
date = "2024-08-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 966: Vowel Spellchecker in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Twas2VoFXW4"
youtube_upload_date="2021-01-02"
youtube_thumbnail="https://i.ytimg.com/vi/Twas2VoFXW4/maxresdefault.jpg"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #967: Numbers With Same Consecutive Differences](https://grid47.xyz/leetcode/solution-967-numbers-with-same-consecutive-differences/) |
| --- |
