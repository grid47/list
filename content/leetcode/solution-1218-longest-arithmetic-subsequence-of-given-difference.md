
+++
authors = ["grid47"]
title = "Leetcode 1218: Longest Arithmetic Subsequence of Given Difference"
date = "2024-07-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1218: Longest Arithmetic Subsequence of Given Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NpQ-ZKBNCa8"
youtube_upload_date="2020-09-01"
youtube_thumbnail="https://i.ytimg.com/vi/NpQ-ZKBNCa8/maxresdefault.jpg"
comments = true
+++



---
Given an integer array arr and an integer difference, find the length of the longest subsequence in arr such that the difference between each adjacent element in the subsequence equals the given difference.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array arr and an integer difference.
- **Example:** `Input: arr = [2, 4, 6, 8, 10], difference = 2`
- **Constraints:**
	- 1 <= arr.length <= 10^5
	- -10^4 <= arr[i], difference <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest subsequence where the difference between adjacent elements equals the given difference.
- **Example:** `Output: 5`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest subsequence of numbers that have a constant difference between adjacent elements.

- Use a map to store the length of the longest subsequence ending at each element.
- For each element in the array, check if there is a subsequence ending at the previous element that can be extended with the current element.
- Update the map and keep track of the longest subsequence found.
{{< dots >}}
### Problem Assumptions ✅
- The input array may contain both positive and negative integers.
- The difference can be both positive and negative.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [2, 4, 6, 8, 10], difference = 2`  \
  **Explanation:** The entire array forms an arithmetic subsequence with a common difference of 2.

- **Input:** `Input: arr = [1, 2, 3, 4], difference = 3`  \
  **Explanation:** The longest subsequence with a difference of 3 is [1, 4].

{{< dots >}}
## Approach 🚀
We can use dynamic programming with a hashmap to efficiently track the longest subsequence for each element.

### Initial Thoughts 💭
- Each element in the array can potentially extend a subsequence if it forms a valid arithmetic progression with the previous element.
- We will use a map to store the longest subsequence that ends with each element and update it as we iterate through the array.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least one element, as per the constraints.
- The solution should be efficient enough to handle arrays of length up to 10^5.
- Consider cases where the entire array is a valid arithmetic subsequence or when no subsequence forms.
- The solution should work within the given time and space limits.
{{< dots >}}
## Code 💻
```cpp
int longestSubsequence(vector<int>& arr, int diff) {
    map<int, int> mp;
    int ans = 1;
    for(int x: arr) {
        mp[x] = 1 + max(mp[x - diff], mp.count(x)? mp[x] -1 :0);
        ans = max(ans, mp[x]);
    }
    return ans;
}
```

This function finds the length of the longest subsequence in the given array `arr` where the difference between consecutive elements is exactly `diff`. It uses dynamic programming with a hashmap to store the longest subsequence length for each element.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestSubsequence(vector<int>& arr, int diff) {
	```
	Define the function `longestSubsequence` which takes a vector `arr` and an integer `diff` as input, where `diff` is the required difference between consecutive elements in the subsequence.

2. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	Initialize a map `mp` where the key is an element from `arr`, and the value is the length of the longest subsequence ending with that element.

3. **Answer Initialization**
	```cpp
	    int ans = 1;
	```
	Initialize `ans` to 1, which will store the length of the longest subsequence found so far. The minimum subsequence length is 1 (the element itself).

4. **Loop Through Array**
	```cpp
	    for(int x: arr) {
	```
	Start a loop to iterate through each element `x` in the input array `arr`.

5. **Update Map with Subsequence Length**
	```cpp
	        mp[x] = 1 + max(mp[x - diff], mp.count(x)? mp[x] -1 :0);
	```
	For each element `x`, update the map `mp`. The new value is 1 plus the maximum of two cases: the length of the subsequence that ends with `x - diff` or the length of the subsequence ending with `x`, adjusted if it exists.

6. **Update Maximum Length**
	```cpp
	        ans = max(ans, mp[x]);
	```
	Update `ans` to be the maximum of the current `ans` and the subsequence length ending at `x`. This ensures that the longest subsequence length is stored.

7. **Return Result**
	```cpp
	    return ans;
	```
	Return the length of the longest subsequence found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the array, as we process each element once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of subsequence lengths in the map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/)

---
{{< youtube NpQ-ZKBNCa8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
