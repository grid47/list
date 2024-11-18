
+++
authors = ["grid47"]
title = "Leetcode 2583: Kth Largest Sum in a Binary Tree"
date = "2024-02-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2583: Kth Largest Sum in a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Sorting","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Sh-IqBIg9dU"
youtube_upload_date="2024-10-22"
youtube_thumbnail="https://i.ytimg.com/vi/Sh-IqBIg9dU/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/)

---
**Code:**

{{< highlight cpp >}}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            while(sz--) {
                auto it = q.front();
                sum += it->val;
                q.pop();
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            pq.push(sum);
            if(pq.size() > k) pq.pop();
        }
        if(pq.size() < k) return -1;
        return pq.top();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2583.md" >}}
---
{{< youtube Sh-IqBIg9dU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2586: Count the Number of Vowel Strings in Range](https://grid47.xyz/leetcode/solution-2586-count-the-number-of-vowel-strings-in-range/) |
| --- |
