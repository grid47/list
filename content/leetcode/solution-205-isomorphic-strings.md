
+++
authors = ["grid47"]
title = "Leetcode 205: Isomorphic Strings"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 205: Isomorphic Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/205.webp"
youtube = "WIJcGWvzu24"
youtube_upload_date="2022-06-26"
youtube_thumbnail="https://i.ytimg.com/vi/WIJcGWvzu24/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/205.webp" 
    alt="Two strings gently morphing into each other, with glowing connections between each corresponding character."
    caption="Solution to LeetCode 205: Isomorphic Strings Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Two strings s and t are isomorphic if you can replace the characters in s to get t. The replacement should be such that each character in s maps to exactly one character in t, and the mapping must preserve the order of characters. No two characters in s or t can map to the same character.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings s and t.
- **Example:** `s = 'abc', t = 'xyz'`
- **Constraints:**
	- 1 <= s.length, t.length <= 5 * 10^4
	- s.length == t.length
	- Both s and t consist of printable ASCII characters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the two strings s and t are isomorphic, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean value indicating whether the strings are isomorphic.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the characters of s can be uniquely mapped to the characters of t without violating the mapping rules.

- Iterate through each character in both strings.
- Use two maps: one to track the mapping from s to t and another from t to s.
- For each character in s and t, check if a consistent mapping exists.
{{< dots >}}
### Problem Assumptions ✅
- The input strings are valid and consist of printable ASCII characters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'abc', t = 'xyz'`  \
  **Explanation:** In this case, 'a' maps to 'x', 'b' maps to 'y', and 'c' maps to 'z'. Since no characters map to the same character, the strings are isomorphic.

- **Input:** `s = 'foo', t = 'bar'`  \
  **Explanation:** Here, 'o' maps to both 'a' and 'r', so the strings are not isomorphic.

{{< dots >}}
## Approach 🚀
The problem can be solved by checking if there is a consistent one-to-one mapping between characters of s and t.

### Initial Thoughts 💭
- This problem requires mapping characters between two strings while ensuring uniqueness in both directions.
- Using two hash maps to track mappings from s to t and t to s can help efficiently solve this problem.
{{< dots >}}
### Edge Cases 🌐
- Since the strings are guaranteed to have the same length and be non-empty, there will be no empty inputs.
- The algorithm must handle large inputs efficiently, given the constraint of up to 50,000 characters.
- When s and t are identical strings, they are always isomorphic.
- The solution must work within the time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
bool isIsomorphic(string s, string t) {
   
     
    map<char, char> fwd, rwd;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if (fwd.count(s[i])){
            if(fwd[s[i]] != t[i])
                return false;
        }
        if(rwd.count(t[i])){
            if(rwd[t[i]] != s[i])
                return false;
        }
        fwd[s[i]] = t[i];
        rwd[t[i]] = s[i];
    }
    return true;
}
```

This code solves the Isomorphic Strings problem by ensuring a one-to-one character mapping between the two strings `s` and `t`. The function uses two maps (`fwd` and `rwd`) to check if the characters in `s` and `t` can be consistently mapped to each other.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isIsomorphic(string s, string t) {
	```
	Define the function `isIsomorphic` that checks if two strings `s` and `t` are isomorphic. Two strings are isomorphic if characters in `s` can be mapped to characters in `t` in a consistent one-to-one manner.

2. **Variable Initialization**
	```cpp
	    map<char, char> fwd, rwd;
	```
	Initialize two maps, `fwd` and `rwd`, to store the character mappings from `s` to `t` and from `t` to `s`, respectively.

3. **String Length Calculation**
	```cpp
	    int n = s.size();
	```
	Calculate the length of string `s` and store it in the variable `n`. The same length applies to string `t`.

4. **For Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a for loop to iterate through each character of the strings `s` and `t`.

5. **Check Forward Mapping**
	```cpp
	        if (fwd.count(s[i])){
	```
	Check if the character `s[i]` has already been mapped in the `fwd` map.

6. **Validate Forward Mapping**
	```cpp
	            if(fwd[s[i]] != t[i])
	```
	If `s[i]` is already mapped, check if the current mapping matches `t[i]`. If not, the strings are not isomorphic.

7. **Return False**
	```cpp
	                return false;
	```
	Return `false` if the mappings are inconsistent.

8. **Check Reverse Mapping**
	```cpp
	        if(rwd.count(t[i])){
	```
	Check if the character `t[i]` has already been mapped in the `rwd` map.

9. **Validate Reverse Mapping**
	```cpp
	            if(rwd[t[i]] != s[i])
	```
	If `t[i]` is already mapped, check if the current mapping matches `s[i]`. If not, the strings are not isomorphic.

10. **Return False**
	```cpp
	                return false;
	```
	Return `false` if the mappings are inconsistent.

11. **Forward Mapping Assignment**
	```cpp
	        fwd[s[i]] = t[i];
	```
	Assign the mapping `s[i]` to `t[i]` in the `fwd` map.

12. **Reverse Mapping Assignment**
	```cpp
	        rwd[t[i]] = s[i];
	```
	Assign the mapping `t[i]` to `s[i]` in the `rwd` map.

13. **Return True**
	```cpp
	    return true;
	```
	Return `true` if no inconsistencies were found, indicating that the strings are isomorphic.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the strings, as we perform a single pass through the strings and constant time operations with hash maps.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the two hash maps.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/isomorphic-strings/description/)

---
{{< youtube WIJcGWvzu24 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
