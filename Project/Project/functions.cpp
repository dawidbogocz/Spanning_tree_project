#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

#include "functions.h"

class Graph{
	private:
		std::vector<std::pair<double,std::pair<int,int>>> edges;
		std::vector<std::vector<double>> contents;
		int *parent;
		std::vector<std::pair<double,std::pair<int,int>>> tmp;
	public:
		Graph(int N);
		void read(std::string input);
		int find(int x);
		void unite(int a, int b);
		void MST();
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
	std::cout<<"-h -> Show this information"<<std::endl;
}