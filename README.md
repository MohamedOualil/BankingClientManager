# Bank Management System

A comprehensive C++ banking system that provides robust functionality for managing bank operations, client accounts, currencies, and transactions.

## 🌟 Features

### Client Management
- Create and manage client profiles
- View client details and transaction history
- Update client information
- Delete client accounts

### Currency Operations
- Support for multiple currencies
- Real-time currency conversion
- Currency rate management
- Currency exchange calculations

### User Management
- Secure user authentication
- Role-based access control
- User activity logging
- Password management

### Date Management
- Comprehensive date manipulation utilities
- Business day calculations
- Vacation day tracking
- Calendar operations

### Transaction Processing
- Deposit handling
- Withdrawal processing
- Transfer between accounts
- Transaction logging

### Administrative Features
- System monitoring
- User activity tracking
- Transaction reports
- System settings management

## 🛠️ Technical Details

### Core Components
- **clsBankClient**: Handles all client-related operations
- **clsCurrency**: Manages currency conversion and rates
- **clsDate**: Provides comprehensive date manipulation functionality
- **clsUsers**: Manages user authentication and permissions
- **Various UI Screens**: Modular interface components for different operations

### Key Technologies
- Language: C++
- Development Environment: Visual Studio
- Architecture: Object-Oriented Design
- File System: Text-based data storage

## 📖 Usage

### Client Operations
```cpp
// Example: Creating a new client
clsBankClient newClient;
newClient.AddNewClient();

// Example: Finding a client
clsFindClientScreen::ShowFindClientScreen();
```

### Currency Operations
```cpp
// Example: Currency conversion
clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
```

### User Management
```cpp
// Example: User authentication
clsShowLoginScreen::ShowLoginScreen();
```

## 🔒 Security Features
- Secure password handling
- Input validation
- Access control
- Transaction logging

## 📊 Data Management
- Text-based data storage
- Transaction logs
- User activity tracking
- Currency rate history


