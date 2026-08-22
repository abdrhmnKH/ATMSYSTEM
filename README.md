# ATM Banking System

A simple **ATM Banking System** developed in **C++** as a console-based application.

The project simulates basic ATM operations such as user login, withdrawing money, depositing money, and checking the account balance. Client information is stored and managed using a text file.

## Features

* 🔐 **Login System**

  * Login using Account Number and PIN Code.
  * Validates the entered credentials.

* 💵 **Quick Withdraw**

  * Provides predefined withdrawal amounts:

    * 20
    * 50
    * 100
    * 200
    * 400
    * 600
    * 800
    * 1000

* 💸 **Normal Withdraw**

  * Allows the user to enter a custom withdrawal amount.
  * The amount must be a multiple of 5.
  * Prevents withdrawing more than the available balance.

* 💰 **Deposit**

  * Allows the user to deposit money into their account.
  * The deposit amount must be positive.

* 📊 **Check Balance**

  * Displays the current account balance.

* 🚪 **Logout**

  * Allows the user to safely log out of the system.

## Data Storage

Client information is stored in a file named:

```text
Clients.txt
```

Each client record contains:

```text
Account Number
PIN Code
Name
Phone
Account Balance
```

The program uses `#//#` as a separator when saving client records to the file.

## Technologies Used

* **C++**
* File Handling (`fstream`)
* `vector`
* `struct`
* String Manipulation
* Functions
* Loops and Conditions
* Console-Based User Interface

## Project Structure

The main program contains several functions responsible for different parts of the system:

| Function                    | Description                               |
| --------------------------- | ----------------------------------------- |
| `LoadCleintsDataFromFile()` | Loads client data from `Clients.txt`      |
| `SaveCleintsDataToFile()`   | Saves client data back to the file        |
| `ConvertLinetoRecord()`     | Converts a file line into a client record |
| `ConvertRecordToLine()`     | Converts a client record into a file line |
| `Loginscreen()`             | Handles the login process                 |
| `QuickWithdraw()`           | Handles predefined withdrawal amounts     |
| `Withdraw()`                | Handles custom withdrawals                |
| `Deposit()`                 | Handles deposits                          |
| `CheckBalance()`            | Displays the account balance              |
| `SwitchOperation()`         | Controls the ATM menu operations          |


## Example

After logging in, the user will see the main ATM menu:

```text
[1] Quick Withdraw
[2] Normal Withdraw
[3] Deposit
[4] Check Balance
[5] Logout
```

The user can then select the required operation.

## Purpose

This project was created to practice and demonstrate fundamental **C++ programming concepts**, including:

* Structures
* Vectors
* File handling
* Functions
* References
* String processing
* Loops
* Conditional statements
* Basic data management

## Author

**Abd Al-Rahman**

---

⭐ If you find this project useful, feel free to give it a star!
