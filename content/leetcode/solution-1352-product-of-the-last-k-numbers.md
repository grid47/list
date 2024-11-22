
+++
authors = ["grid47"]
title = "Leetcode 1352: Product of the Last K Numbers"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1352: Product of the Last K Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Design","Queue","Data Stream"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fH1WYQCcMd8"
youtube_upload_date="2021-02-26"
youtube_thumbnail="https://i.ytimg.com/vi/fH1WYQCcMd8/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class ProductOfNumbers {
    vector<long long> p;
public:
    ProductOfNumbers() {
        p = {1};
    }
    
    void add(int num) {
        if(num > 0) {
            p.push_back(p.back() * num);
        } else {
            p = {1};            
        }

    }
    
    int getProduct(int k) {
        int n = p.size();
        return k < n ? p[n - 1] / p[n - k - 1]: 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
{{< /highlight >}}
---


### Problem Statement
The goal of this class, `ProductOfNumbers`, is to manage a sequence of positive integers while allowing for two main operations:

1. **Adding a Number**: You can add a positive integer to the sequence. If the number is zero, the product history should reset, as multiplying by zero results in zero.
2. **Getting the Product**: You can retrieve the product of the last `k` numbers added to the sequence. If `k` exceeds the current number of elements or if there has been a zero added, the product should be returned as zero.

### Approach
To achieve the functionality required, we use the following approach:

- Maintain a vector `p` where each entry at index `i` holds the product of all numbers from the start up to the `i`-th number.
- When a number is added:
  - If the number is positive, update the product vector with the new product.
  - If the number is zero, reset the product vector since all subsequent products would be zero.
- For retrieving the product of the last `k` numbers, we can compute it using the formula:
  - If `k` is less than the length of the product vector, the product of the last `k` numbers can be obtained by dividing the last product by the product at the position `n - k - 1`, where `n` is the current size of the vector.

### Code Breakdown (Step by Step)

```cpp
class ProductOfNumbers {
    vector<long long> p; // Vector to store cumulative product
public:
    ProductOfNumbers() {
        p = {1}; // Initialize with a product of 1
    }
```
- The `ProductOfNumbers` class begins with a private vector `p`, which will store the cumulative product of the numbers added.
- The constructor initializes `p` with `1`, as it serves as the multiplicative identity.

```cpp
    void add(int num) {
        if(num > 0) {
            p.push_back(p.back() * num); // Update product
        } else {
            p = {1}; // Reset on zero
        }
    }
```
- The `add` method checks if the incoming number `num` is greater than `0`. 
  - If it is, it calculates the new product as the product of the last number in `p` multiplied by `num` and appends this value to `p`.
  - If `num` is `0`, it resets `p` to contain only `1` since any subsequent product would involve multiplication by `0`.

```cpp
    int getProduct(int k) {
        int n = p.size(); // Get current size of product vector
        return k < n ? p[n - 1] / p[n - k - 1] : 0; // Calculate product of last k numbers
    }
};
```
- The `getProduct` method retrieves the product of the last `k` numbers added to the sequence.
  - It first determines the size of `p`.
  - If `k` is less than the size of `p`, it returns the product of the last `k` numbers by dividing the last product by the product at the index corresponding to `n - k - 1`.
  - If `k` exceeds the size of `p`, it returns `0`, indicating that the product cannot be computed due to insufficient numbers.

### Complexity Analysis
- **Time Complexity**:
  - The `add` method runs in \(O(1)\) time, as it performs a constant-time operation for both updating the product and resetting the vector.
  - The `getProduct` method also runs in \(O(1)\) time due to direct index accesses and arithmetic operations.

- **Space Complexity**:
  - The space complexity is \(O(n)\), where \(n\) is the number of positive integers added to the `ProductOfNumbers` instance. In the worst case, every number added is positive, leading to a linear growth of the `p` vector.

### Conclusion
The `ProductOfNumbers` class provides a highly efficient way to manage the product of a sequence of integers with the ability to handle zeroes gracefully. By leveraging cumulative products stored in a vector, it allows for quick calculations of the product over the last `k` entries. This class is particularly useful in scenarios where tracking multiplicative values is necessary, such as in financial applications, analytics, or any domain where product history matters.

In coding interviews and competitive programming, understanding how to maintain and manipulate sequences efficiently is crucial. This implementation showcases a clear grasp of data structures and algorithms, emphasizing optimal performance for both operations while also managing edge cases effectively. The techniques demonstrated here can serve as a foundation for more complex data management tasks, reinforcing the importance of strategic thinking in software development.


[`Link to LeetCode Lab`](https://leetcode.com/problems/product-of-the-last-k-numbers/description/)

---
{{< youtube fH1WYQCcMd8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
