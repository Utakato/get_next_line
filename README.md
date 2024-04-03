STATIC - line



read into buffer.
if read 0 
	if line
		return line
	return null

if no line
	duplicate buffer

if no \n
	join buffer and line

if \n
	join substr buffer and line
	return line.


valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose test