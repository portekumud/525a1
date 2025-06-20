/*
 * common-code.cpp
 *
 *  Created on: 18-Jun-2025
 *      Author: Kumud
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

enum testValidity {
	IsValid,
	IsNotValid
};


void h01_readTheInputFileAndRecoverTheTwoHiddenThings(char *, vector<vector<int>> &, vector<int> &);
void h02_checkTheOneThArgument_forAll3Codes(vector<vector<int>>, vector<int>, enum testValidity &);
void h03_checkTheTwoThCommanLineArgument_forCode1(string, vector<vector<int>>, enum testValidity &);
//void h03_checkTheTwoThCommanLineArgument_forCode2(string);
//void h03_checkTheTwoThCommanLineArgument_forCode3(string);
void h04_driverForCode1(vector<vector<int>> &, vector<int> &, int);
//void h04_driverForCode2();
//void h04_driverForCode3();
void h05_doLocalComplementationUsingOnePivotVertex(vector<vector<int>> myGraph, vector<int> theNeighborsOfPivot, vector<vector<int>> &theNewGraph);
void h06_doColorReversal(vector<int> myOldBicoloration, vector<int> theNeighborsOfPivot, vector<int> &myNewBicoloration);
void h07_showMatrixGraph(vector<vector<int>>, string);
void h08_showMatrixBiCOloration(vector<int>, string);
void h09_drawPNGorPDF(vector<vector<int>> myGraph, vector<int> myBicoloration, string parameter1, string parameter2);
void auxiliaryFile01_extractIntegerWords(string myLine,vector<vector<int>> &myGraph);


int main(int argc, char **argv) {
	//vector<vector<int>> theInputFile;
	vector<vector<int>> theHiddenGraphInTheInputFile, oldGraph;
	vector<int> theHiddenBiColorationInTheInputFile, oldBiColoration;
	string theTwoThCommandLineArgumentString;
	int theTwoThCommandLineArgumentIntegerForCode1 = stoi(*(argv + 2));
	vector<int> theTwoThCommandLineArgumentIntegerForCode2;
	int theTwoThCommandLineArgumentIntegerForCode3;
	enum testValidity validORnotArgumentOneTh = IsValid;
	enum testValidity validORnotArgumentTwoThForCode1 = IsValid;
	enum testValidity validORnotArgumentTwoThForCode2 = IsValid;
	enum testValidity validORnotArgumentTwoThForCode3 = IsValid;

	if( argc == 3 ) {
		cout << "The number of arguments is 3. All seems good. Keep going";
		h01_readTheInputFileAndRecoverTheTwoHiddenThings(*(argv + 1), theHiddenGraphInTheInputFile, theHiddenBiColorationInTheInputFile);
		h02_checkTheOneThArgument_forAll3Codes(theHiddenGraphInTheInputFile, theHiddenBiColorationInTheInputFile, validORnotArgumentOneTh);
		h03_checkTheTwoThCommanLineArgument_forCode1(*(argv + 2), theHiddenGraphInTheInputFile, validORnotArgumentTwoThForCode1);
		oldGraph.clear();
		oldBiColoration.clear();
		oldGraph = theHiddenGraphInTheInputFile;
		oldBiColoration = theHiddenBiColorationInTheInputFile;

		if(validORnotArgumentOneTh == IsValid && validORnotArgumentTwoThForCode1 == IsValid) {
			h09_drawPNGorPDF(theHiddenGraphInTheInputFile, theHiddenBiColorationInTheInputFile, "0", "input-graph");
			h04_driverForCode1(oldGraph, oldBiColoration, theTwoThCommandLineArgumentIntegerForCode1);
		}

	}
	else {
		cout << "The number of arguments is not 3. Exiting. Try again";
	}

	return 0;
}

void h01_readTheInputFileAndRecoverTheTwoHiddenThings(char *myInputFileName, vector<vector<int>> &myHiddenGraphInTheInputFile, vector<int> &myHiddenBiColorationInTheInputFile) {
	ifstream theReadFile(myInputFileName, ios::in);
	int lineNUmber = 1;
	int notRead = 0, yesRead = 0;
	vector<vector<int>>::iterator i1;
	vector<int> lastrow;

	cout << endl << endl << "In h01_readTheInputFileAndRecoverTheTwoHiddenThings" << endl;
	if (theReadFile.is_open()) {
		string myLine;
		while (getline(theReadFile, myLine)) {
			if (myLine[0] == '/' || myLine[0] == '*') {
				cout << "This line does not start with an integer. Skipping line " << lineNUmber << endl;
				notRead++;
			}
			else if (myLine[0] == '0' || myLine[0] == '1') {
				cout << "This line starts with an integer. Reading line " << lineNUmber << endl;
				yesRead++;
				auxiliaryFile01_extractIntegerWords(myLine, myHiddenGraphInTheInputFile);
			}
			else {
				cout << "Wrong code. " << typeid(myLine).name() << endl;

			}
			lineNUmber++;
		}
		theReadFile.close();
	}
	else {
		cout << "Unable to open file " << myInputFileName << "." << endl;
	}

	i1 = myHiddenGraphInTheInputFile.end() - 1;

	lastrow = *i1;

	for(vector<int>::iterator i2_lastrow = lastrow.begin(); i2_lastrow != lastrow.end(); i2_lastrow++){
		cout << "Last row for bicoloration: " << *i2_lastrow << endl;
		myHiddenBiColorationInTheInputFile.push_back(*i2_lastrow);
	}

	myHiddenGraphInTheInputFile.erase(i1);

	return;
}

void auxiliaryFile01_extractIntegerWords(string myLine,vector<vector<int>> &myGraph) {
	cout << endl << endl << "In auxiliaryFile01_extractIntegerWords. " << endl;

    stringstream aStringStream;
    string temp;
    int found;
    vector<int> v1;


    /* Storing the whole string into string stream */
    aStringStream << myLine;
    /* Running loop till the end of the stream */

    v1.clear();

    while (!aStringStream.eof()) {
    	/* extracting word by word from stream */
    	aStringStream >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found)
        	//cout << ":" << found << " ";
        v1.push_back(found);

        /* To save from space at the end of string */
        temp = "";
    }
    myGraph.push_back(v1);

    return;
}

