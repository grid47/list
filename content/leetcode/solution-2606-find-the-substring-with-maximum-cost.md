
+++
authors = ["grid47"]
title = "Leetcode 2606: Find the Substring With Maximum Cost"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2606: Find the Substring With Maximum Cost in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EwSIfXGq2B4"
youtube_upload_date="2023-04-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/EwSIfXGq2B4/maxresdefault.webp"
comments = true
+++



---
You are given a string s, a string chars of distinct characters, and an integer array vals of the same length as chars. The value of each character is determined by either its position in the alphabet or a corresponding value in the vals array if it is present in chars. The cost of a substring is the sum of the values of each character in that substring. Your goal is to find the maximum cost of any substring of s.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string s consisting of lowercase English letters, a string chars with distinct lowercase letters, and an integer array vals with values corresponding to each character in chars.
- **Example:** `s = 'xyz', chars = 'xy', vals = [10, 20]`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- 1 <= chars.length <= 26
	- chars consists of distinct lowercase English letters
	- vals.length == chars.length
	- -1000 <= vals[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum cost among all substrings of the string s, where the cost of a substring is the sum of the values of its characters.
- **Example:** `Output: 30`
- **Constraints:**
	- The output is a single integer representing the maximum cost of any substring.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine the maximum cost among all substrings by efficiently calculating the value of each substring.

- First, create a map where each character in the string s gets a corresponding value based on chars and vals.
- For characters not present in chars, assign them their position in the alphabet.
- Use a sliding window or dynamic programming approach to calculate the maximum possible sum of character values in any substring.
{{< dots >}}
### Problem Assumptions ✅
- The characters in s are all lowercase English letters.
- The vals array corresponds to the characters in chars.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'abc', chars = 'abc', vals = [-1, -1, -1]`  \
  **Explanation:** In this case, each character in 'abc' has a value of -1, so the best substring with the maximum cost is the empty string, with a cost of 0.

- **Input:** `s = 'adaa', chars = 'd', vals = [-1000]`  \
  **Explanation:** In this example, the value of 'a' is 1 and 'd' is -1000. The maximum cost comes from the substring 'aa', with a total cost of 2.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to calculate the cost of every possible substring of s and track the maximum cost found.

### Initial Thoughts 💭
- The maximum cost could come from a single character or from a longer substring.
- We need to efficiently compute the cost of each substring and avoid recalculating values multiple times.
- By assigning each character a value based on its presence in chars, we can calculate the cost of any substring as the sum of the values of its characters.
{{< dots >}}
### Edge Cases 🌐
- An empty string s should return a maximum cost of 0.
- The string s can have up to 100,000 characters, so the solution must handle large inputs efficiently.
- Negative values in vals could affect the maximum cost, especially when characters in s have low or negative values.
- Ensure that the solution works in O(n) time to handle the large input size of s.
{{< dots >}}
## Code 💻
```cpp
int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    map<char, int> mp;
    for(int i = 0; i < chars.size(); i++) {
        mp[chars[i]] = vals[i];
    }
    for(int i = 0; i < 26; i++) {
        char x = 'a' + i;
        if(mp.count(x)) continue;
        mp[x] = i + 1;
    }
    
    int lmax = 0, gmax = 0;
    for(int i = 0; i < s.size(); i++) {
        if(mp[s[i]] < lmax + mp[s[i]]) {
            lmax = lmax + mp[s[i]];
        } else lmax = mp[s[i]];
        
        gmax = max(gmax, lmax);
    }
    return gmax;
}
```

This code calculates the maximum cost of a substring from string `s` where each character has a cost defined in `chars` and `vals`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	int maximumCostSubstring(string s, string chars, vector<int>& vals) {
	```
	Start by declaring the function that takes the string `s`, a string `chars`, and a vector `vals` which maps characters in `chars` to their respective costs.

2. **Data Structures**
	```cpp
	    map<char, int> mp;
	```
	Initialize a map `mp` to store the cost for each character in the string `chars`.

3. **Loop**
	```cpp
	    for(int i = 0; i < chars.size(); i++) {
	```
	Loop through each character in the `chars` string.

4. **Mapping**
	```cpp
	        mp[chars[i]] = vals[i];
	```
	For each character in `chars`, map it to its corresponding value from `vals`.

5. **Character Initialization**
	```cpp
	    for(int i = 0; i < 26; i++) {
	```
	Start a loop for all lowercase English letters (26 total).

6. **Character Processing**
	```cpp
	        char x = 'a' + i;
	```
	Assign each letter of the alphabet to `x` by adding the loop index `i` to the character 'a'.

7. **Check for Missing Characters**
	```cpp
	        if(mp.count(x)) continue;
	```
	Check if the character `x` is already in the map. If it is, skip to the next character.

8. **Character Assignment**
	```cpp
	        mp[x] = i + 1;
	```
	If the character `x` is not in the map, assign it a cost of `i + 1`.

9. **Initialization**
	```cpp
	    int lmax = 0, gmax = 0;
	```
	Initialize two variables: `lmax` to track the local maximum substring sum and `gmax` to track the global maximum.

10. **Iterate Through String**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Iterate through each character in the string `s`.

11. **Compare with Local Max**
	```cpp
	        if(mp[s[i]] < lmax + mp[s[i]]) {
	```
	Check if adding the current character's cost to `lmax` gives a larger sum.

12. **Update Local Max**
	```cpp
	            lmax = lmax + mp[s[i]];
	```
	If the local sum is larger, update `lmax`.

13. **Else Condition**
	```cpp
	        } else lmax = mp[s[i]];
	```
	Otherwise, reset `lmax` to the cost of the current character.

14. **Update Global Max**
	```cpp
	        gmax = max(gmax, lmax);
	```
	Update the global maximum `gmax` to be the maximum of `gmax` and `lmax`.

15. **Return Result**
	```cpp
	    return gmax;
	```
	Return the global maximum sum of the substring.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the length of the string s, as we process each character in the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case due to the need to store the values of characters in the string s.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-substring-with-maximum-cost/description/)

---
{{< youtube EwSIfXGq2B4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
