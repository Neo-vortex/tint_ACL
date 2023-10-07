# tint_ACL


# Command Line User Management Tool

Welcome to the Command Line User Management Tool project! This tool is designed to simplify user and access management operations for system administrators, providing a command-line interface for performing various user-related tasks.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)

## Features

- User creation and authentication
- Domain and type management
- Access control for users
- Modular and clean C++ codebase
- Error handling with the Error Printer module
- Directory management with Directory Structure Helper
- User-friendly command line interface

## Getting Started

### Prerequisites

Before you can use this tool, you'll need the following:

- C++ compiler compatible with C++11
- Git (optional, for cloning the repository)

### Installation

### Clone the repository:
   ```bash
   git clone [repository_url]
   ```
### Build
   ```bash
  make
  ```

## Usage

```bash
# Add a new user
./user_management_tool AddUser [username] [password]

# Authenticate a user
./user_management_tool Authenticate [username] [password]

# Set a user's domain
./user_management_tool SetDomain [username] [domain]

# Get domain information
./user_management_tool DomainInfo [domain]

# Set a user's type
./user_management_tool SetType [username] [type]

# Get type information
./user_management_tool TypeInfo [type]

# Add access for a user
./user_management_tool AddAccess [username] [domain] [type]

# Check if a user can access a domain with a specific type
./user_management_tool CanAccess [username] [domain] [type]
```
