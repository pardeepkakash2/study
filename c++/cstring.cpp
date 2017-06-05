#include <string>
#include <algorithm>
#include <iostream>

int main (int argc, char* argv[])
{
	std::string sourceString = "Abc";
	std::string destinationString;

	// Allocate the destination space
	destinationString.resize(sourceString.size());

	// Convert the source string to lower case
	// storing the result in destination string
	std::transform(sourceString.begin(), sourceString.end(), destinationString.begin(), ::tolower);

	// Output the result of the conversion
	std::cout << sourceString << " -> " << destinationString << std::endl;

}
