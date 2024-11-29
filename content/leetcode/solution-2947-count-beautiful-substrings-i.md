
+++
authors = ["grid47"]
title = "Leetcode 2947: Count Beautiful Substrings I"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2947: Count Beautiful Substrings I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String","Enumeration","Number Theory","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "AnuZGQmVPQM"
youtube_upload_date="2023-11-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/AnuZGQmVPQM/maxresdefault.webp"
comments = true
+++



---
You are given a string s and a positive integer k. A string is beautiful if it satisfies the conditions that the number of vowels equals the number of consonants, and the product of the number of vowels and consonants is divisible by k. Return the number of non-empty beautiful substrings in the string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s and a positive integer k.
- **Example:** `s = 'abec', k = 2`
- **Constraints:**
	- 1 <= s.length <= 1000
	- 1 <= k <= 1000
	- s consists of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the number of non-empty substrings of s that are beautiful.
- **Example:** `Output: 1`
- **Constraints:**
	- The number of substrings is non-negative.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find and return the number of beautiful substrings from the input string.

- Iterate through all possible substrings of s.
- Count the vowels and consonants in each substring.
- Check if the number of vowels equals the number of consonants and if their product is divisible by k.
{{< dots >}}
### Problem Assumptions ✅
- The input string will contain only lowercase English letters.
- The value of k will be positive and within the range [1, 1000].
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'abec', k = 2`  \
  **Explanation:** The substring 'abec' is the only beautiful substring. It has 2 vowels ['a', 'e'] and 2 consonants ['b', 'c']. Since the product of the number of vowels and consonants (2 * 2 = 4) is divisible by 2, it is considered beautiful.

- **Input:** `s = 'aaee', k = 1`  \
  **Explanation:** The substrings 'aa' and 'ee' are beautiful because they both have equal numbers of vowels and consonants, and their product is divisible by 1.

{{< dots >}}
## Approach 🚀
The solution requires iterating through all possible substrings and checking if they satisfy the criteria for being beautiful.

### Initial Thoughts 💭
- We need to count the number of vowels and consonants efficiently for each substring.
- Using nested loops to check each substring will require optimization, especially for longer strings.
{{< dots >}}
### Edge Cases 🌐
- The string will never be empty based on the given constraints.
- The solution must be efficient for strings of length up to 1000.
- When k = 1, any string where the number of vowels equals the number of consonants is a valid beautiful string.
- Efficient algorithms are necessary due to the input size constraints.
{{< dots >}}
## Code 💻
```cpp
unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
bool isVowel(char c) { return st.find(c) != st.end(); }
int beautifulSubstrings(string s, int k) {
    int ans = 0;
    for(int i = 0; i < s.size(); ++i){
        int vow = 0, con = 0;
        for(int j = i; j < s.size(); ++j) {
            (isVowel(s[j]))? vow++: con++;
            if(vow == con && (vow*con)%k == 0) ans++;
        }
    }
    return ans;
}
```

This function counts the number of 'beautiful' substrings in a given string 's' where the number of vowels and consonants are equal, and the product of the number of vowels and consonants is divisible by 'k'. It uses a helper function 'isVowel' to check if a character is a vowel.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Vowel Set Initialization**
	```cpp
	unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
	```
	Initializes an unordered set 'st' that contains the vowels 'a', 'e', 'i', 'o', and 'u'. This set is used to check if a character is a vowel in the helper function 'isVowel'.

2. **Helper Function**
	```cpp
	bool isVowel(char c) { return st.find(c) != st.end(); }
	```
	Defines the helper function 'isVowel', which checks if a character 'c' is present in the set of vowels 'st'. It returns 'true' if 'c' is a vowel and 'false' otherwise.

3. **Function Definition**
	```cpp
	int beautifulSubstrings(string s, int k) {
	```
	Defines the function 'beautifulSubstrings' which takes a string 's' and an integer 'k', and returns the count of beautiful substrings where the number of vowels and consonants are equal and their product is divisible by 'k'.

4. **Answer Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes a variable 'ans' to 0. This will hold the count of beautiful substrings.

5. **Outer Loop**
	```cpp
	    for(int i = 0; i < s.size(); ++i){
	```
	Starts a loop to iterate through the string 's', where 'i' is the starting index of the current substring.

6. **Vowel and Consonant Counters**
	```cpp
	        int vow = 0, con = 0;
	```
	Initializes two variables 'vow' and 'con' to 0. These will count the number of vowels and consonants in the current substring.

7. **Inner Loop**
	```cpp
	        for(int j = i; j < s.size(); ++j) {
	```
	Starts an inner loop to iterate through the substring starting from index 'i' and ending at index 'j'.

8. **Vowel or Consonant Count**
	```cpp
	            (isVowel(s[j]))? vow++: con++;
	```
	Checks if the character at position 'j' is a vowel using the 'isVowel' function. If it is, it increments the vowel count ('vow'), otherwise it increments the consonant count ('con').

9. **Beautiful Substring Check**
	```cpp
	            if(vow == con && (vow*con)%k == 0) ans++;
	```
	Checks if the number of vowels ('vow') is equal to the number of consonants ('con') and if their product is divisible by 'k'. If both conditions are satisfied, it increments the 'ans' counter.

10. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the value of 'ans', which is the total count of beautiful substrings.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In the worst case, we must check all substrings, leading to a time complexity of O(n^2).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(1) if we only use a few extra variables, but it could be O(n) if we store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-beautiful-substrings-i/description/)

---
{{< youtube AnuZGQmVPQM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
