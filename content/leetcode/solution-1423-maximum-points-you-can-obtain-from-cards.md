
+++
authors = ["grid47"]
title = "Leetcode 1423: Maximum Points You Can Obtain from Cards"
date = "2024-06-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1423: Maximum Points You Can Obtain from Cards in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TsA4vbtfCvo"
youtube_upload_date="2021-06-29"
youtube_thumbnail="https://i.ytimg.com/vi/TsA4vbtfCvo/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        vector<int> frt, bck;
        frt.push_back(0);
        bck.push_back(0);
        for(int i = 0; i < n; i++) {

        frt.push_back(frt.back() + card[i]);
 bck.push_back(bck.back() + card[n - 1 - i]);

        }

        int ans = bck[k];
        for(int i = 1; i <= k; i++) {
            
            ans = max(ans, frt[i] + bck[k - i]);
            }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to find the maximum score obtainable from a given array of cards by drawing cards from both ends. Specifically, given an array `card` and an integer `k`, we can select up to `k` cards from either the front or the back of the array. The goal is to maximize the sum of the selected cards. 

### Approach

To achieve the desired result, we can employ the following approach:

1. **Prefix and Suffix Sums**: We will create two auxiliary arrays:
   - `frt`: This array will store the cumulative sum of cards from the front (left side).
   - `bck`: This array will store the cumulative sum of cards from the back (right side).

2. **Cumulative Sums Calculation**:
   - For the `frt` array, we calculate the cumulative sums as we traverse from the beginning of the `card` array.
   - For the `bck` array, we calculate the cumulative sums while traversing from the end of the `card` array.

3. **Maximizing the Score**: After obtaining the cumulative sums in both arrays:
   - We iterate through the possible selections of cards from both ends. Specifically, we can take `i` cards from the front and `k-i` cards from the back.
   - For each possible split, we calculate the total score and update the maximum score found.

4. **Return Result**: Finally, return the maximum score obtained from the iterations.

### Code Breakdown (Step by Step)

Let’s analyze the implementation step by step:

1. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```

   - This declares a `Solution` class where our method for computing the maximum score will be implemented.

2. **Function Declaration**:
   ```cpp
   int maxScore(vector<int>& card, int k) {
   ```

   - The method `maxScore` takes a vector of integers `card` and an integer `k`, returning the maximum score as an integer.

3. **Initialization**:
   ```cpp
   int n = card.size();
   vector<int> frt, bck;
   frt.push_back(0);
   bck.push_back(0);
   ```

   - We store the size of the `card` array in `n`. We then initialize two vectors, `frt` and `bck`, both starting with a `0` to account for the cumulative sum calculations.

4. **Cumulative Sums Calculation**:
   ```cpp
   for(int i = 0; i < n; i++) {
       frt.push_back(frt.back() + card[i]);
       bck.push_back(bck.back() + card[n - 1 - i]);
   }
   ```

   - We iterate through the `card` array. For each card:
     - We append the cumulative sum of cards from the front to `frt`.
     - We append the cumulative sum of cards from the back to `bck`. Here, `n - 1 - i` accesses the elements from the back of the array.

5. **Initial Maximum Score**:
   ```cpp
   int ans = bck[k];
   ```

   - We set the initial answer to the score obtained by taking the first `k` cards from the back (`bck[k]`).

6. **Maximizing the Score**:
   ```cpp
   for(int i = 1; i <= k; i++) {
       ans = max(ans, frt[i] + bck[k - i]);
   }
   ```

   - We iterate from `1` to `k` to check different combinations of taking cards from the front and back:
     - For each `i`, we take `i` cards from the front (`frt[i]`) and `k-i` cards from the back (`bck[k-i]`).
     - We update `ans` with the maximum value obtained.

7. **Return Statement**:
   ```cpp
   return ans;
   }
   ```

   - Finally, we return the maximum score calculated.

### Complexity

- **Time Complexity**: The overall time complexity of this solution is \(O(n)\), where \(n\) is the length of the `card` array. This is due to the single pass required to compute the cumulative sums and another pass to compute the maximum score.

- **Space Complexity**: The space complexity is \(O(n)\) as we are using additional space for the `frt` and `bck` vectors to store the cumulative sums.

### Conclusion

The `maxScore` function efficiently calculates the maximum score obtainable by selecting up to `k` cards from both ends of the `card` array. By utilizing cumulative sums and iterating over possible selections, we minimize unnecessary calculations while maximizing the score.

#### Key Takeaways:

- **Cumulative Sum Optimization**: This approach highlights how cumulative sums can simplify and optimize calculations involving contiguous subarrays or selections.
- **Flexible Selection**: The method elegantly allows for flexible selections from both ends of an array, showcasing versatility in problem-solving.
- **Efficiency**: The use of simple loops and cumulative storage results in an efficient solution that operates in linear time, making it suitable for larger inputs.

Overall, the provided solution offers a clear and efficient way to tackle the problem of maximizing the score with a clever use of data structures and algorithmic principles, demonstrating both effective problem-solving and computational efficiency.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/)

---
{{< youtube TsA4vbtfCvo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
