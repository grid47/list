
+++
authors = ["grid47"]
title = "Leetcode 744: Find Smallest Letter Greater Than Target"
date = "2024-08-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 744: Find Smallest Letter Greater Than Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/744.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/744.webp" 
    alt="A string where the smallest letter greater than the target is found and highlighted with a soft glow."
    caption="Solution to LeetCode 744: Find Smallest Letter Greater Than Target Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a sorted array `letters` containing lowercase English letters and a character `target`. Return the smallest character in `letters` that is lexicographically greater than `target`. If no such character exists, return the first character in `letters`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sorted array of lowercase English characters `letters` and a character `target`. The array `letters` has at least two distinct characters.
- **Example:** `letters = ["b", "e", "h", "m", "t"], target = "a"`
- **Constraints:**
	- 2 <= letters.length <= 10^4
	- letters[i] is a lowercase English letter.
	- letters is sorted in non-decreasing order.
	- letters contains at least two different characters.
	- target is a lowercase English letter.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest character from `letters` that is greater than `target`. If no such character exists, return the first character in `letters`.
- **Example:** `For letters = ["b", "e", "h", "m", "t"], target = "a", the output is "b".`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the smallest character in `letters` that is greater than `target`, or return the first character if no such character exists.

- Iterate over the `letters` array to find the first character that is greater than `target`.
- If such a character is found, return it.
- If no such character is found, return the first character of `letters`.
{{< dots >}}
### Problem Assumptions ✅
- The array `letters` is sorted in non-decreasing order and contains at least two distinct characters.
{{< dots >}}
## Examples 🧩
- **Input:** `For letters = ["b", "e", "h", "m", "t"], target = "a"`  \
  **Explanation:** The smallest character in `letters` that is greater than 'a' is 'b'.

- **Input:** `For letters = ["b", "e", "h", "m", "t"], target = "h"`  \
  **Explanation:** The smallest character in `letters` that is greater than 'h' is 'm'.

- **Input:** `For letters = ["a", "b", "d", "f"], target = "z"`  \
  **Explanation:** There is no character in `letters` greater than 'z', so we return the first character 'a'.

{{< dots >}}
## Approach 🚀
This problem can be solved by iterating through the sorted array `letters` to find the first character greater than `target`.

### Initial Thoughts 💭
- The input array is sorted, which allows us to use a simple iteration to find the smallest character greater than `target`.
- Since the array is sorted, we can stop as soon as we find a character greater than `target`, which optimizes the solution.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that `letters` has at least two distinct characters, so there will be no empty array cases.
- For large inputs with up to 10^4 characters in `letters`, the solution should still be efficient, using linear time to find the result.
- If `target` is the largest character in `letters`, the solution will return the first character from the array.
- The solution should handle the constraints efficiently with a time complexity of O(n), where n is the length of `letters`.
{{< dots >}}
## Code 💻
```cpp
char nextGreatestLetter(vector<char>& letters, char target) {
    char ans = letters[0];
    for(int i = 0; i < letters.size(); i++) {
        if(letters[i] > target) {
            ans = letters[i];
            break;
        }
    }
    return ans;
}
```

This function finds the smallest letter in the vector 'letters' that is strictly greater than the given 'target'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	char nextGreatestLetter(vector<char>& letters, char target) {
	```
	This line declares the function nextGreatestLetter, which takes a vector of characters and a target character as input and returns a character.

2. **Variable Initialization**
	```cpp
	    char ans = letters[0];
	```
	Initialize the variable 'ans' to the first character in the 'letters' vector, which will be updated with the next greater letter.

3. **For Loop Start**
	```cpp
	    for(int i = 0; i < letters.size(); i++) {
	```
	Start of a loop that iterates over each character in the 'letters' vector.

4. **Conditional Check**
	```cpp
	        if(letters[i] > target) {
	```
	Check if the current character in 'letters' is greater than the 'target'.

5. **Variable Update**
	```cpp
	            ans = letters[i];
	```
	If the condition is true, update 'ans' to the current letter in the vector.

6. **Break Statement**
	```cpp
	            break;
	```
	Exit the loop once the first letter greater than the target is found.

7. **Return Statement**
	```cpp
	    return ans;
	```
	Return the result stored in 'ans', which is the first character greater than the 'target'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), if the first character is greater than `target`.
- **Average Case:** O(n), where n is the length of the `letters` array.
- **Worst Case:** O(n), where n is the length of the `letters` array.

The time complexity is O(n) because we iterate over the array once.

### Space Complexity 💾
- **Best Case:** O(1), since we do not use any additional data structures.
- **Worst Case:** O(1), the space complexity is constant as we only store a few variables.

The space complexity is O(1), as we are only using a few variables for the iteration.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
