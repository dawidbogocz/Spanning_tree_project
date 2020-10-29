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

	void read() {

		std::string line;
		double i = 0;
		double j = 0;

		std::ifstream file("graph.txt");

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



int main(int argc, char *argv[]) {
	Graph a;
	a.read();
	return 0;
}
