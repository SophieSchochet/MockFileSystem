Answer studio 16 questions here
1. Veda Bhalla, Sophie Schochet, Ellie Ertl

2. To declare an interface in C++, you need an abstract class that uses pure virtual functions because there is no interface
keyword like there is in Java. You do not define the implementation in the interface declaration.

3. 
	A. This is an example of interface inheritance because we are using pure virtual functions and only inheriting 
	the interface, defining our own implementation.
	B. The member variables could be private or protected because you want the least access. But, in this case we will 
	choose private because there's not a valid reason to use protected.

4. First, we tried just writing 'hi' to a file. It printed out as 'hi', which is what we expected given our implementation.
Then, we tried entering a blank file name. This gave an error since no constructor matched, which was expected behavior. Next, 
we wrote 'hi' to the file, printed it, and then wrote 'bye' and printed it. As expected, the final output was only 'bye' because
'hi' was overwritten, as our method defined. When we read the size of the file, it returned the correct size (2). Then, when we 
tested append by adding "world", it correctly printed out the expected results. 

5. 
	A. To avoid using a concrete file type, we called the functions on a pointer to an abstract file. We initialized this pointer 
	   to point to the TextFile that we created. 
	   Code for our main function: 
	    TextFile file = TextFile("tester");
		AbstractFile* filePtr = &file;
		vector<char> writeIn;
		writeIn.push_back('h');
		writeIn.push_back('i');
		filePtr->write(writeIn);
		cout << "Reading..." << endl;
		filePtr->read();
		return 0;