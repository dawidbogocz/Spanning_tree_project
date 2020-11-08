#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>


class Graph{
	private:
        /**
         * A vector that represents edges in weighted graph. 
         * First pair consists of double value that represents weight of the edge and second pair.
         * Second pair consists of two integer values that represent two different nodes.
         */
		std::vector<std::pair<double,std::pair<int,int>>> edges;

        /** 2D Vector that stores values taken from input file. */
		std::vector<std::vector<double>> contents;

        /** Pointer used in functions find and unite that represents root of set. */
		int *parent;

        /** A vector that represents edges of Minimal Spanning Tree, it's structure is the same as of vector edges.*/
		std::vector<std::pair<double,std::pair<int,int>>> tmp;
	public:

        /** Function that creates N disjoint sets. */
		Graph(int nodes);

        /**
         * Function that reads input file and puts values stored in it into vector edges.
         * @param line stores one line taken from input file.
         * @param rows stores number of rows from vector contents that represent number of edges.
         * @param part stores a part of line and is used to extract numbers form parentheses.
         * @param x represents one of two nodes connected with weighted edge.
         * @param y represents one of two nodes connected with weighted edge.
         * @param w represents weighted edge.
         */
		void read(std::string input);

        /** Function that finds the root of the set in which element x belongs. */
		int find(int x);

        /** 
         * Function that unites of two subsets .
         * @param a represents first subset.
         * @param b represents second subset.
         */
		void unite(int a, int b);

        /**
         * Function that finds Minimal Spanning Tree using Kruskal's algorithm and disjoint-set.
         * @param a represents one of two nodes connected with weighted edge.
         * @param b represents one of two nodes connected with weighted edge.
         * @param weight represents weighted edge.
         */
		void MST();

        /** Function that prints result of the program into output file. */
		void print(std::string outpout);
};

Graph::Graph(int N){
	parent=new int[N];
	for(int i=0; i<N; i++){
		parent[i]=i;
	}
}

void Graph::read(std::string input){
	std::string line;
	
	double rows;

	std::ifstream file(input);
	if (file.is_open()){
		while(file.good()){
			getline(file, line);
			std::string part;
			std::stringstream ss(line);
			while(ss){
				std::vector<double> row;
				getline(ss, part, '(');
				getline(ss, part, ',');
				row.push_back(std::stoi(part));
				getline(ss, part, ',');
				row.push_back(std::stoi(part));
				getline(ss, part, ')');
				row.push_back(std::stod(part));
				getline(ss, part, ',');
				contents.push_back(row);
			}
		}

		rows=contents.size();

		int x, y;
		double w;

		for(int i=0; i<rows; i++){
			x=contents[i][0];
			y=contents[i][1];
			w=contents[i][2];
			edges.push_back(std::make_pair(w,std::make_pair(x,y)));
		}
	}else{
		std::cout<< "File "<< input <<" not found!" <<std::endl;
	}
	file.close();
}

int Graph::find(int x){
	if(x==parent[x]){
		return x;
	}else{
		return find(parent[x]);
	}
}

void Graph::unite(int a, int b){
	int fa=find(a);
	int fb=find(b);
	parent[fa]=fb;
}

void Graph::MST(){
	int a,b;
	double weight;
	sort(edges.begin(),edges.end()); 
	for(int i=0; i<edges.size(); i++){
		a=find(edges[i].second.first);
		b=find(edges[i].second.second);
		weight=find(edges[i].first);
		if(a!=b){
			tmp.push_back(edges[i]);
			unite(a,b);
		}
	}
}

void Graph::print(std::string output){
	std::ofstream file(output);
	if(file.is_open()){
		file << "Edge   : Weight: \n";
		std::cout<<"Edge   : Weight:"<<std::endl;
		for(int i=0; i<tmp.size(); i++){
			file << tmp[i].second.first << " - " << tmp[i].second.second << "  : " << tmp[i].first << "\n";
			std::cout << tmp[i].second.first << " - " << tmp[i].second.second << "  : " << tmp[i].first << std::endl;
		}
	}
	file.close();
}

/**
 * Function that finds how many nodes are in the weighted graph.
 * @param line stores one line taken from input file.
 * @param unique stores unique nodes (one node can be called multiple times in input file to create a graph).
 */
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

/** Function that prints a help message on how to use flags in command line. */
void usage(){
	std::cout<<"Options: "<<std::endl;
	std::cout<<"-i input   -> Select input file"<<std::endl;
	std::cout<<"-o output  -> Select output file"<<std::endl;
	std::cout<<"-h -> Show this information"<<std::endl;
}
