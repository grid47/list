
+++
authors = ["grid47"]
title = "Leetcode 1624: Largest Substring Between Two Equal Characters"
date = "2024-05-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1624: Largest Substring Between Two Equal Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rfjeFs3JuYM"
youtube_upload_date="2020-12-21"
youtube_thumbnail="https://i.ytimg.com/vi/rfjeFs3JuYM/maxresdefault.jpg"
comments = true
+++



---
Given a string s, find the length of the longest substring between two equal characters, excluding the two characters themselves. If no such substring exists, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string s (1 <= s.length <= 300) consisting of lowercase English letters.
- **Example:** `s = "zz"`
- **Constraints:**
	- 1 <= s.length <= 300
	- s contains only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest substring between two equal characters, excluding the two characters themselves. If no such substring exists, return -1.
- **Example:** `Output: 0`
- **Constraints:**
	- If no such substring exists, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the longest substring between two equal characters and calculate its length.

- Use a map to store the first occurrence of each character as you iterate through the string.
- When encountering a character that has been seen before, calculate the length of the substring between the two occurrences.
- Update the maximum length if a longer substring is found.
{{< dots >}}
### Problem Assumptions ✅
- The input string will not be empty and will only contain lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "zz"`  \
  **Explanation:** The optimal substring here is an empty substring between the two 'z's.

- **Input:** `s = "xyzxy"`  \
  **Explanation:** The optimal substring here is "yzx" between the two 'x's.

- **Input:** `s = "abcdef"`  \
  **Explanation:** There are no repeated characters, so no valid substring exists.

{{< dots >}}
## Approach 🚀
We will use a map to store the first occurrence of each character, and when a character repeats, we compute the distance between its two occurrences.

### Initial Thoughts 💭
- We need to traverse the string and keep track of the first index of each character.
- If we encounter a character that has been seen before, we calculate the substring length between the two occurrences.
- The string can be scanned in one pass using a hash map for efficient lookup.
{{< dots >}}
### Edge Cases 🌐
- An empty string will never be input since the length is guaranteed to be at least 1.
- Ensure the algorithm works efficiently for strings of length up to 300.
- Handle cases where no character repeats (return -1).
- The solution should work for strings up to a length of 300.
{{< dots >}}
## Code 💻
```cpp
int maxLengthBetweenEqualCharacters(string s) {
    int n = s.size();
    map<char, int> mp;
    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(mp.count(s[i])) {
            ans = max(ans, i - mp[s[i]] - 1);
        }
        if(!mp.count(s[i])) {
            mp[s[i]] = i;
        }
    }
    return ans;
}
```

This is the complete implementation of the 'maxLengthBetweenEqualCharacters' function that finds the maximum length of a substring where the first and last characters are the same.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int maxLengthBetweenEqualCharacters(string s) {
	```
	Function definition starts, takes a string input.

2. **String Manipulations**
	```cpp
	    int n = s.size();
	```
	Calculating the length of the input string and storing it in variable 'n'.

3. **Map Initialization**
	```cpp
	    map<char, int> mp;
	```
	Declaring a map 'mp' to store characters and their first occurrence indices.

4. **Variable Initialization**
	```cpp
	    int ans = -1;
	```
	Initializing 'ans' variable to -1. This will hold the maximum length of substring.

5. **Loop Constructs**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starting a loop to iterate through the string 's'.

6. **Conditional Function Call**
	```cpp
	        if(mp.count(s[i])) {
	```
	Checking if the character 's[i]' has appeared before using the map.

7. **Mathematical Operations**
	```cpp
	            ans = max(ans, i - mp[s[i]] - 1);
	```
	If the character has appeared, calculate the substring length and update 'ans'.

8. **Conditional Function Call**
	```cpp
	        if(!mp.count(s[i])) {
	```
	If the character hasn't appeared before, add it to the map with its index.

9. **Map Insertions**
	```cpp
	            mp[s[i]] = i;
	```
	Insert the character 's[i]' into the map 'mp' with its current index 'i'.

10. **Return Statement**
	```cpp
	    return ans;
	```
	Returning the final value of 'ans', the maximum length of substring found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We traverse the string once, checking the map for each character, making the time complexity O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the map that tracks the indices of characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/)

---
{{< youtube rfjeFs3JuYM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
