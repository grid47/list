
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
comments = true
+++



---
You are given a 0-indexed array of strings `words` and two integers `left` and `right`. A string is considered a vowel string if it starts and ends with a vowel character (vowels are 'a', 'e', 'i', 'o', 'u'). Your task is to return the number of vowel strings in the array `words` where the indices fall within the range [left, right].
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `words` and two integers `left` and `right`.
- **Example:** `For example, `words = ["apple", "banana", "oreo"], left = 0, right = 2`.`
- **Constraints:**
	- 1 <= words.length <= 1000
	- 1 <= words[i].length <= 10
	- words[i] consists of only lowercase English letters
	- 0 <= left <= right < words.length

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer that represents the number of vowel strings within the specified range of indices.
- **Example:** `For input `words = ["apple", "banana", "oreo"], left = 0, right = 2`, the output is `2`.`
- **Constraints:**
	- The result will always be a valid integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the number of vowel strings in the given range of indices.

- 1. Iterate through the array `words` from index `left` to index `right`.
- 2. For each word, check if the first and last characters are vowels.
- 3. Count how many words meet the condition of being a vowel string.
{{< dots >}}
### Problem Assumptions ✅
- The input array is valid, containing only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `For `words = ["apple", "banana", "oreo"], left = 0, right = 2``  \
  **Explanation:** The valid vowel strings in the range are "apple" and "oreo", so the result is 2.

{{< dots >}}
## Approach 🚀
To solve the problem, we can loop through the array `words` within the specified range, and for each word, check if it starts and ends with a vowel. This can be achieved using basic string operations.

### Initial Thoughts 💭
- We can easily check the start and end characters of each word to see if they are vowels.
- By iterating over the range and checking each word, we can count the number of valid vowel strings efficiently.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the input will contain at least one word.
- The solution should handle arrays with up to 1000 words efficiently.
- If `left` equals `right`, we are checking only one word, which should be handled accordingly.
- The given range [left, right] will always be valid for the input array.
{{< dots >}}
## Code 💻
```cpp
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
```

This function calculates the kth largest sum of nodes at a level in a binary tree, using a priority queue to store the sums of levels while traversing the tree level by level.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long kthLargestLevelSum(TreeNode* root, int k) {
	```
	Define the function `kthLargestLevelSum` which takes a `TreeNode* root` (the root of the binary tree) and an integer `k` (the level number to find the kth largest sum for).

2. **Priority Queue Initialization**
	```cpp
	    priority_queue<long long, vector<long long>, greater<long long>> pq;
	```
	Create a min-heap priority queue `pq` to store the sums of levels, which will help track the kth largest sum.

3. **Edge Case Check**
	```cpp
	    if(!root) return 0;
	```
	Check if the root is null. If the tree is empty, return 0 since there are no level sums.

4. **Queue Initialization**
	```cpp
	    queue<TreeNode*> q;
	```
	Initialize a queue `q` to perform a breadth-first search (BFS) on the binary tree.

5. **Add Root to Queue**
	```cpp
	    q.push(root);
	```
	Push the root node into the queue to start the BFS traversal.

6. **BFS Loop**
	```cpp
	    while(!q.empty()) {
	```
	Start a while loop that runs until the queue is empty, ensuring that we process each level of the binary tree.

7. **Level Size Calculation**
	```cpp
	        int sz = q.size();
	```
	Store the number of nodes at the current level (`sz`) in the variable `sz`.

8. **Level Sum Initialization**
	```cpp
	        long long sum = 0;
	```
	Initialize a variable `sum` to store the sum of the node values at the current level.

9. **Process Each Node at the Level**
	```cpp
	        while(sz--) {
	```
	Loop through all nodes at the current level.

10. **Node Processing**
	```cpp
	            auto it = q.front();
	```
	Get the front node from the queue (`it`).

11. **Sum Accumulation**
	```cpp
	            sum += it->val;
	```
	Add the value of the current node (`it->val`) to the `sum`.

12. **Queue Update**
	```cpp
	            q.pop();
	```
	Remove the current node from the queue.

13. **Left Child Check**
	```cpp
	            if(it->left) q.push(it->left);
	```
	If the current node has a left child, add it to the queue for processing in the next iteration.

14. **Right Child Check**
	```cpp
	            if(it->right) q.push(it->right);
	```
	If the current node has a right child, add it to the queue for processing in the next iteration.

15. **Push Sum to Priority Queue**
	```cpp
	        pq.push(sum);
	```
	Push the sum of the current level to the priority queue.

16. **Priority Queue Size Check**
	```cpp
	        if(pq.size() > k) pq.pop();
	```
	If the priority queue exceeds size `k`, pop the smallest sum to ensure we only keep the top `k` largest sums.

17. **Check for kth Largest**
	```cpp
	    if(pq.size() < k) return -1;
	```
	Check if the priority queue has fewer than `k` sums. If so, return -1 as there are not enough levels.

18. **Return kth Largest Sum**
	```cpp
	    return pq.top();
	```
	Return the top element of the priority queue, which is the kth largest sum of a level.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of the range [left, right]. For each word, we perform constant time operations to check if the first and last characters are vowels.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only use a few extra variables for counting and checking the vowels.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/)

---
{{< youtube Sh-IqBIg9dU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
