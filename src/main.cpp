#include "libspxch.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
        string t;

        string command;
        string token1;
        string token2;


        CommandHandle c("file.cmdlist");
        cout << "\n\n";
        while(true) {
                cout << "Open Command: ";
                getline(cin,t);

                command = c.access(t,0);
                token1 = c.access(t,1);
                token2 = c.access(t,2);

                for (long unsigned int i = 0;i < c.commands.size();i++) {
                        if (c.commands[i] == command) {
                                std::cout << "Command index: " << i << endl;
                                break;
                        }

                }

                if (command == "do") {
                        if (token1 == "say") {
                                cout << token2 << endl; // Prints the second argument of "do say [text]". Add "do" to file.cmdlist to make this work.
                        }
                } else

                if (command == "$unhandled") {
                        cout << "Command wasn't found\n\n";
                }
        }
}
