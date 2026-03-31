//This Program is a number analysis Program read from a file
//Hunter Hughes 3-31-26
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
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
	
	//Call the readFile function to read the file and get the count of numbers in the file
	fileSize = readFile(numbers);

	//Call the analyzeArray function to analyze the data in the array
	analyzeArray(numbers, fileSize);

	// Test the readfile function by printing the numbers in the array and the count of numbers in the file
	/*for (int i = 0; i < fileSize; i++)
		cout << numbers[i] << endl;*/
	cout << "There are " << fileSize << " numbers in the file." << endl;
	
	return 0;
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

//This function finds the max, min, total, average and standard deiation of the array
void analyzeArray(int numbers[], int size)
{
	//Create variables
	int min = numbers[0];
	int max = numbers[0];
	int total = 0;
	float avg,stdDev;
	float  sum = 0;

	//test min and max
	for (int i = 0; i < size; i++)
	{
		total += numbers[i];
		if (numbers[i] < min)
			min = numbers[i];
		if (numbers[i] > max)
			max = numbers[i];
	}
	avg = static_cast<float>(total) / size;

	//compute the sum of the squared differences from the mean
	for (int i = 0; i < size; i++)
	{
		sum += pow((numbers[i] - avg), 2);
	}
	
	//compute standard deviation
	stdDev = sqrt(sum / size);

	//Display the results
	cout << "The minimum number is: " << min << endl;
	cout << "The maximum number is: " << max << endl;
	cout << "The Total is: " << total << endl;
	cout << "The Average is: " << avg << endl;
	cout << "The standard deviation is: " << stdDev << endl;
}