
+++
authors = ["Crafted by Me"]
title = "Leetcode 127: Word Ladder"
date = "2024-06-28"
description = "Solution to Leetcode 127"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/word-ladder/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int ladderLength(string bg, string ed, vector<string>& list) {
        unordered_map<string, bool> mp;
        for(string x: list)
            mp[x] = true;
        
        queue<string> q;        
        q.push(bg);

        int cnt = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string tmp = q.front();
                q.pop();

                if(tmp == ed) return cnt;
                if(mp.count(tmp))
                    mp.erase(tmp);

                for(int j = 0; j < tmp.size(); j++) {
                    char c = tmp[j];
                    for(int i = 0; i < 26; i++) {
                        char c1 = 'a' + i;
                        tmp[j] = c1;
                        if(mp.count(tmp))
                            q.push(tmp);             
                    }
                    tmp[j] = c;                           
                }
            }
            cnt++;
        }
        return 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/127.md" >}}
---
{{< youtube didn5XCQ14s >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

