
+++
authors = ["grid47"]
title = "Leetcode 2043: Simple Bank System"
date = "2024-04-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2043: Simple Bank System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ouflA0KmCnI"
youtube_upload_date="2021-10-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ouflA0KmCnI/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Bank {
public:
    int n;
    vector<long long> bal;
    Bank(vector<long long>& balance) {
        bal = balance;
        n = bal.size();
    }
    
    bool transfer(int acc1, int acc2, long long money) {
        int ac1 = acc1 - 1 , ac2 = acc2 - 1;
        if(ac1 < 0 || ac1 >= n || ac2 < 0 || ac2 >= n || bal[ac1] < money)
            return false;
        
        bal[ac1] -= money;
        bal[ac2] += money;
        return true;
    }
    
    bool deposit(int acc, long long money) {
        
        if(acc < 1 || acc > n) return false;
        
        bal[acc - 1] += money;
        return true;
    }
    
    bool withdraw(int acc, long long money) {
        if(acc < 1 || acc > n || bal[acc - 1] < money) return false;        
        bal[acc - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
{{< /highlight >}}
---

### Problem Statement

This code represents a simple banking system that supports common bank account operations, including transferring funds between accounts, depositing funds into an account, and withdrawing funds from an account. The banking system is designed to work with a specified list of account balances, and each operation is validated to ensure that it meets certain conditions (e.g., checking if an account exists or if sufficient funds are available).

The objective of this banking system is to efficiently manage balances and validate transactions, returning `true` for successful operations and `false` if any conditions are violated. The functionality allows multiple accounts to interact with each other through deposits, withdrawals, and transfers.

### Approach

To implement this system, we use an object-oriented approach where each bank account is managed within a class called `Bank`. The class contains several key methods for handling the transfer, deposit, and withdrawal functionalities.

The approach for each operation can be broken down as follows:

1. **Account Validation**: For each operation, the code first checks if the account(s) in question exist and meet the requirements (such as having enough balance for a withdrawal or transfer). 
2. **Balance Adjustment**: Once validated, the balance is adjusted accordingly. 
3. **Return Status**: Each operation returns a boolean value (`true` or `false`) to indicate whether the operation was successful or not.

### Code Breakdown (Step by Step)

Let’s go through the code step by step to understand each part of the implementation.

1. **Class and Member Variable Definition**: We define a class named `Bank`. The class contains two member variables: 
   - `n`: An integer representing the number of accounts in the bank.
   - `bal`: A vector of long long integers representing the balance of each account.

    ```cpp
    class Bank {
    public:
        int n;
        vector<long long> bal;
    ```

2. **Constructor**: The constructor initializes the `Bank` object. It takes a vector `balance` as input, which contains the initial balance of each account. The constructor assigns this vector to `bal` and sets `n` to the number of accounts.

    ```cpp
    Bank(vector<long long>& balance) {
        bal = balance;
        n = bal.size();
    }
    ```

3. **Transfer Method**: This method transfers a specified amount (`money`) from one account (`acc1`) to another (`acc2`). It first adjusts `acc1` and `acc2` to 0-based indexing. The method checks if both accounts exist and if the source account has sufficient funds. If these conditions are met, the balance is updated, deducting `money` from `acc1` and adding it to `acc2`. If successful, it returns `true`; otherwise, `false`.

    ```cpp
    bool transfer(int acc1, int acc2, long long money) {
        int ac1 = acc1 - 1 , ac2 = acc2 - 1;
        if(ac1 < 0 || ac1 >= n || ac2 < 0 || ac2 >= n || bal[ac1] < money)
            return false;
        
        bal[ac1] -= money;
        bal[ac2] += money;
        return true;
    }
    ```

4. **Deposit Method**: This method deposits a specified amount (`money`) into an account (`acc`). The method checks if the account number is valid (between 1 and n). If valid, it adds `money` to the account’s balance and returns `true`; otherwise, `false`.

    ```cpp
    bool deposit(int acc, long long money) {
        if(acc < 1 || acc > n) return false;
        bal[acc - 1] += money;
        return true;
    }
    ```

5. **Withdraw Method**: This method withdraws a specified amount (`money`) from an account (`acc`). The method checks if the account exists and has enough funds. If the conditions are met, it deducts `money` from the account’s balance and returns `true`; otherwise, `false`.

    ```cpp
    bool withdraw(int acc, long long money) {
        if(acc < 1 || acc > n || bal[acc - 1] < money) return false;        
        bal[acc - 1] -= money;
        return true;
    }
    ```

6. **Example Usage**: The comment block at the end shows how this `Bank` object might be used. After creating a `Bank` object, we can call its methods to transfer, deposit, or withdraw funds.

    ```cpp
    /**
     * Your Bank object will be instantiated and called as such:
     * Bank* obj = new Bank(balance);
     * bool param_1 = obj->transfer(account1,account2,money);
     * bool param_2 = obj->deposit(account,money);
     * bool param_3 = obj->withdraw(account,money);
     */
    ```

### Complexity

- **Time Complexity**: Each operation (transfer, deposit, and withdrawal) is performed in constant time, or O(1). This makes the code highly efficient, as each method only involves direct balance adjustments and simple condition checks.
- **Space Complexity**: The space complexity is O(n), where n is the number of accounts, because we store the balance of each account in the `bal` vector.

### Conclusion

In summary, this code provides a simple yet efficient solution to simulate a basic banking system with multiple accounts. By using O(1) time complexity for each transaction, the code ensures high performance, even with a large number of accounts and transactions. The `Bank` class encapsulates the functionality for transferring, depositing, and withdrawing funds, allowing for easy extensions or modifications. This approach, with clear validation checks, makes the system secure and user-friendly, providing reliable banking operations while maintaining optimal performance.

[`Link to LeetCode Lab`](https://leetcode.com/problems/simple-bank-system/description/)

---
{{< youtube ouflA0KmCnI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
