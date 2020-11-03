#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct Graph {
	std::vector<std::vector<double>> contents;

	int rows() {
		return contents.size();
	}

	int columns() {
		return contents[0].size();
	}

	void read(std::string input) {

		std::string line;
		double i = 0;
		double j = 0;

		std::ifstream file(input);

		if (file.is_open()) {

			while (file.good()) {
				getline(file, line);
				std::cout << line << std::endl;
			}
			std::string part;
			std::stringstream ss(line);

			for (i = 0; i < 3; i++) {
				std::vector<double> row;
				std::getline(ss, part, '(');

				std::getline(ss, part, ',');
				row.push_back(std::stod(part));

				std::getline(ss, part, ',');
				row.push_back(std::stod(part));

				std::getline(ss, part, ')');
				row.push_back(std::stod(part));

				contents.push_back(row);
			}
			double rows = contents.size();
			double cols = contents[0].size();
			for (i = 0; i < rows; i++) {
				for (j = 0; j < cols; j++) {
					std::cout << contents[i][j]<<", ";
				}
				std::cout << std::endl;
			}
		}
		else {
			std::cout << "there is no such a file" << std::endl;
		}
		file.close();
	}
};

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
			std::ofstream file(output);
			file.close();
			i++;
		}else{
			usage();
		}
	}
	Graph a;
	a.read(input);
	return 0;
}
