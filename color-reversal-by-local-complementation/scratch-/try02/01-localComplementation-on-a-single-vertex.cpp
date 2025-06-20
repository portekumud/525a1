/*
 * 02localComplementation.cpp
 *
 *  Created on: 16-Jun-2025
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

enum inputvalidity {
	notValid,
	yesValid
};


// Enum to represent log levels
enum LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL };

/*class Logger {
public:
    // Constructor: Opens the log file in append mode
    Logger(const string& filename)
    {
        logFile.open(filename, ios::app);
        if (!logFile.is_open()) {
            cerr << "Error opening log file." << endl;
        }
    }

    // Destructor: Closes the log file
    ~Logger() { logFile.close(); }

    // Logs a message with a given log level
    void log(LogLevel level, const string& message)
    {
        // Get current timestamp
        time_t now = time(0);
        tm* timeinfo = localtime(&now);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

        // Create log entry
        ostringstream logEntry;
        logEntry << "[" << timestamp << "] " << levelToString(level) << ": " << message << endl;

        // Output to console
        //cout << logEntry.str();

        // Output to log file
        if (logFile.is_open()) {
            logFile << logEntry.str();
            logFile.flush(); // Ensure immediate write to file
        }
    }

private:
    ofstream logFile; // File stream for the log file

    // Converts log level to a string for output
    string levelToString(LogLevel level)
    {
        switch (level) {
        case DEBUG:
            return "DEBUG";
        case INFO:
            return "INFO";
        case WARNING:
            return "WARNING";
        case ERROR:
            return "ERROR";
        case CRITICAL:
            return "CRITICAL";
        default:
            return "UNKNOWN";
        }
    }
};*/


void g01_checkInputFormat(string, string);
void g02_readInputFile(string, vector<vector<int>> &, vector<int> &);
void g03_extractIntegerWords(string,vector<vector<int>> &);
void g04_checkInput(vector<vector<int>>, vector<int>);
void g05_thisIsTheInputSTring(string, vector<int> &);
void g06_doLocalComplementUSING_aPivotVertex(vector<vector<int>> &, vector<vector<int>> &, int, vector<int> &);
void g06_doLocalComplementUSING_aSequenceOfVertices(vector<vector<int>> &, vector<vector<int>> &, vector<int>, vector<int> &);
void g06_doLocalComplementUSING_allLexicoSequenceOfVertices(vector<vector<int>> &, vector<vector<int>> &);
void g07_doColorReversal(vector<int>, vector<int> &, vector<int> &);
void g08_showGraphMatrix(vector<vector<int>>, string);
void g09_printBicoloration(vector<int>, string);
void g10_drawGraphPNG(vector<vector<int>>, vector<int>, string, string);
void g11_calculateTwoParametersForDrawing(string &, string &);
void g12_checkInputValidity(vector<vector<int>>, vector<int>, unsigned int, enum inputvalidity &);
void g13_driverFunction_for_g06_doLocalComplementUSING_aPivotVertex(vector<vector<int>> &, vector<int> &, vector<vector<int>> &, vector<int> &, int, string, string);
//void g13_driverFunction_for_g06_doLocalComplementUSING_aSequenceOfVertices
//void g13_driverFunction_for_g06_doLocalComplementUSING_allLexicoSequenceOfVertices

inline string getCurrentDateTime( string s ){
    time_t now = time(0);
    struct tm  tstruct;
    char  buf[80];
    tstruct = *localtime(&now);
    if(s=="now")
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    else if(s=="date")
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    return string(buf);
};
inline void kumudLoggerLaptop( string logMsg ){

    string filePath = "./logfile01Kumud_" + getCurrentDateTime("date")+"-";
    string now = getCurrentDateTime("now");
    ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app );
    ofs << now << '\t' << logMsg << '\n';
    ofs.close();
}


