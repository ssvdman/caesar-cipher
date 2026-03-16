A program, caesar, that encrypts messages using Caesar’s cipher.

The program accepts a single command-line argument, a non-negative integer.
If program is executed without any command-line arguments or with more than one command-line argument, program should prints an error message (with printf) and return from main a value of 1 immediately.
If any of the characters of the command-line argument is not a decimal digit, the program prints the message Usage: ./caesar key and return from main a value of 1.
The program outputs plaintext: (with two spaces but without a newline) and then prompts the user for a string of plaintext (using get_string).
The program outputs ciphertext: (with one space but without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext “rotated” by k positions; non-alphabetical characters are outputted unchanged.
The program preserves case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, remains lowercase letters.
After outputting ciphertext, it prints a newline and then exits by returning 0 from main.
