Lab 5 Readme Ellie Ertl, Veda Bhalla, Sophie Schochet

Instead of dividing up each command we worked on all together by meeting and projecting the code on the tv. Once we finished writing code we then split up debugging based on who was available during each office hours. 

Q9
We chose to implement the cat + ds command which should edit the file and display it afterward to see the edits. This would be invoked in the command prompt by: cads <filename> [-a] [-d]. The user can choose to input only -a, only -d, both, or neither. We did define the input for this file to be in a specific order; i.e., if both extensions are added, the extension for the cat command must be added before the extension for ds.  To support this MacroCommand, we had to create a new file parsing strategy that would check for how many inputs there were and determine which commands to pass them to appropriately.

To test our code we:
i. Typed help to receive a list of all commands. This gave the proper output and also ensured that all commands were added to the command prompt correctly
ii. We then tested help followed by a command for every command to ensure that the proper output was created. We received a description of what each command does and how to invoke them as expected
iii. We used touch to create files called myFirst.txt, mySecond.img, myThird.txt and then tested all commands on them by calling cat to write to myFirst then cat -a to append to it. We then called copy to clone myThird, we used both ls and ls -m to ensure the text is properly formatted, and we also called ds in between using cat on myFirst to ensure that the proper data is displayed.
iv. Created the MacroCommand, added it to the system, and ran the command prompt. We created both text and image files and tested “cads” with them. We tried writing regularly, and it correctly wrote and then displayed what had been added. Additionally, we tried all combinations of using either [-a] or [-d] with each type of file, and they worked correctly. We tried entering the extensions in an incorrect order, and the command failed, as expected. 



Some problems that we ran into include:
i. Our unit tests entering an infinite loop and not finishing properly
ii. Dealing with the password protected files - we were accidentally overprompting the user for a password
iii. We didn’t realize that everytime we open a file we need to close it again before returning success or failure codes
iv. We also needed to check the return values of adding files to the system and opening them to make sure they are actually successful before trying to use a command on it
