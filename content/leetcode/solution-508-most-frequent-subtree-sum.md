
+++
authors = ["grid47"]
title = "Leetcode 508: Most Frequent Subtree Sum"
date = "2024-09-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 508: Most Frequent Subtree Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/508.webp"
youtube = "CvmRmzBQhu8"
youtube_upload_date="2023-01-14"
youtube_thumbnail="https://i.ytimg.com/vi/CvmRmzBQhu8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/508.webp" 
    alt="A tree with sums at each subtree, and the most frequent subtree sum glowing brightly as it is discovered."
    caption="Solution to LeetCode 508: Most Frequent Subtree Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree, return the most frequent subtree sum. A subtree sum is the sum of all the node values in the subtree rooted at any node, including the node itself. If there is a tie, return all the subtree sums with the highest frequency.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the root node of a binary tree with integer values.
- **Example:** `[5, 2, -3]`
- **Constraints:**
	- 1 <= Number of nodes <= 10^4
	- -10^5 <= Node.val <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of the most frequent subtree sums.
- **Example:** `[2, -3, 4]`
- **Constraints:**
	- The output list contains the most frequent subtree sums, with no specific order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the most frequent subtree sum(s) by traversing the tree and calculating the sum of each subtree.

- 1. Perform a depth-first search (DFS) on the tree.
- 2. Calculate the sum of each subtree and keep track of their frequencies.
- 3. Identify the subtree sum(s) with the highest frequency.
- 4. Return the list of those sums.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree is well-formed and follows valid tree structure rules.
- The values of the nodes are integers, and they may be negative.
{{< dots >}}
## Examples 🧩
- **Input:** `[5, 2, -3]`  \
  **Explanation:** In this example, the subtree sums are calculated as follows: the sum of the subtree rooted at 5 is 5 + 2 + (-3) = 4; the sum of the subtree rooted at 2 is 2; the sum of the subtree rooted at -3 is -3. Therefore, the most frequent sums are [2, -3, 4].

{{< dots >}}
## Approach 🚀
We will perform a depth-first search (DFS) on the tree, calculate the subtree sums, and track the frequency of each sum. The most frequent sums will be identified and returned.

### Initial Thoughts 💭
- DFS allows us to calculate the sum of each subtree while traversing the tree.
- We need a data structure to store the frequencies of each subtree sum.
- We can use a map or hash map to track the frequency of each sum. After the DFS, we will identify the sums with the highest frequency.
{{< dots >}}
### Edge Cases 🌐
- The tree will always have at least one node, so this case does not occur.
- The solution should handle trees with up to 10,000 nodes efficiently.
- Nodes with negative values should be correctly handled in the sum calculations.
- The algorithm should ensure that it works efficiently within the given constraints.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int mx;
public:
vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> ans;
    map<int, int> mp;

    mx = 0;
    dfs(root, mp, ans);

    return ans;
}

int dfs(TreeNode* root, map<int, int>& mp, vector<int>& ans) {
    
    if (root == NULL) return 0;
    int res;
        
    if (root->left  == NULL && 
        root->right == NULL)
         { res = root->val; }
    else {
        int l = dfs(root->left , mp, ans);
        int r = dfs(root->right, mp, ans);
        res = l + r + root->val;
    }
    
    mp[res] += 1;
    
    if(mx < mp[res]) {
        ans.clear();
        ans.push_back(res);
        mx = mp[res];
    } else if(mx == mp[res]) {
        ans.push_back(res);
    }
    return res;
}
```

The complete code for this solution defines the main logic for finding the most frequent tree sum using a depth-first search (DFS). It traverses the tree, calculates the sums for each subtree, and keeps track of the most frequent sums in a map.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int mx;
	```
	A variable to keep track of the maximum frequency of the tree sums.

2. **Access Modifiers**
	```cpp
	public:
	```
	Public section where the function definitions are accessible.

3. **Function Definition**
	```cpp
	vector<int> findFrequentTreeSum(TreeNode* root) {
	```
	Defines the function that returns the most frequent tree sums from a given root.

4. **Variable Declaration**
	```cpp
	    vector<int> ans;
	```
	A vector to store the most frequent tree sums.

5. **Data Structure Initialization**
	```cpp
	    map<int, int> mp;
	```
	A map to store the frequency of each tree sum.

6. **Frequency Reset**
	```cpp
	    mx = 0;
	```
	Initializes the maximum frequency to 0.

7. **Function Call**
	```cpp
	    dfs(root, mp, ans);
	```
	Calls the dfs function to traverse the tree and compute the frequencies.

8. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the vector containing the most frequent tree sums.

9. **DFS Function Definition**
	```cpp
	int dfs(TreeNode* root, map<int, int>& mp, vector<int>& ans) {
	```
	Defines the dfs function to traverse the tree and calculate the sum for each node.

10. **Base Case**
	```cpp
	    if (root == NULL) return 0;
	```
	Base case for the DFS, returns 0 if the current node is NULL.

11. **Local Variable Declaration**
	```cpp
	    int res;
	```
	Declares a variable to store the current subtree sum.

12. **Leaf Node Check**
	```cpp
	    if (root->left  == NULL && root->right == NULL) { res = root->val; }
	```
	Checks if the current node is a leaf node. If it is, the sum is just the node's value.

13. **Recursive DFS Calls**
	```cpp
	    else {
	```
	If the current node is not a leaf, recursively calculate the left and right subtree sums.

14. **Recursive DFS Left**
	```cpp
	        int l = dfs(root->left , mp, ans);
	```
	Recursively calls dfs for the left child and stores the result in l.

15. **Recursive DFS Right**
	```cpp
	        int r = dfs(root->right, mp, ans);
	```
	Recursively calls dfs for the right child and stores the result in r.

16. **Subtree Sum Calculation**
	```cpp
	        res = l + r + root->val;
	```
	Calculates the sum of the current node, left and right subtree sums.

17. **Frequency Tracking**
	```cpp
	    mp[res] += 1;
	```
	Updates the frequency map with the current subtree sum.

18. **Max Frequency Check**
	```cpp
	    if(mx < mp[res]) {
	```
	Checks if the current subtree sum frequency is greater than the max frequency.

19. **Update Results**
	```cpp
	        ans.clear();
	```
	Clears the results vector if a new max frequency is found.

20. **Add New Max Frequency**
	```cpp
	        ans.push_back(res);
	```
	Adds the current sum to the results list.

21. **Update Max Frequency**
	```cpp
	        mx = mp[res];
	```
	Updates the max frequency to the current frequency.

22. **Frequency Equality Check**
	```cpp
	    } else if(mx == mp[res]) {
	```
	Checks if the current sum frequency equals the max frequency.

23. **Add Equal Frequency**
	```cpp
	        ans.push_back(res);
	```
	Adds the current sum to the results list if it matches the max frequency.

24. **Return Subtree Sum**
	```cpp
	    return res;
	```
	Returns the current subtree sum to the caller.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of nodes in the tree. Each node is visited once during the DFS.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for the map to store the frequency of subtree sums and the recursion stack during DFS.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/most-frequent-subtree-sum/description/)

---
{{< youtube CvmRmzBQhu8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
