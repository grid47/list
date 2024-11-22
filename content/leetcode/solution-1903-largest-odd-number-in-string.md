
+++
authors = ["grid47"]
title = "Leetcode 1903: Largest Odd Number in String"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1903: Largest Odd Number in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "IIt_ARZzclY"
youtube_upload_date="2021-06-27"
youtube_thumbnail="https://i.ytimg.com/vi/IIt_ARZzclY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestOddNumber(string num) {
        string res = "";
        for(int i = num.size(); i >= 0; i--) {
            if((num[i] - '0') % 2)
              return num.substr(0, i + 1);
        }
        return string();
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to find the largest odd-numbered suffix from a given string representing a non-negative integer. The input string, `num`, can contain digits from '0' to '9', and our task is to identify the largest substring that represents an odd number. An odd number is defined as any integer that has a last digit of '1', '3', '5', '7', or '9'. If there is no odd number in the string, the function should return an empty string.

### Approach

The approach to solving this problem involves iterating through the digits of the input string in reverse order. The steps can be summarized as follows:

1. **Iterate in Reverse**: Start from the last character of the string and move backward.

2. **Check for Odd Digits**: For each digit, check if it is odd. If an odd digit is found, return the substring from the start of the string to the index of the odd digit (inclusive).

3. **Return an Empty String**: If the loop completes and no odd digit is found, return an empty string.

This approach is efficient as it scans the string only once, ensuring a time complexity of O(n), where n is the length of the string.

### Code Breakdown (Step by Step)

Let’s analyze the code to understand how it implements the above approach:

1. **Class Definition**: The solution is encapsulated in a class named `Solution`.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Signature**: The function `largestOddNumber` is defined, which takes a string `num` as input and returns a string.

   ```cpp
       string largestOddNumber(string num) {
   ```

3. **Result Initialization**: A variable `res` is initialized to hold the result, although in this implementation it is not strictly necessary as the result is directly returned.

   ```cpp
           string res = "";
   ```

4. **Reverse Iteration**: A for loop is initiated to iterate over the string from the last index (`num.size()`) down to 0. The loop continues while `i` is greater than or equal to 0.

   ```cpp
           for(int i = num.size(); i >= 0; i--) {
   ```

5. **Check for Odd Digit**: Inside the loop, we check if the digit at index `i` is odd. This is achieved by converting the character to its integer value using `(num[i] - '0')` and checking if the result modulo 2 is not zero.

   ```cpp
               if((num[i] - '0') % 2)
   ```

6. **Return the Suffix**: If an odd digit is found, we return the substring from the start of the string up to and including the current index `i` using `num.substr(0, i + 1)`.

   ```cpp
                   return num.substr(0, i + 1);
   ```

7. **Return an Empty String**: If the loop completes without finding an odd digit, an empty string is returned.

   ```cpp
           return string();
       }
   };
   ```

### Complexity

- **Time Complexity**: The time complexity of this algorithm is O(n), where n is the length of the input string `num`. This is because we are potentially scanning through the entire string once.

- **Space Complexity**: The space complexity is O(1) since we are using a constant amount of additional space for variables and not creating any data structures that grow with the size of the input.

### Conclusion

The `largestOddNumber` function efficiently finds the largest suffix of a string that represents an odd number. The solution leverages a straightforward approach that iterates over the string in reverse, checking for odd digits and returning the corresponding substring as soon as it is found.

This algorithm is particularly useful in scenarios where we need to quickly identify valid numeric suffixes from a string representation of an integer. The direct and efficient nature of the code makes it suitable for applications in competitive programming and interviews, where performance is crucial.

### Use Cases

The `largestOddNumber` function can be applied in various domains, including:

- **Data Validation**: In systems that require validation of numeric strings, this function can help ensure that a valid odd number suffix is present.

- **User Input Processing**: When processing user input for financial applications or user interfaces, it can be important to extract valid odd-numbered values from larger numeric strings.

- **Game Development**: In game logic where numeric values are represented as strings (e.g., scores, identifiers), this function can be used to derive specific values based on game rules that require odd numbers.

By implementing this function, developers can ensure their applications effectively handle and manipulate numeric strings while maintaining optimal performance and clarity in their code.

[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-odd-number-in-string/description/)

---
{{< youtube IIt_ARZzclY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
