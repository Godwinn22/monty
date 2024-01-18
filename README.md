# Monty: A Simple Stack-Based Interpreter in C

![Monty Logo](./img/monty.png)

Monty is a minimalist yet powerful stack-based interpreter written in C. This project is designed to provide a straightforward and efficient environment for executing Monty Bytecode files, allowing users to explore the world of stack-based programming.

## Table of Contents

- [Key Features](#key-features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)
- [Compilation $ Output](#compilation--output)

## Key Features

- **Simple and Intuitive:** Monty embraces simplicity, making it an ideal platform for learning stack-based programming concepts.
- **Efficient Stack Operations:** The interpreter supports a variety of stack operations, including push, pop, swap, and arithmetic operations, enabling versatile programming paradigms.
- **Extensible and Customizable:** Monty is easily extensible, allowing users to integrate their own stack operations and customize the interpreter to meet specific project requirements.

## Getting Started

### Prerequisites

Before you begin, ensure you have met the following requirements:

- A C compiler (e.g., GCC)
- Make utility

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/monty.git
2. Build the interpreter:
   
	make
## Usage

Usage: <span style="color:#c94949;">monty file</span>
- where file is the path to the file containing Monty byte code

If the user does not give any file or more than one argument to your program, print the error message
- <span style="color:#c94949;">USAGE: monty file</span>, followed by a new line, and exit with the status <span style="color:#c94949;">EXIT_FAILURE</span>

If, for any reason, it’s not possible to open the file, print the error message <span style="color:#c94949;">Error: Can't open file</span> <file>, followed by a new line, and exit with the status <span style="color:#c94949;">EXIT_FAILURE</span>
where <span style="color:#c94949;">file</span> is the name of the file

If the file contains an invalid instruction, print the error message <span style="color:#c94949;">L<line_number>: unknown instruction</span> <span style="color:#c94949;">opcode</span>, followed by a new line, and exit with the status <span style="color:#c94949;">EXIT_FAILURE</span>
where is the line number where the instruction appears.
Line numbers always start at 1

The monty program runs the bytecodes line by line and stop if either:
it executed properly every line of the file
it finds an error in the file
an error occured

If you can’t malloc anymore, print the error message <span style="color:#c94949;">Error: malloc failed</span>, followed by a new line, and exit with status <span style="color:#c94949;">EXIT_FAILURE</span>.

You have to use <span style="color:#c94949;">malloc</span> and <span style="color:#c94949;">free</span> and are not allowed to use any other function from <span style="color:#c94949;">man malloc</span> (realloc, calloc, …)
Execute Monty Bytecode files using the following command:

	./monty filename.m

Replace filename.m with the path to your Monty Bytecode file.

Explore the power of stack-based programming with Monty and unlock a new dimension of coding simplicity and elegance.

## Compilation & Output
Your code will be compiled this way:

	$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
Any output must be printed on stdout
Any error message must be printed on stderr

[Here is a link to a GitHub repository](https://github.com/ku1ik/stderred) that could help you making sure your errors are printed on stderr

## Contributing
Contributions are welcome! Please follow these guidelines:

Fork the repository.
Create a new branch:

	git checkout -b feature/new-feature.
Make your changes and commit them:

	git commit -m 'Add new feature'.
Push to the branch:

	git push origin feature/new-feature.
Submit a pull request.
For major changes, please open an issue first to discuss your ideas.
