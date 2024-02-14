Project Title: Player Database Management System

Description:The Player Database Management System is a comprehensive Modern C++ project designed for efficient management of player records within a sports organization. Key features include:
1. Move Semantics:

Efficient resource management is ensured through move semantics, notably in the String class, which features a move constructor and move assignment operator. This optimization minimizes unnecessary deep copies and improves performance.

2. Custom String Class:

The custom String class includes a move constructor and move assignment operator, in addition to copy constructor, copy assignment operator, and destructor. These features contribute to effective memory management and resource cleanup.

3. File Handling:

File handling is utilized to maintain logs of system activities and database operations. Logs are stored in .txt files (log.txt, Database.txt), ensuring persistent data storage and easy event tracking.
Database Record Management:

The Database class offers functionalities for insertion, deletion, and updating of player records. Each operation logs the action along with the timestamp and user action (insertion, deletion, or update) into the Database.txt file.

4. Log in and Log out Functionality:

User authentication is facilitated through log in and log out functionalities. Timestamps are logged upon successful log in and log out events, providing an audit trail of user activities.

5. Date and Time Management:

Date and time management is implemented using the Timer class, which logs timestamps for various system events, including database operations, log in, and log out actions.

6. Exception Handling:

Exception handling is incorporated throughout the project, particularly in the Date class for handling out-of-range errors, ensuring robust error management and program stability.

7. STL (Standard Template Library) Usage:

Various STL components, such as std::vector, are employed for managing player data within the Database class, demonstrating effective use of standard library containers for dynamic data storage.

8. Object-Oriented Programming (OOP):

Strong OOP principles are followed with classes like Player, Database, Log, Timer, and Date, encapsulating data and behavior to promote code organization, reusability, and maintainability.

My project has functionalities, including the use of move semantics in the String class, own custom String class, along with database record management, log in and log out functionalities, time and date management, exception handling, STL usage, and object-oriented programming principles.
