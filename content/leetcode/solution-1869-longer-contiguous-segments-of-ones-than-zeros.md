
+++
authors = ["grid47"]
title = "Leetcode 1869: Longer Contiguous Segments of Ones than Zeros"
date = "2024-05-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1869: Longer Contiguous Segments of Ones than Zeros in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "K0WT66cPNmo"
youtube_upload_date="2021-05-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/K0WT66cPNmo/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkZeroOnes(string s) {
        int z = 0, o = 0, gz = 0, oz = 0, res = 1;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') z++;
            else z = 0;
            if(s[i] == '1') o++;
            else o = 0;
            gz = max(gz, z);
            oz = max(oz, o);
        }
        return oz > gz;
    }
};
{{< /highlight >}}
---

### Problem Statement

The objective of this problem is to analyze a binary string composed of '0's and '1's and determine whether the maximum consecutive occurrences of '1's are greater than the maximum consecutive occurrences of '0's. Essentially, we need to identify the longest sequence of '1's and '0's in the string and compare their lengths. If the length of the longest sequence of '1's exceeds that of '0's, the function should return `true`; otherwise, it should return `false`.

### Approach

To efficiently solve this problem, we will employ a single-pass algorithm that traverses the binary string only once. During this traversal, we will maintain counters for the current streak of '1's and '0's. We will also keep track of the maximum streaks found for both characters. Here are the main steps involved in our approach:

1. **Initialization**: Start by initializing counters for the current counts of '0's and '1's as well as the maximum counts found during the traversal.

2. **Single Pass through the String**: Iterate through each character in the string:
   - If the character is '0', increment the zero counter and reset the one counter.
   - If the character is '1', increment the one counter and reset the zero counter.
   - After updating the counters, compare the current counts with the maximum counts found so far and update them accordingly.

3. **Final Comparison**: After traversing the entire string, compare the maximum counts of '1's and '0's. Return `true` if the maximum count of '1's is greater than that of '0's; otherwise, return `false`.

### Code Breakdown (Step by Step)

1. **Class Definition**: The implementation begins by defining the class `Solution`, which contains the method to solve the problem.

    ```cpp
    class Solution {
    public:
    ```

2. **Method Declaration**: We declare the public method `checkZeroOnes`, which takes a string as input and returns a boolean value.

    ```cpp
    bool checkZeroOnes(string s) {
    ```

3. **Variable Initialization**: We initialize several integer variables:
   - `z` to keep track of the current count of '0's.
   - `o` to keep track of the current count of '1's.
   - `gz` to store the maximum count of '0's found during the traversal.
   - `oz` to store the maximum count of '1's found during the traversal.
   - `res` is initialized to 1 but is unused in the final implementation.

    ```cpp
    int z = 0, o = 0, gz = 0, oz = 0, res = 1;
    ```

4. **Iterating through the String**: A `for` loop iterates through each character of the string `s`.

    ```cpp
    for(int i = 0; i < s.size(); i++) {
    ```

5. **Counting '0's and '1's**: Inside the loop, we check the character at the current position:
   - If it is '0', we increment the zero counter (`z`) and reset the one counter (`o`).
   - If it is '1', we increment the one counter (`o`) and reset the zero counter (`z`).

    ```cpp
    if(s[i] == '0') z++;
    else z = 0;
    if(s[i] == '1') o++;
    else o = 0;
    ```

6. **Updating Maximum Counts**: After updating the counts, we compare the current counts with the maximum counts found so far and update them if the current counts exceed the maximums.

    ```cpp
    gz = max(gz, z);
    oz = max(oz, o);
    ```

7. **Returning the Result**: After exiting the loop, we compare the maximum counts of '1's and '0's. If the maximum count of '1's (`oz`) is greater than that of '0's (`gz`), we return `true`; otherwise, we return `false`.

    ```cpp
    return oz > gz;
    }
    ```

### Complexity

The time complexity of this solution is \(O(n)\), where \(n\) is the length of the input string. This is because we perform a single traversal of the string, making constant-time operations at each step. The space complexity is \(O(1)\) since we are using a fixed amount of extra space for the counters and do not depend on the size of the input.

### Conclusion

In conclusion, the provided implementation of the `checkZeroOnes` method effectively determines if the longest sequence of '1's in a binary string exceeds the longest sequence of '0's. The algorithm is optimized for performance, operating in linear time with constant space usage, making it suitable for large input strings. By leveraging simple counting mechanisms and a single traversal approach, this solution is both straightforward and efficient. This implementation can serve as a reference for similar problems involving counting or comparing sequences in strings, showcasing the utility of linear traversal techniques in solving combinatorial challenges effectively. Overall, this code exemplifies clarity and efficiency, making it a solid contribution to algorithm design discussions.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/description/)

---
{{< youtube K0WT66cPNmo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
