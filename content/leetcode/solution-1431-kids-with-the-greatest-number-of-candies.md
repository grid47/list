
+++
authors = ["grid47"]
title = "Leetcode 1431: Kids With the Greatest Number of Candies"
date = "2024-06-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1431: Kids With the Greatest Number of Candies in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "xBpYKQzjjnM"
youtube_upload_date="2023-04-17"
youtube_thumbnail="https://i.ytimg.com/vi/xBpYKQzjjnM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ext) {
        int n = candies.size();
        vector<bool> ans(n, false);
        int mx = *max_element(candies.begin(), candies.end());
        for(int i =0; i < n; i++)
            ans[i] = (candies[i]+ ext>= mx);
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine which kids can have the greatest number of candies after receiving some extra candies. You are given an array representing the number of candies each kid has, and a number representing the extra candies each kid can receive. The task is to find out if each kid can have the maximum number of candies compared to others after they receive the extra candies.

### Approach

The solution involves a straightforward approach:
1. **Identify the Maximum Candies**: First, we need to find the maximum number of candies that any kid has. This will serve as the benchmark for determining whether a kid can reach this maximum after receiving extra candies.
2. **Check Each Kid**: For each kid, we will check if the sum of their current candies and the extra candies they receive is greater than or equal to the maximum number of candies identified in the first step.
3. **Store Results**: Store the results in a boolean array, where each entry corresponds to whether the respective kid can have the maximum number of candies after receiving the extra candies.

### Code Breakdown (Step by Step)

Now let’s analyze the provided code to see how it implements this approach effectively:

1. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```

   - We declare a class named `Solution` which contains the method for solving the problem.

2. **Function Declaration**:
   ```cpp
   vector<bool> kidsWithCandies(vector<int>& candies, int ext) {
   ```

   - The method `kidsWithCandies` takes a reference to a vector of integers `candies`, representing the number of candies each kid currently has, and an integer `ext`, representing the extra candies each kid can receive. It returns a vector of booleans.

3. **Variable Initialization**:
   ```cpp
   int n = candies.size();
   vector<bool> ans(n, false);
   ```

   - We first store the size of the `candies` vector in `n`.
   - We then initialize a boolean vector `ans` of size `n` with all values set to `false`. This vector will hold the result for each kid.

4. **Find the Maximum Candies**:
   ```cpp
   int mx = *max_element(candies.begin(), candies.end());
   ```

   - Using the `max_element` function from the Standard Library, we find the maximum value in the `candies` vector and store it in the variable `mx`. This value represents the highest number of candies held by any kid.

5. **Evaluate Each Kid**:
   ```cpp
   for(int i = 0; i < n; i++)
       ans[i] = (candies[i] + ext >= mx);
   ```

   - We iterate through each kid using a for loop. 
   - For each index `i`, we check if the sum of `candies[i]` (the current candies of the kid) and `ext` (the extra candies) is greater than or equal to `mx` (the maximum number of candies).
   - The result of this condition is stored in `ans[i]`. If it’s true, `ans[i]` will be set to `true`, indicating that this kid can have the greatest number of candies. Otherwise, it remains `false`.

6. **Return Statement**:
   ```cpp
   return ans;
   }
   ```

   - Finally, the method returns the boolean vector `ans`, which contains the results for each kid.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n)\), where \(n\) is the number of kids (or the size of the `candies` vector). This is because we iterate through the list of candies to find the maximum and then again to fill the results.
- **Space Complexity**: The space complexity is also \(O(n)\) due to the auxiliary space used for the result vector `ans`.

### Conclusion

The `kidsWithCandies` function effectively solves the problem of determining which kids can achieve the maximum number of candies after receiving additional candies. The implementation is efficient, making it suitable for a large number of kids and their respective candy counts.

#### Key Takeaways:

- **Utilization of STL Functions**: The solution demonstrates the use of the Standard Template Library (STL) in C++, specifically `max_element`, which simplifies the process of finding the maximum value in a collection.
- **Boolean Logic**: The use of boolean conditions to determine if a kid can reach the maximum number of candies is a straightforward but powerful approach to this type of problem.
- **Efficiency**: The approach is efficient in both time and space, ensuring that it performs well even with larger input sizes.

Overall, the provided solution is not only correct but also well-structured and efficient, showcasing fundamental programming techniques that are widely applicable in competitive programming and software development.

[`Link to LeetCode Lab`](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/)

---
{{< youtube xBpYKQzjjnM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