int main(int argc, char **argv) {
	vector<vector<int>> theInputGraph, theOldGraph;
	vector<int> theInputBicoloration, theOldBicoloration;
	vector<vector<int>> theNewGraph;
	vector<int> theNewBicoloration;
	vector<int> theInputSequence;
	string theNameIndex, theNameTitle;
	enum inputvalidity isInputValid = yesValid;
	string parameter1, parameter2;
	//freopen( "log01Kumud", "w", stdout );
    //Logger kumudLogger("logfile02Kumud"); // Create logger instance

	unsigned int pivotVertexFor_g06One = stoi(*(argv + 2));

	//cout << "Assumtion: local complement + color reversal = local inversion" << endl;
	//cout << "myPivotVertexFor_g06One: " << pivotVertexFor_g06One << endl;
	kumudLoggerLaptop("\n\n\nExecution started at time " + getCurrentDateTime("now"));
	kumudLoggerLaptop("Assumtion: local complement + color reversal = local inversion");
	kumudLoggerLaptop("myPivotVertexFor_g06One: " + to_string(pivotVertexFor_g06One));

	//kumudLogger.log(INFO, "Program started.");
	//kumudLogger.log(DEBUG, "Debugging information.");
	//kumudLogger.log(ERROR, "An error occurred.");

	if (argc != 3) {
		kumudLoggerLaptop("Number of argument is incorrect.");
		cout << "Number of argument is incorrect." << endl;
	}
	else {
		cout << "Number of argument is correct." << endl;
		g01_checkInputFormat(*(argv + 1), *(argv + 2));

		//"0 1 0 2 0 2 1 2 1" on input5

		g02_readInputFile(*(argv + 1), theInputGraph, theInputBicoloration);
		cout << "Input reading is done.";

		theOldGraph = theInputGraph;
		theOldBicoloration = theInputBicoloration;

		cout << "Input matrix validity checking is going one.";
		g12_checkInputValidity(theInputGraph, theInputBicoloration, pivotVertexFor_g06One, isInputValid);


		g04_checkInput(theOldGraph, theInputBicoloration);
		g05_thisIsTheInputSTring(*(argv + 2), theInputSequence);

		if(isInputValid == yesValid) {
			g13_driverFunction_for_g06_doLocalComplementUSING_aPivotVertex(theOldGraph, theOldBicoloration, theNewGraph, theNewBicoloration, pivotVertexFor_g06One, parameter1, parameter2);
		}
		else if (isInputValid == notValid) {
			cout << endl << "Input is not valid.";
			kumudLoggerLaptop("Input is not valid.");

		}
		else {
			cout << "Wrong code";
			kumudLoggerLaptop("Wrong code");

		}
	}
	cout << "Done. Please check the log file and the output files.";

	return 0;
}

void g01_checkInputFormat(string myParameter1, string myParameter2) {
	cout << endl << "In g01_checkInputFormat" << endl;
	cout << "myParameter1: " << myParameter1 << endl;
	cout << "myParameter2: " << myParameter2 << endl;
	kumudLoggerLaptop("In g01_checkInputFormat");
	kumudLoggerLaptop("myParameter1: " + myParameter1);
	kumudLoggerLaptop("myParameter2: " + myParameter2);

	return;
}

void g02_readInputFile(string myFileName, vector<vector<int>> &myGraph, vector<int> &myBicoloration) {
	ifstream readFile(myFileName, ios::in);
	int lineNUmber = 1;
	int notRead = 0, yesRead = 0;
	vector<vector<int>>::iterator i1;
	vector<int> lastrow;

	//cout << endl << "In g02_readInputFile" << endl;
	kumudLoggerLaptop("In g02_readInputFile");
	if (readFile.is_open()) {
		string myLine;
		while (getline(readFile, myLine)) {
			if (myLine[0] == '/' || myLine[0] == '*') {
				//cout << "This line does not start with an integer. Skipping line " << lineNUmber << endl;
				kumudLoggerLaptop("This line does not start with an integer. Skipping line " + to_string(lineNUmber));
				notRead++;
			}
			else if (myLine[0] == '0' || myLine[0] == '1') {
				//cout << "This line starts with an integer. Reading line " << lineNUmber << endl;
				kumudLoggerLaptop("This line starts with an integer. Reading line " + to_string(lineNUmber));
				yesRead++;
				g03_extractIntegerWords(myLine, myGraph);
			}
			else {
				cout << "Wrong code. " << typeid(myLine).name() << endl;
				kumudLoggerLaptop("Wrong code");
			}
			lineNUmber++;
		}
		readFile.close();
	}
	else {
		cerr << "Unable to open file " << myFileName << "." << endl;
	}

	i1 = myGraph.end() - 1;

	lastrow = *i1;

	for(vector<int>::iterator i2_lastrow = lastrow.begin(); i2_lastrow != lastrow.end(); i2_lastrow++){
		//cout << "Last row for bicoloration: " << *i2_lastrow << endl;
		kumudLoggerLaptop("Last row for bicoloration: " + to_string(*i2_lastrow));
		myBicoloration.push_back(*i2_lastrow);
	}

	myGraph.erase(i1);
	return;
}



