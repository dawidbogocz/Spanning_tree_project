#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

int count(std::string input){
	std::string line;
	std::set<int> unique;

    std::ifstream file(input);
    if(file.is_open()){
        while(file.good()){
            getline(file,line);

            std::string part;
            std::stringstream ss(line);

            while(ss){
                getline(ss, part, '(');
                getline(ss, part, ',');
                unique.insert(std::stoi(part));
                getline(ss, part, ',');
                unique.insert(std::stoi(part));
                getline(ss, part, ')');
                getline(ss, part, ',');
            }
        }
	}
    int u=unique.size();
	return u;
}


void usage(){
	std::cout<<"Options: "<<std::endl;
	std::cout<<"-i input   -> Select input file"<<std::endl;
	std::cout<<"-o output  -> Select output file"<<std::endl;
}

int main(int argc, char* argv[]) {

	std::string input;
	std::string output;

	std::string in="-i";
	std::string out="-o";

    if (argc < 3) {
    	usage();
    	return 0;
	}

	for(int i=1;i<argc;i++){
		if(argv[i]==in){
			input=argv[i+1];
			i++;
		}else if(argv[i]==out){
			output=argv[i+1];
			i++;
		}else{
			usage();
			return 0;
		}
	}

	int u=count(input);

	return 0;
}
