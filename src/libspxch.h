/*
      Command Line Handler - Distributable and Library version

    Single file
         Coded by: Spixa
  Sourcecode repository for GitHub on Spixa
  For education purposes only.



*/
// THIS CODE IS "NOT" C FRIENDLY
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
// Command Handle Class
class CommandHandle {
public:

        CommandHandle(std::string load) {
                std::ifstream file;
                std::string buff;
		
		file.open(load);
		if (!(file.is_open())) {
			if (load == "") load = "a non-existing file";
			std::cout << "I couldn't open command data.\n\tCouldn't open " << load << '\n';
			return;
		}
                while (file >> buff) {
                        commands.push_back(buff);


                }


                for (long unsigned int i = 0;i < commands.size();i++ ) {
                 std::cout << "Loaded command: " << commands[i] << std::endl;
               }
                file.close();
        }
//      const static unsigned int m_args = 256;
    std::vector<std::string> commands;


    std::string access(std::string str,int accint) {
            std::string args[256];
            process(str,args);

        for (long unsigned int i = 0; i < commands.size();i++) {
                if (args[0]  == commands[i]) {
                     return args[accint];
                }

        }
        return "$unhandled";

    }
        std::string getLastBuffer() {return last_buffer;} // Gets last buffer.

private:
     void process(std::string str, std::string  arg[])
        {
                std::string word = "";
                int i = 0;
                for (auto x : str)
                {
                        if (x == ' ')
                        {
                                i++;
                                arg[i] = word;

                                word = "";
                        }
                        else
                        {
                                word = word += x;
                        }

                        arg[i] = word;
                }
        }






        std::string last_buffer;
        // Wiki & Doc error: last_buffer is within a private context. Use the getter function
};
