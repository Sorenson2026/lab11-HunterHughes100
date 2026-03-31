//This Program is a number analysis Program read from a file
//Hunter Hughes 3-31-26
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Function prototypes and named constants
int readFile(int numbers[]);
void analyzeArray(int[], int);
const int SIZE = 100;

//The main function creates the array and calls the functions to read the file and analyze the data
int main()
{
	//Create Array to read from
	int numbers[SIZE] = { 0 };
	int fileSize;
	//Greeting 
	cout << "Hi, I'm a Program that reads your file of numbers and does analysis on them" << endl;
	fileSize = readFile(numbers);

	for (int i =0; i < fileSize; i++)
		cout << numbers[i] << endl;
	cout << "There are " << fileSize << " numbers in the file." << endl;
}

//The readFile funciton read the number and determine how many there are and return that count
int readFile(int numbers[])
{
	//Create Variables
	ifstream inputFile;
	string filename;
	int count = 0;

	//Get file from user
	cout << "Enter the file name: ";
	cin >> filename;

	//Get file open for reading
	inputFile.open(filename);

	//verify that the file works
	while (!inputFile)
	{
		cout << "Error invalid file!\nPlease enter a valid file: ";
		cin >> filename;
		inputFile.open(filename);
	}
	
	//Create loop to read input from the file and get count
	while (inputFile >> numbers[count])
		count++;

	//Close File
	inputFile.close();

	return count;
}