#include "GetTextFile.h"


using namespace std;


std::string GetTextFile::getTxtFile(const char strChar[],const unsigned short GrosseurString)
{
	std::string string;
	ifstream inFile;
	inFile.open(strChar);

	if (!inFile) {
		std::cout << "Unable to open txt file.";
		system("pause");
		exit(1);
	}
	stringstream strStream;
	strStream << inFile.rdbuf();
	inFile.close();
	return strStream.str();
}
