
+++
authors = ["grid47"]
title = "Leetcode 1010: Pairs of Songs With Total Durations Divisible by 60"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1010: Pairs of Songs With Total Durations Divisible by 60 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gM5Wu42UTQk"
youtube_upload_date="2021-02-05"
youtube_thumbnail="https://i.ytimg.com/vi/gM5Wu42UTQk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> c(60, 0);
        int res = 0;
        for(int t: time) {
            res += c[(600 - t)%60];
            c[t%60] += 1;
        }
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to find the number of pairs of time durations from a given list that, when summed together, yield a total that is divisible by 60 seconds. Each time duration is represented in seconds, and we need to count the pairs without concern for their order (i.e., the pair `(t1, t2)` is the same as `(t2, t1)`).

For example, if we have a list of times `[30, 30, 60, 90, 120]`, we want to determine how many pairs of these times can be summed to produce a number divisible by 60.

### Approach
To efficiently solve this problem, we can utilize a frequency array that tracks the remainders of the time durations when divided by 60. The key steps in the approach are:
1. Initialize an array to count occurrences of each possible remainder (0 through 59).
2. For each time duration, calculate the required complement that would make the sum of the pair divisible by 60.
3. Update the frequency array accordingly and count valid pairs based on previous entries in the array.

This method allows us to achieve the result in linear time complexity, which is optimal for this type of problem.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   - The function `numPairsDivisibleBy60` is declared as a public member of the `Solution` class. It accepts a vector of integers (`time`) representing the time durations.

2. **Variable Initialization**:
   - We initialize a vector `c` of size 60 to keep track of how many times each remainder (when divided by 60) has been seen. All entries are initially set to zero.
   - A variable `res` is initialized to zero, which will hold the count of valid pairs that meet the criteria.

3. **Iterating Through Time Durations**:
   - A `for` loop iterates over each duration `t` in the `time` vector.
   - For each duration, we calculate the complement required for it to form a pair that is divisible by 60. This is achieved using the formula `(600 - t) % 60`, which computes what remainder is needed to make the total sum of `t` and another time divisible by 60.

4. **Counting Valid Pairs**:
   - The expression `c[(600 - t) % 60]` retrieves the count of previously seen times that can pair with the current time `t` to produce a sum divisible by 60. We add this count to `res`, incrementing the total pairs found so far.

5. **Updating the Remainder Count**:
   - After checking for valid pairs, we update the count for the current time’s remainder by incrementing `c[t % 60]`. This step ensures that the next time we encounter a matching duration, it will be included in the count of pairs.

6. **Returning the Result**:
   - After processing all durations, the function returns the total count of valid pairs stored in `res`.

### Complexity Analysis
- **Time Complexity**: The time complexity of this function is O(n), where `n` is the number of elements in the `time` vector. This efficiency arises because each duration is processed in a single pass through the array.
- **Space Complexity**: The space complexity is O(1), as the size of the frequency array `c` is fixed at 60, regardless of the input size. Thus, the algorithm uses a constant amount of extra space.

### Conclusion
The `numPairsDivisibleBy60` function presents an efficient solution for counting pairs of time durations that sum to values divisible by 60. By employing a frequency array to track the occurrences of remainders, this approach effectively reduces the complexity of the problem from a naive O(n^2) method to a linear O(n) solution.

This implementation exemplifies how modular arithmetic can simplify the detection of conditions involving divisibility and complements, making it a robust technique for similar problems. Understanding and mastering this approach can significantly enhance problem-solving skills in algorithmic challenges, especially those involving combinatorial counting and modular conditions.

Moreover, the clarity and efficiency of this solution make it a valuable addition to any programmer's toolkit, particularly in contexts such as competitive programming and technical interviews where performance and correctness are critical. The method can be generalized to solve various problems involving summation conditions across diverse data sets.

In summary, the `numPairsDivisibleBy60` function serves as an excellent illustration of using counting techniques and modular arithmetic to tackle combinatorial problems efficiently, showcasing the beauty of algorithmic thinking in practical scenarios.


[`Link to LeetCode Lab`](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/)

---
{{< youtube gM5Wu42UTQk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
