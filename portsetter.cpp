//Chris Dron
//Portsetter Part 1
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstdlib>
#include <string.h>
#include <locale> 
using namespace std;
void usage();
void about();
void printResults(int port);
string getLang();
const int MAX_PORT = 65000;
//g++ portsetter.cpp -o portsetter.cpp.o
//setport -p 5000
//Main project fuction
//Will do all but print the usage in this project
int main(int argc, char *args[])
{
	//If too many arguments
	if (argc > 4) {
		cout << "Error: Too many arguments" << endl;
		usage();
		cout << "Error Code: 1" << endl;
		return 1;
	}
	//if no input
	if(argc == 1){
		cout << "No Input" << endl;
		usage();
		return 0;
	}
	string flag = args[1];
	if (argc == 2) {
		if (flag == "-h" || flag == "--help" || flag == "-?") {
			usage();
			return 0;
		}
		else if(flag == "-v" || flag == "--version"){
			cout << "Version 1.2" << endl;
			return 0;
		}
		else if(flag == "-!" || flag == "--about"){
			about();
			return 0;
		}
		else {
			cout << "Error: Too few arguments" << endl;
			usage();
			cout << "Error Code: 2" << endl;
			return 2;
		}
	}
	string eflag = args[2];
	if(argc == 4){
		if(flag == "-p" || flag == "--port"){
			if(eflag == "-e"){
				char* port = args[3];
				if(const char* env_p = std::getenv(port)) std::cout << "Your PATH is: " << env_p << '\n';
				return 0;
			}
			cout << "Error: Incorrect input" << endl;
			usage();
			cout << "Error Code: 3" << endl;
			return 3;
			}
		cout << "Error: Too many arguments" << endl;
		usage();
		cout << "Error Code: 1" << endl;
		return 1;
		}
	int port = atoi(args[2]);
	if((flag == "-p" || flag == "--port") && eflag == "-e"){
		if(const char* env_p = std::getenv("PORT")) std::cout << "Your PATH is: " << env_p << '\n';
		return 0;
	}
	if (flag != "-p" && flag != "--port" && flag != "-?" || port == 0){
		cout << "Error: Incorrect input" << endl;
		usage();
		cout << "Error Code: 3" << endl;
		return 3;
	}
	if (port < 1 || port > MAX_PORT) {
		cout << "Error: Port out of Bounds" << endl;
		usage();
		cout << "Error Code: 4" << endl;
		return 4;
	}
	
	printResults(port);
	return 0;
}
//Usage Function
//Prints proper usage to command line
void usage() {
	//cout << "Usage: (-p or --port) [Number between 1 and 65000]" << endl;
  string lang = getLang();
  string line;
  string fileName = "portsetter.usage_" + lang + ".txt";
  ifstream usageFile(fileName.c_str());
  if (usageFile.is_open()){
    while ( getline (usageFile,line) ){
      cout << line << '\n';
    }
    usageFile.close();
  }

  else cout << "Unable to open file"; 
}
void about(){
	//cout << "About stuff";
	string line;
	string lang = getLang();
	string fileName = "portsetter.about_" + lang + ".txt";
	ifstream aboutFile(fileName.c_str());
	if (aboutFile.is_open()){
	    while ( getline (aboutFile,line) ){
	      cout << line << endl;
	    }
	    aboutFile.close();
	  }

  else cout << "Unable to open file"; 
}
string getLang(){
	const char* language = std::getenv("LANGUAGE");
	if(language== NULL || strcmp(language, "C.UTF-8") == 0 || strcmp(language, "") == 0 || strcmp(language, "C") == 0) language = std::getenv("LC_ALL");
	if(language== NULL || strcmp(language, "C.UTF-8") == 0 || strcmp(language, "") == 0 || strcmp(language, "C") == 0) language = std::getenv("LC_Messages");
	if(language== NULL || strcmp(language, "C.UTF-8") == 0 || strcmp(language, "") == 0 || strcmp(language, "C") == 0) language = std::getenv("LANG");
	if(language== NULL || strcmp(language, "C.UTF-8") == 0 || strcmp(language, "") == 0 || strcmp(language, "C") == 0){
		cout << "Defaulting to English" << endl;
		language = "en";
		return language;
	}
	string output(language);
	if(!isalpha(output[0]) || !isalpha(output[1])|| !isupper(output[0]) || !isupper(output[1])){
		cout << "Incorrect Language Syntax Defaulting to english" << endl;
		output = "en";
		return output;
	}
	if(!output.size() != 2 && !output.size() != 5 && !output.size() != 8 && !output.size() != 11){
		cout << "Incorrect Language Syntax Defaulting to english" << endl;
		output = "en";
		return output;
	}
	if(output.size() == 5){
		if(!output[3] != '_' || !isalpha(output[4]) || !isalpha(output[5])|| !islower(output[4]) || !islower(output[5])){
			cout << "Incorrect Language Syntax Defaulting to english" << endl;
			output = "en";
			return output;
		}
		
	}
	if(output.size() == 8){
		if(output.substr(3,8) != ".UTF-8"){
			cout << "Incorrect Language Syntax Defaulting to english" << endl;
			output = "en";
			return output;
		}
	}
	if(output.size() == 11){
		if(!output[3] != '_' || !isalpha(output[4]) || !isalpha(output[5])|| !islower(output[4]) || !islower(output[5])){
			cout << "Incorrect Language Syntax Defaulting to english" << endl;
			output = "en";
			return output;
		}
		if(output.substr(6,11) != ".UTF-8"){
			cout << "Incorrect Language Syntax Defaulting to english" << endl;
			output = "en";
			return output;
		}
	}
	if(!output.find("es") && !output.find("en")){
		cout << "Language Not supported, Defaulting to English" << endl;
		output = "en";
	}
	output = output.substr(0,2);
	if(!output.find("es") && !output.find("en")){
		cout << "Language Not supported, Defaulting to English" << endl;
		output = "en";
	}
	//cout << output<< endl;
	return output;
}
void printResults(int port){

  string lang = getLang();
  string line;
  string fileName = "portsetter.listening_" + lang + ".txt";
  ifstream usageFile(fileName.c_str());
  if (usageFile.is_open()){
    while ( getline (usageFile,line) ){
      cout << line << port << endl;
    }
    usageFile.close();
  }

  else cout << "Unable to open file"; 
}