
+++
authors = ["grid47"]
title = "Leetcode 1839: Longest Substring Of All Vowels in Order"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1839: Longest Substring Of All Vowels in Order in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "hhyzRnwYBwA"
youtube_upload_date="2021-04-25"
youtube_thumbnail="https://i.ytimg.com/vi/hhyzRnwYBwA/maxresdefault.jpg"
comments = true
+++



---
A string is considered beautiful if it satisfies the following conditions: each of the five vowels ('a', 'e', 'i', 'o', 'u') must appear at least once, and the characters must appear in alphabetical order. Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string word containing only vowels ('a', 'e', 'i', 'o', 'u').
- **Example:** `word = 'aeiouaeiouaei'`
- **Constraints:**
	- 1 <= word.length <= 5 * 10^5
	- word consists only of characters 'a', 'e', 'i', 'o', 'u'.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the length of the longest beautiful substring in the word.
- **Example:** `11`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the longest contiguous substring that contains all five vowels at least once and appears in alphabetical order.

- Initialize a map for vowel indices.
- Iterate through the string and use a sliding window to track the longest valid substring that meets the conditions of a beautiful string.
- Update the result with the longest valid substring found during iteration.
{{< dots >}}
### Problem Assumptions ✅
- The input string will always contain characters from the set { 'a', 'e', 'i', 'o', 'u' }.
- The string will have at least 1 character.
{{< dots >}}
## Examples 🧩
- **Input:** `word = 'aeiouaeiouaei'`  \
  **Explanation:** The longest beautiful substring in 'aeiouaeiouaei' is 'aeiouaeioua' because it contains all vowels in the correct order and is the longest such substring.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a sliding window approach to iterate through the string and keep track of the longest valid substring. The window is valid if it contains all five vowels and they appear in order.

### Initial Thoughts 💭
- We need to track the positions of each vowel in the string to check if they appear in the correct order.
- A sliding window is a natural choice here since we are looking for a contiguous sequence of characters.
{{< dots >}}
### Edge Cases 🌐
- The input string will always contain at least one character, so this case does not need to be handled explicitly.
- The solution should be efficient enough to handle large strings up to 5 * 10^5 characters.
- Strings with only one type of vowel or without all five vowels cannot be considered beautiful.
- The solution must work for strings of varying lengths, from 1 to 5 * 10^5 characters.
{{< dots >}}
## Code 💻
```cpp
int longestBeautifulSubstring(string s) {
    map<char, int> idx;
    idx['a'] = 0;
    idx['e'] = 1;
    idx['i'] = 2;
    idx['o'] = 3;
    idx['u'] = 4;
    
    int j = 0, res = 0, n = s.size();
    int id = -1;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            if(id != 0) {                 
                j = i;
            }
            id = 0;
        }else if((idx[s[i]] < id) || (idx[s[i]] - id > 1)) {
            id = -1;
            j = i;
        } else if(idx[s[i]] - id == 1) {
            id = idx[s[i]];
            
        }
        
        if(id == 4) {
            res = max(res, i - j + 1);
        }
    }
    return res;
}
```

This function finds the length of the longest substring of a string `s` that contains characters 'a', 'e', 'i', 'o', 'u' in order, where the characters must appear exactly once and in consecutive order. It uses a sliding window approach with a map to track the required characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestBeautifulSubstring(string s) {
	```
	Defines the function `longestBeautifulSubstring`, which takes a string `s` and returns the length of the longest substring containing the vowels 'a', 'e', 'i', 'o', 'u' in order.

2. **Map Initialization**
	```cpp
	    map<char, int> idx;
	```
	Declares a map `idx` that associates each vowel with a corresponding integer value to track the order in which the vowels should appear.

3. **Assign Vowel Indexes**
	```cpp
	    idx['a'] = 0;
	```
	Assigns 0 to 'a' in the map `idx`, representing its position in the sequence of vowels.

4. **Assign Vowel Indexes**
	```cpp
	    idx['e'] = 1;
	```
	Assigns 1 to 'e' in the map `idx`, representing its position in the sequence of vowels.

5. **Assign Vowel Indexes**
	```cpp
	    idx['i'] = 2;
	```
	Assigns 2 to 'i' in the map `idx`, representing its position in the sequence of vowels.

6. **Assign Vowel Indexes**
	```cpp
	    idx['o'] = 3;
	```
	Assigns 3 to 'o' in the map `idx`, representing its position in the sequence of vowels.

7. **Assign Vowel Indexes**
	```cpp
	    idx['u'] = 4;
	```
	Assigns 4 to 'u' in the map `idx`, representing its position in the sequence of vowels.

8. **Variable Initialization**
	```cpp
	    int j = 0, res = 0, n = s.size();
	```
	Initializes variables: `j` to track the starting index of the current substring, `res` to store the result (longest valid substring length), and `n` for the size of the input string `s`.

9. **Variable Initialization**
	```cpp
	    int id = -1;
	```
	Initializes the variable `id` to -1 to keep track of the most recent vowel index in the substring.

10. **For Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to iterate through the string `s` character by character.

11. **Check for 'a'**
	```cpp
	        if(s[i] == 'a') {
	```
	Checks if the current character is 'a'.

12. **Check and Update Window**
	```cpp
	            if(id != 0) {                 
	```
	If the previous vowel was not 'a', reset the start of the window by setting `j` to the current index `i`.

13. **Update Start Index**
	```cpp
	                j = i;
	```
	Sets `j` to the current index `i` to start a new potential substring.

14. **Update Vowel Index**
	```cpp
	            id = 0;
	```
	Sets the vowel index `id` to 0, representing the 'a' vowel.

15. **Check for Invalid Vowel Sequence**
	```cpp
	        }else if((idx[s[i]] < id) || (idx[s[i]] - id > 1)) {
	```
	Checks if the current character does not follow the correct vowel sequence or if it's out of order.

16. **Reset Vowel Sequence**
	```cpp
	            id = -1;
	```
	Resets `id` to -1 and `j` to the current index `i`, marking the start of a new potential valid substring.

17. **Update Start Index**
	```cpp
	            j = i;
	```
	Resets the starting index `j` because the current character breaks the valid vowel order.

18. **Check for Valid Vowel Progression**
	```cpp
	        } else if(idx[s[i]] - id == 1) {
	```
	Checks if the current character is the next vowel in the sequence.

19. **Update Vowel Index**
	```cpp
	            id = idx[s[i]];
	```
	Updates the vowel index `id` to the index of the current character.

20. **Check for Full Sequence**
	```cpp
	        if(id == 4) {
	```
	Checks if the substring has reached the end of the vowel sequence, 'u'.

21. **Update Result**
	```cpp
	            res = max(res, i - j + 1);
	```
	Updates the result `res` with the length of the current valid substring if it's longer than the previous longest substring.

22. **Return Result**
	```cpp
	    return res;
	```
	Returns the length of the longest beautiful substring found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only need to iterate over the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only need a constant amount of extra space for the sliding window.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/description/)

---
{{< youtube hhyzRnwYBwA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
