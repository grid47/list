
+++
authors = ["grid47"]
title = "Leetcode 29: Divide Two Integers"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 29: Divide Two Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/29.webp"
youtube = "LzcSE7-m6vY"
youtube_upload_date="2024-04-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/LzcSE7-m6vY/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/29.webp" 
    alt="Two smooth, glowing beams dividing and separating in perfect balance."
    caption="Solution to LeetCode 29: Divide Two Integers Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long dvd = labs(dividend), dvs = labs(divisor);
        int sgn = (dividend > 0) ^ (divisor > 0) ? -1: 1;
        long ans = 0;

        while( dvd >= dvs ) {
            long tmp = dvs, m = 1;
            while(tmp << 1 <= dvd) {
                tmp <<= 1;
                m <<= 1;
            }
            dvd -= tmp;
            ans += m;
        }

        return sgn * ans;
    }
};
{{< /highlight >}}
---

### 🌟 **Dividing Two Integers Without Using the Division Operator**

This problem challenges us to divide two integers without directly using the division (`/`), multiplication (`*`), or modulus (`%`) operators. The goal is to calculate the quotient of the division using bit manipulation and repeated subtraction. Let’s break this down and make it digestible! 🚀

---

#### 🧠 **Approach Overview**

The key idea here is to **use bit shifts** to optimize the division process. Instead of performing repeated subtraction (which is slow), we can use shifts to find how many times the divisor can fit into the dividend efficiently. This method reduces the complexity of the problem significantly.

---

### **Steps to Solve the Problem:**

1. **Handle Edge Case for Overflow**  
   When dividing `INT_MIN` by `-1`, the result would exceed the integer limit (`INT_MAX`), so we handle this case separately.

2. **Convert to Positive Numbers**  
   To simplify, we work with the absolute values of both the dividend and divisor. This way, we focus only on the magnitude, and the final result's sign can be calculated later.

3. **Bitwise Division**  
   The idea is to **shift the divisor** left (which is equivalent to multiplying by powers of 2) until it exceeds the dividend. This helps us quickly figure out how many times the divisor can fit into the dividend.

4. **Sign Handling**  
   Once the division is performed, the result's sign is determined based on whether the dividend and divisor have the same or different signs.

---

### 👇 **Breaking Down the Code:**

#### 1. **Handle Special Overflow Case**
   ```cpp
   if (dividend == INT_MIN && divisor == -1) return INT_MAX;
   ```
   - This checks for overflow when dividing `INT_MIN` by `-1`, which would result in an integer overflow.

#### 2. **Prepare the Dividend and Divisor**
   ```cpp
   long dvd = labs(dividend), dvs = labs(divisor);
   int sgn = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
   ```
   - Convert both `dividend` and `divisor` to their absolute values using `labs()` (absolute value for long integers).
   - Determine the sign (`sgn`) of the result by checking whether the signs of the `dividend` and `divisor` are different using XOR. If they are, the result is negative.

#### 3. **Initialize the Answer**
   ```cpp
   long ans = 0;
   ```
   - `ans` will store the final quotient, initialized to `0`.

#### 4. **Bit Shifting for Division**
   ```cpp
   while (dvd >= dvs) {
       long tmp = dvs, m = 1;
       while (tmp << 1 <= dvd) {
           tmp <<= 1;
           m <<= 1;
       }
       dvd -= tmp;
       ans += m;
   }
   ```
   - **Outer loop**: Continues subtracting multiples of the divisor from the dividend.
   - **Inner loop**: Doubles the divisor (`tmp <<= 1`) and tracks the power of two with `m <<= 1` to see how much of the divisor can be subtracted at once.
   - Once the largest `tmp` that fits into `dvd` is found, subtract it from the dividend and add the corresponding power of two to `ans`.

#### 5. **Return the Final Answer with the Correct Sign**
   ```cpp
   return sgn * ans;
   ```
   - Finally, multiply the result by `sgn` to apply the correct sign, and return the quotient.

---

### ⏳ **Complexity Breakdown**

- **Time Complexity: O(log n)**  
  The algorithm's time complexity is logarithmic because the divisor is doubled at each step using bit shifting. The number of iterations is proportional to the logarithm of the dividend, so we achieve **O(log n)** time complexity.

- **Space Complexity: O(1)**  
  The space complexity is constant since the algorithm only uses a fixed amount of extra space (for variables like `dvd`, `dvs`, `sgn`, and `ans`), making it very space-efficient.

---

### 💡 **Key Insights**

- **Efficient Division Using Bit Shifting**: By shifting the divisor left, we can quickly determine how many times the divisor fits into the dividend, drastically reducing the number of operations needed compared to repeated subtraction. 🔧
- **Handling Overflow**: Special handling for the case where dividing `INT_MIN` by `-1` avoids overflow and ensures the correct result. 🌟
- **In-Place Calculation**: No extra data structures are used, and all modifications happen in-place, which is both memory-efficient and fast. 💨

---

### 🚀 **Conclusion**

This solution offers an optimal approach to dividing two integers **without using division**, multiplication, or modulus operators. By utilizing **bit shifting** and efficient subtraction, we achieve **O(log n)** time complexity and **O(1)** space complexity. This makes the algorithm both **time-efficient** and **space-efficient**, perfect for large inputs. 🙌

Understanding how to leverage **bit manipulation** for such tasks is a powerful tool in your programming toolkit! 🛠

[`Link to LeetCode Lab`](https://leetcode.com/problems/divide-two-integers/description/)

---
{{< youtube LzcSE7-m6vY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
