
+++
authors = ["grid47"]
title = "Leetcode 437: Path Sum III"
date = "2024-09-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 437: Path Sum III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/437.webp"
youtube = "Vam9gldRapY"
youtube_upload_date="2020-08-08"
youtube_thumbnail="https://i.ytimg.com/vi/Vam9gldRapY/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGIgZSgsMA8=&rs=AOn4CLByu4Pnq9YHL4GumLlrHVQp65TWqQ"
+++



[`Problem Link`](https://leetcode.com/problems/path-sum-iii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/437.webp" 
    alt="A tree with nodes lighting up, showing the path sum from a root node to the leaves, highlighting valid paths."
    caption="Solution to LeetCode 437: Path Sum III Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
    int cnt = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return cnt;
    }
    
    void dfs(TreeNode* root, long sum) {
        if(root == NULL) return;

        test(root, sum);
        dfs(root->left,  sum);
        dfs(root->right, sum);

    }
    
    void test(TreeNode* root, long sum) {
        if  (root     == NULL) return;
        if  (root->val == sum ) cnt++;
        test(root->left,  sum - root->val);
        test(root->right, sum - root->val);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/437.md" >}}
---
{{< youtube Vam9gldRapY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #438: Find All Anagrams in a String](https://grid47.xyz/leetcode/solution-438-find-all-anagrams-in-a-string/) |
| --- |
