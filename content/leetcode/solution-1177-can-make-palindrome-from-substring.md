
+++
authors = ["grid47"]
title = "Leetcode 1177: Can Make Palindrome from Substring"
date = "2024-07-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1177: Can Make Palindrome from Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "tCr-y-1P2J8"
youtube_upload_date="2024-06-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/tCr-y-1P2J8/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` and an array of queries `queries`, where `queries[i] = [lefti, righti, ki]`. For each query, you can rearrange the substring `s[lefti...righti]` and replace up to `ki` characters in it with any lowercase English letters. Determine whether it is possible to form a palindrome from the resulting substring. Return an array of booleans `answer` where `answer[i]` is `true` if it is possible to form a palindrome for the `i-th` query, otherwise `false`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The function receives a string `s` and an array `queries` as input.
- **Example:** `Input: s = 'abcbcba', queries = [[0, 6, 2], [1, 4, 1], [0, 2, 0], [3, 5, 1]]`
- **Constraints:**
	- 1 <= s.length, queries.length <= 10^5
	- 0 <= lefti <= righti < s.length
	- 0 <= ki <= s.length
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The function returns a list of booleans indicating the result for each query.
- **Example:** `Output: [true, true, false, true]`
- **Constraints:**
	- The output list must be of the same length as the input `queries`.

{{< dots >}}
### Core Logic 🔍
**Goal:** Check whether the substring defined by `lefti` and `righti` in each query can be rearranged and modified with up to `ki` character replacements to form a palindrome.

- Calculate prefix bit masks to track character frequencies for the entire string.
- For each query, compute the XOR of prefix masks for the specified range to determine the odd-frequency characters.
- Count the number of odd-frequency characters and check if they can be adjusted to form a palindrome using up to `ki` replacements.
{{< dots >}}
### Problem Assumptions ✅
- Each query operates independently without altering the input string `s`.
- Only lowercase English letters (26 characters) are considered.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'aabbcc', queries = [[0, 5, 1], [0, 3, 0], [2, 4, 2]]`  \
  **Explanation:** Query 0: Substring 'aabbcc' can be rearranged to 'abcba' with 1 replacement. Query 1: Substring 'aabb' cannot be a palindrome without replacements. Query 2: Substring 'bbc' can be rearranged to 'cbc' with 2 replacements.

{{< dots >}}
## Approach 🚀
Use bit manipulation with prefix masks to efficiently compute the odd-frequency characters in each query range.

### Initial Thoughts 💭
- A string can be rearranged into a palindrome if at most one character has an odd frequency.
- Efficient range queries can be handled using prefix bit masks to store character frequency states.
- Track odd/even counts for characters using XOR.
- Check the number of odd counts and compare with the allowed replacements `ki`.
{{< dots >}}
### Edge Cases 🌐
- Empty string or empty queries array.
- Maximum possible length of `s` and number of queries.
- All characters in the substring are the same.
- Substring contains alternating characters.
- Ensure correct handling of indices and boundary conditions.
{{< dots >}}
## Code 💻
```cpp
vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
    vector<bool> ans;
    
    vector<int> pt(1,0);
    int mask = 0;
    
    for(int i = 0; i < s.length(); i++) {
    pt.push_back(mask ^= 1 << (s[i] - 'a'));
    }
    
    
    for(int i = 0; i < q.size(); i++) {
    
auto &v = q[i];

  
int cnt = __builtin_popcount(pt[v[1]+1] ^ pt[v[0]]);

ans.push_back(cnt/2 <= v[2]);
    }
    
    return ans;
}
```

This function, `canMakePaliQueries`, checks whether a given string `s` can be rearranged into a palindrome after making at most `k` modifications for each query. The queries are given as a list of ranges and a maximum allowed number of modifications.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
	```
	Define the function `canMakePaliQueries` that takes a string `s` and a 2D vector of queries `q`. It returns a vector of booleans indicating whether the given substring can be rearranged into a palindrome with at most `k` modifications.

2. **Variable Initialization**
	```cpp
	    vector<bool> ans;
	```
	Initialize the vector `ans` to store the results for each query.

3. **Variable Initialization**
	```cpp
	    vector<int> pt(1,0);
	```
	Initialize a vector `pt` to store prefix XOR values, starting with 0.

4. **Variable Initialization**
	```cpp
	    int mask = 0;
	```
	Initialize `mask` to 0. This variable will be used to track the state of characters in the string.

5. **Loop**
	```cpp
	    for(int i = 0; i < s.length(); i++) {
	```
	Loop through each character in the string `s`.

6. **Bitwise Operation**
	```cpp
	    pt.push_back(mask ^= 1 << (s[i] - 'a'));
	```
	Use bitwise operations to update `mask` for the current character and store the result in `pt`.

7. **Loop**
	```cpp
	    for(int i = 0; i < q.size(); i++) {
	```
	Loop through each query in `q`.

8. **Variable Initialization**
	```cpp
	auto &v = q[i];
	```
	Get the current query from the list `q`.

9. **Bitwise Operation**
	```cpp
	int cnt = __builtin_popcount(pt[v[1]+1] ^ pt[v[0]]);
	```
	Calculate the number of different bits (i.e., characters) between the prefix sums at positions `v[0]` and `v[1]`.

10. **Vector Operation**
	```cpp
	ans.push_back(cnt/2 <= v[2]);
	```
	Push the result of the query (whether the count of different bits divided by 2 is less than or equal to `v[2]`) to the `ans` vector.

11. **Return Statement**
	```cpp
	    return ans;
	```
	Return the vector `ans` containing the results of all queries.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + q)
- **Average Case:** O(n + q)
- **Worst Case:** O(n + q)

Precomputing prefix masks takes O(n), and each query is processed in O(1).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space is used for the prefix mask array and temporary variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/can-make-palindrome-from-substring/description/)

---
{{< youtube tCr-y-1P2J8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
