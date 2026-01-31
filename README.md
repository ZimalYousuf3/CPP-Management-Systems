# CPP Management Systems

A comprehensive collection of complete C++ management system applications demonstrating real-world software development. Each system includes full CRUD operations, menu-driven interfaces, and professional-grade functionality.

## Overview

This repository contains 13 fully functional management systems built in C++. Each project represents a complete real-world application with features like data management, report generation, file I/O, and user interaction. These systems showcase advanced C++ concepts, including structures, enums, unions, file handling, and object-oriented design patterns.

---

## Management Systems

### 1. Customer Feedback System
A comprehensive customer feedback management application.

**Features**:
- Add and manage customer feedback records
- Track satisfaction scores
- Generate feedback analysis reports
- Menu-driven interface for easy navigation

**Key Concepts**: Structures, file I/O, data validation, reporting

---

### 2. E-Commerce Inventory System
A complete inventory management solution for e-commerce businesses.

**Files**: `E-Commerce Inventory System.cpp`, `inventory.txt`

**Features**:
- Read product data from the inventory file
- Display all products in a formatted table
- Process product sales and update quantities
- Find the most expensive product
- Reorder level monitoring
- Generate comprehensive inventory reports

**Key Concepts**: Structures, CSV file parsing, inventory management, report generation

---

### 3. Employee Management Systems
A multi-featured employee management application with performance tracking.

**Features**:
- Employee Performance Tracker
- Employee Record System with File I/O
- Add and manage employee records
- Calculate performance ratings
- Input validation system
- Generate employee reports

**Key Concepts**: Structures, file handling, performance metrics, data validation

---

### 4. Hospital Patient Management System
A complete patient management solution for healthcare facilities.

**Features**:
- Add and manage patient records
- Track blood groups using enums
- Calculate hospital bills based on stay duration
- Tiered billing system (different rates for different stay durations)
- Find patients by blood group
- Generate hospital reports with revenue tracking

**Key Concepts**: Structures, enums, nested structures, bill calculation algorithms

---

### 5. Hotel Guest Management System
A professional hotel guest management and billing application.

**Features**:
- Add and manage guest records
- Multiple room types (Single, Double, Deluxe, Suite)
- Calculate stay duration and bills
- Room-type-based pricing system
- Find guests by room type
- Generate hotel revenue reports

**Key Concepts**: Structures, enums, date calculations, tiered pricing

---

### 6. Library Book Management System
A comprehensive library management application with fine calculation.

**Files**: `Library Book Management System.cpp`, `Library Management System.cpp`, `books.txt`

**Features**:
- Add and manage book records
- Categorize books (Fiction, Non-Fiction, Science, Computer, History, Islamic)
- Calculate borrow duration and fines
- Tiered fine system based on overdue days
- Find books by category
- Generate library reports

**Key Concepts**: Structures, enums, fine calculation algorithms, categorization

---

### 7. Restaurant Menu Ordering System
A complete restaurant ordering and billing application.

**Features**:
- Interactive menu display with prices
- Handle customer orders and special requests
- Apply discounts and promotions
- Calculate bills with tax
- Manage inventory levels
- Generate order summaries

**Key Concepts**: Menu systems, order processing, discount calculations, inventory tracking

---

### 8. Smart City Analytics
A comprehensive smart city data analytics platform with multiple modules.

**Files**: Multiple .cpp files and data files (`air_quality.txt`, `transportation.txt`, `waste_data.txt`)

**Modules**:

#### Air Quality Monitoring System
- Analyze PM2.5 levels from sensor data
- Categorize air quality (Good, Moderate, Unhealthy)
- Calculate statistics and identify trends
- Generate health recommendations

#### Public Transportation Analytics
- Analyze passenger count data
- Categorize passenger loads (Light, Moderate, Heavy)
- Calculate weekly and monthly averages
- Suggest optimal vehicle allocation

#### Waste Management Optimizer
- Analyze daily waste collection data
- Categorize waste generation levels
- Optimize truck allocation based on waste volume
- Generate waste management recommendations

**Key Concepts**: Data analytics, multiple modules, statistical analysis, resource optimization

---

### 9. Smart Home Device Manager
An IoT-based smart home device management system.

**Features**:
- Add and manage smart devices
- Multiple device types (Light, Thermostat, Security Camera, Speaker)
- Change device settings in real-time
- Find devices by room
- Memory statistics using unions
- Display all devices in a formatted table

**Key Concepts**: Structures, enums, unions, IoT concepts, memory optimization

---

### 10. Smart Traffic Light System
A simulated smart traffic light management system.

