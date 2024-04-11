## Project description/requirements

1. Write a function that returns the next line from a file.

2. Multiple calls should ge the next line.

3. Should return NULL if there is nothing else to read or if an error occured.

4. Got a specific buffer which could be smaller or bigger than the line.

<!-- Process -->

1. Read into temporary buffer.
2. Join permanent buffer + temporary buffer.
3. Check for newline in permanent buffer.
4. If no newline, go back to 1. --- sounds like end of loop? ---
5. If newline copy permanent buffer to "current line" up to newline. --- sounds like break from loop---
6. Move the rest of the line to a tmp_storage.
7. Free the permanent buffer.
8. Cp tmp storage to permanent buffer.
9. Free tmp storage.
