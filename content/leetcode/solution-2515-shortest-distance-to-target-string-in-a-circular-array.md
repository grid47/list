
+++
authors = ["grid47"]
title = "Leetcode 2515: Shortest Distance to Target String in a Circular Array"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2515: Shortest Distance to Target String in a Circular Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "yTpRd3yvyz0"
youtube_upload_date="2023-01-07"
youtube_thumbnail="https://i.ytimg.com/vi/yTpRd3yvyz0/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed circular array of strings `words` and a target string `target`. A circular array means that the last element connects to the first one. For any index `i`, the next element is `words[(i + 1) % n]` and the previous element is `words[(i - 1 + n) % n]`, where `n` is the length of the array. Starting at `startIndex`, you can move to either the next or previous word with one step at a time. Your goal is to find the minimum distance needed to reach the `target` string from the starting index. If `target` does not exist in the array, return `-1`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a circular string array `words` and a string `target`.
- **Example:** `words = ["good", "morning", "world", "good"], target = "good", startIndex = 2`
- **Constraints:**
	- 1 <= words.length <= 100
	- 1 <= words[i].length <= 100
	- words[i] and target consist of only lowercase English letters
	- 0 <= startIndex < words.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum distance to reach the target string, or -1 if the target is not found in the array.
- **Example:** `Output: 1`
- **Constraints:**
	- If the target does not exist in words, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to compute the shortest possible distance to the target string in the circular array starting from the given index.

- Iterate over the words array to find all indices where the target exists.
- Calculate the distance from the startIndex to each of these indices.
- Compute the shortest circular distance by considering both left and right movements.
- Return the minimum distance, or -1 if the target is not found.
{{< dots >}}
### Problem Assumptions ✅
- The words array is non-empty and the target is always a lowercase string.
- The input startIndex is always a valid index.
{{< dots >}}
## Examples 🧩
- **Input:** `words = ["good", "morning", "world", "good"], target = "good", startIndex = 2`  \
  **Explanation:** Starting from index 2, the closest 'good' can be found at index 3 by moving 1 step to the left, or at index 0 by moving 3 steps to the right. The shortest distance is 1.

- **Input:** `words = ["apple", "banana", "cherry"], target = "banana", startIndex = 0`  \
  **Explanation:** The target 'banana' is directly at index 1, so the shortest distance is 1.

{{< dots >}}
## Approach 🚀
The goal is to compute the minimum distance to the target string in the circular words array starting from the given index.

### Initial Thoughts 💭
- The array is circular, which means that the distances should be calculated modulo the array size.
- We can calculate distances by moving both left and right from the start index.
- The key challenge is efficiently calculating the minimum distance in a circular array.
{{< dots >}}
### Edge Cases 🌐
- The words array is non-empty by definition.
- Handle cases where the words array is at its maximum length (100).
- If the target string does not exist, return -1.
- Ensure the startIndex is within the bounds of the array.
{{< dots >}}
## Code 💻
```cpp
int closetTarget(vector<string>& words, string target, int s) {
    int n = words.size(), ans = INT_MAX;
    
    for(int i = 0; i < n; i++) 
        if(words[i] == target) 
            ans = min(ans, min(abs(s - i), abs(n - abs(s - i)))); 
    
    return ans == INT_MAX ? -1 : ans;
}
```

This function calculates the minimum distance to the target word from a starting index in a circular manner.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int closetTarget(vector<string>& words, string target, int s) {
	```
	Define the function `closetTarget`, which takes a vector of words, a target string, and a starting index `s`.

2. **Variable Initialization**
	```cpp
	    int n = words.size(), ans = INT_MAX;
	```
	Initialize the variable `n` to store the size of the words vector, and `ans` to store the minimum distance, initially set to the maximum integer value.

3. **Loop**
	```cpp
	    
	```
	This space is for the loop that will iterate over the words array.

4. **Loop Iteration**
	```cpp
	    for(int i = 0; i < n; i++) 
	```
	A loop that iterates over each word in the `words` vector.

5. **Conditional Check**
	```cpp
	        if(words[i] == target) 
	```
	Check if the current word matches the target word.

6. **Distance Calculation**
	```cpp
	            ans = min(ans, min(abs(s - i), abs(n - abs(s - i)))); 
	```
	Calculate the minimum of the current distance and the circular distance between the current index `i` and the starting index `s`, and update the result `ans`.

7. **Return Statement**
	```cpp
	    return ans == INT_MAX ? -1 : ans;
	```
	Return the minimum distance if a target word was found, otherwise return -1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the number of words in the array.
- **Average Case:** O(n) where n is the number of words in the array.
- **Worst Case:** O(n) where n is the number of words in the array.

We iterate over the array to find the target and compute distances.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant because we only store a few variables during computation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/)

---
{{< youtube yTpRd3yvyz0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