**Features**:
- Vehicle count detection simulation
- Adjustable green light duration based on traffic density
- Emergency vehicle handling
- Pedestrian crossing management
- Multiple modes (Rush Hour, Night Mode)

**Key Concepts**: Simulation, conditional logic, traffic management algorithms

---

### 11. Student Fee Management System
A complete student fee tracking and management application.

**Files**: `Student Fee Management System.cpp`, `studentsNew.txt`

**Features**:
- Read student data from file
- Display all student records
- Process fee payments
- Track due fees and payment status
- Find the student with the highest due fee
- Generate fee reports

**Key Concepts**: Structures, file parsing, fee calculations, financial tracking

---

### 12. Student Management Systems
A comprehensive student record management application.

**Features**:
- Add and manage student records
- Track student information
- Search and display students
- Calculate statistics
- Menu-driven interface

**Key Concepts**: Structures, arrays, data management, search algorithms

---

### 13. University Course Management System
A university course management and analytics application.

**Files**: `University Course Management System.cpp`, `courses.txt`

**Features**:
- Read course data from file
- Categorize courses (Introductory, Intermediate, Advanced)
- Calculate average credit hours
- Identify advanced courses
- Calculate course workload estimates
- Generate academic reports

**Key Concepts**: Structures, recursive functions, function overloading, academic analytics

---

## Learning Objectives

### Data Management
- Creating and managing structured data
- Implementing CRUD operations
- Organizing records efficiently
- Maintaining data integrity

### File I/O Operations
- Reading structured data from files
- Writing reports and outputs
- CSV and delimited file parsing
- Error handling for file operations

### Real-World Applications
- Healthcare management
- Financial systems
- Educational management
- Retail and e-commerce
- Smart city infrastructure
- IoT device management

### Advanced C++ Concepts
- Structures and nested structures
- Enumerations for type safety
- Unions for memory optimization
- Function overloading
- Recursive algorithms
- Reference parameters
- Static variables

---

## Technical Specifications

- **Language**: C++ (Standard C++11 and above)
- **Compiler Compatibility**: g++, MSVC, Clang++, MinGW
- **Input Format**: Text files (.txt) with structured data
- **Output Format**: Console output and formatted reports
- **Platform**: Cross-platform (Windows, Linux, macOS)

---

## How to Use

### Running a Management System

1. Navigate to the project folder
```bash
   cd "Library Book Management System"
```

2. Compile the program
```bash
   g++ "Library Book Management System.cpp" -o library
```

3. Ensure data files exist
   - Make sure the required .txt files are in the same directory as the executable

4. Run the program
```bash
   ./library
```

5. Follow the menu
   - Each system has a menu-driven interface
   - Simply enter the number of your choice and press Enter

---

## Systems Overview

| # | System | Has Data Files | Menu Driven | Report Generation |
|---|--------|---------------|-------------|-------------------|
| 1 | Customer Feedback | No | Yes | Yes |
| 2 | E-Commerce Inventory | Yes | Yes | Yes |
| 3 | Employee Management | No | Yes | Yes |
| 4 | Hospital Patient | No | Yes | Yes |
| 5 | Hotel Guest | No | Yes | Yes |
| 6 | Library Book | Yes | Yes | Yes |
| 7 | Restaurant Menu | No | Yes | Yes |
| 8 | Smart City Analytics | Yes | Yes | Yes |
| 9 | Smart Home Device | No | Yes | Yes |
| 10 | Smart Traffic Light | No | Yes | No |
| 11 | Student Fee | Yes | Yes | Yes |
| 12 | Student Management | No | Yes | Yes |
| 13 | University Course | Yes | Yes | Yes |

---

## Customization

Each system can be enhanced with:
- Database connectivity
- User authentication
- Graphical user interface
- Data visualization
- Network capabilities
- Additional reporting features

---

## Related Repositories

- **[CPP-Basics](https://github.com/ZimalYousuf3/CPP-Basics)** - Fundamental C++ programs (100+ examples)
- **[CPP-Practice-Problems](https://github.com/ZimalYousuf3/CPP-Practice-Problems)** - Practice problems with data processing

---

## Author

**Zimal Yousuf**
BSCS Student | C++ Developer
Passionate about building real-world applications and clean software design

---

## Notes

- All systems include comprehensive input validation
- Menu-driven interfaces for easy navigation
- Data files must be placed in the same directory as executables
- Programs use standard C++ libraries only (no external dependencies)
- Each system is self-contained and runs independently

---

*This collection represents a complete portfolio of real-world C++ management system applications, showcasing the ability to design, implement, and deliver functional software solutions. Developed as part of Programming Fundamentals coursework.*