void h02_checkTheOneThArgument_forAll3Codes(vector<vector<int>> myGraph, vector<int> myBiColoration, enum testValidity &myValidity) {
	cout << endl << endl << "In h02_checkTheOneThArgument_forAll3Codes. " << endl;

	unsigned int theNumberOfVertices = myBiColoration.size();
	unsigned int numberOfRows = 0;

	for (vector<vector<int>>::iterator i1_myGraph = myGraph.begin(); i1_myGraph != myGraph.end(); i1_myGraph++) {
		if ((*i1_myGraph).size() != theNumberOfVertices) {
			myValidity = IsNotValid;
			break;
		}
		numberOfRows++;
	}

	if (myValidity == IsValid)
		if (numberOfRows != theNumberOfVertices) {
		myValidity = IsNotValid;
	}

	return;
}

void h04_driverForCode1(vector<vector<int>> &myOldGraph, vector<int> &myOldBiColoration, int myPivotVertex) {
	cout << endl << endl << "In h04_driverForCode1. " << endl;
	cout << "myPivotVertex: " << myPivotVertex << endl;

	vector<vector<int>> theNewGraph;
	vector<int> theNewBiColoration;
	vector<int> theNeighborsOfPivot;
	vector<int> thePivotRow;
	int indexOfNeighbor;

	theNewGraph.clear();
	theNewBiColoration.clear();
	theNeighborsOfPivot.clear();
	thePivotRow = myOldGraph[myPivotVertex];
	indexOfNeighbor = 0;

	for(vector<int>::iterator i1_thePivotRow = thePivotRow.begin(); i1_thePivotRow != thePivotRow.end(); i1_thePivotRow++, indexOfNeighbor++) {
		if(*i1_thePivotRow == 1) {
			theNeighborsOfPivot.push_back(indexOfNeighbor);
		}
	}

	cout << "The neighbors of pivot: ";
	for(vector<int>::iterator i1_myNeighborOfPivot = theNeighborsOfPivot.begin(); i1_myNeighborOfPivot != theNeighborsOfPivot.end(); i1_myNeighborOfPivot++) {
		cout << *i1_myNeighborOfPivot << " ";

	}

	h07_showMatrixGraph(myOldGraph, "Calling from h04_driverForCode1");
	h05_doLocalComplementationUsingOnePivotVertex(myOldGraph, theNeighborsOfPivot, theNewGraph);
	h07_showMatrixGraph(theNewGraph, "Calling from h04_driverForCode1");

	h08_showMatrixBiCOloration(myOldBiColoration, "Calling from h04_driverForCode1");
 	h06_doColorReversal(myOldBiColoration, theNeighborsOfPivot, theNewBiColoration);
 	h08_showMatrixBiCOloration(theNewBiColoration, "Calling from h04_driverForCode1");

 	h09_drawPNGorPDF(theNewGraph, theNewBiColoration, "1", to_string(myPivotVertex));

	return;
}


