# Disk Analyzer

Disk Analyzer is a command line disk usage utility for mac OS.
Since the upgrade to mac OS 10.15.6 most APIs have changed and software like Disk Inventory X is not working anymore 
so I decided to write my own tool and while it's CLI and only in the beginning it works quite well and scan faster than all of the software I worked with.



## Getting Started
### How to run
1.download / clone the repository and unzip

2.cd to /cmake-build-debug/ and run `make

3. **launch the program with sudo**

#### Regarding sudo launch
as mac os very restrictive about permissions and also implemented SIP protection on the hard drive this can cause the application to fail. please make sure to run with super user to avoid any errors. 

I also defined paths in private areas of the disks to avoid because of SIP integration.


After the hard disk scan is done you will have the option to navigate from the root folder and see the sizes of every folder and file in the current directory.
 
### **commands**
* `:b` - go back to the previous directory
* `:c` - clear the screen
* `:q` - quit the program
* `:p` - print contents of the folder
* `name of folder` - change directory


### Examples



## Built With

* [Boost 1.74](https://www.boost.org/users/history/version_1_74_0.html) 


