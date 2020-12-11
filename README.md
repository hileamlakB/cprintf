##  cprintf 

<br>
### Description


### Files :page_with_curl:

* [printer.c](./printer)
	* In this file, there is the printer function which works like a normal printer. This function inside 'printer.c' is a wrapper around the `write` system call inorder to make as small as `math.upper((length of string / 1024))` system calls to the kernal.
