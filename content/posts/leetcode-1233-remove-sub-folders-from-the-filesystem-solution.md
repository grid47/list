
+++
authors = ["grid47"]
title = "Leetcode 1233: Remove Sub-Folders from the Filesystem"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1233: Remove Sub-Folders from the Filesystem in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Depth-First Search","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/)

---
**Code:**

{{< highlight cpp >}}
class TrieNode {
    vector<TrieNode*> letter;
    bool main;
public:
    TrieNode (bool m) {
        letter.resize(27, NULL);
        main = m;
    }
    
    bool add(string key) {
        TrieNode* root = this;
        for (int i = 1; i < key.size(); i++) {
            int nxt;
            if (key[i] == '/') nxt = 26;
            else               nxt = key[i] - 'a';

            if (root->letter[nxt] == NULL) {
                if(nxt != 26) root->letter[nxt] = new TrieNode(false);
                else {
                    if (root->main) return false;
                    root->letter[nxt] = new TrieNode(false);
                }
            }
            root = root->letter[nxt];
        }
        if(!root->main) {
            root->main = true;
            root->letter.resize(27, NULL);
        }
        return true;
    }
};

// plane sequence equated till they match
//     sufix is a letter        - go head its new directory with prefix name natches
//     sufix is a  : bar
//          is current a main dir then cut else create new dir
//                 - new folder - create it,
//                 - sub dir    - stop do not proceed or add

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        sort(folder.begin(), folder.end());
        vector<string> ans;
        TrieNode* root = new TrieNode(false);
        for(int i = 0; i < folder.size(); i++) {
            if(root->add(folder[i]))
                ans.push_back(folder[i]);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1233.md" >}}
---
{{< youtube sFv6T_wLS4k >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1234: Replace the Substring for Balanced String](https://grid47.xyz/posts/leetcode-1234-replace-the-substring-for-balanced-string-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}