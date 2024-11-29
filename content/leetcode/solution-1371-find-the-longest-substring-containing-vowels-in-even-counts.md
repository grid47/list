
+++
authors = ["grid47"]
title = "Leetcode 1371: Find the Longest Substring Containing Vowels in Even Counts"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1371: Find the Longest Substring Containing Vowels in Even Counts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "o17MBWparrI"
youtube_upload_date="2024-09-15"
youtube_thumbnail="https://i.ytimg.com/vi/o17MBWparrI/maxresdefault.jpg"
comments = true
+++



---
Given a string s, find the size of the longest substring containing each vowel ('a', 'e', 'i', 'o', 'u') an even number of times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single string s, containing only lowercase English letters.
- **Example:** `s = 'amazingtime'`
- **Constraints:**
	- 1 <= s.length <= 5 * 10^5
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the size of the longest substring where each vowel ('a', 'e', 'i', 'o', 'u') appears an even number of times.
- **Example:** `6`
- **Constraints:**
	- The output will be a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the longest substring where vowels appear an even number of times.

- Iterate through the string while keeping track of the count of each vowel.
- Use a bitmask to represent the count of each vowel appearing in the string so far.
- Track the first occurrence of each bitmask in a map and calculate the longest substring where the bitmask repeats.
{{< dots >}}
### Problem Assumptions ✅
- The string is non-empty and contains only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'amazingtime'`  \
  **Explanation:** The longest substring 'amazi' contains two 'a's and two 'i's, so both appear an even number of times.

- **Input:** `s = 'applepie'`  \
  **Explanation:** The substring 'appl' contains an even number of 'e's, so the result is 5.

{{< dots >}}
## Approach 🚀
We use a bitmask to track the parity of the vowel counts as we traverse the string. Each vowel corresponds to a unique bit, allowing us to efficiently check when all vowels appear an even number of times.

### Initial Thoughts 💭
- The problem can be solved efficiently using a bitmask representation for vowel counts.
- A bitmask will allow us to track which vowels have appeared an odd or even number of times, enabling efficient substring length calculations.
{{< dots >}}
### Edge Cases 🌐
- If the string is empty, return 0.
- Ensure that the algorithm runs efficiently even for strings of maximum length (500,000).
- Strings with no vowels should return the length of the entire string.
- The solution must handle up to 500,000 characters efficiently.
{{< dots >}}
## Code 💻
```cpp
int findTheLongestSubstring(string s) {
    map<char, int> id = {
        {'a' , 1},
        {'e' , 2},
        {'i' , 3},
        {'o' , 4},
        {'u' , 5},
        };
    int res = 0, msk = 0;
    map<int, int> mp;
 
    mp[0] = -1;
    for (int i = 0; i < s.length(); i++) {
        int x = id[s[i]];
        
        if(x != 0)
        msk ^= (1 << x);
        if(mp.count(msk)) {
        res = max(res, i - mp[msk]);
            }
        else {
        mp[msk] = i;}
    }
    
    return res;
}
```

This code finds the longest substring that contains an even number of vowels ('a', 'e', 'i', 'o', 'u') by using bitwise operations and dynamic programming techniques.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int findTheLongestSubstring(string s) {
	```
	The function 'findTheLongestSubstring' takes a string 's' and aims to find the longest substring that contains an even number of each vowel.

2. **Map Initialization**
	```cpp
	    map<char, int> id = {
	```
	A map 'id' is initialized to associate vowels ('a', 'e', 'i', 'o', 'u') with unique integer values to track their occurrence status.

3. **Map Initialization**
	```cpp
	        {'a' , 1},
	```
	Maps the vowel 'a' to the value 1.

4. **Map Initialization**
	```cpp
	        {'e' , 2},
	```
	Maps the vowel 'e' to the value 2.

5. **Map Initialization**
	```cpp
	        {'i' , 3},
	```
	Maps the vowel 'i' to the value 3.

6. **Map Initialization**
	```cpp
	        {'o' , 4},
	```
	Maps the vowel 'o' to the value 4.

7. **Map Initialization**
	```cpp
	        {'u' , 5},
	```
	Maps the vowel 'u' to the value 5.

8. **Map Initialization**
	```cpp
	        };
	```
	The map initialization completes the vowel-to-value mappings.

9. **Variable Initialization**
	```cpp
	    int res = 0, msk = 0;
	```
	Two integer variables 'res' and 'msk' are initialized. 'res' will store the length of the longest valid substring, and 'msk' will track the bitwise state of vowel occurrences.

10. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	A map 'mp' is initialized to store the first occurrence index of each bitmask 'msk'.

11. **Empty Line**
	```cpp
	 
	```
	An empty line used for separation.

12. **Base Case**
	```cpp
	    mp[0] = -1;
	```
	The map 'mp' is initialized with the bitmask value 0 mapping to -1. This serves as the base case, representing an even number of vowels before any characters are processed.

13. **Loop Iteration**
	```cpp
	    for (int i = 0; i < s.length(); i++) {
	```
	A loop is initiated to iterate over each character in the input string 's'.

14. **Character Processing**
	```cpp
	        int x = id[s[i]];
	```
	Each character 's[i]' is checked in the map 'id'. The corresponding value is stored in 'x'. If the character is a vowel, 'x' will be non-zero.

15. **Empty Line**
	```cpp
	        
	```
	An empty line for separation.

16. **Bitwise Operation**
	```cpp
	        if(x != 0)
	```
	If 'x' is non-zero (meaning the character is a vowel), the bitwise XOR operation is performed on 'msk'.

17. **Bitwise Operation**
	```cpp
	        msk ^= (1 << x);
	```
	This operation flips the bit corresponding to the vowel found at 's[i]'.

18. **Check for Previous Bitmask**
	```cpp
	        if(mp.count(msk)) {
	```
	The code checks if the current bitmask 'msk' has been seen before by checking the map 'mp'.

19. **Update Result**
	```cpp
	        res = max(res, i - mp[msk]);
	```
	If the bitmask has been seen before, the length of the valid substring is updated by calculating the difference between the current index 'i' and the stored index of the previous occurrence of 'msk'.

20. **Store First Occurrence**
	```cpp
	        else {
	```
	If the bitmask has not been seen before, the current index 'i' is stored in the map 'mp' with 'msk' as the key.

21. **Store First Occurrence**
	```cpp
	        mp[msk] = i;}
	```
	Store the current index 'i' as the first occurrence of the bitmask 'msk'.

22. **Return Result**
	```cpp
	    return res;
	```
	The function returns the value of 'res', which is the length of the longest substring with an even number of vowels.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm runs in linear time, where n is the length of the input string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(32)

The space complexity is constant, as we only store bitmask values and the first occurrences of these bitmasks.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/)

---
{{< youtube o17MBWparrI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
