studio 19 answers here
1. Veda, Ellie, Sophie
2. To test this we created a vector toWrite that contains a,b,c,z then created a new textFile and used the write function to write in the vector we created. We then save the result of the read function into a vector readIn. Then we edited toWrite by adding y and called write on the textFile. We saved the return of read as a vector called “updated” then printed both readIn and Updated using the for loop. This created an output of 
a b c z
a b c z y
As expected
3. We drew our interaction diagram on the board with Jordan shown below

	TextFile	ImageFile						BasicDisplayVisitor
		tf		it										v
		|		|										|
		|		|										|
		|  TextFile:accept(v)							|
		b --------------------------------------------->b
		o BasiciDisplay: visit_TextFile(tf)	            o
		x <---------------------------------------------x
		|		|										|
		|		|										|
		|		|										|
		|		|	ImageFile:accept(v)					|
		|		b ------------------------------------->b
		|		o BasiciDisplay: visit_ImageFile(it)	o
		|		x <-------------------------------------x			
		|		|										|
		|		|										|


4. By using delegation, the visitor pattern does not modify the interface much, reducing clutter.
5. You have to manually define the implementation for each type so if you have a lot of file types it’s a lot of extra work.
