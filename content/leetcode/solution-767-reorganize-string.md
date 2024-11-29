
+++
authors = ["grid47"]
title = "Leetcode 767: Reorganize String"
date = "2024-08-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 767: Reorganize String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Sorting","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/767.webp"
youtube = "2g_b1aYTHeg"
youtube_upload_date="2021-12-27"
youtube_thumbnail="https://i.ytimg.com/vi/2g_b1aYTHeg/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/767.webp" 
    alt="A string where letters are reorganized, glowing softly as each valid move is made."
    caption="Solution to LeetCode 767: Reorganize String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a string s consisting of lowercase English letters. The task is to rearrange the characters of the string such that no two adjacent characters are the same. Return any valid rearrangement of the string, or return an empty string if it is not possible to rearrange the characters in such a way.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single string s, which contains only lowercase English letters.
- **Example:** `Input: s = "abc"`
- **Constraints:**
	- 1 <= s.length <= 500
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return any valid rearrangement of the string s such that no two adjacent characters are the same. If such rearrangement is not possible, return an empty string.
- **Example:** `Output: "abc"`
- **Constraints:**
	- The output string should satisfy the condition where no two adjacent characters are the same.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to rearrange the string in such a way that no two adjacent characters are the same.

- Count the frequency of each character in the string.
- Identify if any character appears too many times (more than half of the string's length).
- Place the most frequent character in every alternate position first, then fill in the remaining positions with the other characters.
{{< dots >}}
### Problem Assumptions ✅
- The string is non-empty and consists of lowercase English letters only.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: s = "abc"`  \
  **Explanation:** In this case, the characters 'a', 'b', and 'c' can be rearranged in any order without any adjacent characters being the same.

{{< dots >}}
## Approach 🚀
We can solve this problem by first counting the frequency of each character and ensuring that no character appears more than half of the string's length. Then, we can place characters in alternate positions to avoid adjacent duplicates.

### Initial Thoughts 💭
- If any character appears more than half of the string length, it is impossible to rearrange the string without adjacent duplicates.
- The frequency distribution of characters is key to determining if a rearrangement is possible.
{{< dots >}}
### Edge Cases 🌐
- Handle strings where all characters are the same, e.g., "aaa".
- Ensure the solution works efficiently for strings up to 500 characters long.
- If the string contains only one character, return the string itself.
- Ensure the rearrangement preserves the original characters and doesn't introduce any adjacent duplicates.
{{< dots >}}
## Code 💻
```cpp
string reorganizeString(string s) {
    int mfq = 0, i = 0;
    
    vector<int> frq(26, 0);
    for(char c: s)
        if (++frq[c - 'a'] > frq[mfq])
            mfq = c - 'a';
    
    // if mfq over bounds return ""
    if(2 * frq[mfq] - 1 > s.size()) return "";
    /*  dist mfq across
        dist rest across */
    while(frq[mfq]) {
        s[i] = 'a' + mfq;
        i += 2;
        frq[mfq]--;
    }

    for(int j = 0; j < 26; j++) {
        while(frq[j]) {
            if(i >= s.size()) i = 1;
            s[i] = 'a' + j;
            frq[j]--;
            i += 2;
        }
    }
    
    return s;
    
}
```

The function reorganizes the input string such that no two adjacent characters are the same. It achieves this by placing the most frequent character first and then filling in the rest of the characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	string reorganizeString(string s) {
	```
	Defines the function to reorganize a string where no two adjacent characters are the same.

2. **Initialization**
	```cpp
	    int mfq = 0, i = 0;
	```
	Initializes the variables 'mfq' for the most frequent character index and 'i' for the position to place the characters.

3. **Frequency Calculation**
	```cpp
	    vector<int> frq(26, 0);
	```
	Creates a frequency array to track the count of each character in the string.

4. **Frequency Calculation**
	```cpp
	    for(char c: s)
	```
	Iterates through each character in the string.

5. **Frequency Calculation**
	```cpp
	        if (++frq[c - 'a'] > frq[mfq])
	```
	Increments the frequency of the current character and updates 'mfq' if the current character becomes the most frequent.

6. **Frequency Calculation**
	```cpp
	            mfq = c - 'a';
	```
	Sets the 'mfq' index to the current character if it becomes the most frequent.

7. **Bounds Check**
	```cpp
	    if(2 * frq[mfq] - 1 > s.size()) return "";
	```
	Returns an empty string if it is impossible to rearrange the string (i.e., the most frequent character exceeds half the string size).

8. **Main Logic**
	```cpp
	    while(frq[mfq]) {
	```
	Loops to place the most frequent character in every alternate position.

9. **Main Logic**
	```cpp
	        s[i] = 'a' + mfq;
	```
	Places the most frequent character at the current position 'i'.

10. **Main Logic**
	```cpp
	        i += 2;
	```
	Increments the index by 2 to place the next most frequent character at an alternate position.

11. **Main Logic**
	```cpp
	        frq[mfq]--;
	```
	Decreases the frequency count of the most frequent character.

12. **Main Logic**
	```cpp
	    for(int j = 0; j < 26; j++) {
	```
	Loops through the remaining characters (other than the most frequent character).

13. **Main Logic**
	```cpp
	        while(frq[j]) {
	```
	Loops to place each character at available positions.

14. **Main Logic**
	```cpp
	            if(i >= s.size()) i = 1;
	```
	If the end of the string is reached, start placing characters at position 1.

15. **Main Logic**
	```cpp
	            s[i] = 'a' + j;
	```
	Places the current character in the available position 'i'.

16. **Main Logic**
	```cpp
	            frq[j]--;
	```
	Decreases the frequency count of the current character.

17. **Main Logic**
	```cpp
	            i += 2;
	```
	Increments the index by 2 to place the next character at an alternate position.

18. **Return**
	```cpp
	    
	```
	Empty space for the return statement.

19. **Return**
	```cpp
	    return s;
	```
	Returns the reorganized string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string, since we need to count the frequency of characters and rearrange them.
- **Average Case:** O(n), as the operations for rearranging characters are linear in complexity.
- **Worst Case:** O(n), as the worst case is when all characters are distinct or the same and we have to process every character.

Time complexity is linear because we iterate through the string to count frequencies and rearrange characters.

### Space Complexity 💾
- **Best Case:** O(n), if the input is already optimally arranged or does not require rearranging.
- **Worst Case:** O(n), as we store the frequency of each character and the rearranged string.

Space complexity is linear because we store the frequency count and the rearranged string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reorganize-string/description/)

---
{{< youtube 2g_b1aYTHeg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
