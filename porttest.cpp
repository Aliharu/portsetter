//Chris Dron
//Portsetter Part 1
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
//g++ porttest.cpp -o porttest.cpp.o
int main(int argc, char *args[])
{
    cout << "Test -p 4040" << endl;
    int result = system("./portsetter.cpp.o -p 4040")/256;
    if (result != 0)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" <<endl;
    
    cout  << endl << "Test (no input)" << endl;
    result = system("./portsetter.cpp.o")/256;
    if (result != 0)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful";
    
    cout << endl << "Test --port 4040" << endl;
    result = system("./portsetter.cpp.o --port 4040")/256;
    if (result != 0)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" <<endl;
    
    cout << endl << "Test -h" << endl;
    result = system("./portsetter.cpp.o -h ")/256;
    if (result != 0)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test --help" << endl;
    result = system("./portsetter.cpp.o --help ")/256;
    if (result != 0)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -p -e" << endl;
    result = system("./portsetter.cpp.o -p -e")/256;
    if (result != 0)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -p -e PORT" << endl;
    result = system("./portsetter.cpp.o -p -e PORT")/256;
    if (result != 0)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -?" << endl;
    result = system("./portsetter.cpp.o -?")/256;
    if (result != 0)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -!" << endl;
    result = system("./portsetter.cpp.o -!")/256;
    if (result != 0)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    //Sad Cases
    /*setport help 			-1pt
    setport -help  	    	-1pt
    setport --h  			-1pt
    setport -h --help 		-1pt
    setport -hs 			-1pt
    setport -p --port 9 	-1pt
    setport -p 77 33 		-1pt
    setport -p -21 	    	-1pt
    setport -p 0 			-1pt
    setport --port  		-1pt
    setport -p 90642 		-1pt
    setport -x 45321 		-1pt
    setport -P 714 */

    cout << endl << "Test help" << endl;
    result = system("./portsetter.cpp.o -help ")/256;
    if (result != 2)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -help" << endl;
    result = system("./portsetter.cpp.o -help")/256;
    if (result != 2)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test --h" << endl;
    result = system("./portsetter.cpp.o --h ")/256;
    if (result != 2)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -h --help" << endl;
    result = system("./portsetter.cpp.o -h --help ")/256;
    if (result != 3)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    
    cout << endl << "Test -hs" << endl;
    result = system("./portsetter.cpp.o -hs ")/256;
    if (result != 2)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -p --port 9" << endl;
    result = system("./portsetter.cpp.o -p --port 9")/256;
    if (result != 1)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -p 77 33" << endl;
    result = system("./portsetter.cpp.o -p 77 33")/256;
    if (result != 1)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -p -21" << endl;
    result = system("./portsetter.cpp.o -p -21")/256;
    if (result != 4)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -p 0" << endl;
    result = system("./portsetter.cpp.o -p 0")/256;
    if (result != 3)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test --port" << endl;
    result = system("./portsetter.cpp.o --port")/256;
    if (result != 2)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -p 90642" << endl;
    result = system("./portsetter.cpp.o -p 90642")/256;
    if (result != 4)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -x 45321" << endl;
    result = system("./portsetter.cpp.o -x 45321")/256;
    if (result != 3)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -P 714" << endl;
    result = system("./portsetter.cpp.o -P 714")/256;
    if (result != 3)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;
    
    cout << endl << "Test -p -e junk" << endl;
    result = system("./portsetter.cpp.o -P 714")/256;
    if (result != 3)  cout << "Test failed with error code " << result << endl;
    else cout << "Test Successful" << endl;

    
	return 0;
}

