# libspxch
This is the library version of [Spixa-Command-Handler](https://github.com/Spixa/CommandHandler-OpenSource) that handles commands and arguments. This library allows you to load a command list from a file and be able to compile and add it to your project as a command with a collection of strings as argument sheet. You can use and manage your command afterwards as you wish.
## How to port libspxch to your project
libspxch does not contain any additional libraries and also for convenience it is all bound in a single header file.
### Link to your project
Add libspxch.h to the header file section of your compiler (e.g. _g++ main.cpp libspxch.h -o my_bin_)

## Documentation and how to use
Here you can see the basic documentation and tutorial of this library

# Documentation
***

# Load a command list
The first thing you need to do is to load the command list. You can set the command-list file in the CommandHandle class constructor:

`CommandHandle c("my_command_list.txt")`

## Command list file:
Commands are divided by a whitespace. A command list file will look like this:  
help info test_command another_command   
  
In the example at /src/main.cpp you can see how it works in action.

# Get user input and divide the input by whitespace
When you get a user input from a user using `std::getline(std::cin, myString)` it reads everything the user has inputted and saves them to `myString`, however in libspxch you can solve the string into: 
* The command 
* The argument sheet

***

The way you do that is by using the access function from the CommandHandle class.
Let's solve the input "say hello":  
> std::string command,arg1 // The buffers for the command and the first argument.  
> CommandHandle handle("cmds.txt"); // Note: cmds.txt should contain the "say" command.  
> command = handle.access(user_Input,0) // returns the command  
> arg1 = handle.access(user_Input,1) // returns the first argument  

You can add a for loop which checks if the command exists in the cmds.txt (the whole purpose of the file, right?)  

> for (long unsigned int i = 0;i < c.commands.size();i++) {  
>                           if (c.commands[i] == command) {  
>                                 std::cout << "Command index: " << i << endl;  
>                                 break;  
>                         }  

  
When you add this for loop if the command didn't exist in the cmds.txt it will return: `$unhandled`  
You can use an if statement that checks if `command` is equals to `"$unhandled"` and that means user has inputted a non-existing command  

***
# Make use of commands
Now after we have set up all the good stuff, we can make use of this library, and that is by checking the value of "command" and token (argument 1) "arg1"  
