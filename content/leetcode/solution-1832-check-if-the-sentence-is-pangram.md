
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkIfPangram(string set) {
        bitset<26> bit;
        for(char x: set) bit.set(x - 'a');
        return bit.count() == 26;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine if a given string contains every letter of the English alphabet at least once. Such a string is known as a "pangram." For example, the sentence "The quick brown fox jumps over the lazy dog" is a well-known pangram because it includes all 26 letters from 'a' to 'z'. The goal is to implement a function that checks if the provided string meets this criteria.

### Approach

To solve the problem of checking if a string is a pangram, we can use the following approach:

1. **Character Representation**: Since the English alphabet consists of 26 letters, we can represent the presence of each letter using a bitset, which allows us to efficiently track the presence of each character.

2. **Iterate Through the String**: Loop through each character in the input string and update the bitset to indicate which characters are present.

3. **Count the Set Bits**: After processing the string, check if all 26 bits in the bitset are set. If they are, the string is a pangram; otherwise, it is not.

4. **Return the Result**: Based on the count of set bits, return `true` if the string is a pangram and `false` otherwise.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    bool checkIfPangram(string set) {
```
- We define a class `Solution` that contains the method `checkIfPangram`, which takes a string `set` as input. This string represents the characters we want to analyze.

```cpp
        bitset<26> bit; // Create a bitset of size 26 to track letters
```
- We initialize a `bitset` of size 26. Each bit in this bitset will correspond to one letter of the English alphabet, with bit position 0 representing 'a', bit position 1 representing 'b', and so on, up to bit position 25 representing 'z'.

```cpp
        for(char x: set) bit.set(x - 'a'); // Set the bit for each character
```
- We loop through each character `x` in the input string `set`. For each character, we calculate its corresponding bit position by subtracting the ASCII value of 'a' from the ASCII value of `x`. The `bit.set()` function is called to mark this position in the bitset as "set," indicating that the corresponding letter is present in the string.

```cpp
        return bit.count() == 26; // Check if all 26 letters are present
    }
};
```
- Finally, we use the `bit.count()` function, which returns the number of bits that are set in the bitset. If this count equals 26, it means all letters from 'a' to 'z' are present, and we return `true`. If not, we return `false`.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n)\), where \(n\) is the length of the input string `set`. We traverse the string once, performing constant-time operations for each character.

- **Space Complexity**: The space complexity is \(O(1)\) because the size of the bitset is fixed at 26, regardless of the input size. Thus, the space used by the bitset does not scale with the input.

### Conclusion

The provided solution efficiently checks if a string is a pangram by leveraging a bitset to track the presence of each letter of the English alphabet. This approach is optimal in terms of both time and space complexity, making it suitable for scenarios where performance is a concern.

In summary, the `checkIfPangram` function effectively determines if a string contains every letter from 'a' to 'z', thus verifying if it is a pangram. Its simplicity and efficiency make it an excellent solution for this common problem in string processing and character recognition tasks.

By using this method, we ensure that our solution remains concise and efficient, which is particularly beneficial in competitive programming and real-world applications where performance is critical.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/)

---
{{< youtube rk82ArzlPHM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
