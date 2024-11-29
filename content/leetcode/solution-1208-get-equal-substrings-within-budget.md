
+++
authors = ["grid47"]
title = "Leetcode 1208: Get Equal Substrings Within Budget"
date = "2024-07-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1208: Get Equal Substrings Within Budget in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3lsT1Le526U"
youtube_upload_date="2024-05-28"
youtube_thumbnail="https://i.ytimg.com/vi/3lsT1Le526U/maxresdefault.jpg"
comments = true
+++



---
You are given two strings s and t of the same length, and an integer maxCost. You want to change string s to string t. The cost of changing the ith character of s to the ith character of t is the absolute difference between their ASCII values. Your task is to find the maximum length of a substring of s that can be changed to match the corresponding substring of t, with the total cost not exceeding maxCost.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings s and t of the same length, and an integer maxCost.
- **Example:** `Input: s = "hello", t = "hxllo", maxCost = 2`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- t.length == s.length
	- 0 <= maxCost <= 10^6
	- s and t consist of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum length of a substring of s that can be changed to the corresponding substring of t with a total cost no greater than maxCost.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest possible substring that can be converted from s to t such that the total cost of the transformation is within the allowed maxCost.

- Calculate the cost of changing each character of s to the corresponding character of t.
- Use a sliding window approach to find the longest substring where the total change cost does not exceed maxCost.
{{< dots >}}
### Problem Assumptions ✅
- The input strings s and t are non-empty and consist of lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "hello", t = "hxllo", maxCost = 2`  \
  **Explanation:** You can change the substring 'hel' of s to 'hxl' of t. The total cost is 2, which is within the maxCost.

- **Input:** `Input: s = "abcde", t = "bbcde", maxCost = 1`  \
  **Explanation:** You can change the substring 'ab' of s to 'bb' of t. The cost is 1, which is within the maxCost.

- **Input:** `Input: s = "abc", t = "xyz", maxCost = 0`  \
  **Explanation:** Since maxCost is 0, no changes can be made. The longest valid substring is 0.

{{< dots >}}
## Approach 🚀
We can use a sliding window technique to solve this problem. The idea is to keep track of the running cost of converting substrings of s to substrings of t and adjust the window size accordingly.

### Initial Thoughts 💭
- We need to track the cost of character changes between s and t for substrings.
- The sliding window will help in dynamically adjusting the substring length while ensuring the total cost stays within maxCost.
- The total cost of transforming any substring can be efficiently managed with a sliding window technique.
{{< dots >}}
### Edge Cases 🌐
- Input strings s and t should always have at least one character, as per the constraints.
- Ensure that the solution can handle inputs with lengths up to 10^5.
- Consider cases where maxCost is 0, which means no changes can be made.
- The lengths of s and t are guaranteed to be the same, so there is no need to check for different lengths.
{{< dots >}}
## Code 💻
```cpp
int equalSubstring(string s, string t, int mxc) {
    vector<int> nums(s.size(), 0);
    for(int i = 0; i < s.size(); i++) {
        nums[i] = abs(s[i] - t[i]);
    }
    int res = 0, j = 0;
    for(int i = 0; i < nums.size(); i++) {
        mxc -= nums[i];
        while(mxc < 0) {
            mxc += nums[j++];
        }
        res = max(res, i - j + 1);
    }
    return res;
}
```

This function calculates the maximum length of a substring that can be transformed into another substring by making no more than `mxc` changes. It uses a sliding window technique to efficiently calculate the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int equalSubstring(string s, string t, int mxc) {
	```
	Define the function `equalSubstring` that takes two strings `s`, `t`, and an integer `mxc`, which represents the maximum allowed difference.

2. **Vector Initialization**
	```cpp
	    vector<int> nums(s.size(), 0);
	```
	Initialize a vector `nums` of the same size as `s`, filled with zeros. This vector will store the absolute differences between corresponding characters in `s` and `t`.

3. **Loop to Calculate Differences**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Start a for loop to iterate over the characters in the strings `s` and `t`.

4. **Calculate Absolute Difference**
	```cpp
	        nums[i] = abs(s[i] - t[i]);
	```
	For each character pair in `s` and `t`, compute the absolute difference between their ASCII values and store it in the `nums` vector.

5. **Variable Initialization**
	```cpp
	    int res = 0, j = 0;
	```
	Initialize `res` to 0 to store the maximum length of the valid substring, and `j` to 0 as the starting index for the sliding window.

6. **Sliding Window Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Start a for loop that will iterate over the `nums` vector to find the maximum substring with the allowed differences.

7. **Update Maximum Difference**
	```cpp
	        mxc -= nums[i];
	```
	Subtract the current difference from `mxc` to track how much the allowed difference decreases as the window expands.

8. **Adjust Window for Validity**
	```cpp
	        while(mxc < 0) {
	```
	Start a while loop to shrink the window from the left when the total difference exceeds the allowed `mxc`.

9. **Expand Window by Moving Left Pointer**
	```cpp
	            mxc += nums[j++];
	```
	Increment `j` (move the left pointer) and add back the difference for the element that is being excluded from the window.

10. **Update Maximum Substring Length**
	```cpp
	        res = max(res, i - j + 1);
	```
	Update `res` to store the maximum length of a valid substring found so far by comparing the current window length `i - j + 1`.

11. **Return Result**
	```cpp
	    return res;
	```
	Return the final result `res`, which is the maximum length of a valid substring that can be transformed by no more than `mxc` changes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the strings. This is because each character in the strings is processed at most twice.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the differences between corresponding characters in s and t.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/get-equal-substrings-within-budget/description/)

---
{{< youtube 3lsT1Le526U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
