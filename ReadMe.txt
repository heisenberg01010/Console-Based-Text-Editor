######
ReadMe for assignment submitted by 2019B1PS0946P
Practical section number: P8
Assignment question attempted: 4
######
Team:
1. 2019B1PS0946P Siddham Jasoria
2. 2019A5PS1058P Debojita Saha
3. 2019D2TS1282P Vidhi Bhardwaj
######
Description of the program:
The attached code is for a text editor program in C language. It is a menu driven application.
It performs the essential functions of creating new file,deleting,copying,editing
and renaming existing files and also has word search. Will also ....
1.
2.
3.When you run the program it will first diplay a menu page with nine function options. The user is prompted for a choice.
4.The first choice 'New' prompts the user for the name of a file to be created. After entering the file name the user can input the content of the file.
  A sequence of esc and enter key saves the file and the content. Tab and enter key deletes the newly created file along with the contents. 
5.The second choice 'View' prompts the user for a file name. If the file entered exists, the content of the file is displayed. In case an invalid file name is
  entered an error message is displyed and menu page is refreshed.
6.The third choice 'Copy' allows the user to copy the contents of one file to another file. The user is prompted for name of exisitng file and name of the new file. 
  The content of the previous file is then copied on to the new file.
7.The fourth choice 'Delete' allows the user to delete an existing file along with its content. 
8.The fifth choice 'Comparison' is to compare the contents of two files and check wether they are identical or not. In case the files are not identical, an appropriate
  message along with first dissimilarity is displayed.
9.The sixth choice 'Edit' allows the user to append to the file or delete a word. The user is prompted to choose between appending and deleting.
  Append option displays the content of the file and the user can write more, accordingly. Esc and enter key sequence allows user to save the changes.
  Delete option is very specific and prompts the user for word as well as line number from which it is to be deleted. If the word is deleted succesfully a
  appropriate message is displayed.
10.The seventh choice 'Save as' is used to rename a file. The user is propmted for existing file name and new name to be changed to. The task is completed 
   using built in c function.
11.The eighth choice 'Find' can be used to find the occurrence of a word in a file. The user is prompted for file name and word. The occurrences of the word is then
   displayed highlighted along with the lines and line numbers of its postion.
12.The ninth choice 'Exit' is used to terminate the program.
13. In case a file does not exist or does not have read and write privileges. An appropriate message is displayed and menu page is refreshed.
######
Limitations:
All the requirements given in the question have been completed by our team as best as possible. Some of the limitations are:
1.The Edit function does not allow flexible editing by the user. It requires specification of word and line number from which the word has to be deleted.
  New text can be added only to the end of the document. Text cannot be added in the middle of the document. New text added is always considered a new line and
  not continuation of previous line.
2. File name should not have spaces in between. 
######
Contributions:
1.Siddham: Code for View,Comparison,Save as,Find and Edit(Append)functions
2.Debojita: Code for Remove and Erase text functions, comments and editing the code
3.Vidhi: Code for Main body,New and Copy functions.   
    
 