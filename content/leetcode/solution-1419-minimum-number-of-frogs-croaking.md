
+++
authors = ["grid47"]
title = "Leetcode 1419: Minimum Number of Frogs Croaking"
date = "2024-06-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1419: Minimum Number of Frogs Croaking in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a string croakOfFrogs, which represents a mix of sounds from multiple frogs croaking the word 'croak'. Each frog croaks the sequence of letters: 'c', 'r', 'o', 'a', 'k'. Your task is to determine the minimum number of frogs needed to croak all the sounds in the string, while following the correct letter sequence. If the string is not a valid combination of croaks, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single string croakOfFrogs that contains characters 'c', 'r', 'o', 'a', and 'k'.
- **Example:** `"croakcroak"`
- **Constraints:**
	- 1 <= croakOfFrogs.length <= 10^5
	- The string contains only the characters 'c', 'r', 'o', 'a', 'k'.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the minimum number of frogs required to croak all the sounds. If the string is not valid, return -1.
- **Example:** `1`
- **Constraints:**
	- If the string is valid, return the number of frogs required.
	- If the string is not a valid combination, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count how many frogs are needed to croak all the sounds while ensuring the proper order of letters in each croak.

- Count the occurrences of each letter 'c', 'r', 'o', 'a', 'k'.
- Ensure that the letters follow the correct sequence. For example, the count of 'r' cannot exceed the count of 'c', and the same for 'o', 'a', and 'k'.
- Track the maximum number of frogs needed at any point during the croaking process.
{{< dots >}}
### Problem Assumptions ✅
- The string may contain scrambled sequences of the letters 'c', 'r', 'o', 'a', 'k'.
- A valid croak must follow the exact sequence of letters 'c', 'r', 'o', 'a', and 'k'.
{{< dots >}}
## Examples 🧩
- **Input:** `"croakcroak"`  \
  **Explanation:** In this example, one frog croaks 'croak' twice, so the minimum number of frogs needed is 1.

- **Input:** `"crcoakroak"`  \
  **Explanation:** Here, the minimum number of frogs is 2: the first frog croaks 'crcoakroak', and the second frog croaks 'crcoakroak'.

- **Input:** `"croakcrook"`  \
  **Explanation:** This is an invalid combination because it doesn't form a valid sequence of croaks, so the output is -1.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to count the occurrences of each letter, ensure they follow the correct sequence, and track the maximum number of frogs needed.

### Initial Thoughts 💭
- The order of the letters is crucial, so we need to track each frog's croak in sequence.
- We can use counters to ensure that the sequence 'c', 'r', 'o', 'a', 'k' is followed properly and track the maximum number of frogs needed at any point.
{{< dots >}}
### Edge Cases 🌐
- An empty string should return -1 because no croaks are made.
- Ensure that the solution works efficiently even with strings up to 100,000 characters long.
- Handle cases where characters are out of order, such as 'crak', which should return -1.
- Ensure that the solution adheres to the constraint that the string can only contain 'c', 'r', 'o', 'a', and 'k'.
{{< dots >}}
## Code 💻
```cpp
int minNumberOfFrogs(string croakOfFrogs) {
    int cnt[5] = {}, frogs = 0, max_frog = 0;
    for(auto ch : croakOfFrogs) {
        auto n = string("croak").find(ch);
        ++cnt[n];
        if(n == 0) max_frog = max(max_frog, ++frogs);
        else if(--cnt[n - 1] < 0)   return -1;
        else if(n == 4)             --frogs;
    }
    return frogs == 0? max_frog : -1;
}
```

The function `minNumberOfFrogs` determines the minimum number of frogs needed to form the given string `croakOfFrogs`. It tracks the counts of each character in the word 'croak' and ensures they are correctly ordered and balanced. If there are inconsistencies, the function returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minNumberOfFrogs(string croakOfFrogs) {
	```
	Defines the function `minNumberOfFrogs` that takes a string `croakOfFrogs` and returns the minimum number of frogs that could have made those croaks.

2. **Variable Initialization**
	```cpp
	    int cnt[5] = {}, frogs = 0, max_frog = 0;
	```
	Initializes an array `cnt` of size 5 to track the counts of each character ('c', 'r', 'o', 'a', 'k'). Initializes variables `frogs` to track the number of active frogs and `max_frog` to track the maximum number of frogs needed.

3. **Loop Constructs**
	```cpp
	    for(auto ch : croakOfFrogs) {
	```
	Begins a loop that iterates through each character in the input string `croakOfFrogs`.

4. **String Manipulations**
	```cpp
	        auto n = string("croak").find(ch);
	```
	Finds the position of the character `ch` in the string 'croak'. The position corresponds to the order of the letters in the word.

5. **Array Manipulation**
	```cpp
	        ++cnt[n];
	```
	Increments the count for the current character (`ch`) in the `cnt` array.

6. **Conditionals**
	```cpp
	        if(n == 0) max_frog = max(max_frog, ++frogs);
	```
	If the character is 'c' (the first character of 'croak'), it increments the number of frogs and updates the `max_frog` variable to track the maximum number of active frogs.

7. **Conditional Check**
	```cpp
	        else if(--cnt[n - 1] < 0)   return -1;
	```
	If the current character isn't the first one in 'croak', it checks if the previous character count (from `cnt`) is valid. If negative, it indicates an invalid order, so the function returns -1.

8. **Conditional Check**
	```cpp
	        else if(n == 4)             --frogs;
	```
	If the current character is 'k' (the last character in 'croak'), it means a frog has finished its croak, so the frog count is decremented.

9. **Return Statement**
	```cpp
	    return frogs == 0? max_frog : -1;
	```
	At the end of the loop, the function checks if there are any active frogs left. If no frogs are left and the characters followed the proper order, it returns `max_frog` (the maximum number of frogs needed). Otherwise, it returns -1 for an invalid input.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input string.
- **Average Case:** O(n), as we need to process each character in the string once.
- **Worst Case:** O(n), where n is the length of the input string.

We only need to traverse the input string once to count the letters and verify the sequence.

### Space Complexity 💾
- **Best Case:** O(1), when the string is valid and processed efficiently.
- **Worst Case:** O(1), since we only need a fixed number of counters (5 for 'c', 'r', 'o', 'a', 'k').

The space complexity is constant, as we only need a fixed amount of space to store the counters for each letter.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-frogs-croaking/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
