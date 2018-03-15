#include <iostream>
#include <fstream>
#include <cstdlib>
//Use standard library namespace
using namespace std;
//Create some global variables
char checkThese[4] = {'a', 'A', 'F', 'b'};
int  itemCounter[4] = {0 ,  0 ,  0 ,   0};
char currentChar;

int main()
{
	//Create file streams
	ifstream inputStream;
	//open the info.dat
	inputStream.open("info.dat");
	cout << "-----------------------------------\nReading \"info.dat\" . . . . . . . .\n-----------------------------------\n";
    //Test Input Stream
    if( inputStream.fail() )
	{
		cout << "Unable to open file info.dat";
		//Exit the program
		exit(1);
	}
	//Loop counter counts each character in document
	int loopCounter = 0;
	//Store the next char from input stream into currentChar
	inputStream >> currentChar;
	//While its not the end of file, change current char and determine if it's in checkThese
	while(!inputStream.eof()){
		inputStream >> currentChar;
		for(int i = 0;  i < 4; i++){
			if(currentChar == checkThese[i]){
				//Count each char in their own counter
				itemCounter[i]++;
			}	
		}
		//Count total number of characters
		loopCounter++;
	}
	//Print out the information to the user
	for(int i = 0; i < 4; i++) { 
		cout << "Number of '"<< checkThese[i] <<"'s: " << itemCounter[i] << endl; 
	}
	cout << "Total number of characters: " << loopCounter << "\n-----------------------------------\n";
	return 0;
}




