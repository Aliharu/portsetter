Portsetter Project CS 3370

I used g++ portsetter.cpp -o portsetter.cpp.o to create the file

Then either setport -p 5000 or portsetter.cpp.o -p 5000 to run the program (setport works if you have set the alias)

To add alias to the project go to the .bash_aliases page and add "portsetter.cpp.o"=setport to the bottom of the list
Open the .bash_aliases file
-open a terminal in your workspace
-type: cd ~
-type: ls -a
-click on .bash_aliases and open it

Supported Languages: English and Spanish

---
##Recent Changes
Added support for command
> setport -p --environment [PORT_VAR]

> setport --port --environment [PORT_VAR]

where PORT_VAR is the name of the envar that the port number is listed on.