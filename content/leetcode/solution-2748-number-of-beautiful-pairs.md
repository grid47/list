
+++
authors = ["grid47"]
title = "Leetcode 2748: Number of Beautiful Pairs"
date = "2024-02-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2748: Number of Beautiful Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mjceDBNh7vg"
youtube_upload_date="2023-07-01"
youtube_thumbnail="https://i.ytimg.com/vi/mjceDBNh7vg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int countBeautifulPairs(vector<int>& nums) {
    int cnt[10] = {}, res = 0;
    for(int i = 0; i < nums.size(); ++i) {
        for (int n = 1; n < 10; ++n)
            if (gcd(n, nums[i] % 10) == 1)
                res += cnt[n];
        while (nums[i] >= 10)
            nums[i] /= 10;
        ++cnt[nums[i]];
    }
    return res;
}
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the number of beautiful pairs in an array of integers. A beautiful pair is defined as a pair of numbers `(x, y)` where:

- The last digit of `x` and the first digit of `y` are coprime (i.e., the greatest common divisor (GCD) of these two digits is 1).

We are given an array of integers `nums`, and our task is to calculate the number of such beautiful pairs in the array.

### Approach

To solve this problem, we need to determine the GCD between the last digit of one number and the first digit of another number. To optimize the solution, we can utilize the following approach:

1. **Last and First Digits**:
   - For each number in the array, extract its last digit (i.e., the last digit in the number modulo 10) and its first digit (which is the leftmost non-zero digit). 
   
2. **GCD Calculation**:
   - We need to check whether the GCD of the last digit of one number and the first digit of another number is 1, which means these digits are coprime.

3. **Efficient Counting**:
   - Instead of comparing each pair directly, we can use a counting approach where we count how many times each first digit appears across the array. This allows us to efficiently compute the number of beautiful pairs by checking the GCD between the last digit of each number and all possible first digits of other numbers.

4. **Optimization**:
   - We can avoid repeatedly calculating the GCD for each possible pair by using an array `cnt` to store how many times each digit (1 through 9) appears as the first digit in the numbers processed so far.
   - For each number in the array, we check if the GCD of its last digit with any of the digits from 1 to 9 is 1. If so, we count how many times that digit has appeared as the first digit of previous numbers, and this gives us the number of valid pairs.

### Code Breakdown

#### 1. **Initial Setup and Array Declaration**

```cpp
int cnt[10] = {}, res = 0;
```

- `cnt[10]`: An array of size 10 is used to count how many times each digit (from 0 to 9) appears as the first digit of a number processed so far. We initialize all elements to 0.
- `res`: This variable will store the result, i.e., the total number of beautiful pairs.

#### 2. **Processing Each Number**

```cpp
for(int i = 0; i < nums.size(); ++i) {
    for (int n = 1; n < 10; ++n)
        if (gcd(n, nums[i] % 10) == 1)
            res += cnt[n];
```

- We loop through each number in the array `nums`.
- For each number, we calculate the last digit (`nums[i] % 10`) and check its GCD with every possible first digit (from 1 to 9). If the GCD is 1, it means the two digits are coprime.
- For each valid coprime pair, we add the count of how many times that first digit has appeared before (stored in `cnt[n]`).

#### 3. **Extract the First Digit of the Current Number**

```cpp
while (nums[i] >= 10)
    nums[i] /= 10;
```

- This loop extracts the first digit of the current number. We keep dividing the number by 10 until only the first digit remains.

#### 4. **Update the Count of the First Digit**

```cpp
++cnt[nums[i]];
```

- After extracting the first digit, we increment the count of that digit in the `cnt` array. This allows us to track how many times each digit has appeared as the first digit of previous numbers.

#### 5. **Return the Result**

```cpp
return res;
```

- Finally, we return the result `res`, which contains the number of beautiful pairs in the array.

### Complexity Analysis

#### Time Complexity

1. **Outer Loop**: The loop runs once for each number in the array, so this part takes \(O(n)\), where \(n\) is the number of elements in the `nums` array.
2. **Inner Loop**: For each number, we check the GCD between its last digit and each of the digits from 1 to 9. The GCD operation takes constant time, so the inner loop runs in \(O(9)\) time.
3. **First Digit Calculation**: The while loop runs for the number of digits in the number. In the worst case, the number has a constant number of digits (since we are dealing with integers), so this operation is \(O(1)\).

Thus, the total time complexity is \(O(n)\), where \(n\) is the number of elements in the `nums` array.

#### Space Complexity

1. **Array `cnt[10]`**: The `cnt` array is of constant size (10), so the space complexity for this is \(O(1)\).
2. **Result `res`**: We only need to store a single integer to hold the result, so this also takes \(O(1)\) space.

Thus, the overall space complexity is \(O(1)\).

### Conclusion

The solution efficiently counts the number of beautiful pairs by leveraging the properties of the GCD and using an array to track the frequency of first digits. The algorithm runs in \(O(n)\) time, making it suitable for large input sizes. By avoiding a brute-force comparison of every pair, the solution provides a significant optimization while still guaranteeing correctness. This approach is both time and space efficient, making it ideal for solving the problem in competitive programming and other scenarios.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-beautiful-pairs/description/)

---
{{< youtube mjceDBNh7vg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
