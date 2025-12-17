*This project has been created as part of the 42 curriculum by <your_login>.*

# Minitalk

## Description

**Minitalk** is a client-server communication project written in C, using only UNIX signals (`SIGUSR1` and `SIGUSR2`) to transmit data between two processes.

The server prints its PID and waits for incoming messages.  
The client sends a string to the server by encoding each character bit by bit and transmitting those bits using signals.

The purpose of this project is to understand:
- UNIX signal handling
- Inter-process communication (IPC)
- Bitwise data encoding
- Process synchronization

## Instructions

### Compilation

From the root of the repository, compile the project with:

make

open two terminals,
run the ./server first
in the other term, run ./client with the pid and the string to copy.
