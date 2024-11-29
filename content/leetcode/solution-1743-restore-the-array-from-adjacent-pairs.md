
+++
authors = ["grid47"]
title = "Leetcode 1743: Restore the Array From Adjacent Pairs"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1743: Restore the Array From Adjacent Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Depth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "SGfdp6CFDrA"
youtube_upload_date="2021-01-31"
youtube_thumbnail="https://i.ytimg.com/vi/SGfdp6CFDrA/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array `nums` with unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in `nums`. You are given a 2D integer array `adjacentPairs` where each `adjacentPairs[i] = [ui, vi]` indicates that the elements `ui` and `vi` are adjacent in `nums`. Your task is to reconstruct the original array `nums` using these adjacent pairs. There could be multiple valid solutions, so return any one of them.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `adjacentPairs` containing n - 1 pairs where each pair represents two adjacent elements of the original array `nums`.
- **Example:** `Input: adjacentPairs = [[1,2], [2,3], [4,2]]`
- **Constraints:**
	- nums.length == n
	- adjacentPairs.length == n - 1
	- adjacentPairs[i].length == 2
	- 2 <= n <= 10^5
	- -10^5 <= nums[i], ui, vi <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the reconstructed original array `nums`.
- **Example:** `Output: [1, 2, 3, 4]`
- **Constraints:**
	- The solution should be reconstructed based on the given adjacent pairs.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reconstruct the array `nums` using the adjacent pairs and determine the correct order of the elements.

