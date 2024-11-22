
+++
authors = ["grid47"]
title = "Leetcode 1017: Convert to Base -2"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1017: Convert to Base -2 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string baseNeg2(int n) {
        string res = "";

        while(n) {
            res = to_string(n&1) + res;
            n = -(n >> 1);
        }

        return res == ""? "0":res;
    }
};
{{< /highlight >}}
---



### Problem Statement
The task is to convert an integer \( n \) into its base -2 representation. In base -2, the digits are represented as \( 0 \) and \( 1 \), and each digit's position corresponds to a power of -2. For example:
- The decimal number \( 2 \) in base -2 is represented as "110", since \( 2 = 1 \times (-2)^2 + 1 \times (-2)^1 + 0 \times (-2)^0 \).
- The number \( 3 \) would be "111", since \( 3 = 1 \times (-2)^2 + 1 \times (-2)^1 + 1 \times (-2)^0 \).

The challenge is to create a function that takes an integer \( n \) and returns its base -2 representation as a string.

### Approach
To convert an integer \( n \) into base -2:
1. **Repeated Division**: Similar to converting to any other base, we repeatedly divide \( n \) by -2.
2. **Tracking Remainders**: Instead of just tracking the quotient, we also need to track the remainder, which will be either \( 0 \) or \( 1 \) (the digits in base -2).
3. **Adjustments**: When dividing by -2, if the remainder is negative, adjustments must be made to ensure it falls within the \( 0-1 \) range. This is achieved by modifying the quotient accordingly.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   - The function `baseNeg2` is defined as a public member of the `Solution` class, taking an integer \( n \) as an input parameter.

2. **String Initialization**:
   - A string variable `res` is initialized to hold the resulting base -2 representation.

3. **While Loop**:
   - The loop continues as long as \( n \) is non-zero.
   - Inside the loop, the least significant bit (LSB) is obtained using the expression `n & 1`. This effectively gives the remainder when \( n \) is divided by -2.
   - The result is then prepended to the string `res` using `to_string(n & 1) + res`.

4. **Updating \( n \)**:
   - The next step involves updating \( n \). The new value of \( n \) is calculated using `-(n >> 1)`. The right shift operator `>>` divides \( n \) by 2, and negating it provides the required adjustment for the base -2 conversion.

5. **Final Result Handling**:
   - After the loop, if `res` is still an empty string (which means \( n \) was 0 initially), the function returns "0".
   - Otherwise, it returns the constructed string `res`, which represents \( n \) in base -2.

### Complexity Analysis
- **Time Complexity**: The time complexity of this function is \( O(\log |n|) \). The number of iterations of the loop corresponds to the number of digits in the base -2 representation of \( n \), which is logarithmic in relation to \( n \).
- **Space Complexity**: The space complexity is \( O(1) \) for auxiliary space, as we are using a fixed number of variables for computation and the output string, which grows with the number of digits in the result.

### Conclusion
The `baseNeg2` function efficiently converts an integer \( n \) to its representation in base -2. By employing a straightforward iterative approach that utilizes bitwise operations for efficiency, the solution is both clear and optimal.

Understanding this approach provides insight into how number systems can be represented differently, particularly with non-standard bases such as negative bases. This highlights the flexibility and versatility of numeral systems beyond the common binary, decimal, and hexadecimal systems.

This implementation showcases the importance of adjusting typical algorithms for base conversion to handle special cases like negative bases. It serves as a practical example of combining mathematical logic with programming techniques to solve problems that require a deeper understanding of number theory.

In summary, the `baseNeg2` function exemplifies how to handle non-standard numeral systems in programming. It combines efficiency and clarity, making it an excellent reference for anyone looking to deepen their understanding of numerical base conversions.

Additionally, this function can be applied in scenarios requiring representation in unusual numeral systems, which can be beneficial in theoretical computer science and algorithm design. The skills demonstrated in this solution can also translate to a broader range of problems involving different numeral systems, making it a valuable addition to any programmer's skill set.


[`Link to LeetCode Lab`](https://leetcode.com/problems/convert-to-base-2/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
