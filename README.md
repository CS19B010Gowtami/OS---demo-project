# OS---demo-project
OS DEMO PROJECT REPORT
Team 9:
CS19B008 B Roopa Sree
CS19B010 Ch Gowtami
CS19B011 D P Sahithi Rani
CS19B046 Githin George

Brief description of the project:
	To create a program that displays the values of three variables x, y, and z according to the user permissions set by the admin. 

Implementation:

The 3 main components of implementation are listed below.
Source Code:
We wrote a program that tries to access values from 3 files “X.txt”, “Y.txt”, 	“Z.txt”. The code simply tries to open the files with respective permissions. If Permission is not available, then the open system call returns -1 and does necessary handling.
System Calls used in the program:
open
close
read
write
lseek


System Commands:

Create Users
adduser
Remove Users
rmuser
Login Users
Type exit command and the terminal will automatically show option to login
or
su -l <username>
Logout Users
exit  or su -l <username> 
Add User to Group
pw usermod <username> -G <groupname> 
Change permissions
chmod u=rwx,g+rx,o-r <filename>
List file permissions in a directory
ls -l
Change group of a file or directory
chgrp <groupname> <Dir/Filename>
Change owner of a file or directory
chown <ownername> <Dir/Filename>


User Management:
User Management from an administrator account is very important. 
As of currently, we are using the super user permissions to add new users to the 3 file groups (filex, filey and filez). Only the users in the “filex” group can read the contents of X.txt. 
Only admin account can edit the file contents
	


User Accounts:
	
Account Name
Permissions
H
Can read x, y and z
S
Can only read x
F
Can only read y
A
Can read and write for x, y, and z


	
Program Output:
	Users can run the file demo.cpp. The program displays the value of the variable if the user has access to it and it displays an underscore in place of it otherwise. If the user has access to the variables, the program will provide an option to edit them.

 Output for user H:

H is able to read the values of x, y and z but he cannot edit them. 




       S is able to read the values of x but not y and z. S cannot edit any of x, y, and z.


 Output for user F:


         F is able to read the values of x but not y and z. F cannot edit any of x, y, and z.


Output for user A:



        
         A  is able to read the values of x, y and z and is also able to edit them.












