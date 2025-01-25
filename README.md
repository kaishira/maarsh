# Maarsh

This project contains a C program designed as a **malicious software sample** for educational and research purposes. The program demonstrates how malicious code can replicate itself.

> **Disclaimer:** This software is intended for academic and research purposes only. Unauthorized use of this code in any malicious activity is strictly prohibited and may be illegal. Use responsibly.

Read my blog post about this repository: [Computer Viruses in Practice: Self-Replication](https://kaishira.com/2025/01/25/computer-viruses-in-practice-self-replication/)

## Features

- Iterates through all files in the current working directory.
- Creates a `.c` file with malicious predefined content for each file.
- Compiles the `.c` file into an executable using GCC.
- Deletes the generated `.c` file after compilation.

## Malicious Payload
The program generates a `.c` file with the following payload:

```c
#include <stdio.h>
int main() {
    printf("You are stupid!\n");
    return 0;
}
```

## How It Works
1. Scans all files in the current directory.
2. Skips `.` and `..` entries.
3. Generates a `.c` file for each filename, appending the `.c` extension.
4. Inserts the malicious payload into the newly created file.
5. Compiles the `.c` file into an executable using GCC:
   - On Windows: Creates a `.exe` file.
   - On Linux/Unix: Creates a binary file without an extension.
6. Deletes the `.c` file after compilation.

## Usage
### Prerequisites
- GCC installed on your system.
- A directory containing files to process.

### Steps
1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd <repository_name>
   ```
2. Compile the program:
   ```bash
   gcc -o maarsh maarsh.c
   ```
3. Run the executable:
   ```bash
   ./maarsh
   ```
4. Malicious executables will be created for each file in the current directory.

## Notes
- The generated payload can be modified to simulate different types of malicious behavior.
- This program is for research and educational purposes only. Ensure you have the proper authorization before executing it.

## Disclaimer
This software is strictly for **educational and research purposes only**. Any misuse of this program in malicious activities is unethical and may result in legal consequences. The author is not responsible for any damage caused by the use or misuse of this software.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Author
Kaishira
