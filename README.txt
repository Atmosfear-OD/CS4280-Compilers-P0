> This is the first program for the cumulative compiler project.
> This program can be build through the provided makefile. >> Use command 'make P0'
> Once built, there are three ways to start the program:
1) Passing a file >> Note - Do not specify extension. The extension .sp2021 will be attached during execution
	 ./P0 fileName
2) Redirecting file >> Note - When redirecting, state the extension
	./P0 < fileName.ext
3) Keyboard input >> Note - When finished typing input, press ctrl+d to end (...may have to press twice)
	./P0

IMPORTANT: Only strings are acceptable input, anything else will throw an error

> The program will then build a Binary Search Tree with the string input and then traverse the BST inorder, postorder, and preorder
> These traversals will then be written to output files
Note - Keyboard and redirection input will create output files named output.inorder, output.preorder, and output.postorder
       Passing a file will create output files named fileName.inorder, fileName.preorder, and fileName.postorder   
> To clean the output files and the .o files, use command 'make clean'
