# get_next_line

resources:

1. https://softwareengineering.stackexchange.com/questions/163931/is-using-a-bigger-buffer-useful    -Explanation on buffer size.

   Q. Is using a bigger buffer useful?
   "I use buffer for quite a long time when I need to copy a stream or read a file.And every time I set my buffer size to 2048 or 1024, but from my point of view a buffer is like a "bucket" which carries my "sand" (stream) from one part of my land (memory) to an other part. So, increase my bucket capacity will in theory allow me to do less travel? Is this a good things to do in programming?"
   "A. A bigger buffer will always make transfers faster... right up until it gets big enough that it breaks your cache, and then things get slow again. You really need to measure this."
   
   "Also make sure your "bucket" is not smaller than your "shovel." For example, a disk i/o buffer which is much smaller than your cluster size means rereading the same hard disk clusters over and over again, like filling a thimble with a shovel and then dumping most of the sand back onto the beach."
   
   "Let's pretend you are copying a data structure from one file to another, and you use a buffer to store the data between the time you read it and the time you write it.
  There is an overhead when you read and write data. On disk, the head has to find the sector and read or write the track. In memory, it takes a processor instruction to move a chunk of memory (usually 1-8 bytes at a time) plus a bus operation to move data from one part of memory to another, or between memory and the processor or memory and disk. Each chunk that you read is processed in a loop somewhere and the smaller the chunks, the more times the loop has to be executed.
  If your buffer is a single byte, you will incur this overhead every time you read or write a byte of data. In our example, the disk can't read and write simultaneously, so the write may have to wait until the read is finished. For a one-byte file, this is the best you can do, but for a 1MB file, this will be extremely slow.
  If you have a 10MB buffer and want to copy a 10MB file, you can read the whole thing into your buffer, then write it all out again in one step.
  Now, if you want to copy a 20GB file, you probably don't have that much memory. Even if you do, if every program allocated 20GB of memory for buffers, there wouldn't be anything left! When you allocate memory, you have to release it, and both the allocation and release can take time.
  If a client of some kind is waiting for whole chunks of data, sometimes smaller chunks are better. If the client gets a few chunks and knows they don't want the rest, they can abort, or maybe they can display what they have while waiting for more so that a human user can see that something is going on.
  If you know the amount of data you are copying before you have to allocate your buffer, you can make a buffer that's the ideal size for the data you are copying. Either the exact size of all your data, or big enough for the data to be copied in a reasonable number of chunks. If you have to guess, some size around 1MB is reasonable for an unknown purpose.
  To create the perfect sized buffer, you need to study the data that you are going to use it for. If you are copying files, how big are most of the files people copy? Then you guess at a good buffer size and time it. Tweak the size and time it again. Your total available memory may limit your maximum size. Eventually you arrive at the ideal buffer size for your specific goal."

2. https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/           -Explanation on read function and file descriptor
3. https://stackoverflow.com/questions/14272083/initialize-static-char-const-somevar                 -Explanation on constant pointer to constant data
4. https://www.linuxtopia.org/online_books/programming_books/thinking_in_c++/Chapter10_002.html      -Explanation on diff btwn static and local variable
5. https://www.geeksforgeeks.org/static-variables-in-c/#:~:text=Static%20variables%20have%20a%20property,again%20in%20the%20new%20scope   -Explanation about staic variables.
6. https://www.geeksforgeeks.org/memory-layout-of-c-program/                                         -Explanation on memory layout of c program
    to check memory layout in terminal type : size ./a.out
7. https://www.geeksforgeeks.org/g-fact-80/  -Explanation on why a static variable cannot initialized by a function call.
8. https://www.geeksforgeeks.org/what-are-static-functions-in-c/                                     -Explanation on static function.
