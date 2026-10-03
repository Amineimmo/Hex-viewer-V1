# Hex Viewer

A lightweight command-line hex viewer written in C.

This project reads a file in binary mode and displays its contents in hexadecimal and printable ASCII, with 16 bytes per row.

Built as a hands-on project while studying computer systems fundamentals from *Computer Systems: A Programmer's Perspective* (CS:APP).

## Features

- Reads files in binary mode using `fopen()` and `fread()`
- Displays hexadecimal file offsets
- Processes files in 16-byte chunks
- Displays each byte in hexadecimal
- Shows printable ASCII characters alongside the hex output
- Replaces non-printable bytes with `.`
- Aligns the ASCII column for incomplete rows
- Handles empty files and invalid file paths

## Example Output

For a file containing the bytes:

```text
48 65 6C 6C 6F 00 01 09 0A 1B 7F FF 21
```

The program displays:

```text
00000000 : 48 65 6C 6C 6F 00 01 09 0A 1B 7F FF 21             | Hello.......!
```

Each output row contains:

- **Offset:** Starting byte position in the file, displayed in hexadecimal.
- **Hex:** The hexadecimal representation of the bytes.
- **ASCII:** Printable ASCII characters, with non-printable bytes replaced by dots.

## Requirements

- A C compiler (GCC recommended)
- A terminal

Developed and tested on Fedora Linux.

## Compilation

Compile the program using GCC:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o hexviewer
```

## Usage

Run the program and provide the path to a file:

```bash
./hexviewer <filename>
```

Example:

```bash
./hexviewer test.txt
```

You can also inspect binary files:

```bash
./hexviewer binary_test.bin
```

## Testing

The program was manually tested with the following cases:

| Test | Purpose |
|---|---|
| Regular text file | Verify hexadecimal and ASCII output |
| File containing non-printable bytes | Verify that non-printable bytes are replaced with dots |
| 17-byte file | Verify multiple rows and final-row alignment |
| Empty file | Verify clean handling of empty input |
| Invalid file path | Verify error handling |

## Concepts Practised

This project helped me apply several computer systems concepts:

- Binary file I/O in C
- Bytes and hexadecimal representation
- `unsigned char` and byte values
- Arrays and pointers
- Command-line arguments (`argc` and `argv`)
- Fixed-size buffers
- File offsets
- Printable versus non-printable ASCII
- Basic error handling and resource management

## Limitations

Hex Viewer is an educational project, not a replacement for established tools such as `xxd`.

Currently, it uses a fixed output width of 16 bytes per row and provides a minimal command-line interface.

## Learning Context

This project is part of my systems programming roadmap, following a first study pass through Chapters 1, 2, 3, and 9 of CS:APP.

The goal was to move from understanding bytes and memory conceptually to working with actual binary data in C.