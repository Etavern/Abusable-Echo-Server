# Abusable-Echo-Server
School project to abuse a C Echo Server. 

## Files

- echo-server.out is the echo server to run
- fixed-echo-server.out is the fixed version (strcpy -> strncpy)
- client.py takes a string and a number; send string * num to echo-server
- overflow-* are the different payloads to use
- paylods.py sends a file (one of the overflows) to the echo server
- screenshots of the execution included
- Notes contains the Shellcode that was used as well as some notes made while working on this; memory locations and such. 
