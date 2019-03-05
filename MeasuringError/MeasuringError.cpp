#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	double trueValue = 0,
		averageQuadError = 0,
		measuresCount = 0,
		inputMeasure = 0;

	ifstream dataFile;
	dataFile.open("data.txt");

	if (!dataFile.is_open())
	{
		cout << "Can't open file with data!";
		return 0;
	}

	dataFile >> trueValue;

	while (!dataFile.eof())
	{
		dataFile >> inputMeasure;
		averageQuadError += pow(trueValue - inputMeasure, 2);

		measuresCount++;
	}

	averageQuadError = sqrt(averageQuadError / --measuresCount);
	cout << "Average quadratic error is: " << averageQuadError;

	cin.get();
	return 0;
}