void h03_checkTheTwoThCommanLineArgument_forCode1(string myTwoThArgument, vector<vector<int>> myGraph, enum testValidity &myValidity) {
	cout << endl << endl << "In h03_checkTheTwoThCommanLineArgument_forCode1" << endl;
	unsigned int myTwoThArgumentIntererForm = stoi(myTwoThArgument);

	if(myTwoThArgumentIntererForm < 0 || myTwoThArgumentIntererForm >= myGraph.size()) {
		cout << "The input graph has only " << myGraph.size() << " vertices, and you have entered a pivot vertex which is invalid. Bye." << endl;
		myValidity = IsNotValid;
	}

	return;
}


void h05_doLocalComplementationUsingOnePivotVertex(vector<vector<int>> myOldGraph, vector<int> myneighborsOfPivot, vector<vector<int>> &myNewGraph) {
	cout << endl << endl << "In h05_doLocalComplementationUsingOnePivotVertex" << endl;

	vector<int> oneLine;

	oneLine.clear();

	/*
	 * Copying the myOldGraph into myNewGraph
	 */
	for(vector<vector<int>>::iterator i1 = myOldGraph.begin(); i1 != myOldGraph.end(); i1++) {
		oneLine.clear();
		for(vector<int>::iterator i2 = (*i1).begin(); i2 != (*i1).end(); i2++) {
			oneLine.push_back(*i2);
		}
		myNewGraph.push_back(oneLine);
	}

	/*
	 * Applying the definition of Local Complementation using relation1 and relation2
	 */
	for(vector<int>::iterator i1_myNeighborOfPivot = myneighborsOfPivot.begin(); i1_myNeighborOfPivot != myneighborsOfPivot.end(); i1_myNeighborOfPivot++) {
			for(vector<int>::iterator i2_myNeighborOfPivot = myneighborsOfPivot.begin(); i2_myNeighborOfPivot != myneighborsOfPivot.end(); i2_myNeighborOfPivot++) {
				if(*i1_myNeighborOfPivot < *i2_myNeighborOfPivot) {
					cout << "Checking connection between pairs: " << *i1_myNeighborOfPivot << " and " << *i2_myNeighborOfPivot;
					int theConnectivity = myOldGraph[*i1_myNeighborOfPivot][*i2_myNeighborOfPivot];
					if(theConnectivity == 0) {
						cout << ": not connected, so connect them.";
						myNewGraph[*i1_myNeighborOfPivot][*i2_myNeighborOfPivot] = 1;
						myNewGraph[*i2_myNeighborOfPivot][*i1_myNeighborOfPivot] = 1;
						cout << " Done";
					}
					else if (theConnectivity == 1) {
						cout << ": yes connected, so disconnect them";
						myNewGraph[*i1_myNeighborOfPivot][*i2_myNeighborOfPivot] = 0;
						myNewGraph[*i2_myNeighborOfPivot][*i1_myNeighborOfPivot] = 0;
						cout << " Done";
					}
					else {
						cout << "Wrong code";
					}
					 cout << endl;
				}
			}
		}

	return;
}
void h06_doColorReversal(vector<int> myOldBiColoration, vector<int> theNeighborsOfPivot, vector<int> &myNewBiColoration) {
	cout << endl << endl << "In h06_doColorReversal" << endl;

	/* Copying myOldBicoloration to myNewBicoloration
	 *
	 */
	for(vector<int>::iterator i1_myOldBicoloration = myOldBiColoration.begin(); i1_myOldBicoloration != myOldBiColoration.end(); i1_myOldBicoloration++) {
		myNewBiColoration.push_back(*i1_myOldBicoloration);
	}

	for(vector<int>::iterator i1_myNeighborsOfPivot = theNeighborsOfPivot.begin(); i1_myNeighborsOfPivot != theNeighborsOfPivot.end(); i1_myNeighborsOfPivot++) {
		if(myNewBiColoration[*i1_myNeighborsOfPivot] == 1) {
			myNewBiColoration[*i1_myNeighborsOfPivot] = -1;
		}
		else if (myNewBiColoration[*i1_myNeighborsOfPivot] == -1) {
			myNewBiColoration[*i1_myNeighborsOfPivot] = 1;
		}
		else {
			cout << "Wrong code";
		}
	}

	return;
}

