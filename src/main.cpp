#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#define filenamelimit 100

  char filename[filenamelimit];
  std::string checkexit = "";
  char input[1000];
  bool isoptionexit = false;
  bool option = false;
  int line = 0;
  char mode[100];
  
  
       int main(){
              std::cout << "Enter filename : ";
              std::cin.getline(filename, filenamelimit);
              std::cin.ignore();
              std::fstream file;
                   /* Lists of opening mode
                   * SELECT MODE 1 : ios::app
                   * SELECT MODE 2 : ios::ate
                   * SELECT MODE 3 : ios::out
                   * SELECT MODE 4 : ios::trunc
                   */
              while(!option){
                std::string opt  = "";
                std::cout << "Enter opening mode: ";
                std::cin.getline(mode, 100);
                if(strcmp(mode, "HELP") == 0 || strcmp(mode, "help") == 0 || strcmp(mode, "Help") == 0){
                     std::cout << "Lists of opening mode"
                                  "SELECT MODE 1 - ios::app: Write control output appended to the end"
                                  "SELECT MODE 2 - ios::ate: Open a file for output and move the write control to the end of the file. "
                                  "SELECT MODE 3 - ios::out: Open a file for reading, if the file exist, all contents will be erased"
                                  "SELECT MODE 4 - ios::trunc: If the file already exists, its contents will be truncated before opening the file";

                }
                  else if(strcmp(mode, "SELECT MODE 1") == 0){
                    file.open(filename, std::ios::app);
                    option = true;
                  }
                  else if(strcmp(mode, "SELECT MODE 2") == 0){
                    file.open(filename, std::ios::ate);
                    option = true;
                  }
                  else if(strcmp(mode, "SELECT MODE 3") == 0){
                    std::cout << "ARE YOU SURE? THIS OPTION WILL ERASE ALL DATA AND IT WILL BE UNRECOVERABLE : ";
                    std::cin >> opt;
                    if(opt == "yes" || "YES" || "Yes"){
                      file.open(filename, std::ios::out);
                      option = true;
                    }
                    else {
                      std::cout << "Exited." << std::endl;
                    }
                  }
                  else if(strcmp(mode, "SELECT MODE 4") == 0){
                    std::cout << "ARE YOU SURE? IF YOU FILE EXISTS, THIS OPTION WILL ERASE ALL DATA AND IT WILL BE UNRECOVERABLE : ";
                    std::cin >> opt;
                        if(opt == "yes" || "YES" || "Yes"){
                            file.open(filename, std::ios::trunc);
                            option = true;
                    }
                        else {
                           std::cout << "Exited." << std::endl;
                    }
                  
                  }
                  else{
                    std::cout << "Input mode doesn't match, please try again" << std::endl;
                    option = false;
                  }
              }

                  for (int z = 0; z < 4; z++){
                       input[z] = '~';
                  }
            
              while(!isoptionexit){
                line++;
                checkexit = "";
                    std::cout << "Enter line " << line << " : ";
                    std::cin.ignore();
                    std::cin.getline(input, 1000);
                    file << input << std::endl;

                     for (int i = 0; i < (sizeof(input) / sizeof(char)); i++){
                          if(input[i] != '~'){
                               checkexit = checkexit + input[i];
                           }
                           if(checkexit == "exit"){
                                isoptionexit = true;
                                break;
                    }
                }
            }
        
        std::cout << "Last line input : " << input << std::endl;
        std::cout << "-----------------Wrote " << line << " line(s)-----------------" << std::endl;
        file.close();

      return 0;
              
    }