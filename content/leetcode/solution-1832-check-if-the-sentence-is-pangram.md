
+++
authors = ["grid47"]
title = "Leetcode 1832: Check if the Sentence Is Pangram"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1832: Check if the Sentence Is Pangram in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rk82ArzlPHM"
youtube_upload_date="2021-04-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rk82ArzlPHM/maxresdefault.webp"
comments = true
+++



---
Given a string `sentence` consisting of lowercase English letters, determine whether the sentence contains every letter of the English alphabet at least once.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `sentence` containing only lowercase English letters.
- **Example:** `sentence = "abcdefghijklmnopqrstuvwxyz"`
- **Constraints:**
	- 1 <= sentence.length <= 1000
	- sentence consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if the sentence is a pangram, otherwise return `false`.
- **Example:** `true`
- **Constraints:**
	- The output will be a boolean value indicating whether the sentence is a pangram.

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if all the letters of the alphabet are present in the given sentence.

- Initialize a set or bitmask to track the unique letters in the sentence.
- Iterate through each character in the sentence and update the set or bitmask.
- If all 26 letters are present, return `true`; otherwise, return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The string `sentence` contains lowercase English letters and is not empty.
- The sentence length is within the given constraint.
{{< dots >}}
## Examples 🧩
- **Input:** `sentence = "abcdefghijklmnopqrstuvwxyz"`  \
  **Explanation:** The sentence contains every letter from 'a' to 'z', so the output is `true`.

- **Input:** `sentence = "hello"`  \
  **Explanation:** The sentence does not contain every letter of the alphabet, so the output is `false`.

{{< dots >}}
## Approach 🚀
To solve this problem, we will check if the sentence contains every letter of the alphabet using a set or bitmask.

### Initial Thoughts 💭
- The problem can be efficiently solved using a set or bitmask to track the presence of each letter.
- We can utilize a bitmask of 26 bits to represent each letter of the alphabet. Each bit corresponds to a letter, and if the bit is set, it means that letter is present in the sentence.
{{< dots >}}
### Edge Cases 🌐
- The sentence will always have at least one character, based on the constraints.
- For large inputs, the solution should efficiently check for the presence of all alphabet letters.
- If the sentence is too short to contain all 26 letters, the result will be `false`.
- Ensure the solution works efficiently within the provided input size constraints.
{{< dots >}}
## Code 💻
```cpp
bool checkIfPangram(string set) {
    bitset<26> bit;
    for(char x: set) bit.set(x - 'a');
    return bit.count() == 26;
}
```

This function `checkIfPangram` checks if the given string `set` contains all 26 letters of the alphabet. It uses a bitset to track the presence of each letter.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool checkIfPangram(string set) {
	```
	Defines the function `checkIfPangram`, which takes a string `set` as input and returns a boolean indicating whether the string contains all 26 letters of the alphabet.

2. **Bitset Initialization**
	```cpp
	    bitset<26> bit;
	```
	Initializes a bitset of size 26, where each bit represents one of the 26 letters of the alphabet. A set bit indicates the presence of that letter.

3. **Loop Through Characters**
	```cpp
	    for(char x: set) bit.set(x - 'a');
	```
	Loops through each character `x` in the string `set` and sets the corresponding bit in the bitset. The expression `x - 'a'` maps each letter to an index between 0 and 25.

4. **Bitset Count Check**
	```cpp
	    return bit.count() == 26;
	```
	Checks if all 26 bits in the bitset are set. If all bits are set (i.e., all letters are present), the count will be 26, and the function returns `true`; otherwise, it returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the sentence. We only need one pass through the sentence to check for the presence of all letters.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we are only using a fixed-size bitset or set for tracking the letters, regardless of the sentence length.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/)

---
{{< youtube rk82ArzlPHM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
