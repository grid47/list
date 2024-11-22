
+++
authors = ["grid47"]
title = "Leetcode 1996: The Number of Weak Characters in the Game"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1996: The Number of Weak Characters in the Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Greedy","Sorting","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DFqwkF9a6KI"
youtube_upload_date="2021-09-05"
youtube_thumbnail="https://i.ytimg.com/vi/DFqwkF9a6KI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}

class Solution {

    public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        } else return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& prpt) {
        sort(prpt.begin(), prpt.end(), comp);
        
        int mn = INT_MIN;
        int ans = 0;
        
        for(int i = prpt.size() - 1; i >= 0; i--) {
            if(prpt[i][1] < mn) ans++;
            mn = max(mn, prpt[i][1]);
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves finding the number of "weak characters" in a game setting where each character is represented by their attack and defense values. A character is considered weak if there exists another character with both higher attack and higher defense values. Given a list of characters, each represented by a vector containing their attack and defense values, the task is to determine how many characters are weak according to this definition.

### Approach

The approach to solving this problem involves sorting the characters based on their attack and defense values and then iterating through the sorted list to count the weak characters. The key steps in the approach are:

1. **Sorting the Characters**: The characters are sorted primarily by their attack value in ascending order. If two characters have the same attack value, the one with a higher defense value comes first. This sorting helps in efficiently identifying the weak characters.

2. **Tracking the Maximum Defense**: As we iterate through the sorted characters from right to left, we maintain a variable to track the maximum defense value encountered so far. This helps in determining whether a character is weak compared to those that have already been processed.

3. **Counting Weak Characters**: For each character, if its defense value is less than the maximum defense seen so far, it is counted as weak. If not, we update the maximum defense value accordingly.

### Code Breakdown (Step by Step)

Let's break down the provided code step by step to understand how the solution works:

```cpp
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) {
            return a[1] > b[1]; // Sort by defense in descending order if attack values are equal
        } else return a[0] < b[0]; // Sort by attack in ascending order
    }
```
- We define a class `Solution` with a static comparison function `comp` that takes two vectors `a` and `b` (representing characters).
- The comparison function sorts characters by their attack value in ascending order. If two characters have the same attack value, it sorts them by their defense value in descending order. This sorting is crucial for efficiently identifying weak characters in the next steps.

```cpp
    int numberOfWeakCharacters(vector<vector<int>>& prpt) {
        sort(prpt.begin(), prpt.end(), comp); // Sort the characters using the comparison function
        
        int mn = INT_MIN; // Initialize the minimum defense seen so far
        int ans = 0; // Initialize the count of weak characters
```
- The `numberOfWeakCharacters` function takes a vector of vectors `prpt`, where each inner vector represents a character with attack and defense values.
- We sort the characters using the previously defined `comp` function.
- `mn` is initialized to `INT_MIN` to represent the minimum defense value seen so far as we traverse the sorted characters.
- `ans` is initialized to zero to keep track of the number of weak characters.

```cpp
        for(int i = prpt.size() - 1; i >= 0; i--) { // Iterate through the sorted characters from right to left
            if(prpt[i][1] < mn) ans++; // If the current character's defense is less than the max defense, it's weak
            mn = max(mn, prpt[i][1]); // Update the maximum defense seen so far
        }
        return ans; // Return the total count of weak characters
    }
};
```
- The loop iterates through the sorted list of characters from the last character to the first.
- For each character, if its defense value (`prpt[i][1]`) is less than `mn` (the maximum defense seen so far), we increment the `ans` counter.
- The variable `mn` is then updated to be the maximum of its current value and the current character's defense value.
- After finishing the iteration, the function returns the total count of weak characters.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \(O(n \log n)\), where \(n\) is the number of characters. This complexity arises from the sorting step, which is the most computationally expensive operation in this approach. The subsequent linear scan through the characters is \(O(n)\), but this is dominated by the sorting step.

- **Space Complexity**: The space complexity is \(O(1)\) if we consider only the space used by the algorithm (excluding the input storage). The algorithm does not use any additional data structures that grow with input size, aside from a few variables for counting and tracking maximum values.

### Conclusion

The provided solution effectively counts the number of weak characters in a given list by utilizing sorting and a single pass through the sorted list to track maximum defense values. By sorting the characters based on attack and defense values, the solution efficiently identifies weak characters without needing to compare every character against every other character directly. 

This method demonstrates an efficient way to handle the problem of counting weak characters in a competitive programming or algorithmic context. The approach is clear, concise, and leverages sorting and linear traversal to achieve the desired outcome efficiently.

### Example Usage

Here’s an example of how to use the `Solution` class to count the number of weak characters:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Solution sol;
    vector<vector<int>> characters = {{5, 5}, {6, 3}, {3, 6}}; // Example input
    int result = sol.numberOfWeakCharacters(characters);
    cout << "Number of weak characters: " << result << endl; // Should print the count of weak characters
    return 0;
}
```

This example initializes a `Solution` object and passes a vector of characters to count the weak characters, demonstrating practical usage of the method.

[`Link to LeetCode Lab`](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/)

---
{{< youtube DFqwkF9a6KI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
