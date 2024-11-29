
+++
authors = ["grid47"]
title = "Leetcode 1422: Maximum Score After Splitting a String"
date = "2024-06-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1422: Maximum Score After Splitting a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mc_eSStDrWw"
youtube_upload_date="2023-12-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mc_eSStDrWw/maxresdefault.webp"
comments = true
+++



---
You are given a binary string `s` consisting of characters '0' and '1'. Your task is to split the string into two non-empty substrings (a left substring and a right substring) and return the maximum score that can be achieved by splitting the string. The score is the sum of the number of '0's in the left substring and the number of '1's in the right substring. Find the maximum score by evaluating all possible splits.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary string `s` with characters '0' and '1'.
- **Example:** `"10101"`
- **Constraints:**
	- 2 <= s.length <= 500
	- The string `s` consists of only the characters '0' and '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the maximum score obtained after splitting the string `s` into two non-empty substrings.
- **Example:** `4`
- **Constraints:**
	- The score is the sum of the number of '0's in the left substring and the number of '1's in the right substring.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum score by evaluating every possible split of the string.

- Step 1: Traverse the string and calculate the number of '1's in the right substring.
- Step 2: For each position in the string (excluding the last), calculate the number of '0's in the left substring and the number of '1's in the right substring.
- Step 3: Track the maximum score during this traversal.
{{< dots >}}
### Problem Assumptions ✅
- The string will have at least two characters.
- The string contains only '0' and '1', and we need to count occurrences of each character.
{{< dots >}}
## Examples 🧩
- **Input:** `"10101"`  \
  **Explanation:** In this example, the maximum score is achieved when the left substring is '1' and the right substring is '0101'. The score is calculated as 0 (zeros in the left) + 3 (ones in the right) = 3.

- **Input:** `"1101"`  \
  **Explanation:** Here, the maximum score is 3 when the left substring is '11' and the right substring is '01'. The score is calculated as 2 (zeros in the left) + 1 (ones in the right) = 3.

{{< dots >}}
## Approach 🚀
We can solve this by traversing the string, keeping track of the number of zeros in the left substring and the number of ones in the right substring, and updating the score at each step.

### Initial Thoughts 💭
- The number of zeros and ones in each substring must be tracked separately.
- We can traverse the string once and calculate the score for each potential split.
- We need to handle the traversal efficiently, updating counts of zeros and ones as we process the string.
{{< dots >}}
### Edge Cases 🌐
- A string of length 1 or less is not valid based on the problem constraints.
- Ensure the solution can handle strings up to length 500 efficiently.
- Handle cases where the string is mostly zeros or mostly ones.
- The string should contain at least two characters and only '0' and '1'.
{{< dots >}}
## Code 💻
```cpp
int maxScore(string s) {
    int rightOnes = 0, leftZeroes = 0;
    for(char c: s)
        if(c=='1') rightOnes++;
    
    int score = 0;
    for(int i=0; i<s.length()-1; i++){
        if(s[i]=='0') leftZeroes++;
        else rightOnes--;
        score = max(score, leftZeroes + rightOnes);
    }
    return score;
}
```

The function `maxScore` calculates the maximum score obtainable by splitting the string `s` into two non-empty parts. The score is the sum of the number of '0's on the left part and the number of '1's on the right part of the split.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxScore(string s) {
	```
	Defines the function `maxScore` that takes a string `s` and returns the maximum score possible by splitting it into two parts.

2. **Variable Initialization**
	```cpp
	    int rightOnes = 0, leftZeroes = 0;
	```
	Initializes two variables: `rightOnes` to count the number of '1's on the right part of the string, and `leftZeroes` to count the number of '0's on the left part.

3. **Loop Constructs**
	```cpp
	    for(char c: s)
	```
	Begins a loop to iterate over each character `c` in the string `s`.

4. **Conditionals**
	```cpp
	        if(c=='1') rightOnes++;
	```
	If the character is '1', increment the `rightOnes` counter to track the number of '1's.

5. **Variable Initialization**
	```cpp
	    int score = 0;
	```
	Initializes the variable `score` to 0, which will keep track of the maximum score found during the iterations.

6. **Loop Constructs**
	```cpp
	    for(int i=0; i<s.length()-1; i++){
	```
	Begins another loop to iterate through the string `s`, excluding the last character to ensure both parts of the split are non-empty.

7. **Conditionals**
	```cpp
	        if(s[i]=='0') leftZeroes++;
	```
	If the character at position `i` is '0', increment the `leftZeroes` counter to track the number of '0's in the left part of the split.

8. **Conditionals**
	```cpp
	        else rightOnes--;
	```
	If the character at position `i` is '1', decrement the `rightOnes` counter, reducing the number of '1's in the right part.

9. **Score Calculation**
	```cpp
	        score = max(score, leftZeroes + rightOnes);
	```
	Calculates the score for the current split as the sum of `leftZeroes` and `rightOnes`, and updates the `score` to the maximum score found so far.

10. **Return Statement**
	```cpp
	    return score;
	```
	Returns the maximum score found from all possible splits.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string.
- **Average Case:** O(n), as we process each character exactly once.
- **Worst Case:** O(n), since we need to process each character to calculate the maximum score.

The time complexity is linear, as we only traverse the string once.

### Space Complexity 💾
- **Best Case:** O(1), since the space usage does not depend on the input size.
- **Worst Case:** O(1), as the solution uses only a few counters to keep track of zeros and ones.

The space complexity is constant since we only store a few counters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/)

---
{{< youtube mc_eSStDrWw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
