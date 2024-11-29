
+++
authors = ["grid47"]
title = "Leetcode 3138: Minimum Length of Anagram Concatenation"
date = "2023-12-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3138: Minimum Length of Anagram Concatenation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "T64iR68Fxng"
youtube_upload_date="2024-05-05"
youtube_thumbnail="https://i.ytimg.com/vi/T64iR68Fxng/maxresdefault.jpg"
comments = true
+++



---
You are given a string `s`, which is a concatenation of several anagrams of some string `t`. Your task is to find the minimum possible length of the string `t`. An anagram is formed by rearranging the letters of a string. For example, 'abc' and 'cab' are anagrams of each other. The string `t` is the original string that has been rearranged multiple times to form `s`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s`.
- **Example:** `Example 1:
Input: s = "abcabc"
Output: 3`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum length of the string `t` that can be used to form the concatenated anagrams in `s`.
- **Example:** `Example 1:
Input: s = "abcabc"
Output: 3`
- **Constraints:**
	- The result must be an integer representing the minimum length of the string `t`.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the minimum possible length of `t`, we need to determine the greatest common divisor (GCD) of the frequency of characters in the string.

- Count the frequency of each character in the string `s`.
- Find the GCD of the frequency counts of the characters in `s`.
- The length of `t` will be the length of `s` divided by the GCD of the frequencies.
{{< dots >}}
### Problem Assumptions ✅
- The string `s` is guaranteed to be a concatenation of anagrams.
- The string `s` contains only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** For the string 'abcabc', the frequency of each character is 2. The greatest common divisor (GCD) of 2 is 2, so the minimum length of `t` is 3 (which is the length of `s` divided by 2).

- **Input:** `Example 2:`  \
  **Explanation:** For the string 'abcdabcd', the frequency of each character is 2. The GCD of 2 is 2, so the minimum length of `t` is 4.

{{< dots >}}
## Approach 🚀
To solve this problem, we will use a frequency count of the characters in the string and apply the GCD method to determine the minimum possible length of `t`.

### Initial Thoughts 💭
- The problem is asking for the smallest possible string `t` that, when rearranged, can form the input string `s` through multiple concatenations.
- By counting the frequency of characters and applying the GCD, we can identify the smallest repeating unit in `s`.
{{< dots >}}
### Edge Cases 🌐
- The input string is always guaranteed to have at least one character.
- Ensure that the solution can handle input strings of length up to 10^5 efficiently.
- The solution must handle cases where all characters in the string are the same.
- Make sure to handle cases where characters have varying frequencies.
{{< dots >}}
## Code 💻
```cpp
int minAnagramLength(string s) {
    // 12,  4
    // aaxxbb
    // bbxxaa

    int n = s.size();
    map<char, int> mp;        
    for(char x: s)
        mp[x]++;

    int mn = mp[s[0]];
    for(auto it: mp)
    mn = __gcd(mn, it.second);

    return n / mn;
}
```

This function calculates the minimum length of an anagram that can be made from a given string `s`. It finds the greatest common divisor (GCD) of the frequencies of characters in the string and divides the string length by this value to determine the anagram length.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minAnagramLength(string s) {
	```
	Defines the function `minAnagramLength`, which takes a string `s` as input and returns an integer representing the minimum length of an anagram that can be formed from `s`.

2. **Variable Initialization**
	```cpp
	    int n = s.size();
	```
	Initializes the variable `n` to store the length of the string `s`.

3. **Map Initialization**
	```cpp
	    map<char, int> mp;        
	```
	Initializes a map `mp` to store the frequency of each character in the string `s`.

4. **For Loop**
	```cpp
	    for(char x: s)
	```
	Starts a loop that iterates through each character in the string `s`.

5. **Map Update**
	```cpp
	        mp[x]++;
	```
	For each character `x` in the string, it increments its count in the map `mp`.

6. **Variable Initialization**
	```cpp
	    int mn = mp[s[0]];
	```
	Initializes `mn` to the frequency of the first character in the string `s` to start finding the GCD of character frequencies.

7. **For Loop**
	```cpp
	    for(auto it: mp)
	```
	Starts a loop to iterate through the map `mp`, which contains the frequencies of each character in the string.

8. **GCD Calculation**
	```cpp
	    mn = __gcd(mn, it.second);
	```
	For each character frequency in the map, it calculates the GCD of `mn` and the current character's frequency (`it.second`). This finds the greatest common divisor of all character frequencies.

9. **Return Statement**
	```cpp
	    return n / mn;
	```
	Returns the result of dividing the string length `n` by the GCD `mn`, which gives the minimum length of the anagram that can be made from the string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, where `n` is the length of the input string `s`, since we are only iterating over the string once and performing constant time operations for each character.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the frequency counts of the characters in the string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-length-of-anagram-concatenation/description/)

---
{{< youtube T64iR68Fxng >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