- 1. Create a map to store the adjacency list of each element.
- 2. Identify the element with only one adjacent element, as this is either the first or last element of `nums`.
- 3. Starting from that element, iteratively build the array by moving to the next adjacent element until the entire array is reconstructed.
{{< dots >}}
### Problem Assumptions ✅
- The given pairs are valid and consistent, allowing for the reconstruction of the array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: adjacentPairs = [[1,2], [2,3], [4,2]]`  \
  **Explanation:** The pairs tell us that 1 and 2 are adjacent, 2 and 3 are adjacent, and 2 and 4 are adjacent. This allows us to reconstruct the array as [1, 2, 3, 4].

- **Input:** `Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]`  \
  **Explanation:** The adjacent pairs indicate that the array could be [-2, 4, 1, -3], as 4 and 1 are adjacent, 1 and -3 are adjacent, and 4 and -2 are adjacent.

{{< dots >}}
## Approach 🚀
The approach involves using an adjacency list to store the connections between the elements and reconstructing the array by identifying the starting point (an element with only one adjacent element), then iteratively finding the next element in the array.

### Initial Thoughts 💭
- The problem involves finding the correct order of elements from a set of pairs.
- Using an adjacency list is a natural way to represent this problem.
- We should be careful to handle cases where the solution has multiple valid outputs. Any valid reconstruction is acceptable.
{{< dots >}}
### Edge Cases 🌐
- This case is not applicable as `adjacentPairs` will always have at least one element.
- Ensure that the solution handles large inputs with up to 100,000 elements efficiently.
- Consider cases with negative numbers or large positive numbers.
- The algorithm must be efficient enough to handle the upper limit of `n`.
{{< dots >}}
## Code 💻
```cpp
vector<int> restoreArray(vector<vector<int>>& ap) {
    int n = ap.size() + 1;
    map<int, vector<int>> mp;
    for(auto e : ap) {
        int u = e[0], v = e[1];
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    vector<int> ans;
    for(auto it: mp) {
        if(it.second.size() == 1) {
            ans.push_back(it.first);
            ans.push_back(it.second[0]);
            break;
        }
    }

    while(ans.size() < n) {
        auto tail = ans.back(), prv = ans[ans.size() - 2];
        auto &next = mp[tail];
        if(next[0] != prv)
            ans.push_back(next[0]);
        else
            ans.push_back(next[1]);
    }

    return ans;
}

```

This function restores an array of integers from a given set of edges where each edge connects two elements of the array. The array is restored by examining the structure of these connections, starting with the end points, and sequentially adding the next elements until the entire array is reconstructed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> restoreArray(vector<vector<int>>& ap) {
	```
	This is the function declaration for `restoreArray`, which takes a 2D vector `ap` representing edges between pairs of elements and returns a vector of integers representing the restored array.

2. **Variable Initialization**
	```cpp
	    int n = ap.size() + 1;
	```
	This line calculates the number of elements in the restored array, which is one more than the number of edges in `ap`.

3. **Variable Initialization**
	```cpp
	    map<int, vector<int>> mp;
	```
	This initializes a map `mp`, where each key is an integer (an element of the array) and each value is a vector containing the integers it is connected to (the other elements in the array).

4. **Edge Processing**
	```cpp
	    for(auto e : ap) {
	```
	This loop iterates through each edge in `ap`, processing pairs of connected elements.

5. **Edge Assignment**
	```cpp
	        int u = e[0], v = e[1];
	```
	This extracts the two integers `u` and `v` from the current edge `e`.

6. **Map Update**
	```cpp
	        mp[u].push_back(v);
	```
	This adds `v` to the list of elements connected to `u` in the map `mp`.

7. **Map Update**
	```cpp
	        mp[v].push_back(u);
	```
	This adds `u` to the list of elements connected to `v` in the map `mp`.

8. **Result Initialization**
	```cpp
	    vector<int> ans;
	```
	This initializes an empty vector `ans` that will hold the restored array.

9. **Edge Processing**
	```cpp
	    for(auto it: mp) {
	```
	This loop iterates through the map `mp` to find the starting point of the restored array.

10. **Condition Check**
	```cpp
	        if(it.second.size() == 1) {
	```
	This checks if the current element in the map is connected to only one other element, indicating it's an endpoint of the array.

11. **Add to Result**
	```cpp
	            ans.push_back(it.first);
	```
	This adds the element `it.first` (the endpoint) to the result vector `ans`.

12. **Add to Result**
	```cpp
	            ans.push_back(it.second[0]);
	```
	This adds the other element connected to the endpoint to the result vector `ans`.

13. **Break**
	```cpp
	            break;
	```
	This breaks out of the loop as we've found the first two elements of the restored array.

14. **Restoration Loop**
	```cpp
	    while(ans.size() < n) {
	```
	This `while` loop continues to add elements to the result array `ans` until it reaches the required size `n`.

15. **Element Selection**
	```cpp
	        auto tail = ans.back(), prv = ans[ans.size() - 2];
	```
	This line gets the last two elements in `ans`, which will be used to find the next element.

16. **Map Lookup**
	```cpp
	        auto &next = mp[tail];
	```
	This retrieves the list of elements connected to `tail` from the map `mp`.

17. **Condition Check**
	```cpp
	        if(next[0] != prv)
	```
	This checks if the first element in the list `next` is not the previous element `prv`.

18. **Add to Result**
	```cpp
	            ans.push_back(next[0]);
	```
	This adds the next element to the result array `ans` if it is not the previous element.

19. **Add to Result**
	```cpp
	        else
	```
	If the first element is the previous one, then the second element must be the next element.

20. **Add to Result**
	```cpp
	            ans.push_back(next[1]);
	```
	This adds the second element from the list `next` to `ans`.

21. **Return**
	```cpp
	    return ans;
	```
	This returns the fully restored array `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where `n` is the number of elements in the array.
- **Average Case:** O(n), since we must visit each element once to reconstruct the array.
- **Worst Case:** O(n), as we need to process all pairs and elements.

The time complexity is linear in the number of elements.

### Space Complexity 💾
- **Best Case:** O(n), since we are storing the adjacency pairs.
- **Worst Case:** O(n), as we need to store the adjacency list for all elements.

The space complexity is linear in the number of elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/)

---
{{< youtube SGfdp6CFDrA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
