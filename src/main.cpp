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
  std::string exitopt = "";
  
       int main(){
          back:
            system("Color A7");
            system("cls");
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
                system("Color A7");
                std::string opt  = "";
                std::cout << "Enter opening mode: ";
                std::cin.getline(mode, 100);
                if(strcmp(mode, "HELP") == 0 || strcmp(mode, "help") == 0 || strcmp(mode, "Help") == 0){
                     std::cout << "Lists of opening mode\n"
                                  "app - ios::app: Write control output appended to the end\n"
                                  "ate - ios::ate: Open a file for output and move the write control to the end of the file. \n"
                                  "out - ios::out: Open a file for writing, if the file exist, all contents will be erased\n"
                                  "trunc - ios::trunc: If the file already exists, its contents will be truncated before opening the file\n";

                }
                  else if(strcmp(mode, "app") == 0){
                    file.open(filename, std::ios::app);
                    option = true;
                  }
                  else if(strcmp(mode, "ate") == 0){
                    file.open(filename, std::ios::ate);
                    option = true;
                  }
                  else if(strcmp(mode, "out") == 0){
                    std::cout << "ARE YOU SURE? THIS OPTION WILL ERASE ALL DATA AND IT WILL BE UNRECOVERABLE : ";
                    std::cin >> opt;
                    if(opt == "yes" || opt == "YES" || opt == "Yes"){
                      file.open(filename, std::ios::out);
                      option = true;
                    }
                    else {
                      std::cout << "Exited." << std::endl;
                    }
                  }
                  else if(strcmp(mode, "trunc") == 0){
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
                    system("Color 04");
                    std::cout << "Input mode doesn't match, please try again" << std::endl;
                    option = false;
                  }
              }

              system("cls");
              system("Color 0B");
              while(!isoptionexit){
                line++;
                checkexit = "";
                    std::cout << "Enter line " << line << " : ";
                    std::cin.ignore();
                    std::cin.get(input, 1000);
                    file << input << std::endl;

                     for (int i = 0; i < 4; i++){
                            checkexit = checkexit + input[i];
                           if(checkexit == "exit"){
                                isoptionexit = true;
                    }
                }
            }
        
        std::cout << "\nLast line input : " << input << std::endl;
        std::cout << "-----------------Wrote " << line << " line(s)-----------------\n" << std::endl;
        system("Color 04");
        std::cout << "Are you sure you want to exit : ";
        std::cin >> exitopt;
        if(exitopt == "nope" || exitopt == "no" || exitopt == "NO"){
            goto back;
        }
        file.close();
      system("pause");
      return 0;
              
    }
