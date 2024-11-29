
+++
authors = ["grid47"]
title = "Leetcode 409: Longest Palindrome"
date = "2024-09-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 409: Longest Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/409.webp"
youtube = "_g9jrLuAphs"
youtube_upload_date="2024-06-04"
youtube_thumbnail="https://i.ytimg.com/vi/_g9jrLuAphs/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/409.webp" 
    alt="A string where the longest palindrome is highlighted, with characters mirroring in a soft glow."
    caption="Solution to LeetCode 409: Longest Palindrome Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string consisting of lowercase and/or uppercase English letters, find the length of the longest palindrome that can be constructed from the letters in the string. Letters are case-sensitive.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string s consisting of lowercase and/or uppercase English letters.
- **Example:** `For s = 'aabbcc', the longest palindrome is 'abccba', with a length of 6.`
- **Constraints:**
	- 1 <= s.length <= 2000
	- s consists of lowercase and/or uppercase English letters only.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest palindrome that can be formed with the characters from the string.
- **Example:** `For s = 'xyzxy', the longest palindrome is 'xyzxy', with a length of 5.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine the maximum length of the palindrome that can be formed using the characters of the given string.

- 1. Count the frequency of each character in the string.
- 2. Add the maximum even occurrences of characters to the result.
- 3. If any character has an odd count, add one extra character to the center of the palindrome.
{{< dots >}}
### Problem Assumptions ✅
- The input string contains only valid lowercase and/or uppercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `For s = 'aabbcc', the longest palindrome is 'abccba', which has a length of 6.`  \
  **Explanation:** The palindrome is formed by choosing pairs of characters and placing one in the first half and one in the second half of the palindrome. Since all characters appear an even number of times, all can be used to form a palindrome.

{{< dots >}}
## Approach 🚀
Count the frequency of each character, then determine the maximum palindrome length that can be formed by using even counts of characters and adding one extra character if any odd counts are present.

### Initial Thoughts 💭
- A palindrome reads the same forward and backward. To form the longest possible palindrome, we need to use pairs of characters.
- If there are characters with odd occurrences, we can place one of them in the center of the palindrome.
- We need to iterate through the string, count the occurrences of each character, and then determine how many pairs we can form.
{{< dots >}}
### Edge Cases 🌐
- If the string is very large, ensure the solution can handle up to 2000 characters efficiently.
- If the string consists of only one character, the length of the palindrome is 1.
- Handle both uppercase and lowercase letters correctly since they are case-sensitive.
{{< dots >}}
## Code 💻
```cpp
int longestPalindrome(string s) {
    map<char, int> mp;
    for(char x: s)
        mp[x]++;
    bool odd = false;
    int res = 0;
    for(auto [key, val]: mp) {
        if(val % 2) odd = true;
        res += (val/2) * 2;
    }
    return odd? res + 1: res;
}
```

This function finds the length of the longest palindrome that can be formed by the characters of a given string. It counts the frequencies of characters and uses the fact that a palindrome can have at most one character with an odd frequency.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestPalindrome(string s) {
	```
	Define the function `longestPalindrome` which takes a string `s` and returns the length of the longest possible palindrome that can be formed using its characters.

2. **Map Initialization**
	```cpp
	    map<char, int> mp;
	```
	Initialize a `map` named `mp` that stores the frequency of each character in the string `s`.

3. **Loop Iteration**
	```cpp
	    for(char x: s)
	```
	Iterate through each character `x` in the string `s`.

4. **Map Insertion**
	```cpp
	        mp[x]++;
	```
	For each character `x`, increment its count in the `map` `mp`.

5. **Boolean Initialization**
	```cpp
	    bool odd = false;
	```
	Initialize a boolean variable `odd` to track if there's any character with an odd frequency.

6. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initialize an integer variable `res` to accumulate the total length of the palindrome formed.

7. **Map Iteration**
	```cpp
	    for(auto [key, val]: mp) {
	```
	Iterate through each entry in the `map` `mp`, where `key` is the character and `val` is its frequency.

8. **Odd Frequency Check**
	```cpp
	        if(val % 2) odd = true;
	```
	If the frequency of a character is odd, set the `odd` flag to `true`.

9. **Palindrome Length Calculation**
	```cpp
	        res += (val/2) * 2;
	```
	For each character, add the largest even number less than or equal to its frequency to `res`. This represents the part of the palindrome that can be used symmetrically on both sides.

10. **Return Statement**
	```cpp
	    return odd? res + 1: res;
	```
	If there was at least one character with an odd frequency, add 1 to `res` (since we can place exactly one odd character in the middle of the palindrome). Otherwise, return `res` as is.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string, because we only need to iterate through the string once to count the characters and once more to calculate the palindrome length.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only need to store the frequency of characters, which is constant for the 26 lowercase and 26 uppercase English letters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-palindrome/description/)

---
{{< youtube _g9jrLuAphs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
