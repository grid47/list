
+++
authors = ["grid47"]
title = "Leetcode 1702: Maximum Binary String After Change"
date = "2024-05-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1702: Maximum Binary String After Change in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FL972h3KqKA"
youtube_upload_date="2020-12-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FL972h3KqKA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string maximumBinaryString(string binary) {
        int ones = 0, zeros = 0, n = binary.size();
        for (auto &c: binary) {
            if(c == '0')
            zeros++;
            else if (zeros == 0)
            ones++;
            c = '1';
        }
        if(ones < n)
        binary[zeros + ones -1] = '0';
        return binary;
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal is to transform a given binary string into its maximum possible value by performing a specific operation: we can flip any '0' to '1', but if we do this, we must ensure that all leading '1's are maintained in the string. The objective is to find the lexicographically largest binary string possible by strategically changing bits while following these rules.

### Approach

To achieve the maximum binary string, we need to count the number of '1's and '0's in the string. The strategy is straightforward: we will convert every bit to '1', maintaining the condition that we may only change a '0' to a '1' if there is at least one '0' left to keep. The plan can be summarized as follows:

1. Traverse the binary string and count the number of '1's and '0's.
2. Change every character in the string to '1'.
3. If there are any '0's present in the original string, replace the last '1' (which was originally '0') to '0'. This ensures we are keeping at least one '0' while maximizing the leading '1's.

### Code Breakdown (Step by Step)

Let’s break down the provided code to understand how this approach is implemented:

1. **Class Definition**: We define a class named `Solution`, which contains our method.

    ```cpp
    class Solution {
    public:
    ```

2. **Method Declaration**: The method `maximumBinaryString` takes a binary string as input and returns the modified string.

    ```cpp
    string maximumBinaryString(string binary) {
    ```

3. **Variable Initialization**: We initialize three variables: `ones` to count the '1's, `zeros` to count the '0's, and `n` to hold the size of the binary string.

    ```cpp
    int ones = 0, zeros = 0, n = binary.size();
    ```

4. **Iterating Through the Binary String**: We loop through each character of the binary string using a range-based for loop.

    ```cpp
    for (auto &c: binary) {
    ```

5. **Counting '1's and '0's**: Inside the loop, we check if the current character is '0'. If it is, we increment the `zeros` counter. If it is a '1' and there are no '0's counted yet, we increment the `ones` counter. Regardless of the character, we set the current character to '1' as our goal is to maximize the string.

    ```cpp
    if(c == '0')
        zeros++;
    else if (zeros == 0)
        ones++;
    c = '1'; // Set current character to '1'
    ```

6. **Replacing the Last '1' with '0'**: After the loop, we check if the number of counted '1's is less than the length of the string. If true, it implies there were some '0's present in the original string. We then replace the last '1' in our modified string (which corresponds to the last counted '0') with a '0'.

    ```cpp
    if(ones < n)
        binary[zeros + ones - 1] = '0'; // Replace the last '1' with '0'
    ```

7. **Returning the Result**: Finally, we return the modified binary string.

    ```cpp
    return binary;
    }
    ```

### Complexity

The time complexity of this solution is O(n), where n is the length of the input binary string. This is due to the single traversal of the string to count the bits and modify them. The space complexity is O(1) because we only use a few integer variables to keep track of counts and do not require any additional data structures that grow with input size.

### Conclusion

In conclusion, the provided code effectively transforms a given binary string into its maximum lexicographical form while adhering to the constraints of only flipping '0's to '1's. By strategically counting the bits and replacing the appropriate character at the end, we ensure that the result is not only maximized but also meets the required conditions. This approach is efficient and straightforward, making it a suitable solution for problems involving binary strings and manipulations. By leveraging a simple counting mechanism and a direct string modification, the code achieves its goals with optimal performance, making it an excellent example of algorithmic efficiency.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-binary-string-after-change/description/)

---
{{< youtube FL972h3KqKA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
