Linux Log Analyzer (C++)
A C++ based Linux security project that analyzes authentication logs to detect suspicious repeated failed login attempts.
Features

Reads Linux authentication log files
Detects failed login attempts
Counts failed attempts using hashing (unordered_map)
Flags suspicious IP addresses after repeated failures
Generates suspicious IP report automatically

Technologies Used

C++
File Handling
Hashing (unordered_map)
Linux Log Analysis
Cyber Security Basics

Sample Output
Suspicious Login Attempt Analysis
IP Address: 10.0.0.5 | Failed Attempts: 1
IP Address: 192.168.1.10 | Failed Attempts: 3 --> Suspicious
