# ATM

A simple ATM (Automated Teller Machine) simulation program written in C. This project allows users to manage bank accounts through a text-based interface, supporting both employee (admin) and customer roles. It is designed as an educational example of file I/O, data structures, and user interaction in C.

---

## Features

### For Employees (Admins)
- **Create a new customer account**: Add new accounts with personal details and an initial balance.
- **Edit account information**: Update customer data such as name, phone number, national code, card number, and password.
- **View the richest customer**: Display the customer with the highest account balance.
- **Show total balance**: Calculate and show the sum of all customer account balances.

### For Customers
- **Login using card number and password**
- **View account balance**
- **Cash transfer**: Transfer money to another account by card number.
- **Cash withdrawal**: Withdraw money from the account.
- **View recent account updates**: Display recent transactions and updates for the account.
- **Change password**

---

## Getting Started

### Clone the Repository

You can clone this project using the following command:

```sh
git clone https://github.com/HoomanMoradnia/ATM.git
cd ATM
```

### Prerequisites

- **Windows**: 
  - C compiler (such as GCC in MinGW or MSVC)
  - Supports `windows.h` and `conio.h` natively
- **Linux**: 
  - GCC or compatible C compiler
  - You may need to remove or replace Windows-specific headers and functions (`windows.h`, `conio.h`, `system("cls")`, etc.) for compatibility

### Compilation

#### On Windows

```sh
gcc ATM.c -o atm.exe
```

#### On Linux

You need to modify or remove Windows-specific code:
- Replace `#include <windows.h>` and `#include <conio.h>` with POSIX-compatible alternatives or remove them if not used.
- Replace `system("cls")` with `system("clear")` or remove it.

Then compile:

```sh
gcc ATM.c -o atm
```

### Running

- **Windows:**  
  ```sh
  atm.exe
  ```
- **Linux:**  
  ```sh
  ./atm
  ```

---

## File Structure

- `ATM.c` – Main program source code
- `recentData.txt` – Stores recent account updates (created at runtime)
- `LICENSE` – MIT License

---

## Usage

On launch, you will see:

```
----------------------
|   welcome to ATM   |
----------------------

 (1) Log in as an employee

 (2) Log in as a customer

 (3) Exit
```

Follow the prompts to log in as an employee (default: username `admin`, password `1234`) or as a customer (using a valid card number and password).

---

## Data Storage

- Account details and recent updates are stored in text files.
- Data is loaded on program start and saved on updates.

---

## Example Account Fields

- First Name
- Last Name
- Phone Number
- National Code
- Card Number (16 digits)
- Password (4 digits)
- Balance

---

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

---

## Notes

- This project is for educational purposes. It does not include real security measures.
- Passwords and sensitive data are stored in plain text.
- Only basic error handling and data validation are implemented.
- **Linux port:** If you wish to run this on Linux, make sure to address Windows-specific dependencies and test accordingly.

---

## Author

Hooman Moradnia