void h07_showMatrixGraph(vector<vector<int>> myGraph, string myMessage) {
	cout << endl << endl << "In h07_showMatrixGraph. " << myMessage << endl;

	for(vector<vector<int>>::iterator i1 = myGraph.begin(); i1 != myGraph.end(); i1++) {
		for(vector<int>::iterator i2 = (*i1).begin(); i2 != (*i1).end(); i2++) {
			cout << *i2 << " ";
		}
		cout << endl;
	}

	return;
}

void h08_showMatrixBiCOloration(vector<int> myBicoloration, string myMessage) {
	cout << endl << endl << "In h08_showMatrixBiCOloration. " << myMessage << endl;

	for(vector<int>::iterator i1 = myBicoloration.begin(); i1 != myBicoloration.end(); i1++) {
		cout << *i1 << " ";
	}

	return;
}

void h09_drawPNGorPDF(vector<vector<int>> myGraph, vector<int> myBicoloration, string parameter1, string parameter2) {
	cout << endl << endl << "In h09_drawPNGorPDF. " << endl;

	vector<vector<int>>::iterator p1_myGraph;
	string name = "graph" + parameter1 + "-" + parameter2 + ".py";
	vector<int>::iterator p2;
	int i = 0, j, k = 0;
	int theNumberOfVertices;

	ofstream file(name);

	cout << endl << "In g10_drawGraphPNG. name: " << name;


	p1_myGraph = myGraph.begin();

	file << "import networkx as nx" << endl;
	file << "import matplotlib.pyplot as plt" << endl;
	file << "G = nx.Graph() " << endl;
	file << "plt.subplot(211)" << endl;
	file << "G.add_edges_from([";

	while(p1_myGraph != myGraph.end()) {
		p2 = (*p1_myGraph).begin();
		j = 0;
		while(p2 != (*p1_myGraph).end()) {
			if (*p2 == 1) {
				if (k == 0) {
					file << "(" << i << ", " << j << ")";
					k++;
				}
				else {
					file << ", (" << i << ", " << j << ")";
				}
			}
			p2++;
			j++;
		}
		p1_myGraph++;
		i++;
	}

	file << "])";

	file << endl << "nx.set_node_attributes(G, {";
	theNumberOfVertices = myBicoloration.size();
	for (int t1 = 0; t1 < theNumberOfVertices; t1++) {
		if(t1 == 0) {
			file << t1 << ": \'";
			if(myBicoloration[t1] == 1) {
				file << "yellow";
			}
			else if (myBicoloration[t1] == -1){
				file << "green";
			}
			else {
				cout << endl << "Wrong code";

			}
			file << "\'";
		}
		else {
			file << ", " << t1 << ": \'";
			if(myBicoloration[t1] == 1) {
				file << "yellow";
			}
			else if (myBicoloration[t1] == -1){
				file << "green";
			}
			else {
				cerr << endl << "Wrong code";

			}
			file << "\'";
		}
	}
	file << "}, name=\'color\')";
	file << endl << "nx.draw(G, with_labels=True, node_color=list(nx.get_node_attributes(G, \'color\').values()))";

	file << endl << "plt.savefig('graph";
	file << parameter1;
	file << "-";
	file << parameter2;
	file << ".png')" << endl;

	file.close();

	cout << endl;


	return;
}








