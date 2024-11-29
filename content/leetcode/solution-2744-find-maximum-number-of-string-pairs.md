
+++
authors = ["grid47"]
title = "Leetcode 2744: Find Maximum Number of String Pairs"
date = "2024-02-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2744: Find Maximum Number of String Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "f8qWoxowloA"
youtube_upload_date="2023-06-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/f8qWoxowloA/maxresdefault.webp"
comments = true
+++



---
You are given a list of distinct strings `words`, where each string consists of exactly two lowercase English letters. You are tasked with finding the maximum number of pairs of strings that can be formed where one string is the reverse of the other.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of distinct strings `words` where each string has exactly two lowercase English letters.
- **Example:** `words = ["cd", "ac", "dc", "ca", "zz"]`
- **Constraints:**
	- 1 <= words.length <= 50
	- words[i].length == 2
	- All strings in words are distinct.
	- words[i] contains only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of pairs that can be formed where one string is the reverse of the other.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To count the maximum number of pairs where one string is the reverse of another in the given list.

- Create an array to track previously seen string pairs.
- For each string in the list, check if its reverse has already been seen.
- If it has been seen, increase the count of valid pairs.
{{< dots >}}
### Problem Assumptions ✅
- The list of strings will always be distinct.
{{< dots >}}
## Examples 🧩
- **Input:** `words = ["cd", "ac", "dc", "ca", "zz"]`  \
  **Explanation:** The two valid pairs are: ["cd", "dc"] and ["ac", "ca"]. Hence, the output is 2.

- **Input:** `words = ["ab", "ba", "cc"]`  \
  **Explanation:** The valid pair is ["ab", "ba"]. Hence, the output is 1.

- **Input:** `words = ["aa", "ab"]`  \
  **Explanation:** No valid pairs can be formed, so the output is 0.

{{< dots >}}
## Approach 🚀
The approach involves creating a simple check to identify valid pairs by tracking seen pairs and counting valid combinations.

### Initial Thoughts 💭
- The problem can be solved by checking if a reversed string exists in the list.
- We can leverage a hash-based approach to store previously seen strings and their reverses.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the list will never be empty.
- The solution must handle lists with up to 50 elements efficiently.
- When all words are the same or have no reversals, no pairs can be formed.
- All words are distinct and consist of two lowercase letters, making it easy to check for reversals.
{{< dots >}}
## Code 💻
```cpp
int maximumNumberOfStringPairs(vector<string>& words) {
int vis[676] = {}, res = 0;
for (const auto &w : words) {
    res += vis[(w[1] - 'a') * 26 + w[0] - 'a'];
    vis[(w[0] - 'a') * 26 + w[1] - 'a'] = true;
}
return res;
}
```

This function calculates the maximum number of string pairs that can be formed where each pair of strings consists of two words that are reversals of each other.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int maximumNumberOfStringPairs(vector<string>& words) {
	```
	Defines the main function to calculate the maximum number of string pairs from a list of words.

2. **Array Initialization**
	```cpp
	int vis[676] = {}, res = 0;
	```
	Initializes an array `vis` of size 676 to track pairs of characters, and a result variable `res` to store the number of valid pairs.

3. **Looping**
	```cpp
	for (const auto &w : words) {
	```
	Iterates through each word in the `words` array.

4. **Frequency Calculation**
	```cpp
	    res += vis[(w[1] - 'a') * 26 + w[0] - 'a'];
	```
	Checks the frequency of the reversed pair of characters in the `vis` array and adds the count to the result.

5. **Array Update**
	```cpp
	    vis[(w[0] - 'a') * 26 + w[1] - 'a'] = true;
	```
	Marks the current pair of characters as encountered in the `vis` array.

6. **Return Statement**
	```cpp
	return res;
	```
	Returns the total count of valid string pairs found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear with respect to the number of words, as each word is checked once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear, as we store a small number of possible string reversals.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-maximum-number-of-string-pairs/description/)

---
{{< youtube f8qWoxowloA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
