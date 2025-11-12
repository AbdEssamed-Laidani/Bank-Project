# ِ� Bank Management System

A comprehensive C++ console-based banking application with user authentication, client management, and transaction processing capabilities.

## ِ Table of Contents
- [Overview](#overview)
- [Features](#features)
- [System Requirements](#system-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [User Permissions](#user-permissions)
- [File Format](#file-format)
- [Screenshots](#screenshots)
- [Contributing](#contributing)
- [License](#license)

## ِ� Overview

This Bank Management System is a secure, console-based application designed to manage banking operations including client accounts, transactions, and user access control. The system implements a role-based permission system to ensure secure access to different functionalities.

## ق� Features

### ِ Authentication System
- Secure login with username and password
- Role-based access control
- Admin and user roles with customizable permissions

### ِ� Client Management
- **View Clients List**: Display all registered clients with their details
- **Add New Client**: Register new clients with account number, PIN, name, phone, and balance
- **Delete Client**: Remove clients from the system with confirmation
- **Update Client**: Modify existing client information
- **Find Client**: Search for specific clients by account number

### ِ� Transaction Operations
- **Deposit**: Add funds to client accounts
- **Withdraw**: Remove funds with balance verification
- **Total Balance**: View cumulative balance of all accounts
- Real-time balance updates

### ِ¤ User Management
- **List Users**: Display all system users
- **Add New User**: Create new users with custom permissions
- **Delete User**: Remove users (Admin protected)
- **Update User**: Modify user credentials and permissions
- **Find User**: Search for specific users

### ِ Permission System
The system implements 7 different permission levels:
1. **Show Client List** (1)
2. **Add Client** (2)
3. **Delete Client** (4)
4. **Update Client** (8)
5. **Find Client** (16)
6. **Transactions** (32)
7. **Manage Users** (64)
8. **Full Access** (-1)

Permissions are stored as bit flags, allowing flexible combinations.

## ِ؛ System Requirements

- **Compiler**: C++11 or higher
- **Operating System**: Windows (uses `system("cls")` and `system("pause")`)
- **Dependencies**: 
  - Standard C++ Library
  - `MyLib.h` (custom library - ensure it's in the same directory)

## ِ Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/AbdEssamed-Laidani/Bank-Project.git
   cd Bank-Project
   ```

2. **Ensure all files are present**
   - `Project1.cpp` (main source code)
   - `MyLib.h` (custom library header)
   - `Client.txt` (client data file)
   - `Users.txt` (user credentials file)

3. **Compile the project**
   ```bash
   g++ -std=c++11 Project1.cpp -o BankSystem
   ```

4. **Run the application**
   ```bash
   ./BankSystem
   ```

## ِ Usage

### First Login
Default admin credentials:
- **Username**: `Admin`
- **Password**: `1234`

### Main Menu Navigation
After successful login, you'll see the main menu with 8 options:

```
=====================================================
                    Main Menu
=====================================================

    [1] Show Clients List.
    [2] Add New Client.
    [3] Delete Client.
    [4] Update Client Data.
    [5] Find Client.
    [6] Transaction.
    [7] Manage Users.
    [8] LogOut.

=====================================================
```

### Adding a New Client
1. Select option `[2] Add New Client`
2. Enter client details:
   - Account Number (must be unique)
   - PIN Code
   - Client Name
   - Phone Number
   - Initial Balance

### Performing Transactions
1. Select option `[6] Transaction`
2. Choose transaction type:
   - `[1]` Deposit
   - `[2]` Withdraw
   - `[3]` Show Total Balance
   - `[4]` Return to Main Menu

### Managing Users
1. Select option `[7] Manage Users`
2. Available operations:
   - List all users
   - Add new user with custom permissions
   - Delete user (Admin is protected)
   - Update user credentials
   - Find specific user

## ِ Project Structure

```
Bank-Project/
ق
ققق Project1.cpp          # Main application source code
ققق MyLib.h              # Custom utility library
ققق Client.txt           # Client data storage
ققق Users.txt            # User credentials storage
ققق README.md            # Project documentation
```

### Code Organization

The project is organized into several functional sections:

- **Data Structures**: `stClientData`, `stUserInfo`
- **Enums**: `enMenuChoices`, `enTransactionOption`, `enUserPermission`
- **File Operations**: Save/Load functions for persistent storage
- **Client Operations**: CRUD operations for client management
- **Transaction Handlers**: Deposit, withdraw, balance calculations
- **User Management**: User CRUD with permission handling
- **Authentication**: Login system with credential verification

## ِ User Permissions

Permissions are implemented using bitwise operations:

| Permission | Value | Description |
|------------|-------|-------------|
| Show List | 1 | View client list |
| Add | 2 | Add new clients |
| Delete | 4 | Delete clients |
| Update | 8 | Update client data |
| Find | 16 | Search for clients |
| Transaction | 32 | Perform transactions |
| Manage | 64 | Manage users |
| Full Access | -1 | All permissions |

### Example Permission Calculations
- Read + Write: `1 + 2 = 3`
- All Operations: `1 + 2 + 4 + 8 + 16 + 32 + 64 = 127`
- Full Access: `-1`

## ِ File Format

### Client.txt Format
```
AccountNumber #//# PinCode #//# ClientName #//# PhoneNumber #//# Balance
```

**Example:**
```
A150 #//# 123 #//# AbdEssamed Laidani #//# 00000000 #//# 15000
```

### Users.txt Format
```
Username #//# Password #//# Permission
```

**Example:**
```
Admin #//# 1234 #//# -1
User1 #//# 1234 #//# 48
```

## ِ�ُ� Security Features

- **Authentication Required**: All operations require valid login
- **Permission-Based Access**: Users can only perform authorized operations
- **Admin Protection**: Admin account cannot be deleted or modified
- **Balance Verification**: Withdrawals are validated against available balance
- **Unique Identifiers**: Account numbers and usernames must be unique

## ِ Known Limitations

- Windows-specific commands (`system("cls")`, `system("pause")`)
- Text-based file storage (not encrypted)
- No transaction history logging
- Single-session use (no concurrent users)

## ِ� Future Enhancements

- [ ] Database integration (SQLite/MySQL)
- [ ] Transaction history and audit logs
- [ ] Data encryption for sensitive information
- [ ] Cross-platform compatibility (Linux/Mac support)
- [ ] GUI interface
- [ ] Interest calculation
- [ ] Account statement generation
- [ ] Backup and restore functionality

## ِ¤ Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## ِ� Contact

**AbdEssamed Laidani**
- GitHub: [@AbdEssamed-Laidani](https://github.com/AbdEssamed-Laidani)

## ِ License

This project is open source and available under the [MIT License](LICENSE).

---

ق­ If you find this project helpful, please consider giving it a star!

**Developed with ق¤ُ� by AbdEssamed Laidani**
