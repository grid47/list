
+++
authors = ["grid47"]
title = "Leetcode 1447: Simplified Fractions"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1447: Simplified Fractions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xAPYdvSkcF8"
youtube_upload_date="2020-05-17"
youtube_thumbnail="https://i.ytimg.com/vi/xAPYdvSkcF8/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGUgZSgVMA8=&rs=AOn4CLA8kfJhe38vkPWigQhNMfXCO873lw"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        if(n == 1) return {};
        vector<string> res;
        queue<tuple<int, int, int, int>> q;
        q.emplace(0, 1, 1, 1);
        while(!q.empty()) {
            auto [num1, den1, num2, den2] = q.front();
            q.pop();
            int num = num1 + num2;
            int den = den1 + den2;
            res.push_back(to_string(num) + "/" + to_string(den));
            if(den + den1 <= n) q.emplace(num1, den1, num, den);
            if(den + den2 <= n) q.emplace(num, den, num2, den2);
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal is to generate all simplified fractions between `0` and `1` for a given integer `n`. A fraction is represented as `num/den` where `num` is the numerator and `den` is the denominator. The fractions should be in their simplest form, meaning that the greatest common divisor (GCD) of the numerator and denominator should be `1`. 

### Approach

To solve the problem, we will use a breadth-first search (BFS) strategy to explore all possible fractions. The main steps in our approach include:

1. **Queue for BFS**: We will use a queue to explore all possible fractions in a systematic manner, starting from the smallest fractions and building up to larger ones.
2. **Tuple Representation**: Each fraction will be represented as a tuple of numerators and denominators so we can efficiently compute new fractions.
3. **Constraints on Denominators**: We need to ensure that the denominators do not exceed `n` and are always larger than the numerators to maintain the fraction between `0` and `1`.

### Code Breakdown (Step by Step)

Let’s break down the provided code to understand how it works:

1. **Class Definition**:
   ```cpp
   class Solution {
   ```

   - The code is encapsulated within a class named `Solution`, which is a common practice in competitive programming and coding challenges.

2. **Main Function**:
   ```cpp
   vector<string> simplifiedFractions(int n) {
   ```

   - The method `simplifiedFractions` takes an integer `n` as an argument and returns a vector of strings representing the simplified fractions.

3. **Edge Case for `n = 1`**:
   ```cpp
   if(n == 1) return {};
   ```

   - If `n` is `1`, there are no fractions between `0` and `1` that can be formed, so the function immediately returns an empty vector.

4. **Initialization**:
   ```cpp
   vector<string> res;
   queue<tuple<int, int, int, int>> q;
   q.emplace(0, 1, 1, 1);
   ```

   - We create a vector `res` to hold the resulting fractions.
   - We initialize a queue `q` that will hold tuples representing the fractions in the form `(num1, den1, num2, den2)`. This is initialized with the tuple `(0, 1, 1, 1)`, representing the fractions `0/1` and `1/1`.

5. **BFS Loop**:
   ```cpp
   while(!q.empty()) {
       auto [num1, den1, num2, den2] = q.front();
       q.pop();
   ```

   - We enter a loop that continues until the queue is empty. In each iteration, we pop the front tuple from the queue and unpack it into `num1`, `den1`, `num2`, and `den2`.

6. **Create New Fraction**:
   ```cpp
   int num = num1 + num2;
   int den = den1 + den2;
   res.push_back(to_string(num) + "/" + to_string(den));
   ```

   - We compute a new fraction by adding the numerators and denominators from the two fractions represented by the current tuple.
   - The new fraction `num/den` is then converted to a string and added to the result vector `res`.

7. **Enqueue New Fractions**:
   ```cpp
   if(den + den1 <= n) q.emplace(num1, den1, num, den);
   if(den + den2 <= n) q.emplace(num, den, num2, den2);
   ```

   - We check if we can create new fractions by combining the current fraction with the existing ones. 
   - If the denominator of the new fraction does not exceed `n`, we enqueue the new tuples for further exploration.

8. **Return Result**:
   ```cpp
   return res;
   ```

   - After the BFS completes, we return the vector `res` containing all the simplified fractions.

### Complexity

- **Time Complexity**: The time complexity is primarily determined by the number of fractions we can generate, which is related to the values of `n`. The exact complexity may vary, but it generally grows with the size of `n`.

- **Space Complexity**: The space complexity is \(O(N)\), where \(N\) is the number of fractions generated. This includes space for the result vector and the queue.

### Conclusion

This code provides an efficient and straightforward method to generate all simplified fractions between `0` and `1` for a given integer `n`. The BFS approach allows us to systematically explore the possible fractions while ensuring they remain in their simplest form.

#### Key Takeaways:

1. **Breadth-First Search (BFS)**: BFS is a powerful technique for exploring combinatorial structures in a systematic way, ensuring all possible combinations are explored.

2. **Tuple Utilization**: Using tuples to represent multiple related values (numerators and denominators) simplifies the process of generating new fractions.

3. **Efficiency Considerations**: The checks to limit denominators ensure we only generate valid fractions, helping keep our solution efficient.

In summary, the provided code effectively demonstrates a method to compute all simplified fractions within a specific range, making it a valuable reference for similar problems involving combinatorial generation and simplification.

[`Link to LeetCode Lab`](https://leetcode.com/problems/simplified-fractions/description/)

---
{{< youtube xAPYdvSkcF8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
