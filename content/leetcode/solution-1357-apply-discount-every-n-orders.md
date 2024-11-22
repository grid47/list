
+++
authors = ["grid47"]
title = "Leetcode 1357: Apply Discount Every n Orders"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1357: Apply Discount Every n Orders in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "A-PXwozdaCg"
youtube_upload_date="2024-06-25"
youtube_thumbnail="https://i.ytimg.com/vi/A-PXwozdaCg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Cashier {
    int cnt, mod;
    double pct;
    unordered_map<int, int> tags;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        cnt = 0;
        mod = n;
        pct = (100 - discount)/ 100.0;
        for(int i = 0; i < products.size(); i++)
            tags[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        int ans = 0;
        for(int i = 0; i < product.size(); i++)
            ans += tags[product[i]] * amount[i];
        return cnt%mod? ans: ans * pct; 
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
{{< /highlight >}}
---


### Problem Statement
The goal is to create a `Cashier` class that simulates a cashier system in a store. The cashier must handle billing for customers, applying a discount after every `n` transactions. The following features should be implemented:
1. **Product Management**: The cashier should store a list of products and their corresponding prices.
2. **Bill Calculation**: When a customer checks out, the cashier should calculate the total bill based on the products purchased and their quantities.
3. **Discount Application**: If the cashier has processed exactly `n` transactions, a discount should be applied to the current bill.

### Approach
1. **Initialization**: The `Cashier` class is initialized with the total number of transactions (`n`), a discount percentage, a list of products, and their corresponding prices. During initialization, a mapping of products to prices is created using an unordered map for quick lookups.
2. **Bill Calculation**: The `getBill` method takes two vectors: one for the products purchased and another for their respective quantities. It calculates the total cost based on these inputs.
3. **Discount Logic**: After every transaction, a counter (`cnt`) keeps track of the number of transactions. If `cnt` is a multiple of `n`, the discount is applied; otherwise, the full price is charged.

### Code Breakdown (Step by Step)

```cpp
class Cashier {
    int cnt, mod;  // Counter for transactions and the limit for discount
    double pct;    // Percentage to apply after discount
    unordered_map<int, int> tags; // Maps product IDs to prices
public:
    // Constructor to initialize the Cashier
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        cnt = 0; // Initialize transaction count
        mod = n; // Set the number of transactions for discount application
        pct = (100 - discount) / 100.0; // Calculate the discount percentage

        // Map products to their prices
        for(int i = 0; i < products.size(); i++)
            tags[products[i]] = prices[i];
    }
    
    // Method to calculate the bill
    double getBill(vector<int> product, vector<int> amount) {
        cnt++; // Increment the transaction counter
        int ans = 0; // Variable to store total price

        // Calculate total price based on product and amount
        for(int i = 0; i < product.size(); i++)
            ans += tags[product[i]] * amount[i];
        
        // Apply discount if the transaction count is a multiple of mod
        return cnt % mod ? ans : ans * pct; 
    }
};
```

1. **Class Definition**: The `Cashier` class contains member variables for tracking the transaction count (`cnt`), the modulo for applying discounts (`mod`), and the discount percentage (`pct`). It also has an unordered map (`tags`) to store product prices.
   
2. **Constructor**: The constructor takes four parameters: the maximum number of transactions before applying a discount (`n`), the discount percentage, and vectors for product IDs and their prices. It initializes the `tags` map for quick access to product prices.

3. **getBill Method**: This method accepts two vectors: `product` (product IDs purchased) and `amount` (quantities purchased). It increments the transaction counter and computes the total cost. 
   - If the transaction count (`cnt`) is a multiple of `mod`, the discount percentage (`pct`) is applied to the total; otherwise, the full total is returned.

### Complexity Analysis
- **Time Complexity**:
  - **Initialization**: The constructor has a time complexity of \(O(p)\), where \(p\) is the number of products since it iterates through the list of products to populate the `tags` map.
  - **getBill**: This method has a time complexity of \(O(m)\), where \(m\) is the number of products purchased in the transaction. It iterates through the `product` vector to compute the total cost.
  
- **Space Complexity**: The space complexity is \(O(p)\) due to the storage of product-price pairs in the `tags` map.

### Conclusion
The `Cashier` class effectively simulates a cashier's behavior in a store, handling product sales and applying discounts after every `n` transactions. By using an unordered map to manage product prices, the implementation allows for efficient lookups, ensuring that bill calculations are performed quickly and accurately.

This implementation is particularly useful in e-commerce and retail environments, where efficient billing systems are essential. Understanding this code provides insights into object-oriented programming, data structures, and algorithms necessary for building practical applications in software development.

By breaking down the code and providing detailed explanations of each part, this overview serves as an educational resource for readers looking to enhance their understanding of algorithm design and implementation in C++.


[`Link to LeetCode Lab`](https://leetcode.com/problems/apply-discount-every-n-orders/description/)

---
{{< youtube A-PXwozdaCg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
