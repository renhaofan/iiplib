#include <iostream>
#include <string>

#include <IIPLConfig.h>

int main(int argc, char** argv) 
{

	std::cout << "IIPL Version "
              << IIPL_VERSION_MAJOR << "." 
              << IIPL_VERSION_MINOR << "." 
              << IIPL_VERSION_PATCH
			  << "\n";
	return 0;
}