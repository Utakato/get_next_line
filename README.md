## Project description/requirements

1. Write a function that returns the next line from a file.

2. Multiple calls should ge the next line.

3. Should return NULL if there is nothing else to read or if an error occured.

4. Got a specific buffer which could be smaller or bigger than the line.

<!-- Pseudo code -->

1. Read to buffer.
2. Buffer to line until \n.
3. if no \n -> go back to 1.
4. if \n ->

<!--  -->

1. Fill line until \n or \0 is found
2. Once filled we go set_line.
3. Return line, and set the rest into left_C

Fill_line.
Left C

We always duplicate buffer into left_c. if there is some chars in left_c, we append.

when \n is found it will break out returning left_c.
