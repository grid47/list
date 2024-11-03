
+++
authors = ["Crafted by Me"]
title = "Leetcode 1859: Sorting the Sentence"
date = "2019-10-01"
description = "In-depth solution and explanation for Leetcode 1859: Sorting the Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sorting-the-sentence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string sortSentence(string s) 
    {
        stringstream words(s); 
        string word;
        pair<int, string> m;
        vector<pair<int, string> > sent;
        
        //SECTION 1
        while(words>>word)
        {
            int len = word.size();
            int i = int(word[len-1]) - 48;
            sent.push_back(make_pair(i, word.substr(0, len-1)));
        }
        
        //SECTION 2
        sort(sent.begin(), sent.end());
        
        //SECTION 3
        string ans = "";
        int len = sent.size();
        for(int i=0; i<len; i++)
        {
            ans += sent[i].second;
            if(i!= len-1)
                ans += " ";
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1859.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1860: Incremental Memory Leak](https://grid47.xyz/posts/leetcode_1860) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

