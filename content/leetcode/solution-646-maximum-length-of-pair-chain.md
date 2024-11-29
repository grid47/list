
+++
authors = ["grid47"]
title = "Leetcode 646: Maximum Length of Pair Chain"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 646: Maximum Length of Pair Chain in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/646.webp"
youtube = "LcNNorqMVTw"
youtube_upload_date="2023-08-26"
youtube_thumbnail="https://i.ytimg.com/vi/LcNNorqMVTw/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/646.webp" 
    alt="A sequence of pairs where the longest chain is highlighted and softly glowing."
    caption="Solution to LeetCode 646: Maximum Length of Pair Chain Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of pairs where each pair represents an interval with two integers. A pair can follow another pair if the second integer of the first pair is less than the first integer of the second pair. Your task is to determine the length of the longest chain that can be formed by linking the pairs.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of pairs, where each pair is a list of two integers [lefti, righti] with lefti < righti. The number of pairs is n.
- **Example:** `pairs = [[1, 2], [2, 3], [3, 4]]`
- **Constraints:**
	- 1 <= n <= 1000
	- -1000 <= lefti < righti <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the length of the longest chain of pairs that can be formed.
- **Example:** `2`
- **Constraints:**
	- The result will be a single integer representing the length of the longest chain.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the length of the longest chain that can be formed from the given pairs.

- 1. Sort the pairs by the second value of each pair.
- 2. Iterate over the sorted pairs and greedily select the ones that can form a chain, starting with the first pair and selecting each subsequent pair where the first value is greater than the second value of the previous pair.
{{< dots >}}
### Problem Assumptions ✅
- The input will always contain at least one pair.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1, 2], [2, 3], [3, 4]]`  \
  **Explanation:** The longest chain is formed by selecting pairs [1, 2] and [3, 4], giving a chain length of 2.

{{< dots >}}
## Approach 🚀
The solution is based on sorting the pairs and using a greedy approach to select pairs that can form a valid chain.

### Initial Thoughts 💭
- Sorting the pairs based on their second element allows us to efficiently find the longest chain by selecting pairs that follow each other.
- A greedy approach works well here because it ensures that we always pick the next pair that can extend the chain without skipping any possible valid pairs.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one pair.
- The solution should handle inputs up to the maximum size of 1000 pairs.
- Pairs that are already sorted or pairs with no possible chain need to be handled properly.
- Ensure that the algorithm sorts the pairs efficiently and selects the valid chain in linear time after sorting.
{{< dots >}}
## Code 💻
```cpp

static bool cmp(vector<int> &a, vector<int> &b) {
    if(a[0] == b[0]) return a[1] < b[1];
    else return a[0] < b[0];
}

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), cmp);
    
    int n = pairs.size();
    
    vector<int> dp(n, 1);
    int mx = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(pairs[i][0] > pairs[j][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
                mx = max(mx, dp[i]);
            }
        }
    }
    
    return mx;
}
```

This code finds the longest chain of pairs in a collection of pairs of integers. It uses dynamic programming to track the longest chain while sorting the pairs to simplify the comparison logic.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Helper Function**
	```cpp
	static bool cmp(vector<int> &a, vector<int> &b) {
	```
	Defines a helper function 'cmp' that compares two pairs (a and b). It first compares the first elements of the pairs, and if they are equal, it compares the second elements. This function is used for sorting the pairs.

2. **Comparison Logic**
	```cpp
	    if(a[0] == b[0]) return a[1] < b[1];
	```
	Compares the second element of the pair if the first elements are equal. This ensures that the pairs are ordered first by the first element and then by the second element.

3. **Comparison Logic**
	```cpp
	    else return a[0] < b[0];
	```
	If the first elements of the pairs are not equal, this part of the function ensures that pairs are sorted in increasing order of the first element.

4. **Function Definition**
	```cpp
	int findLongestChain(vector<vector<int>>& pairs) {
	```
	Defines the main function 'findLongestChain' which takes a reference to a vector of pairs and returns an integer representing the length of the longest chain of pairs.

5. **Sorting**
	```cpp
	    sort(pairs.begin(), pairs.end(), cmp);
	```
	Sorts the pairs using the 'cmp' function defined earlier. This ensures that the pairs are sorted in a way that makes it easier to find the longest chain.

6. **Variable Initialization**
	```cpp
	    int n = pairs.size();
	```
	Initializes an integer 'n' with the size of the 'pairs' vector, representing the total number of pairs.

7. **Dynamic Programming Initialization**
	```cpp
	    vector<int> dp(n, 1);
	```
	Declares and initializes a dynamic programming vector 'dp' with size 'n', where each element is initialized to 1. The vector will be used to store the longest chain ending at each pair.

8. **Variable Initialization**
	```cpp
	    int mx = 1;
	```
	Initializes the variable 'mx' to 1, which will keep track of the length of the longest chain found.

9. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts an outer loop to iterate through each pair in the sorted 'pairs' vector.

10. **Inner Loop**
	```cpp
	        for(int j = 0; j < i; j++) {
	```
	Starts an inner loop to check each pair before the current pair 'i' to find a valid chain.

11. **Chain Check**
	```cpp
	            if(pairs[i][0] > pairs[j][1]) {
	```
	Checks if the current pair 'i' can form a valid chain with pair 'j'. The first element of pair 'i' must be greater than the second element of pair 'j'.

12. **Dynamic Programming Update**
	```cpp
	                dp[i] = max(dp[i], dp[j] + 1);
	```
	If the chain condition is met, updates the dynamic programming value for pair 'i', ensuring it holds the maximum length of the chain ending at that pair.

13. **Maximum Chain Length Update**
	```cpp
	                mx = max(mx, dp[i]);
	```
	Updates the variable 'mx' to store the maximum length of any chain found so far.

14. **Final Return**
	```cpp
	    return mx;
	```
	Returns the length of the longest chain found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the pairs and the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-length-of-pair-chain/description/)

---
{{< youtube LcNNorqMVTw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
