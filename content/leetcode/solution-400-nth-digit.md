
+++
authors = ["grid47"]
title = "Leetcode 400: Nth Digit"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 400: Nth Digit in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/400.webp"
youtube = "4QAGxDIVpdM"
youtube_upload_date="2020-07-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4QAGxDIVpdM/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/400.webp" 
    alt="A glowing sequence of digits where the nth digit is softly illuminated and revealed."
    caption="Solution to LeetCode 400: Nth Digit Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
typedef long long int lli;
class Solution {
public:
    int findNthDigit(int n) {
        lli len = 1;
        lli cnt = 9;
        lli start = 1;
        while(n > len * cnt) {

            n -= len * cnt;
            
            len++;
            cnt *= 10;
            start *= 10;

        }
        start += (n - 1) / len;
        string s = to_string(start);     
        return s[(n - 1) % len] - '0';
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

Given a positive integer `n`, you are tasked with finding the nth digit in the sequence of positive integers. The sequence starts from `1` and goes on indefinitely, like `123456789101112...`. For example, if `n = 11`, the sequence looks like `123456789101112...`, and the 11th digit is `0`. The challenge is to determine the nth digit efficiently without explicitly constructing the entire sequence. 

---

### 🧠 Approach

This problem can be solved without constructing the full sequence by leveraging the following insights:

#### Key Observations:

1. **Increasing Number Lengths**: 
   - The numbers in the sequence consist of different lengths:
     - 1-digit numbers: `1 to 9` (9 numbers)
     - 2-digit numbers: `10 to 99` (90 numbers)
     - 3-digit numbers: `100 to 999` (900 numbers)
     - And so on.
   - Each group of numbers contributes a specific number of digits:
     - `1-digit numbers` contribute `9` digits (`1-9`).
     - `2-digit numbers` contribute `90 * 2 = 180` digits (`10-99`).
     - `3-digit numbers` contribute `900 * 3 = 2700` digits (`100-999`).

2. **Breaking Down the Problem**: 
   - We need to identify which group of numbers contains the nth digit. 
   - Once we identify the group, we can calculate the exact number and the specific digit within that number.

---

### 🔨 Step-by-Step Code Breakdown

Let's walk through the solution step by step:

```cpp
typedef long long int lli;
class Solution {
public:
    int findNthDigit(int n) {
        lli len = 1;  // Start with 1-digit numbers
        lli cnt = 9;  // 9 numbers (1 to 9)
        lli start = 1;  // Start from the number 1
        
        // Step 1: Find the range that contains the nth digit
        while (n > len * cnt) {
            n -= len * cnt;  // Reduce n by the number of digits in the current range
            len++;  // Move to the next length of numbers (2-digit, 3-digit, etc.)
            cnt *= 10;  // Increase the count of numbers in the current range (10, 100, 1000, etc.)
            start *= 10;  // Adjust the start number (10, 100, 1000, etc.)
        }
        
        // Step 2: Find the number that contains the nth digit
        start += (n - 1) / len;  // Determine the exact number by calculating the position
        string s = to_string(start);  // Convert the number to a string to access digits
        return s[(n - 1) % len] - '0';  // Return the nth digit (converted to an integer)
    }
};
```

#### Code Explanation:

1. **Initialization**:
   - We start with `len = 1` (representing 1-digit numbers), `cnt = 9` (the count of 1-digit numbers), and `start = 1` (the first 1-digit number).

2. **Identifying the Range**:
   - The `while` loop subtracts the total number of digits in each range from `n` until we find the correct range that contains the nth digit.
   - For each range, we update `len`, `cnt`, and `start` to reflect the next group of numbers (2-digit, 3-digit, etc.).

3. **Finding the Exact Number**:
   - Once the correct range is found, we calculate the exact number that contains the nth digit by adjusting `start` and adding `(n - 1) / len`.

4. **Extracting the Digit**:
   - We convert the number to a string and return the `(n-1) % len`th digit from it (since string indexing is 0-based).

---

### 📈 Complexity Analysis

#### Time Complexity:
1. **Finding the Range**: The `while` loop runs as long as `n` is greater than the total number of digits in the current range. Each iteration reduces `n` by a factor of 10, making the number of iterations proportional to `log n`. Therefore, the time complexity of this part is `O(log n)`.
   
2. **Finding the nth Digit**: Once we find the range, extracting the digit is a constant time operation. So, this part has a time complexity of `O(1)`.

Overall, the time complexity of the solution is **O(log n)**.

#### Space Complexity:
- The space complexity is dominated by the need to store the number as a string in the worst case. The maximum number of digits needed is proportional to `log n`. Therefore, the space complexity is **O(log n)**.

---

### 🏁 Conclusion

This approach efficiently finds the nth digit in the infinitely growing sequence of positive integers by:
- Identifying which range (1-digit, 2-digit, etc.) the nth digit lies in.
- Reducing the problem size step by step until we narrow down the exact number.
- Extracting the nth digit without generating the entire sequence.

With a time complexity of **O(log n)** and space complexity of **O(log n)**, this solution is highly efficient and scales well for large values of `n`. So, no matter how large `n` gets, this method ensures that we can find the answer quickly!

---

### ✨ Quick Recap

- **Problem**: Find the nth digit in a sequence of positive integers.
- **Solution**: Identify which group of numbers (1-digit, 2-digit, etc.) contains the nth digit and calculate the exact digit.
- **Efficiency**: This solution works in **O(log n)** time and **O(log n)** space, making it optimal for large values of `n`.

Keep practicing and mastering these types of problems – you're on your way to becoming a problem-solving pro! 😊💪

[`Link to LeetCode Lab`](https://leetcode.com/problems/nth-digit/description/)

---
{{< youtube 4QAGxDIVpdM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
