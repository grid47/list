
+++
authors = ["grid47"]
title = "Leetcode 1414: Find the Minimum Number of Fibonacci Numbers Whose Sum Is K"
date = "2024-06-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1414: Find the Minimum Number of Fibonacci Numbers Whose Sum Is K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
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
    int findMinFibonacciNumbers(int k) {
        vector<int> arr = {1, 1};
        while(arr[arr.size() - 1] + arr[arr.size() - 2] <= k) {
            arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
        }

        set<int> cnt;
        int i = arr.size() -1;
        while(k > 0) {
            while(i >= 0 && arr[i] > k) i--;
            if(i == -1) break;
            k -= arr[i];
            cnt.insert(arr[i]);
        }
        return cnt.size();
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the minimum number of Fibonacci numbers whose sum equals a given integer \( k \). Fibonacci numbers are defined as a sequence where each number is the sum of the two preceding ones, typically starting with \( 1, 1, 2, 3, 5, \ldots \). The objective is to determine how many distinct Fibonacci numbers can be combined to sum up to \( k \).

### Approach

To solve this problem, we can use a greedy algorithm. The idea is to generate all Fibonacci numbers that are less than or equal to \( k \) and then iteratively subtract the largest Fibonacci number from \( k \) until \( k \) reaches zero. This way, we minimize the number of Fibonacci numbers needed.

1. **Generate Fibonacci Numbers**: Create a list of Fibonacci numbers that are less than or equal to \( k \).

2. **Greedy Selection**: Starting from the largest Fibonacci number, repeatedly subtract it from \( k \) while \( k \) remains greater than zero. Keep track of the Fibonacci numbers used.

3. **Count Distinct Fibonacci Numbers**: Since we need distinct Fibonacci numbers, we can use a set to automatically handle duplicates.

### Code Breakdown (Step by Step)

Here's a step-by-step breakdown of the provided C++ code:

1. **Class Definition**:
   ```cpp
   class Solution {
   public:
   ```

   - A class named `Solution` is defined to encapsulate the solution method.

2. **Function Declaration**:
   ```cpp
       int findMinFibonacciNumbers(int k) {
   ```

   - The method `findMinFibonacciNumbers` takes an integer \( k \) as input and returns the minimum number of distinct Fibonacci numbers that sum to \( k \).

3. **Fibonacci Number Generation**:
   ```cpp
           vector<int> arr = {1, 1};
           while(arr[arr.size() - 1] + arr[arr.size() - 2] <= k) {
               arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
           }
   ```

   - A vector `arr` is initialized with the first two Fibonacci numbers, \( 1 \) and \( 1 \).
   - A while loop generates Fibonacci numbers until the next number exceeds \( k \). The next Fibonacci number is calculated by adding the last two numbers in the vector.

4. **Set for Distinct Count**:
   ```cpp
           set<int> cnt;
           int i = arr.size() - 1;
   ```

   - A set `cnt` is created to store the distinct Fibonacci numbers used in the sum.
   - An integer `i` is initialized to point to the last element of the Fibonacci array.

5. **Greedy Selection**:
   ```cpp
           while(k > 0) {
               while(i >= 0 && arr[i] > k) i--;
               if(i == -1) break;
               k -= arr[i];
               cnt.insert(arr[i]);
           }
   ```

   - A while loop continues until \( k \) is greater than zero.
   - A nested loop checks if the current Fibonacci number (pointed by `i`) is greater than \( k \). If it is, the index `i` is decremented.
   - If `i` becomes \(-1\), it indicates that there are no Fibonacci numbers left to consider, and the loop breaks.
   - The largest valid Fibonacci number is subtracted from \( k \), and this number is added to the set `cnt`.

6. **Return Result**:
   ```cpp
           return cnt.size();
       }
   };
   ```

   - Finally, the size of the set `cnt`, which represents the number of distinct Fibonacci numbers used to sum to \( k \), is returned.

### Complexity

- **Time Complexity**:
  - The time complexity of this solution is \( O(\log k) \) for generating Fibonacci numbers, as the Fibonacci sequence grows exponentially. The subsequent processing of \( k \) requires iterating through the Fibonacci numbers, leading to an overall complexity of \( O(m) \), where \( m \) is the number of Fibonacci numbers up to \( k \). In practice, \( m \) is a constant since Fibonacci numbers grow rapidly.

- **Space Complexity**:
  - The space complexity is \( O(m) \) for storing the Fibonacci numbers in a vector and the set to keep track of distinct numbers. However, since the number of Fibonacci numbers is limited, this can be considered a small overhead.

### Conclusion

The `findMinFibonacciNumbers` function efficiently calculates the minimum number of distinct Fibonacci numbers required to sum to a given integer \( k \) using a greedy approach. This method leverages the properties of Fibonacci numbers to ensure the solution is optimal while maintaining simplicity.

#### Key Takeaways:

- **Greedy Algorithms**: This problem illustrates how greedy algorithms can be effective in finding optimal solutions by making local optimal choices—in this case, choosing the largest possible Fibonacci number at each step.

- **Fibonacci Sequence Properties**: Understanding the growth and properties of the Fibonacci sequence is crucial in problems involving sums and combinations of these numbers.

- **Use of Data Structures**: The use of a set for tracking distinct elements ensures that we can easily count the number of unique Fibonacci numbers used without additional checks for duplicates.

Overall, this solution is an excellent example of leveraging mathematical properties and greedy strategies to tackle a computational problem efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
