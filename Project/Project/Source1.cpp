#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

class Graph{
	private:
		std::vector<std::pair<double,std::pair<int,int>>> edges;
		std::vector<std::vector<double>> contents;
	public:
		void read(std::string input);
};

void Graph::read(std::string input){
	std::string line;
	std::string part;
	std::vector<double> row;
	
	double rows;

	std::ifstream file(input);
	if (file.is_open()){
		while(file.good()){
			getline(file, line);
			std::stringstream ss(line);
			while(ss){
				getline(ss, part, '(');
				getline(ss, part, ',');
				row.push_back(std::stoi(part));
				getline(ss, part, ',');
				row.push_back(std::stoi(part));
				getline(ss, part, ')');
				row.push_back(std::stoi(part));
				getline(ss, part, ',');
				contents.push_back(row);
			}
		}

		rows=contents.size();

		int node1, node2;
		double weight;

		for(int i=0; i<rows; i++){
			node1=contents[i][0];
			node2=contents[i][1];
			weight=contents[i][2];
			edges.push_back(std::make_pair(weight,std::make_pair(node1,node2)));
		}
	}else{
		std::cout<< "there is no file with that name" <<std::endl;
	}
	file.close();
}

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
