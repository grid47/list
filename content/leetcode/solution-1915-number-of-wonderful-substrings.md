
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to count the number of wonderful substrings in a given string `word`. A substring is considered wonderful if at most one character appears an odd number of times. This problem requires an efficient way to analyze substrings due to potentially large input sizes.

### Approach

To solve this problem, we utilize the following approach:

1. **Bitmask Representation**: We can represent the count of characters in the string using a bitmask of size 10, where each bit corresponds to a character ('a' to 'j'). A bit is set if the character at that position has appeared an odd number of times in the current substring.

2. **Tracking Frequency**: We use a map (or an array) to count how many times each bitmask configuration has been seen. This allows us to efficiently calculate how many substrings can be formed from the current character position that satisfy the wonderful substring condition.

3. **Iterate Over the String**: For each character in the string:
   - Update the current bitmask by toggling the corresponding bit for the character.
   - Count substrings that match the current mask.
   - Check for all possible masks that differ from the current mask by just one bit (which would correspond to allowing one character to appear an odd number of times).

4. **Final Count**: The total number of wonderful substrings is accumulated and returned.

### Code Breakdown (Step by Step)

Here's the detailed breakdown of the provided code:

```cpp
class Solution {
public:
    long long wonderfulSubstrings(string word) {
```
This line defines the `wonderfulSubstrings` method, which takes a string `word` as input and returns the count of wonderful substrings as a `long long` integer.

```cpp
        map<int, int> mp;
        mp[0] = 1;
```
We declare a map `mp` to track the frequency of each bitmask. We initialize it with `mp[0] = 1`, representing the empty substring which has an even count for all characters.

```cpp
        int msk = 0;
        long long ans = 0;
```
Here, `msk` is initialized to `0`, representing the current bitmask. `ans` is initialized to `0` to store the total count of wonderful substrings.

```cpp
        for(int i = 0; i < word.size(); i++) {
```
We start a loop to iterate over each character in the input string `word`.

```cpp
            int idx = word[i] - 'a';
            msk ^= (1 << idx);
```
For each character, we calculate its corresponding index (0 for 'a', 1 for 'b', etc.) and update the bitmask by toggling the bit at that index using XOR operation.

```cpp
            ans += mp[msk];
```
We add to the answer the number of times the current bitmask configuration has been seen before. This indicates that all substrings that end at the current index and have the same mask are wonderful.

```cpp
            for(int j = 0; j < 10; j++) {
                int lf = msk ^ (1 << j);
                ans += mp[lf];
            }
```
This inner loop checks all possible masks that differ from the current mask by one bit. For each character position, if we toggle a bit in the current mask, it represents the case where one character appears an odd number of times. We then add the count of these configurations to the answer.

```cpp
            mp[msk]++;
        }
```
Finally, we increment the count of the current bitmask in the map to indicate that we have seen this configuration once more.

```cpp
        return ans;
    }
};
```
After processing all characters in the string, we return the accumulated count of wonderful substrings.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is O(n), where n is the length of the string `word`. Each character is processed exactly once, and checking or updating the map for the bitmask configurations takes O(1) time on average.

- **Space Complexity**: The space complexity is O(1), considering the size of the map will be constant (up to 2^10 masks for characters 'a' to 'j').

### Conclusion

The `wonderfulSubstrings` function efficiently counts the number of wonderful substrings in a given string using a combination of bitmasking and frequency tracking. The approach ensures that even with a potentially large string, the operations remain manageable within linear time complexity. This algorithm is a powerful example of how bit manipulation can simplify counting problems, especially when dealing with conditions related to even and odd occurrences.

### Use Cases

1. **String Analysis**: This algorithm can be utilized in various applications where the analysis of substrings is required, such as text processing and data mining.

2. **Game Development**: In games that involve string manipulation or puzzles based on substring properties, this approach can help evaluate player moves or potential outcomes efficiently.

3. **Competitive Programming**: The method showcases an effective use of bitmasking and can be beneficial in solving other problems related to substring counting, combinatorial problems, and constraints based on character frequencies.

4. **Data Compression**: In scenarios where data compression is applied, identifying properties of substrings may play a crucial role in optimizing storage and retrieval.

5. **Natural Language Processing**: This technique can be integrated into algorithms designed for text analysis, language modeling, or sentiment analysis, where substring properties significantly impact results.

The code is well-structured, concise, and leverages efficient data structures to maintain performance while solving complex substring problems effectively. Understanding this solution provides valuable insight into advanced string manipulation techniques, making it a key addition to any programmer's toolkit.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-wonderful-substrings/description/)

---
{{< youtube P6i1qj8DMZk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
