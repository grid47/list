
+++
authors = ["grid47"]
title = "Leetcode 2405: Optimal Partition of String"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2405: Optimal Partition of String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1Zx7gEznzfI"
youtube_upload_date="2023-04-04"
youtube_thumbnail="https://i.ytimg.com/vi/1Zx7gEznzfI/maxresdefault.jpg"
comments = true
+++



---
You are given a string `s`. Your task is to partition this string into the fewest number of substrings such that no character appears more than once in each substring. Each character must belong to exactly one substring in the partition.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` made up of only lowercase English letters.
- **Example:** `s = 'abcabc'`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists only of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of substrings in such a partition.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of substrings in the partition while ensuring each substring contains only unique characters.

- 1. Use a bitmask to track characters that have appeared in the current substring.
- 2. Iterate through the string and check if the current character is already in the current substring (tracked by the bitmask).
- 3. If a character repeats, start a new substring and reset the bitmask.
- 4. Count the number of substrings formed during the process.
{{< dots >}}
### Problem Assumptions ✅
- The input string contains only lowercase English letters.
- The input string is non-empty, with a length between 1 and 10^5.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'abacaba'`  \
  **Explanation:** The partition could be ['a', 'ba', 'cab', 'a'], forming 4 substrings. The character 'a' repeats, so we need to partition it into multiple substrings.

- **Input:** `s = 'ssssss'`  \
  **Explanation:** The only valid partition is ['s', 's', 's', 's', 's', 's'], where each 's' is in a separate substring due to its repetition.

- **Input:** `s = 'abcabc'`  \
  **Explanation:** The optimal partition is ['abc', 'abc'], forming 2 substrings, where all characters in each substring are unique.

{{< dots >}}
## Approach 🚀
We use a bitmask to efficiently track characters that have been included in the current substring. By resetting the bitmask whenever we encounter a duplicate character, we can minimize the number of substrings.

### Initial Thoughts 💭
- We need to keep track of characters seen so far in the current substring.
- Using a bitmask allows us to track up to 26 characters efficiently.
- A bitmask allows for quick checks and resets without the need for additional data structures like sets or arrays.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as per the problem constraints, but an empty string would theoretically result in 0 substrings.
- For large inputs up to 10^5 characters, the solution should run efficiently in O(n) time.
- If the string contains only one unique character (e.g., 'aaaa'), the result will be the length of the string, as each character must be in a separate substring.
- The solution must handle inputs up to 10^5 characters efficiently with O(n) time complexity.
{{< dots >}}
## Code 💻
```cpp
bool checkBit(int &flag, int &n) {
    return flag & (1<< n);
}

void setBit(int &flag, int & n) {
    flag |= (1<<n);
}

int partitionString(string s) {
    int flag = 0, ans = 1;
    for(auto c: s) {
        int n = c - 'a';
        if(checkBit(flag, n)) {
            flag = 0;
            ans++;
        }
        setBit(flag, n);
    }
    return ans;
}
```

This code defines a method to partition a string into the least number of substrings where each substring contains unique characters. It uses bitwise operations to track character occurrences.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool checkBit(int &flag, int &n) {
	```
	This function checks if the nth bit in `flag` is set. It returns true if the bit is set, indicating that the character corresponding to `n` has already appeared.

2. **Bitwise Check**
	```cpp
	    return flag & (1<< n);
	```
	Performs a bitwise AND operation to check if the nth bit of `flag` is set. If the bit is set, it means that the character has been encountered before.

3. **Function Declaration**
	```cpp
	void setBit(int &flag, int & n) {
	```
	This function sets the nth bit of `flag` to 1, marking the character corresponding to `n` as encountered.

4. **Bitwise Set**
	```cpp
	    flag |= (1<<n);
	```
	Performs a bitwise OR operation to set the nth bit of `flag`. This indicates that the character corresponding to `n` has been seen.

5. **Function Declaration**
	```cpp
	int partitionString(string s) {
	```
	This function partitions the string `s` into the least number of substrings where each substring contains unique characters.

6. **Variable Initialization**
	```cpp
	    int flag = 0, ans = 1;
	```
	Initialize `flag` to 0 (to track which characters have been encountered) and `ans` to 1 (to start the count of substrings).

7. **Loop Through String**
	```cpp
	    for(auto c: s) {
	```
	Loop through each character in the string `s`.

8. **Character Mapping**
	```cpp
	        int n = c - 'a';
	```
	Convert the character `c` to an integer `n` representing its position in the alphabet, where 'a' corresponds to 0, 'b' to 1, and so on.

9. **Check for Duplicate Character**
	```cpp
	        if(checkBit(flag, n)) {
	```
	Check if the character corresponding to `n` has been encountered previously by calling the `checkBit` function.

10. **Reset and Increment Substring Count**
	```cpp
	            flag = 0;
	```
	Reset the `flag` to 0, starting a new substring as a duplicate character was found.

11. **Increment Substring Count**
	```cpp
	            ans++;
	```
	Increment the substring count `ans` as a new substring is started.

12. **Set Current Character Bit**
	```cpp
	        setBit(flag, n);
	```
	Mark the current character `n` as encountered by calling the `setBit` function.

13. **Return Statement**
	```cpp
	    return ans;
	```
	Return the count of substrings `ans`, which is the minimum number of substrings where each substring contains unique characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string, as we only need to process each character once.
- **Average Case:** O(n), since we process every character in the string in linear time.
- **Worst Case:** O(n), where the worst case is when no characters repeat and each character requires a separate substring.

The solution is linear in time complexity, making it efficient for input strings up to the maximum length.

### Space Complexity 💾
- **Best Case:** O(1), as the space required does not depend on the input size but rather on the number of characters (26 for English letters).
- **Worst Case:** O(1), since we only use a constant amount of space to track characters with the bitmask.

The space complexity is constant, as we only use a bitmask to track characters in the substring.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/optimal-partition-of-string/description/)

---
{{< youtube 1Zx7gEznzfI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
