
+++
authors = ["grid47"]
title = "Leetcode 1668: Maximum Repeating Substring"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1668: Maximum Repeating Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","String Matching"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "glQm_MZJywk"
youtube_upload_date="2020-11-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/glQm_MZJywk/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count=0;
        string temp=word;
        while(sequence.find(temp)!=string::npos)
        {
            count++;
            temp+=word;
        }
        return count;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem we are addressing is to find the maximum number of times a given word can be consecutively repeated in a string sequence. In other words, given two strings, `sequence` and `word`, the goal is to determine how many times the `word` can be concatenated with itself such that it is a substring of `sequence`. For instance, if `sequence` is "ababc" and `word` is "ab", the maximum number of times "ab" can be consecutively repeated within "ababc" is 2, because "abab" is present as a substring.

### Approach

To solve this problem, we can adopt a straightforward approach that involves:
1. **Initial Setup**: We will initialize a counter to keep track of the number of repetitions of the word.
2. **Concatenation and Search**: We will repeatedly concatenate the word to itself and check if the resulting string is still found in the original sequence.
3. **Counting Repetitions**: Each time the concatenated word is found within the sequence, we increment our counter.
4. **Return the Result**: Finally, we will return the count of maximum repetitions.

This method effectively utilizes string manipulation and searching capabilities to determine the answer.

### Code Breakdown (Step by Step)

Here's the code with detailed explanations:

```cpp
class Solution {
public:
```
- We define a class `Solution` that encapsulates our approach and includes a public method `maxRepeating`.

```cpp
    int maxRepeating(string sequence, string word) {
```
- The `maxRepeating` function takes two parameters: `sequence` and `word`, both of which are strings. This function will return an integer representing the maximum number of times `word` can be consecutively repeated in `sequence`.

```cpp
        int count = 0;
```
- We initialize a variable `count` to zero. This variable will track the number of times we find the concatenated `word` in `sequence`.

```cpp
        string temp = word;
```
- We create a new string variable `temp` and initialize it with the value of `word`. This string will be used to build the repeated versions of `word`.

```cpp
        while (sequence.find(temp) != string::npos)
        {
```
- We enter a while loop that continues as long as `temp` (the concatenated string) can be found in `sequence`. The `find` function returns the position of the first occurrence of `temp` in `sequence`, and `string::npos` indicates that the string was not found.

```cpp
            count++;
```
- Inside the loop, each time `temp` is found in `sequence`, we increment the `count` by 1 to reflect this successful repetition.

```cpp
            temp += word;
```
- We then concatenate `word` to `temp`, effectively increasing the number of consecutive repetitions of `word`. For example, if `word` was "ab", then `temp` would change from "ab" to "abab", and then to "ababab" in the subsequent iterations.

```cpp
        }
```
- The while loop continues to iterate, checking if the new `temp` can still be found in `sequence`.

```cpp
        return count;
    }
};
```
- Once `temp` can no longer be found in `sequence`, we exit the loop and return the `count`, which now holds the maximum number of consecutive repetitions of `word` found within `sequence`.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n \cdot m)\), where \(n\) is the length of the `sequence` string and \(m\) is the length of the `word` string. This complexity arises because each call to `find` scans through the `sequence`, and in the worst case, the loop may run \(n/m\) times (if the `word` is found repeatedly at overlapping positions).
  
- **Space Complexity**: The space complexity is \(O(m)\), which is required to store the temporary string `temp` that accumulates the concatenated repetitions of `word`.

### Conclusion

The `maxRepeating` method provides a simple yet effective way to count how many times a word can be consecutively repeated as a substring in a given sequence. 

**Key Insights**:
1. **String Manipulation**: This solution highlights the utility of string manipulation methods in C++, such as `find` and concatenation.
2. **Iterative Approach**: The iterative approach is straightforward and easy to implement, making it accessible for many string-related problems.
3. **Optimal for Small Inputs**: While the approach is not optimal for very large strings due to its linear time complexity relative to the lengths of the strings, it is efficient for reasonably sized inputs.

Overall, the code demonstrates a clear understanding of string processing in C++ and showcases the effectiveness of basic algorithms in solving practical problems related to string patterns.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-repeating-substring/description/)

---
{{< youtube glQm_MZJywk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
