studio 18 answers here
Q1 Veda Bhalla, Ellie Ertl, Sophie Schochet

Q2 It would be fairly straightforward to create new file systems that create different file types than the SimpleFileSystem because each system defines their own createFile method. However, if we wanted to add a new concrete file type to each file system, it would be a lot more tedious because we would have to modify the code in each system’s createFile method to add the new file type. 

Q3 One of the disadvantages of having a factory is that it’s a little bit more work on the client side of things. However, it greatly simplifies our file system and allows it to only have one responsibility. We would want to create a new concrete file factory system whenever we create a new concrete file system that uses a different set of files. If two systems use the same types of files, then we can reuse the factory system. If they take different files, we would likely need to make different factories in case one type of file is allowed in one system but not the other.

Q4 We tested creating a new valid file using the file factory. We then added this file to a simple file system and tested opening it. While it was open, we were able to read and write from the file. We then closed and reopened the file, and finally were able to delete it. We also tested creating invalid files (with invalid extensions) in the factory. It would return a nullptr, which is the expected behavior from our program.

Q5 At this point, SimpleFileSystem only depends on the AbstractFileSystem interface. If we wanted to change the types of files that a system accepts, we would change the file factory and allow it to accept another file extension. This removes all dependencies from the SimpleFileSystem