void g03_extractIntegerWords(string myLine,vector<vector<int>> &myGraph) {
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

void g04_checkInput(vector<vector<int>> myGraph, vector<int> myInputBicoloration) {
	//cout << endl << "In g04_checkInput. Printing graph and bicoloration" << endl;
	kumudLoggerLaptop("In g04_checkInput. Printing graph and bicoloration");
	g08_showGraphMatrix(myGraph, "Calling from g04_checkInput");
	g09_printBicoloration(myInputBicoloration, "Calling from g04_checkInput");


	return;
}

void g05_thisIsTheInputSTring(string myOneThArgument, vector<int> &myInputSequence) {
	//cout << endl << endl << "In g05_thisIsTheInputSTring." << endl;
	kumudLoggerLaptop("In g05_thisIsTheInputSTring.");
	//cout << myOneThArgument << endl;
	kumudLoggerLaptop(myOneThArgument);

    stringstream oneStringStream(myOneThArgument);
    vector<int> integers;
    int num;
    while (oneStringStream >> num) {
    	myInputSequence.push_back(num);
    }

    for(vector<int>::iterator i1 = myInputSequence.begin(); i1 != myInputSequence.end(); i1++) {
    	//cout << *i1 << " ";
    	kumudLoggerLaptop(to_string(*i1));
    }

	return;
}

void g06_doLocalComplementUSING_aPivotVertex(vector<vector<int>> &myOldGraph, vector<vector<int>> &myNewGraph, int myPivot, vector<int> &myNeighborsOfPivot) {
	//cout << endl << endl << "In g06_doLocalComplementUSING_aPivotVertex" << endl;
	kumudLoggerLaptop("In g06_doLocalComplementUSING_aPivotVertex");
	myNewGraph.clear();
	myNeighborsOfPivot.clear();
	int indexOfNeighbor = 0;
	vector<int> oneLine;

	cout << endl;
	//cout << "myPivot: " << myPivot;
	kumudLoggerLaptop("myPivot: " + to_string(myPivot));
	cout << endl;

	vector<int> thePivotRow = myOldGraph[myPivot];

	for(vector<int>::iterator i1_thePivotRow = thePivotRow.begin(); i1_thePivotRow != thePivotRow.end(); i1_thePivotRow++, indexOfNeighbor++) {
		if(*i1_thePivotRow == 1) {
			myNeighborsOfPivot.push_back(indexOfNeighbor);
		}
	}
	//cout << "Testing index of pivot: ";
	kumudLoggerLaptop("Testing index of pivot: ");
	for(vector<int>::iterator i1_myNeighborOfPivot = myNeighborsOfPivot.begin(); i1_myNeighborOfPivot != myNeighborsOfPivot.end(); i1_myNeighborOfPivot++) {
		//cout << *i1_myNeighborOfPivot << " ";
		kumudLoggerLaptop(to_string(*i1_myNeighborOfPivot));
	}
	//cout << endl;
	kumudLoggerLaptop("\n");


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

	cout << endl;
	for(vector<int>::iterator i1_myNeighborOfPivot = myNeighborsOfPivot.begin(); i1_myNeighborOfPivot != myNeighborsOfPivot.end(); i1_myNeighborOfPivot++) {
		for(vector<int>::iterator i2_myNeighborOfPivot = myNeighborsOfPivot.begin(); i2_myNeighborOfPivot != myNeighborsOfPivot.end(); i2_myNeighborOfPivot++) {
			if(*i1_myNeighborOfPivot < *i2_myNeighborOfPivot) {
				//cout << "Checking connection between pairs: " << *i1_myNeighborOfPivot << " and " << *i2_myNeighborOfPivot;
				kumudLoggerLaptop("Checking connection between pairs: " + to_string(*i1_myNeighborOfPivot) + " and " + to_string(*i2_myNeighborOfPivot));
				int theConnectivity = myOldGraph[*i1_myNeighborOfPivot][*i2_myNeighborOfPivot];
				if(theConnectivity == 0) {
					//cout << ": not connected, so connect them.";
					kumudLoggerLaptop(": not connected, so connect them.");
					myNewGraph[*i1_myNeighborOfPivot][*i2_myNeighborOfPivot] = 1;
					myNewGraph[*i2_myNeighborOfPivot][*i1_myNeighborOfPivot] = 1;
					//cout << " Done";
					kumudLoggerLaptop("Done");
				}
				else if (theConnectivity == 1) {
					//cout << ": yes connected, so disconnect them";
					kumudLoggerLaptop(": yes connected, so disconnect them");
					myNewGraph[*i1_myNeighborOfPivot][*i2_myNeighborOfPivot] = 0;
					myNewGraph[*i2_myNeighborOfPivot][*i1_myNeighborOfPivot] = 0;
					//cout << " Done";
					kumudLoggerLaptop("Done");
				}
				else {
					//cout << "Wrong code";
					kumudLoggerLaptop("Wrong code");
				}
				 //cout << endl;
				 kumudLoggerLaptop("\n");
			}
		}
	}

	return;
}

void g06_doLocalComplementUSING_aSequenceOfVertices(vector<vector<int>> &myOldGraph, vector<vector<int>> &myNewGraph, vector<int> myInputSequence, vector<int> &myNeighborsOfPivot) {
	return;
}

void g06_doLocalComplementUSING_allLexicoSequenceOfVertices(vector<vector<int>> &myOldGraph, vector<vector<int>> &myNewGraph) {
	return;
}

void g07_doColorReversal(vector<int> myOldBicoloration, vector<int> &myNewBicoloration, vector<int> &myNeighborsOfPivot) {
	//cout << endl << endl << "In g07_doColorReversal" << endl;
	kumudLoggerLaptop("\n\nIn g07_doColorReversal\n");

	/* Copying myOldBicoloration to myNewBicoloration
	 *
	 */
	for(vector<int>::iterator i1_myOldBicoloration = myOldBicoloration.begin(); i1_myOldBicoloration != myOldBicoloration.end(); i1_myOldBicoloration++) {
		myNewBicoloration.push_back(*i1_myOldBicoloration);
	}

	for(vector<int>::iterator i1_myNeighborsOfPivot = myNeighborsOfPivot.begin(); i1_myNeighborsOfPivot != myNeighborsOfPivot.end(); i1_myNeighborsOfPivot++) {
		myNewBicoloration[*i1_myNeighborsOfPivot] = -1;
	}

	return;
}

void g08_showGraphMatrix(vector<vector<int>> myGraph, string myMessage) {
	//cout << endl << endl << "In g08_showGraphMatrix. " << myMessage << endl;
	kumudLoggerLaptop("\n\nIn g08_showGraphMatrix. " + myMessage + "\n");
	for(vector<vector<int>>::iterator i1 = myGraph.begin(); i1 != myGraph.end(); i1++) {
		for(vector<int>::iterator i2 = (*i1).begin(); i2 != (*i1).end(); i2++) {
			//cout << *i2 << " ";
			kumudLoggerLaptop(to_string(*i2));
		}
		//cout << endl;
		kumudLoggerLaptop("\n");
	}
	return;
}

void g09_printBicoloration(vector<int> myBicoloration, string myMessage) {
	//cout << endl << endl << "In g09_printBicoloration. " << myMessage << endl;
	kumudLoggerLaptop("\n\nIn g09_printBicoloration. " + myMessage + "\n");
	for(vector<int>::iterator i1 = myBicoloration.begin(); i1 != myBicoloration.end(); i1++) {
		//cout << *i1 << " ";
		kumudLoggerLaptop(to_string(*i1));
	}
	return;
}


void g10_drawGraphPNG(vector<vector<int>> myGraph, vector<int> myBicoloration, string parameter1, string parameter2) {
	//cout << endl << endl << "In g10_drawGraphPNG.......";
	kumudLoggerLaptop("\n\nIn g10_drawGraphPNG.......");
	vector<vector<int>>::iterator p1_myGraph;
	string name = "graph" + parameter1 + "-" + parameter2 + ".py";
	vector<int>::iterator p2;
	int i = 0, j, k = 0;
	int theNumberOfVertices;

	ofstream file(name);

	//cout << endl << "In g10_drawGraphPNG. name: " << name;
	kumudLoggerLaptop("\nIn g10_drawGraphPNG. name: " + name);

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
				kumudLoggerLaptop("Wrong code");
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
				kumudLoggerLaptop("Wrong code");
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
	kumudLoggerLaptop("\n");

	return;
}

void g11_calculateTwoParametersForDrawing(string &myNameIndex, string &myNameTitle) {
	myNameIndex = "";
	myNameTitle = "";
	return;
}

void g12_checkInputValidity(vector<vector<int>> myGraph, vector<int> myBicoloration, unsigned int myPivotVertexFor_g06One, enum inputvalidity &isInputValid) {
	//cout << endl << endl << "In g12_checkInputValidity. " << endl;
	kumudLoggerLaptop("In g12_checkInputValidity. ");
	unsigned int theNumberOfVertices = myBicoloration.size();
	unsigned int numberOfRows = 0;

	for(vector<vector<int>>::iterator i1_myGraph = myGraph.begin(); i1_myGraph != myGraph.end(); i1_myGraph++) {
		if((*i1_myGraph).size() != theNumberOfVertices) {
			isInputValid = notValid;
			break;
		}
		numberOfRows++;
	}

	if(numberOfRows != theNumberOfVertices) {
		isInputValid = notValid;
	}

	if(myPivotVertexFor_g06One < 0 || myPivotVertexFor_g06One >= theNumberOfVertices) {
		cout << "The input graph has only " << theNumberOfVertices << " vertices, and you have entered a pivot vertex which is invalid. Bye." << endl;
		kumudLoggerLaptop("The input graph has only " + to_string(theNumberOfVertices) + " vertices, and you have entered a pivot vertex which is invalid. Bye.\n");
		isInputValid = notValid;
	}

	if(isInputValid == yesValid) {
		//cout << "isInputValid: yes";
		kumudLoggerLaptop("isInputValid: yes");
	}
	else if (isInputValid == notValid) {
		cout << "isInputValid: no";
		kumudLoggerLaptop("isInputValid: no");
	}
	else {
		cout << "Wrong code";
		kumudLoggerLaptop("Wrong code");
	}

	//cout << endl;

	kumudLoggerLaptop("\n");

	return;
}

void g13_driverFunction_for_g06_doLocalComplementUSING_aPivotVertex(vector<vector<int>> &myOldGraph, vector<int> &myOldBicoloration, vector<vector<int>> &myNewGraph, vector<int> &myNewBicoloration, int myPivotVertexFor_g06One, string myParameter1, string myParameter2) {
	//cout << endl << endl << "In g12_checkInputValidity. " << endl;
	kumudLoggerLaptop("In g12_checkInputValidity. ");

	vector<int> theNeighborsOfPivot;

	g08_showGraphMatrix(myOldGraph, "In main, checking before g06");
	g09_printBicoloration(myOldBicoloration, "In main, checking before g06");
	g06_doLocalComplementUSING_aPivotVertex(myOldGraph, myNewGraph, myPivotVertexFor_g06One, theNeighborsOfPivot);
	g08_showGraphMatrix(myNewGraph, "Checking after g06");
	g09_printBicoloration(myOldBicoloration, "In main, checking before g07_doColorReversal");
	g07_doColorReversal(myOldBicoloration, myNewBicoloration, theNeighborsOfPivot);
	g09_printBicoloration(myNewBicoloration, "In main, checking after g07_doColorReversal");
	g10_drawGraphPNG(myOldGraph, myOldBicoloration, "0", "graphInitial");
	g10_drawGraphPNG(myNewGraph, myNewBicoloration, "1", "graphLCat" + to_string(myPivotVertexFor_g06One));

	return;
}
