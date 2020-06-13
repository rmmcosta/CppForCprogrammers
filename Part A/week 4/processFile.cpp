//this program reads a file 
//and prints to the screen the lines
//of that file

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string fileName;
	cout << "Please input the file name: ";
	cin >> fileName;
	//cout << endl << "The inputed file name is: " << fileName << endl; 
	ifstream fout;
	fout.open(fileName);
	if(fout.is_open())
	{
		cout << "File open" << endl;
		fout.close();
		if(!fout.is_open())
		{
			cout << "File closed" << endl;
		}
		else
		{
			cout << "error" << endl;
			exit(EXIT_FAILURE);
		}
	}	
	else
	{
		cout << "error" << endl;
		exit(EXIT_FAILURE);
	}
	ifstream dataFile(fileName);
	istream_iterator<int> start(dataFile), end;
	vector<int> data(start, end);
	//copy(start, end, back_inserter(data));
	cout << "iterate the data vector..." << endl;
	for(auto it=data.begin(); it!=data.end(); it++)
	{
		cout << *it << endl;
	}
	ifstream fileIn(fileName);
	istream_iterator<string> strStart(fileIn), strEnd;
	vector<string> lines;
	copy(strStart, strEnd, back_inserter(lines));
	cout << "for lines" << endl;	
	for(auto it=lines.begin(); it!=lines.end(); it++)
	{
		cout << *it << endl;
	}
	ifstream fileIn2(fileName);
	istream_iterator<int> intStart(fileIn2), intEnd;
	vector<int> numbers;
	copy(intStart, intEnd, back_inserter(numbers));
	cout << "for lines" << endl;	
	for(auto it=numbers.begin(); it!=numbers.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
