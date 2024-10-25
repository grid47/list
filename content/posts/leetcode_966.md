
+++
authors = ["Yasir"]
title = "Leetcode 966: Vowel Spellchecker"
date = "2022-03-06"
description = "Solution to Leetcode 966"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/vowel-spellchecker/description/)

---

**Code:**

{{< highlight html >}}
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

