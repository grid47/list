
+++
authors = ["grid47"]
title = "Leetcode 752: Open the Lock"
date = "2024-08-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 752: Open the Lock in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/752.webp"
youtube = "Pzg3bCDY87w"
youtube_upload_date="2022-01-19"
youtube_thumbnail="https://i.ytimg.com/vi/Pzg3bCDY87w/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/open-the-lock/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/752.webp" 
    alt="A lock with combination digits, where each correct digit softly glows as it’s guessed correctly."
    caption="Solution to LeetCode 752: Open the Lock Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        queue<string> q({"0000"});
        
        for(int turn = 0;!q.empty(); turn++) {
            for(int i = q.size(); i > 0; i--) {
                auto curr = q.front(); q.pop();
                cout << curr << ' ' << target << endl;
                if (curr == target) return turn;
                for(auto it : neighbours(curr)) {
                    if(dead.count(it)) continue;
                    dead.insert(it);
                    q.push(it);
                }
            }
        }
        return -1;
    }

    vector<string> neighbours(const string &code) {
        vector<string> res;
        for(int i = 0; i < 4; i++) {
            for(int diff = -1; diff <= 1; diff++) {
                string nei = code;
                nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
                res.push_back(nei);
            }
        }
        return res;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/752.md" >}}
---
{{< youtube Pzg3bCDY87w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #754: Reach a Number](https://grid47.xyz/leetcode/solution-754-reach-a-number/) |
| --- |