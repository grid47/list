
+++
authors = ["grid47"]
title = "Leetcode 2957: Remove Adjacent Almost-Equal Characters"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2957: Remove Adjacent Almost-Equal Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PjIWjV-Y5YQ"
youtube_upload_date="2023-12-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/PjIWjV-Y5YQ/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed string word. In each operation, you can change any character of word to a lowercase English letter. Two characters are considered almost-equal if they are the same or adjacent in the alphabet. Your task is to remove all adjacent almost-equal characters with the minimum number of operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A 0-indexed string 'word' containing lowercase English letters.
- **Example:** `word = 'aaaaa'`
- **Constraints:**
	- 1 <= word.length <= 100
	- word consists only of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to remove all adjacent almost-equal characters from the string.
- **Example:** `2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the minimum number of operations needed to ensure no adjacent characters are almost-equal.

- Iterate through the string, checking each pair of adjacent characters.
- If two adjacent characters are almost-equal, increment the operation counter and skip the next character.
- Repeat the process until the end of the string.
{{< dots >}}
### Problem Assumptions ✅
- The input string will have at least one character.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: word = 'aaaaa'`  \
  **Explanation:** The adjacent characters 'a' and 'a' are almost-equal. By changing characters at alternate positions (e.g., 'a' to 'c'), we can remove all adjacent almost-equal characters.

- **Input:** `Input: word = 'abcde'`  \
  **Explanation:** All adjacent characters are distinct and not almost-equal, so no changes are needed.

{{< dots >}}
## Approach 🚀
The approach is to iterate through the string and check each adjacent pair of characters, counting how many changes are needed to avoid adjacent almost-equal characters.

### Initial Thoughts 💭
- Adjacent almost-equal characters can be removed by changing one of them.
- We need to avoid adjacent almost-equal pairs by modifying characters one at a time.
- Using a greedy approach, we can process each character and decide whether to change it based on its adjacency to the previous character.
{{< dots >}}
### Edge Cases 🌐
- The string will always have at least one character.
- Ensure the solution works efficiently when the string length is at its maximum of 100 characters.
- All characters being the same will require the maximum number of operations to break adjacent almost-equal pairs.
- The string length is always between 1 and 100.
{{< dots >}}
## Code 💻
```cpp
int removeAlmostEqualCharacters(string s) {
    int n = s.size();
    int i = 1, cnt = 0;
    while(i < n) {
        if(s[i] == s[i - 1] || abs(s[i] - s[i - 1]) == 1) cnt++, i += 2;
        else i++;
    }
    return cnt;        
}
```

This function removes pairs of adjacent characters in the string 's' that are either equal or have ASCII values differing by 1, and returns the number of pairs removed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int removeAlmostEqualCharacters(string s) {
	```
	Defines the function 'removeAlmostEqualCharacters', which takes a string 's' and removes adjacent character pairs that are either the same or have a difference of 1 in their ASCII values.

2. **String Size**
	```cpp
	    int n = s.size();
	```
	Calculates the size of the string 's' and stores it in 'n'. This helps to determine the length of the string for iteration purposes.

3. **Variable Initialization**
	```cpp
	    int i = 1, cnt = 0;
	```
	Initializes two variables: 'i' to 1 for iterating through the string, and 'cnt' to 0 to count the number of pairs removed.

4. **While Loop Start**
	```cpp
	    while(i < n) {
	```
	Starts a while loop that continues as long as 'i' is less than 'n', the length of the string. This loop will iterate over each character in the string.

5. **Check Adjacent Characters**
	```cpp
	        if(s[i] == s[i - 1] || abs(s[i] - s[i - 1]) == 1) cnt++, i += 2;
	```
	Checks if the current character is equal to the previous character, or if their ASCII values differ by 1. If either condition is true, increments 'cnt' (the count of pairs removed), and skips the next character by increasing 'i' by 2.

6. **Skip to Next Character**
	```cpp
	        else i++;
	```
	If the current character does not meet the conditions (not equal or not differing by 1), simply increments 'i' to move to the next character.

7. **Return Result**
	```cpp
	    return cnt;        
	```
	Returns the total count of pairs of characters that were removed from the string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we process each character in the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only use a few variables for tracking the state.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-adjacent-almost-equal-characters/description/)

---
{{< youtube PjIWjV-Y5YQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
