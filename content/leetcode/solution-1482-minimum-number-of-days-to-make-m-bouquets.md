
+++
authors = ["grid47"]
title = "Leetcode 1482: Minimum Number of Days to Make m Bouquets"
date = "2024-06-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1482: Minimum Number of Days to Make m Bouquets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "C43I3Q0JLB0"
youtube_upload_date="2020-06-14"
youtube_thumbnail="https://i.ytimg.com/vi/C43I3Q0JLB0/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int isValid(vector<int> &bloom, int m, int mid, int k) {
        int bough = 0, cnt = 0;
        
        for(int i = 0; i < bloom.size(); i++) {
            if(bloom[i] > mid) {
                cnt = 0;
            } else if(++cnt >= k) {
                cnt = 0;
                bough++;
            }
        }
        if(bough >= m) return true;
        else return false;
    }
    
    int minDays(vector<int>& bloom, int m, int k) {
        int n = bloom.size();
        if((long)m * k > n) return -1;
        
        int l = 1, r = (int) 1e9, result;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(isValid(bloom, m, mid, k)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return result;
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires determining the minimum number of days needed for a garden represented as an array to bloom such that there are at least `m` bouquets, where each bouquet consists of `k` adjacent blooming flowers. The array contains integers representing the day each flower blooms, and the goal is to find the earliest day when it is possible to create the required number of bouquets.

### Approach

To solve this problem, we can utilize a binary search strategy combined with a greedy algorithm. The idea is to perform a binary search over the possible days to find the minimum day on which we can achieve the desired number of bouquets. Here’s a step-by-step breakdown of the approach:

1. **Input Validation**: First, we check if it is possible to form the required number of bouquets. If the total number of flowers needed, `m * k`, is greater than the size of the bloom array, we return `-1` because it's impossible to create the bouquets.

2. **Binary Search Initialization**: We set up a binary search between `1` and `1e9` (or a higher day limit), which encompasses the range of possible blooming days.

3. **Validity Check Function**: We define a helper function `isValid` that determines if it is possible to create at least `m` bouquets by a given day (`mid`). This function counts the number of adjacent blooming flowers and checks if we can form the required bouquets.

4. **Binary Search Execution**: In the main `minDays` function, we continuously adjust the search bounds based on whether the current middle point (`mid`) allows for enough bouquets:
   - If `isValid` returns `true`, we may have a valid solution, so we move the right pointer to `mid - 1` to look for an earlier possible day.
   - If `isValid` returns `false`, we need to search later days, so we move the left pointer to `mid + 1`.

5. **Result**: Finally, we return the result which will be the minimum day found.

### Code Breakdown (Step by Step)

Here’s a detailed explanation of the code implementation:

```cpp
class Solution {
public:
    int isValid(vector<int> &bloom, int m, int mid, int k) {
        int bough = 0, cnt = 0;
        
        for(int i = 0; i < bloom.size(); i++) {
            if(bloom[i] > mid) {
                cnt = 0;  // Reset count if current flower has not bloomed by 'mid'
            } else if(++cnt >= k) { // Increment count for blooming flowers
                cnt = 0; // Reset count after forming a bouquet
                bough++; // Increment bouquet count
            }
        }
        return bough >= m; // Return true if we can form at least 'm' bouquets
    }
```

- **`isValid` Function**: This function checks if it's possible to form at least `m` bouquets by day `mid`. It iterates over the `bloom` array, counting how many consecutive flowers are blooming by checking if the day of bloom is less than or equal to `mid`. Whenever `k` blooming flowers are counted, it resets the count and increments the bouquet counter.

```cpp
    int minDays(vector<int>& bloom, int m, int k) {
        int n = bloom.size();
        if((long)m * k > n) return -1; // Check if it's impossible to form m bouquets
        
        int l = 1, r = (int) 1e9, result;
        
        while(l <= r) {
            int mid = l + (r - l) / 2; // Calculate mid point
            if(isValid(bloom, m, mid, k)) {
                result = mid; // Save the result
                r = mid - 1; // Search for a smaller day
            } else {
                l = mid + 1; // Search for a larger day
            }
        }
        
        return result; // Return the minimum day found
    }
};
```

- **`minDays` Function**: This function implements the binary search. It starts by checking if creating the bouquets is feasible. Then it performs the binary search by calling `isValid` to determine if we can achieve our goal by the current day. Depending on the result, it narrows down the search space.

### Complexity

- **Time Complexity**:
  - The time complexity of this algorithm is \(O(n \log D)\), where \(n\) is the number of flowers and \(D\) is the maximum number of days. The `isValid` function runs in \(O(n)\) for each check, and we perform at most \(O(\log D)\) checks due to the binary search.

- **Space Complexity**:
  - The space complexity is \(O(1)\) since we are using a fixed amount of extra space for the counters and not using any additional data structures that scale with the input size.

### Conclusion

The `minDays` function efficiently calculates the minimum number of days required for the flowers to bloom such that a specified number of bouquets can be formed. By using binary search in conjunction with a greedy counting strategy, we ensure that the solution is both optimal and efficient.

Key takeaways from this implementation include:

1. **Binary Search Optimization**: Utilizing binary search allows us to reduce the search space significantly, making the solution scalable even for larger inputs.

2. **Greedy Approach**: The greedy counting strategy ensures that we effectively track the number of adjacent blooming flowers, allowing for accurate bouquet formation checks.

3. **Real-World Application**: This problem can be relevant in various scenarios such as scheduling, resource allocation, or any domain where constraints on timing and quantities need to be managed effectively.

In summary, this implementation offers a robust solution to the problem of determining the earliest day to achieve a specified number of adjacent blooming flowers, showcasing the power of combining binary search with greedy algorithms in algorithmic problem-solving.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/)

---
{{< youtube C43I3Q0JLB0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
