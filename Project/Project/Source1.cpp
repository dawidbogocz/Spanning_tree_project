#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

#include "functions.h"

int main(int argc, char* argv[]) {

	std::string input;
	std::string output;

    if (argc < 3) {
    	usage();
    	return 0;
	}

	for(int i=1;i<argc;i++){
		if((std::string(argv[i])=="-i")&&(std::string(argv[i+1])!="-o")){
			input=argv[i+1];
			i++;
		}else if((std::string(argv[i])=="-o")&&(std::string(argv[i+1])!="-i")){
			output=argv[i+1];
			i++;
		}else if(std::string(argv[i])=="-h"){
			usage();
			return 0;
		}else{
			std::cout<<"Incorrect paramters! "<<std::endl;
			usage();
			return 0;
		}
	}

	int u=count(input);

	Graph a(u);

	a.read(input);
	a.MST();
	a.print(output);

	return 0;
}