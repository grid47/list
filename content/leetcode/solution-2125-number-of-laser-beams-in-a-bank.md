
+++
authors = ["grid47"]
title = "Leetcode 2125: Number of Laser Beams in a Bank"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2125: Number of Laser Beams in a Bank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","String","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "KLeKv59LAFY"
youtube_upload_date="2024-01-03"
youtube_thumbnail="https://i.ytimg.com/vi/KLeKv59LAFY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
    public:
    int numberOfBeams(vector<string> bank) {

        int res = 0, m = bank.size(), n = bank[0].size();

        int cnt = 0, prv = 0;
        for (auto b : bank) 
        {
            cnt = 0;
            for(int i = 0; i < n; i++)
                if (b[i] == '1') cnt++;
            if(cnt > 0) {
                res += prv * cnt;
                prv = cnt;
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to calculate the number of laser beams that can be formed in a bank of security devices represented as a grid of strings. Each character in the grid can either be '0' (indicating no device) or '1' (indicating a security device). Laser beams can be formed between devices located in different rows, but they can only connect devices in the same column. The goal is to count the total number of laser beams that can be formed in this manner.

### Approach

To solve the problem, we will follow these steps:

1. **Count Devices**: Iterate through each row of the grid to count the number of devices present.
2. **Calculate Beams**: As we count devices in a row, we will calculate the number of beams that can be formed between the current row and the previous row that contained devices.
3. **Accumulate Results**: We will accumulate the total number of beams formed throughout the iterations.

This approach leverages the fact that the number of beams formed between two rows with device counts `a` and `b` is equal to `a * b`. Thus, by keeping track of the previous row's device count and the current row's device count, we can efficiently compute the total beams.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the implementation:

1. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```
   - The `Solution` class is defined, which contains the method to calculate the number of laser beams.

2. **Function Definition**:
   ```cpp
   int numberOfBeams(vector<string> bank) {
   ```
   - The public member function `numberOfBeams` is declared, which takes a vector of strings (`bank`) as an argument and returns an integer.

3. **Initialization**:
   ```cpp
   int res = 0, m = bank.size(), n = bank[0].size();
   ```
   - We initialize the result variable `res` to store the total number of beams.
   - `m` holds the number of rows in the bank, and `n` holds the number of columns.

4. **Counting Devices**:
   ```cpp
   int cnt = 0, prv = 0;
   for (auto b : bank) 
   {
       cnt = 0;
       for(int i = 0; i < n; i++)
           if (b[i] == '1') cnt++;
   ```
   - We declare `cnt` to count the number of devices in the current row and `prv` to store the count of devices from the previous row.
   - We iterate through each row in the bank with the loop `for (auto b : bank)`.
   - For each row, we reset `cnt` to zero and iterate through each character in the row.

5. **Calculating Beams**:
   ```cpp
       if(cnt > 0) {
           res += prv * cnt;
           prv = cnt;
       }
   }
   ```
   - After counting the devices in the current row, we check if `cnt` is greater than zero. If it is, it means there are devices in this row.
   - We calculate the number of beams formed between the previous row and the current row using the formula `res += prv * cnt`.
   - We update `prv` to the current `cnt` to use in the next iteration.

6. **Return Result**:
   ```cpp
   return res;
   }
   ```
   - Finally, we return the total count of laser beams stored in `res`.

7. **End of Class**:
   ```cpp
   };
   ```
   - This curly brace marks the end of the `Solution` class definition.

### Complexity Analysis

- **Time Complexity**: \(O(m \times n)\)
  - The time complexity is \(O(m \times n)\) because we iterate through each row (m) and then through each column (n) to count devices.

- **Space Complexity**: \(O(1)\)
  - The space complexity is constant \(O(1)\) since we only use a fixed amount of space for variables like `res`, `cnt`, and `prv`.

### Conclusion

The `numberOfBeams` function efficiently computes the total number of laser beams that can be formed in a grid of security devices by counting the devices in each row and calculating the beams based on the device counts. The approach takes advantage of the relationship between the number of devices in consecutive rows to calculate the total beams in an efficient manner.

This solution is optimal for the given problem and handles varying grid sizes effectively. Its simplicity and clarity make it easy to understand, while its performance ensures it can handle large inputs efficiently. By leveraging the properties of multiplication for calculating the beams, we minimize unnecessary computations and keep the implementation straightforward. This solution is a good example of how to apply simple counting techniques to solve a combinatorial problem in a grid efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/)

---
{{< youtube KLeKv59LAFY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
