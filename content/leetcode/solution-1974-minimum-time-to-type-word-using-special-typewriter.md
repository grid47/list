
+++
authors = ["grid47"]
title = "Leetcode 1974: Minimum Time to Type Word Using Special Typewriter"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1974: Minimum Time to Type Word Using Special Typewriter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "DEMUS-1tq-0"
youtube_upload_date="2021-08-21"
youtube_thumbnail="https://i.ytimg.com/vi/DEMUS-1tq-0/maxresdefault.jpg"
comments = true
+++



---
You are given a special typewriter with lowercase English letters ('a' to 'z') arranged in a circle. A pointer initially starts at the character 'a'. Each second, you may perform one of two operations: move the pointer one character clockwise or counterclockwise, or type the character the pointer is currently on. Your task is to determine the minimum number of seconds needed to type the given string `word`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `word` of length `n`, where 1 <= n <= 100, consisting of lowercase English letters.
- **Example:** `word = 'xyz'`
- **Constraints:**
	- 1 <= word.length <= 100
	- word consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer, which represents the minimum number of seconds required to type the entire word.
- **Example:** `Output: 12`
- **Constraints:**
	- The result should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the minimum number of seconds to type out the characters in the word.

- Step 1: Initialize a variable to keep track of the current pointer position, starting at 'a'.
- Step 2: For each character in the word, calculate the time required to move the pointer to the target character (either clockwise or counterclockwise).
- Step 3: Accumulate the time spent on each move and typing action to get the total time.
- Step 4: Return the total time as the result.
{{< dots >}}
### Problem Assumptions ✅
- The word consists only of lowercase letters from 'a' to 'z'.
- There are no special characters or spaces in the input word.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: word = 'abc'`  \
  **Explanation:** Starting with the pointer at 'a', the steps would be: Type 'a' (1 second), move to 'b' (1 second), type 'b' (1 second), move to 'c' (1 second), and type 'c' (1 second). The total time is 5 seconds.

- **Input:** `Input: word = 'bza'`  \
  **Explanation:** Starting with the pointer at 'a', the steps would be: Move to 'b' (1 second), type 'b' (1 second), move counterclockwise to 'z' (2 seconds), type 'z' (1 second), move clockwise to 'a' (1 second), and type 'a' (1 second). The total time is 7 seconds.

- **Input:** `Input: word = 'zjpc'`  \
  **Explanation:** Starting with the pointer at 'a', the steps would be: Move counterclockwise to 'z' (1 second), type 'z' (1 second), move clockwise to 'j' (10 seconds), type 'j' (1 second), move to 'p' (6 seconds), type 'p' (1 second), move counterclockwise to 'c' (13 seconds), and type 'c' (1 second). The total time is 34 seconds.

{{< dots >}}
## Approach 🚀
To solve this problem, we calculate the minimal time required to move the pointer to each character in the word. The key observation is to find the shortest distance between the current pointer position and the target character, either clockwise or counterclockwise, and add the time to type that character.

### Initial Thoughts 💭
- The problem can be approached by calculating the minimal distance between two characters, considering the circular nature of the alphabet.
- A direct approach involves iterating through the string and updating the pointer position as we compute the minimum time to reach each successive character.
{{< dots >}}
### Edge Cases 🌐
- The word will always have at least one character, as per the constraints.
- The solution must efficiently handle strings of up to 100 characters.
- If the word consists of the same repeated character (e.g., 'aaaa'), the time will be minimized as no movement is required after the first character.
- The alphabet is circular, so ensure that the minimal distance between characters is always correctly calculated.
{{< dots >}}
## Code 💻
```cpp
int minTimeToType(string word) {
    int res = word.size(), point = 'a';
    for (auto ch : word) {
        res += min(abs(ch - point), 26 - abs(point - ch));
        point = ch;
    }
    return res;
}
```

This code computes the minimum time required to type a word, assuming each key press takes a fixed amount of time and the typing is done on a circular keyboard.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minTimeToType(string word) {
	```
	This function calculates the minimum time to type a given word on a circular keyboard. It takes the word as input and returns the total time required.

2. **Variable Initialization**
	```cpp
	    int res = word.size(), point = 'a';
	```
	The variable 'res' is initialized to the length of the word, representing the base time to type the word. The variable 'point' keeps track of the current position on the keyboard (starting from 'a').

3. **Loop**
	```cpp
	    for (auto ch : word) {
	```
	This loop iterates over each character in the word to calculate the time required to move from the current character to the next.

4. **Min Time Calculation**
	```cpp
	        res += min(abs(ch - point), 26 - abs(point - ch));
	```
	This line computes the minimum time to move from the current 'point' to the character 'ch'. It calculates both the direct and circular distances between the characters and adds the minimum of these two to 'res'.

5. **Update Point**
	```cpp
	        point = ch;
	```
	After typing the current character, 'point' is updated to the current character 'ch' as the new starting point for the next character.

6. **Return Result**
	```cpp
	    return res;
	```
	The function returns the total time accumulated in 'res', which represents the minimum time required to type the word.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where `n` is the length of the word.
- **Average Case:** O(n)
- **Worst Case:** O(n)

For each character in the word, we calculate the minimal movement to the target character, making the time complexity O(n), where `n` is the length of the word.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only use a few variables to track the current pointer and total time.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/description/)

---
{{< youtube DEMUS-1tq-0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
