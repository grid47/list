
+++
authors = ["grid47"]
title = "Leetcode 2135: Count Words Obtained After Adding a Letter"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2135: Count Words Obtained After Adding a Letter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ag3bur1amBs"
youtube_upload_date="2022-01-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Ag3bur1amBs/maxresdefault.webp"
comments = true
+++



---
Given two arrays of strings, `startWords` and `targetWords`, determine how many strings in `targetWords` can be formed by appending a letter to any string in `startWords` and rearranging the letters.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two arrays of strings `startWords` and `targetWords`, each containing lowercase English letters.
- **Example:** `startWords = ["rat", "tap", "part"], targetWords = ["trap", "pat", "partz"]`
- **Constraints:**
	- 1 <= startWords.length, targetWords.length <= 5 * 10^4
	- 1 <= startWords[i].length, targetWords[j].length <= 26
	- Each string consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of strings in `targetWords` that can be formed by appending a letter to a string in `startWords` and rearranging the letters.
- **Example:** `Output = 2`
- **Constraints:**
	- The result is a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify the number of words in `targetWords` that can be formed from `startWords` using the conversion operation.

- Convert each word in `startWords` and `targetWords` to bitmasks.
- For each word in `targetWords`, check if a matching word in `startWords` exists where only one additional letter is needed.
{{< dots >}}
### Problem Assumptions ✅
- The strings in both arrays consist of lowercase English letters only.
- No string in `startWords` or `targetWords` contains duplicate letters.
{{< dots >}}
## Examples 🧩
- **Input:** `startWords = ["rat", "tap", "part"], targetWords = ["trap", "pat", "partz"]`  \
  **Explanation:** From 'rat' we can form 'trap', from 'tap' we can form 'pat', but 'partz' cannot be formed.

{{< dots >}}
## Approach 🚀
Use bitmasking to represent the sets of characters in the words and check if appending one character to a word from `startWords` can form a word in `targetWords`.

### Initial Thoughts 💭
- The conversion operation involves appending one new character and rearranging the letters, which suggests using a bitmask representation.
- We can use a set to store the bitmasks of the start words and check for each target word if one of these masks can be transformed by adding a single bit.
{{< dots >}}
### Edge Cases 🌐
- Both `startWords` and `targetWords` are non-empty by problem constraints.
- Optimize the solution for large arrays with up to 50,000 strings.
- Consider words in `startWords` that are already identical to words in `targetWords` (no conversion needed).
- Ensure that no more than one letter is appended during the conversion operation.
{{< dots >}}
## Code 💻
```cpp
int wordCount(vector<string>& start, vector<string>& end) {
    set<int> bit;
    for(auto it: start) {
        int mask = 0;
        for(char x: it)
            mask |= 1 << (x - 'a');
        bit.insert(mask);
    }
    
    int cnt = 0;
    
    for(auto it: end) {
        int mask = 0;
        for(char x: it)
            mask |= 1 << (x - 'a');
        
        for(int i = 0; i < 26; i++) {
            if(((mask >> i) & 1) == 0) continue;
            int tmp = (mask ^ (1 << i));
            if(bit.count(tmp)) {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}
```

This function counts the number of words in the 'end' vector that have a similar mask in the 'start' vector by comparing bitwise operations on character masks.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	int wordCount(vector<string>& start, vector<string>& end) {
	```
	Declares the function `wordCount`, which takes two vectors of strings, `start` and `end`, and returns an integer count of words with similar masks.

2. **Variable Declaration**
	```cpp
	    set<int> bit;
	```
	Declares a set `bit` to store unique masks representing characters in the strings from the `start` vector.

3. **Iteration**
	```cpp
	    for(auto it: start) {
	```
	Iterates over each string in the `start` vector.

4. **Mask Calculation**
	```cpp
	        int mask = 0;
	```
	Initializes a variable `mask` to 0, which will be used to store the bitwise representation of characters in the string.

5. **Character Iteration**
	```cpp
	        for(char x: it)
	```
	Iterates over each character `x` in the current string `it`.

6. **Mask Update**
	```cpp
	            mask |= 1 << (x - 'a');
	```
	Updates the mask by setting the bit corresponding to the character `x` in the range 'a' to 'z'.

7. **Mask Insertion**
	```cpp
	        bit.insert(mask);
	```
	Inserts the computed `mask` into the `bit` set.

8. **Count Initialization**
	```cpp
	    int cnt = 0;
	```
	Initializes a counter `cnt` to 0, which will store the number of valid words found in the `end` vector.

9. **End Vector Iteration**
	```cpp
	    for(auto it: end) {
	```
	Iterates over each string in the `end` vector.

10. **Mask Calculation**
	```cpp
	        int mask = 0;
	```
	Initializes a new variable `mask` for the current string from the `end` vector.

11. **Character Iteration**
	```cpp
	        for(char x: it)
	```
	Iterates over each character `x` in the current string `it`.

12. **Mask Update**
	```cpp
	            mask |= 1 << (x - 'a');
	```
	Updates the mask for the current string `it` in the `end` vector.

13. **Blank**
	```cpp
	        
	```
	Empty line for clarity.

14. **Bitwise Comparison**
	```cpp
	        for(int i = 0; i < 26; i++) {
	```
	Iterates through each bit position (0 to 25) to check for possible matches.

15. **Skip if Bit Not Set**
	```cpp
	            if(((mask >> i) & 1) == 0) continue;
	```
	Skips the current iteration if the bit at position `i` is not set in the current mask.

16. **Mask Update**
	```cpp
	            int tmp = (mask ^ (1 << i));
	```
	Calculates a temporary mask by flipping the bit at position `i` in the current `mask`.

17. **Match Check**
	```cpp
	            if(bit.count(tmp)) {
	```
	Checks if the modified `tmp` mask exists in the `bit` set.

18. **Count Increment**
	```cpp
	                cnt++;
	```
	Increments the count `cnt` if a matching mask is found.

19. **Break Loop**
	```cpp
	                break;
	```
	Breaks the inner loop as soon as a match is found.

20. **Return Count**
	```cpp
	    return cnt;
	```
	Returns the count of words in `end` that have matching masks in `start`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n * m)

Where n is the number of words and m is the maximum word length. Time complexity is dominated by checking each target word against the set of bitmasks.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space complexity is proportional to the number of words and the size of the bitmask set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/description/)

---
{{< youtube Ag3bur1amBs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
