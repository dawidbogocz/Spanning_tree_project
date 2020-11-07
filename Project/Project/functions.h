#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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

/**
 * Function that finds how many nodes are in the weighted graph.
 * @param line stores one line taken from input file.
 * @param unique stores unique nodes (one node can be called multiple times in input file to create a graph).
 */
int count(std::string input);

/** Function that prints a help message on how to use flags in command line. */
void usage();

#endif