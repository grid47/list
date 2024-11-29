
+++
authors = ["grid47"]
title = "Leetcode 1915: Number of Wonderful Substrings"
date = "2024-04-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1915: Number of Wonderful Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "P6i1qj8DMZk"
youtube_upload_date="2021-06-27"
youtube_thumbnail="https://i.ytimg.com/vi/P6i1qj8DMZk/maxresdefault.jpg"
comments = true
+++



---
A string is considered wonderful if at most one letter appears an odd number of times. Given a string word consisting of the first ten lowercase English letters ('a' through 'j'), return the total number of wonderful non-empty substrings in the string word. If the same substring appears multiple times, each occurrence should be counted separately.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string word containing lowercase English letters from 'a' to 'j'.
- **Example:** `word = 'abcab'`
- **Constraints:**
	- 1 <= word.length <= 10^5
	- word consists of lowercase English letters from 'a' to 'j'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of wonderful non-empty substrings in the word.
- **Example:** `7`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find all wonderful substrings by checking each substring and counting the ones where at most one letter appears an odd number of times.

- Iterate through all possible substrings of the string.
- For each substring, count the frequency of each character.
- Check if the substring is wonderful by ensuring at most one character appears an odd number of times.
{{< dots >}}
### Problem Assumptions ✅
- The string contains only lowercase English letters from 'a' to 'j'.
- The problem will not test empty strings.
{{< dots >}}
## Examples 🧩
- **Input:** `word = 'abcab'`  \
  **Explanation:** In the word 'abcab', we find 7 wonderful substrings: 'a', 'b', 'c', 'a', 'b', 'ab', 'c'.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we need to iterate through all substrings and count how many of them are wonderful. We can use bitwise operations to track the odd/even frequency of letters.

### Initial Thoughts 💭
- The input string is constrained to only 'a' through 'j', which limits the number of possible characters in any given substring.
- Checking each substring individually would take too long for large inputs.
- Using a bitmask to track the odd/even frequency of characters can speed up the solution.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty based on problem constraints.
- The algorithm must efficiently handle strings with lengths up to 10^5.
- If the string contains only one character, it will always have one wonderful substring.
- The string length will always be at least 1.
{{< dots >}}
## Code 💻
```cpp
long long wonderfulSubstrings(string word) {
    map<int, int> mp;
    mp[0] = 1;
    int msk = 0;
    long long ans = 0;
    for(int i = 0; i < word.size(); i++) {
        
        int idx = word[i] - 'a';
        msk ^= (1 << idx);
        ans += mp[msk];
        for(int j = 0; j < 10; j++) {
            int lf = msk ^ (1 << j);
            ans += mp[lf];
            }
        mp[msk]++;
        }
    
    return ans;
}
```

This function calculates the number of wonderful substrings in a given word. A wonderful substring is one where the number of occurrences of each character differs by at most one in any two positions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long wonderfulSubstrings(string word) {
	```
	Defines the function 'wonderfulSubstrings' which takes a string 'word' and returns a long long integer representing the number of wonderful substrings.

2. **Variable Initialization**
	```cpp
	    map<int, int> mp;
	```
	Initializes a map 'mp' which keeps track of the frequency of bitmask states encountered during iteration.

3. **Variable Assignment**
	```cpp
	    mp[0] = 1;
	```
	Sets the initial condition where the bitmask value 0 (representing an empty set of characters) is encountered once.

4. **Variable Initialization**
	```cpp
	    int msk = 0;
	```
	Initializes the bitmask 'msk' to 0, which will be used to track the parity of characters in the substring.

5. **Variable Initialization**
	```cpp
	    long long ans = 0;
	```
	Initializes the variable 'ans' to store the total count of wonderful substrings.

6. **Loop Start**
	```cpp
	    for(int i = 0; i < word.size(); i++) {
	```
	Begins a loop to iterate through each character of the word.

7. **Bitmask Update**
	```cpp
	        int idx = word[i] - 'a';
	```
	Calculates the index corresponding to the character in 'word' by subtracting 'a' from the character's ASCII value.

8. **Bitmask Update**
	```cpp
	        msk ^= (1 << idx);
	```
	Updates the bitmask by flipping the bit corresponding to the current character.

9. **Count Update**
	```cpp
	        ans += mp[msk];
	```
	Adds the count of substrings with the current bitmask to the total count of wonderful substrings.

10. **Inner Loop**
	```cpp
	        for(int j = 0; j < 10; j++) {
	```
	Begins a loop to check all possible bitmasks that differ by one bit from the current bitmask.

11. **Bitmask Update**
	```cpp
	            int lf = msk ^ (1 << j);
	```
	Calculates a new bitmask 'lf' by flipping one bit of the current bitmask 'msk'.

12. **Count Update**
	```cpp
	            ans += mp[lf];
	```
	Adds the count of substrings with the modified bitmask 'lf' to the total count of wonderful substrings.

13. **Map Update**
	```cpp
	        mp[msk]++;
	```
	Increments the count of the current bitmask 'msk' in the map 'mp'.

14. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the total count of wonderful substrings.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We iterate through the string once and keep track of bitmasks using a map for efficient look-up and updates.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use a map to store bitmasks, and the space complexity depends on the length of the string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-wonderful-substrings/description/)

---
{{< youtube P6i1qj8DMZk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
