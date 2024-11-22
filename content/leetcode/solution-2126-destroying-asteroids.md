
+++
authors = ["grid47"]
title = "Leetcode 2126: Destroying Asteroids"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2126: Destroying Asteroids in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "e9FIRRXjKJI"
youtube_upload_date="2022-01-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/e9FIRRXjKJI/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(), ast.end());
        int n = ast.size();
        long long mss = mass;
        for(int i = 0;i < n; i++) {
            if(mss >= ast[i])
                mss += ast[i];
            else return false;
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to determine whether a spacecraft can destroy all incoming asteroids based on its initial mass. Each asteroid has a specific mass, and if the spacecraft's mass is greater than or equal to the mass of an asteroid, it can destroy that asteroid and increase its own mass by the mass of the destroyed asteroid. The spacecraft starts with a certain initial mass, and the goal is to decide if it can successfully destroy all asteroids without failing.

### Approach

To solve this problem, we will use the following approach:

1. **Sort the Asteroids**: Begin by sorting the asteroids in ascending order of their mass. This allows us to handle the smaller asteroids first, maximizing the chance of the spacecraft surviving against larger ones later on.
2. **Iterate Through Asteroids**: For each asteroid, check if the spacecraft's current mass is sufficient to destroy the asteroid. If it is, we will add the asteroid's mass to the spacecraft's mass; if not, the spacecraft cannot destroy the asteroid, and we will return false.
3. **Return Success**: If we manage to iterate through all asteroids without failing to destroy any, we return true.

This greedy approach ensures that we always deal with the smallest threat first, allowing the spacecraft to grow its mass as quickly as possible.

### Code Breakdown (Step by Step)

Here’s a detailed explanation of the implementation:

1. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```
   - The `Solution` class is defined, which contains the method to determine whether the spacecraft can destroy all asteroids.

2. **Function Definition**:
   ```cpp
   bool asteroidsDestroyed(int mass, vector<int>& ast) {
   ```
   - The public member function `asteroidsDestroyed` is declared, which takes an integer `mass` (the initial mass of the spacecraft) and a vector of integers `ast` (the masses of the asteroids) as arguments. It returns a boolean indicating whether all asteroids can be destroyed.

3. **Sorting the Asteroids**:
   ```cpp
   sort(ast.begin(), ast.end());
   ```
   - We sort the `ast` vector in ascending order using the standard `sort` function from the STL (Standard Template Library). This allows us to efficiently process the smallest asteroids first.

4. **Variable Initialization**:
   ```cpp
   int n = ast.size();
   long long mss = mass;
   ```
   - We initialize `n` to the size of the asteroids vector and create a variable `mss` of type `long long` to store the spacecraft's mass. Using `long long` prevents overflow when adding asteroid masses.

5. **Iterating Through the Asteroids**:
   ```cpp
   for(int i = 0; i < n; i++) {
       if(mss >= ast[i])
           mss += ast[i];
       else return false;
   }
   ```
   - We start a loop to iterate over each asteroid.
   - For each asteroid, we check if the spacecraft's current mass `mss` is greater than or equal to the mass of the asteroid `ast[i]`.
     - If `true`, we add the asteroid's mass to the spacecraft's mass (i.e., `mss += ast[i]`).
     - If `false`, we return `false` immediately since the spacecraft cannot destroy this asteroid.

6. **Return Result**:
   ```cpp
   return true;
   }
   ```
   - If the loop completes without returning `false`, it means the spacecraft successfully destroyed all asteroids. We return `true`.

7. **End of Class**:
   ```cpp
   };
   ```
   - This curly brace marks the end of the `Solution` class definition.

### Complexity Analysis

- **Time Complexity**: \(O(n \log n)\)
  - The time complexity is dominated by the sorting step, which is \(O(n \log n)\), where \(n\) is the number of asteroids.

- **Space Complexity**: \(O(1)\)
  - The space complexity is \(O(1)\) since we are using a constant amount of extra space for variables, regardless of the input size.

### Conclusion

The `asteroidsDestroyed` function effectively determines whether a spacecraft can destroy all incoming asteroids based on its initial mass. By employing a greedy approach that processes smaller asteroids first, the function maximizes the spacecraft's chances of survival against larger asteroids.

This solution is optimal for the problem and efficiently handles various input scenarios, ensuring that the spacecraft either accumulates enough mass to destroy all asteroids or fails gracefully by returning false at the first instance of inability to destroy an asteroid.

The straightforward logic of sorting and iterating over the asteroids allows for a clear understanding of the underlying mechanics of the problem, making the implementation both effective and easy to comprehend. Overall, this solution exemplifies the utility of greedy algorithms in optimizing outcomes based on given constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/destroying-asteroids/description/)

---
{{< youtube e9FIRRXjKJI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
