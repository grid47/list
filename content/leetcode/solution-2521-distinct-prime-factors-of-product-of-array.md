
+++
authors = ["grid47"]
title = "Leetcode 2521: Distinct Prime Factors of Product of Array"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2521: Distinct Prime Factors of Product of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HKc9PcSzNic"
youtube_upload_date="2023-01-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HKc9PcSzNic/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    set<int> cnt;
    
    void fact(int num) {
        while(num % 2 == 0) {
            cnt.insert(2);
            num /= 2;
        }
        for(int i = 3; i <= num; i+=2) {
            while(num % i == 0) {
                cnt.insert(i);
                num /= i;
            }
        }
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0; i < n; i++)
            fact(nums[i]);
        
        
        return cnt.size() ;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given an array of integers `nums`, the task is to find the number of distinct prime factors that appear in at least one element of the array. Each integer in the array can have multiple prime factors, but we are only interested in the distinct prime factors across all elements of the array. The goal is to return the total number of unique prime factors that appear across all the numbers in the array.

### Approach

The problem requires us to find all the prime factors for each number in the array and count the distinct ones. To solve this, we need to:
1. **Prime Factorization:** Decompose each number into its prime factors.
2. **Tracking Distinct Primes:** As we find prime factors, we should store them in a set to automatically handle duplicates.
3. **Efficient Factorization:** Use an efficient algorithm to factorize each number by checking divisibility starting from the smallest primes (2 and then odd numbers).
4. **Final Count:** After processing all numbers, the size of the set will give us the count of distinct prime factors.

The solution involves two main steps:
1. For each number in the `nums` array, perform prime factorization and add the prime factors to a set.
2. Finally, return the size of the set, which contains only distinct prime factors.

### Code Breakdown (Step by Step)

#### Class Definition:
```cpp
class Solution {
public:
    set<int> cnt;
```
- Here, we define a class `Solution` that will hold a set `cnt` which will store distinct prime factors. The `set` is ideal because it automatically handles duplicate entries and stores only unique values.

#### Prime Factorization Function:
```cpp
    void fact(int num) {
        while(num % 2 == 0) {
            cnt.insert(2);
            num /= 2;
        }
```
- The `fact` function is responsible for finding the prime factors of a number.
- **Dividing by 2**: We first check if `num` is divisible by 2 (the smallest prime). While it is divisible by 2, we insert 2 into the set `cnt` and divide `num` by 2.
- This loop will ensure that we eliminate all factors of 2 from `num`.

```cpp
        for(int i = 3; i <= num; i+=2) {
            while(num % i == 0) {
                cnt.insert(i);
                num /= i;
            }
        }
```
- After removing factors of 2, we continue with the odd numbers starting from 3.
- **Dividing by odd numbers**: The loop checks all odd numbers from 3 upwards. For each number `i`, we check if `num` is divisible by `i`. If it is, we insert `i` into the set `cnt` and divide `num` by `i` until it is no longer divisible.
- This ensures we capture all prime factors. The loop stops once `i` exceeds `num`, at which point `num` itself must be a prime number if it is greater than 2.

#### Main Function to Count Distinct Prime Factors:
```cpp
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
            fact(nums[i]);
```
- The function `distinctPrimeFactors` takes a vector `nums` as input. We first determine the size of the vector `n`.
- Then, we iterate over each element in the `nums` array and call the `fact` function to find its prime factors. For each element, `fact` adds the prime factors to the `cnt` set.

```cpp
        return cnt.size();
    }
};
```
- Finally, the function returns the size of the set `cnt`, which represents the total number of distinct prime factors across all numbers in the array. Since a set automatically handles duplicates, it ensures that only unique prime factors are counted.

### Complexity

#### Time Complexity:
- The prime factorization process for each number involves dividing the number by all integers starting from 2 and moving upwards. The complexity of finding the prime factors of a number is approximately \( O(\sqrt{num}) \), where `num` is the value of the number being factored.
- For each number `nums[i]` in the array, we perform a factorization that takes \( O(\sqrt{nums[i]}) \).
- If `n` is the number of elements in the array `nums`, and `max_num` is the largest number in the array, the overall time complexity is \( O(n \times \sqrt{max\_num}) \), where `max_num` is the largest number in the array.

#### Space Complexity:
- The space complexity is \( O(k) \), where `k` is the number of distinct prime factors across all numbers in the array. This is because we are storing the distinct prime factors in a `set`. The set will have a size proportional to the number of distinct prime factors.

### Conclusion

This solution efficiently calculates the number of distinct prime factors across all elements of the array. By using prime factorization and a set to store unique primes, we ensure that the solution handles duplicate factors and efficiently counts distinct primes. The solution is optimal for a wide range of input sizes, with a time complexity of \( O(n \times \sqrt{max\_num}) \) and a space complexity of \( O(k) \), where `n` is the number of elements and `k` is the number of distinct prime factors. The use of a set guarantees that duplicate prime factors are not counted, ensuring the correctness of the result.

[`Link to LeetCode Lab`](https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/)

---
{{< youtube HKc9PcSzNic >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
