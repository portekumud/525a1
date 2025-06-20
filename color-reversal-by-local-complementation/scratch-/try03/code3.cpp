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
#include <limits> // Required for numeric_limits

using namespace std;

enum testValidity {
	IsValid,
	IsNotValid
};

enum haveWeGotColorInversion {
	theAnswerIsNo,
	theAnswerIsYes
};


void h01_readTheInputFileAndRecoverTheTwoHiddenThings(char *, vector<vector<int>> &, vector<int> &);
void h02_checkTheOneThArgument_forAll3Codes(vector<vector<int>>, vector<int>, enum testValidity &);
//void h03_checkTheTwoThCommanLineArgument_forCode1(string, vector<vector<int>>, enum testValidity &);
void h03_checkTheTwoThCommanLineArgument_forCode2(string, vector<vector<int>>, enum testValidity &, vector<unsigned int> &theTwoThCommandLineArgumentIntegerForCode2Inters);
void h03_checkTheTwoThCommanLineArgument_forCode3(string myTwoThArgumentStringForCode3, int &myTwoThArgumentIntegerForCode3, enum testValidity &myValidORnotArgumentTwoThForCode3);
//void h04_driverForCode1(vector<vector<int>> &, vector<int> &, int, vector<vector<int>> &theNewGraph, vector<int> &theNewBiColoration);
void h04_driverForCode2(vector<vector<int>> &, vector<int> &, vector<unsigned int>, vector<string> theParameter1, vector<string> theParameter2);
int h04_driverForCode3(vector<vector<int>> theHiddenGraphInTheInputFile, vector<int> theHiddenBiColorationInTheInputFile, int theTwoThArgumentIntegerForCode3, vector<vector<vector<int>>> &theSetOfAllGraphs, vector<vector<int>> &theSetOfAllBicolorations, vector<string> &setOfAllLexico);
void h05_doLocalComplementationUsingOnePivotVertex(vector<vector<int>> myGraph, vector<int> theNeighborsOfPivot, vector<vector<int>> &theNewGraph, int deleteLaterPivotVertex);
void h06_doColorReversal(vector<int> myOldBicoloration, vector<int> theNeighborsOfPivot, vector<int> &myNewBicoloration);
void h07_showMatrixGraph(vector<vector<int>>, string);
void h08_showMatrixBiCOloration(vector<int>, string);
void h09_drawPNGorPDF(vector<vector<int>> myGraph, vector<int> myBicoloration, string parameter1, string parameter2);
//void h10_checkForCOlorInversion();
vector<int> h10_checkEquivalentGraphStructure(vector<vector<vector<int>>> theSetOfAllGraphs, vector<vector<int>> theSetOfAllBicolorations, vector<int> &resultGraphEq, vector<int> &resultBicolorEq, vector<string> setOfAllLexico);

void auxiliaryFile01_extractIntegerWords(string myLine,vector<vector<int>> &myGraph);
void auxiliaryFile02_extractIntegers(const string &, vector<unsigned int> &);
void auxiliaryFile03_calculateTwoParametersForNamingGraphForCode2(vector<string> &, vector<string> &, vector<unsigned int>);
void auxiliaryFile03_calculateTwoParametersForNamingGraphForCode3(vector<string> &, vector<string> &, vector<unsigned int>);
bool auxiliaryFile04_isInteger(const string &myString);
void auxiliaryFile05_computeSetOfLexiStrings(vector<string> &alphabet, int n, vector<string> &theSetOfAllLexicographicalString);
void auxiliaryFile06_generateStrings(const vector<string> alphabet, const string current, const int maxLength, const unsigned int currentLength, vector<string> &theSetOfAllLexicographicalStrings);



inline string getCurrentDateTime( string s ) {
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

inline void kumudLoggerThinkPad( string logMsg ) {

    string filePath = "../logfile01Kumud_" + getCurrentDateTime("date")+"-";
    string now = getCurrentDateTime("now");
    ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app );
    ofs << now << '\t' << logMsg << '\n';
    ofs.close();
}



int main(int argc, char **argv) {
	//vector<vector<int>> theInputFile;
	vector<vector<int>> theHiddenGraphInTheInputFile, oldGraph;
	vector<int> theHiddenBiColorationInTheInputFile, oldBiColoration;
	string theTwoThCommandLineArgumentString;
	//int theTwoThCommandLineArgumentIntegerForCode1 = stoi(*(argv + 2));
	int theTwoThArgumentIntegerForCode3;
	string theTwoThCommandLineArgumentIntegerForCode2String;
	vector<unsigned int> theTwoThCommandLineArgumentIntegerForCode2Inters;
	enum testValidity validORnotArgumentOneTh = IsValid;
	//enum testValidity validORnotArgumentTwoThForCode1 = IsValid;
	//enum testValidity validORnotArgumentTwoThForCode2 = IsValid;
	enum testValidity validORnotArgumentTwoThForCode3 = IsValid;
	int lastLength;
	string para1ForInitialGraph = "";
	vector<string> setOfAllLexico;
	//enum haveWeGotColorInversion doesThereExistAnEquivalentGraphStructure;
	//enum haveWeGotColorInversion doesWeHaveReverseColor = theAnswerIsNo;
	//enum haveWeGotColorInversion tellMeTheAnswer = theAnswerIsNo;

	vector<int> resultGraphEq;
	vector<int> resultBicolorEq;

	vector<vector<vector<int>>> theSetOfAllGraphs;
	vector<vector<int>> theSetOfAllBicolorations;
	vector<int> finalEquivalence;

	kumudLoggerThinkPad("\n\n\nExecution started at time " + getCurrentDateTime("now"));

	if( argc == 3 ) {
		cout << "The number of arguments is 3. All seems good. Keep going";
		h01_readTheInputFileAndRecoverTheTwoHiddenThings(*(argv + 1), theHiddenGraphInTheInputFile, theHiddenBiColorationInTheInputFile);
		h02_checkTheOneThArgument_forAll3Codes(theHiddenGraphInTheInputFile, theHiddenBiColorationInTheInputFile, validORnotArgumentOneTh);

		theSetOfAllGraphs.push_back(theHiddenGraphInTheInputFile);
		theSetOfAllBicolorations.push_back(theHiddenBiColorationInTheInputFile);
		//h03_checkTheTwoThCommanLineArgument_forCode1(*(argv + 2), theHiddenGraphInTheInputFile, validORnotArgumentTwoThForCode1);
		//h03_checkTheTwoThCommanLineArgument_forCode2(*(argv + 2), theHiddenGraphInTheInputFile, validORnotArgumentTwoThForCode2, theTwoThCommandLineArgumentIntegerForCode2Inters);
		h03_checkTheTwoThCommanLineArgument_forCode3(*(argv + 2), theTwoThArgumentIntegerForCode3, validORnotArgumentTwoThForCode3);

		oldGraph.clear();
		oldBiColoration.clear();
		oldGraph = theHiddenGraphInTheInputFile;
		oldBiColoration = theHiddenBiColorationInTheInputFile;

		if(validORnotArgumentOneTh == IsValid && validORnotArgumentTwoThForCode3 == IsValid) {
			lastLength = h04_driverForCode3(theHiddenGraphInTheInputFile, theHiddenBiColorationInTheInputFile, theTwoThArgumentIntegerForCode3, theSetOfAllGraphs, theSetOfAllBicolorations, setOfAllLexico);

			cout << endl << "In main. lastLength: " << lastLength << endl;
			for(int y1 = 1; y1 < lastLength; y1++) {
				cout << "0";
				para1ForInitialGraph = para1ForInitialGraph + "0";
			}

			h09_drawPNGorPDF(theHiddenGraphInTheInputFile, theHiddenBiColorationInTheInputFile, "0" + para1ForInitialGraph, "input-graph");


			cout << endl << "theSetOfAllGraphs.size(): " << theSetOfAllGraphs.size();
			cout << endl << "theSetOfAllBocoloratio.size(): " << theSetOfAllBicolorations.size();

			finalEquivalence = h10_checkEquivalentGraphStructure(theSetOfAllGraphs, theSetOfAllBicolorations, resultGraphEq, resultBicolorEq, setOfAllLexico);
		}
		else{
			cout << "The input is not valid";
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


void h02_checkTheOneThArgument_forAll3Codes(vector<vector<int>> myGraph, vector<int> myBiColoration, enum testValidity &myValidityForAll) {
	cout << endl << endl << "In h02_checkTheOneThArgument_forAll3Codes. " << endl;

	unsigned int theNumberOfVertices = myBiColoration.size();
	unsigned int numberOfRows = 0;

	for (vector<vector<int>>::iterator i1_myGraph = myGraph.begin(); i1_myGraph != myGraph.end(); i1_myGraph++) {
		if ((*i1_myGraph).size() != theNumberOfVertices) {
			myValidityForAll = IsNotValid;
			break;
		}
		numberOfRows++;
	}

	if (myValidityForAll == IsValid)
		if (numberOfRows != theNumberOfVertices) {
		myValidityForAll = IsNotValid;
	}

	return;
}

void h03_checkTheTwoThCommanLineArgument_forCode1(string myTwoThArgument, vector<vector<int>> myGraph, enum testValidity &myValidityForCode1) {
	cout << endl << endl << "In h03_checkTheTwoThCommanLineArgument_forCode1" << endl;
	unsigned int myTwoThArgumentIntererForm = stoi(myTwoThArgument);

	if(myTwoThArgumentIntererForm < 0 || myTwoThArgumentIntererForm >= myGraph.size()) {
		cout << "The input graph has only " << myGraph.size() << " vertices, and you have entered a pivot vertex which is invalid. Bye." << endl;
		myValidityForCode1 = IsNotValid;
	}

	return;
}

void h03_checkTheTwoThCommanLineArgument_forCode2(string myTwoThArgumentString, vector<vector<int>> myGraph, enum testValidity &myValidityForCode2, vector<unsigned int> &theTwoThCommandLineArgumentIntegerForCode2Inters) {
	cout << endl << endl << "In h03_checkTheTwoThCommanLineArgument_forCode2" << endl;



	cout << myTwoThArgumentString << endl;
	auxiliaryFile02_extractIntegers(myTwoThArgumentString, theTwoThCommandLineArgumentIntegerForCode2Inters);


	for(vector<unsigned int>::iterator i1_myTwoThArgumentInters = theTwoThCommandLineArgumentIntegerForCode2Inters.begin(); i1_myTwoThArgumentInters != theTwoThCommandLineArgumentIntegerForCode2Inters.end(); i1_myTwoThArgumentInters++) {
		cout << *i1_myTwoThArgumentInters << " ";
		if(*i1_myTwoThArgumentInters < 0 || *i1_myTwoThArgumentInters >= myGraph.size()) {
			cout << "The input graph has only " << myGraph.size() << " vertices, and you have entered a string which contains one vertex which is invalid. Bye." << endl;
			myValidityForCode2 = IsNotValid;
			break;
		}
	}

	return;
}

void h03_checkTheTwoThCommanLineArgument_forCode3(string myTwoThArgumentStringForCode3, int &myTwoThArgumentIntegerForCode3, enum testValidity &myValidORnotArgumentTwoThForCode3) {
	cout << endl << endl << "In h03_checkTheTwoThCommanLineArgument_forCode3" << endl;
	cout << myTwoThArgumentStringForCode3 << endl;
	bool boolResult;


	boolResult = auxiliaryFile04_isInteger(myTwoThArgumentStringForCode3);
	cout << "Bool result: " << boolResult << endl;


	if(boolResult == 1) {
		myValidORnotArgumentTwoThForCode3 = IsValid;
		myTwoThArgumentIntegerForCode3 = stoi(myTwoThArgumentStringForCode3);
	}
	else if (boolResult == 0) {
		cout << "Your 2th argument is not an integer";
	}
	else{
		cout << "Wrong code";
	}

	return;
}


void h04_driverForCode1(vector<vector<int>> &myOldGraph, vector<int> &myOldBiColoration, int myPivotVertex, vector<vector<int>> &theNewGraph, vector<int> &theNewBiColoration) {
	cout << endl << endl << "In h04_driverForCode1. " << endl;
	cout << "myPivotVertex: " << myPivotVertex << endl;

	vector<int> theNeighborsOfPivot;
	vector<int> thePivotRow;
	int indexOfNeighbor;

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
	h05_doLocalComplementationUsingOnePivotVertex(myOldGraph, theNeighborsOfPivot, theNewGraph, myPivotVertex);
	h07_showMatrixGraph(theNewGraph, "Calling from h04_driverForCode1");

	h08_showMatrixBiCOloration(myOldBiColoration, "Calling from h04_driverForCode1");
 	h06_doColorReversal(myOldBiColoration, theNeighborsOfPivot, theNewBiColoration);
 	h08_showMatrixBiCOloration(theNewBiColoration, "Calling from h04_driverForCode1");

 	//h09_drawPNGorPDF(theNewGraph, theNewBiColoration, "1", to_string(myPivotVertex));

	return;
}

void h04_driverForCode2(vector<vector<int>> &myOldGraph, vector<int> &myOldBicoloration, vector<unsigned int> theTwoThCommandLineArgumentIntegerForCode2Inters, vector<string> myParameter1,
		vector<string> myParameter2) {
	cout << endl << endl << "In h04_driverForCode2" << endl;

	//vector<vector<int>> theCopy_myOldGraph;
	//vector<int> theCopy_myOldBicoloration;


	vector<vector<int>> theNewGraph;
	vector<int> theNewBiColoration;
	vector<string> theParameter1, theParameter2;
	vector<unsigned int>::iterator i1_myListOfVertex;
	int j1;


	theNewGraph.clear();
	theNewBiColoration.clear();
	theParameter1.clear();
	theParameter2.clear();

	auxiliaryFile03_calculateTwoParametersForNamingGraphForCode2(theParameter1, theParameter2, theTwoThCommandLineArgumentIntegerForCode2Inters);

	for(i1_myListOfVertex = theTwoThCommandLineArgumentIntegerForCode2Inters.begin(), j1 = 0; i1_myListOfVertex != theTwoThCommandLineArgumentIntegerForCode2Inters.end(); i1_myListOfVertex++, j1++) {
		cout << endl << "***************************************************" << endl;
		cout << "Need to call driver-for-code1: " << *i1_myListOfVertex << endl;
		h04_driverForCode1(myOldGraph, myOldBicoloration, *i1_myListOfVertex, theNewGraph, theNewBiColoration);

		myOldGraph = theNewGraph;
		myOldBicoloration = theNewBiColoration;

	 	//h09_drawPNGorPDF(theNewGraph, theNewBiColoration, theParameter1[j1], theParameter2[j1]);

		theNewGraph.clear();
		cout << endl << "Is this clear problametic?" << endl;
		theNewBiColoration.clear();
	}

	return;
}


int h04_driverForCode3(vector<vector<int>> myHiddenGraphInTheInputFile, vector<int> myHiddenBiColorationInTheInputFile, int myTwoThArgumentIntegerForCode3, vector<vector<vector<int>>> &mySetOfAllGraphs, vector<vector<int>> &mySetOfAllBicolorations, vector<string> &setOfAllLexico) {
	cout << endl << endl << "In h04_driverForCode3" << endl;
	vector<string> alphabet;
	vector<string> eachStringConvertedToVectorOfStrings;
	vector<unsigned int> eachStringConvertedToVectorOfIntegers;
	int k = 0;
	vector<vector<int>> copyGraph;
	vector<int> copyBicoloration;
	vector<string> theParameter1, theParameter2;
	vector<string>::iterator f1, f2;
	vector<string>::iterator i1;
	string temp1;
	int i2;
	int lengthLastString, lengthCurrentString;

	alphabet.clear();
	//setOfAllLexico.clear();
	theParameter1.clear();
	theParameter2.clear();


	for(vector<int>::iterator i1 = myHiddenBiColorationInTheInputFile.begin(); i1 != myHiddenBiColorationInTheInputFile.end(); i1++, k++) {
		alphabet.push_back(to_string(k));
	}

	auxiliaryFile05_computeSetOfLexiStrings(alphabet, myTwoThArgumentIntegerForCode3, setOfAllLexico);
	cout << endl << "setOfAllLexico size: " << setOfAllLexico.size() << endl;

	lengthLastString = to_string(setOfAllLexico.size()).size();


	for(i1 = setOfAllLexico.begin(), i2 = 1; i1 != setOfAllLexico.end(); i1++, i2++) {
		lengthCurrentString = to_string(i2).size();
		temp1 = "";

		cout << endl << "i1 and i2: " << *i1 << " : " << i2 << ". Difference: " << lengthLastString << " minus " << lengthCurrentString << ". Add zero:";
		for(int g1 = 1; g1 <= lengthLastString - lengthCurrentString; g1++) {
			cout << "0";
			temp1 = temp1 + "0";
		}


		temp1 = temp1 + to_string(i2);





		theParameter1.push_back(temp1);
		theParameter2.push_back(*i1);
	}


	cout << endl << "Printing theParameter1 and theParameter2" << endl;

			for(f1 = theParameter1.begin(), f2 = theParameter2.begin(); f1 != theParameter1.end(); f1++, f2++) {
				cout << *f1 << " and " << *f2 << endl;
			}

			cout << endl;






	cout << endl << "The set of all lexico strings" << endl;
	for(i1 = setOfAllLexico.begin(), i2 = 0; i1 != setOfAllLexico.end(); i1++, i2++) {
		cout << endl << "=======================================================================" << endl;
		cout << endl << "Doing local complementation on " << *i1 << ". theParameter1: " << theParameter1[i2] << ". And theParameter2: " << theParameter2[i2] << endl;
		cout << endl << "=======================================================================" << endl;
		string temp1 = *i1;
		//cout << endl << "temp1: " << temp1 << " ? " << temp1[0] << typeid(temp1[0]).name() << endl;

		copyGraph = myHiddenGraphInTheInputFile;
		copyBicoloration = myHiddenBiColorationInTheInputFile;

		for(unsigned int i2 = 0; i2 < temp1.size(); i2++) {
			string y = to_string(temp1[i2]);
			int z = temp1[i2] - '0';
			//cout << "Push-z: " << z << " ";

			eachStringConvertedToVectorOfIntegers.push_back(z);

		}

		cout << endl << "Print h: ";
		for(vector<unsigned int>::iterator h = eachStringConvertedToVectorOfIntegers.begin(); h != eachStringConvertedToVectorOfIntegers.end(); h++) {
			cout << *h << " ";
		}



		//cout << endl << "theParameter1: " << theParameter1;
		//cout << endl << "theParameter2: " << theParameter2;


		//auxiliaryFile03_calculateTwoParametersForNamingGraphForCode3(theParameter1, theParameter2, eachStringConvertedToVectorOfIntegers);





		cout << endl;




		//call h04
		h04_driverForCode2(copyGraph, copyBicoloration, eachStringConvertedToVectorOfIntegers, theParameter1, theParameter2) ;


		cout << endl << "Draw graph for " << theParameter1[i2] << " and " << theParameter2[i2];
		h09_drawPNGorPDF(copyGraph, copyBicoloration, theParameter1[i2], theParameter2[i2]);
		cout << endl << "Drawing done" << endl;

		mySetOfAllGraphs.push_back(copyGraph);
		mySetOfAllBicolorations.push_back(copyBicoloration);


		copyGraph.clear();
		copyBicoloration.clear();
		eachStringConvertedToVectorOfIntegers.clear();
		//theParameter1.clear();
		//theParameter2.clear();



	}








	return lengthLastString;
}




void h05_doLocalComplementationUsingOnePivotVertex(vector<vector<int>> myOldGraph, vector<int> myneighborsOfPivot, vector<vector<int>> &myNewGraph, int deleteLaterPivotVertex) {
	cout << endl << endl << "In h05_doLocalComplementationUsingOnePivotVertex: " << deleteLaterPivotVertex << endl;

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

	cout << "theNeighborsOfPivot: ";
	for(vector<int>::iterator i1 = theNeighborsOfPivot.begin(); i1 != theNeighborsOfPivot.end(); i1++) {
		cout << *i1 << " ";
	}

	cout << endl;

	/* Copying myOldBicoloration to myNewBicoloration
	 *
	 */
	cout << "Copying myOldBicoloration to myNewBicoloration";
	for(vector<int>::iterator i1_myOldBicoloration = myOldBiColoration.begin(); i1_myOldBicoloration != myOldBiColoration.end(); i1_myOldBicoloration++) {
		myNewBiColoration.push_back(*i1_myOldBicoloration);
	}

	cout << "Changing neighbors.";
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


vector<int> h10_checkEquivalentGraphStructure(vector<vector<vector<int>>> theSetOfAllGraphs,
		vector<vector<int>> theSetOfAllBicolorations, vector<int> &resultGraphEq,
		vector<int> &resultBicolorEq, vector<string> setOfAllLexico) {
	//theAnswerIsNo
	cout << endl << endl << "In h10_checkEquivalentGraphStructure. " << endl;

	vector<vector<int>> theInitialGraph;
	vector<int> theInitialBicoloration;
	vector<int> finalEquivalence;

	vector<vector<int>>::iterator p0, p1;
	vector<int> row0, rowThis;

	vector<int>::iterator q0, q1;

	vector<int>::iterator h0;
	vector<vector<int>>::iterator h1;

	vector<int> rrow, rrowThis;
	vector<int>::iterator qq0, qq1;

	vector<int>::iterator x0, x1;

	vector<int>::iterator x2, x3;
	vector<string>::iterator i1_setOfAllLexico;
	int counter = 0;



	theInitialGraph = theSetOfAllGraphs[0];
	theInitialBicoloration = theSetOfAllBicolorations[0];

	for(vector<vector<vector<int>>>::iterator i1 = theSetOfAllGraphs.begin(); i1 != theSetOfAllGraphs.end(); i1++) {
		vector<vector<int>> temp1 = *i1;
		cout << endl << "Check this Vs initial: ";

		int equalOrNotGraph = 93; //equal
		for(p0 = theInitialGraph.begin(), p1 = temp1.begin(); p0 != theInitialGraph.end(); p0++, p1++) {
			row0 = *p0;
			rowThis = *p1;

			for(q0 = row0.begin(), q1 = rowThis.begin(); q0 != row0.end() ;q0++, q1++) {
				if(*q0 != *q1) {
					equalOrNotGraph = 94; //not equal
					break;
				}

			}




		}
		cout << "equalOrNotGraph: " << equalOrNotGraph;

		resultGraphEq.push_back(equalOrNotGraph);

	}




	int equalOrNotBicolor;





	for(vector<vector<int>>::iterator h1 = theSetOfAllBicolorations.begin(); h1 != theSetOfAllBicolorations.end(); h1++) {
		vector<int> temp2 = *h1;

		cout << "================" << endl;

		equalOrNotBicolor = 45; // notequal

		for(x0 = theSetOfAllBicolorations[0].begin(), x1 = temp2.begin(); x0 != theSetOfAllBicolorations[0].end(); x0++, x1++) {
			cout << endl << "*x0: " << *x0 << ". And *x1: " << *x1;

			if(*x0 == *x1) {
				equalOrNotBicolor = 46; // equal
				cout << "Entering loop?" << endl;
				break;
			}

		}
		cout << endl << "equalOrNotBicolor: " << equalOrNotBicolor;
		resultBicolorEq.push_back(equalOrNotBicolor);
		cout << endl;
	}


	int hj;


	cout << "Size of resultGraphEq: " << resultGraphEq.size() << endl;
	cout << "Size of setOfAllLexico: " << setOfAllLexico.size() << endl;
	cout << "Size of resultBicolorEq: " << resultBicolorEq.size() << endl;
	cout << "Size of theSetOfAllBicolorations: " << theSetOfAllBicolorations.size() << endl;


	for(x2 = resultGraphEq.begin() + 1, x3 =resultBicolorEq.begin() + 1, hj = 0, i1_setOfAllLexico = setOfAllLexico.begin(), counter = 0; x2 != resultGraphEq.end(); x2++, x3++, hj++, i1_setOfAllLexico++, counter++) {
		if(*x2 == 93 && *x3 == 45) {
			cout << endl << "Is color Inversion achieved: " << *i1_setOfAllLexico << " at " << counter << ". Bicoloration: ";

			for(vector<int>::iterator u1 = theSetOfAllBicolorations[counter + 1].begin(); u1 != theSetOfAllBicolorations[counter + 1].end(); u1++) {
				cout << *u1 << " ";
			}
			cout << endl;
			for(vector<vector<int>>::iterator u5 = theSetOfAllGraphs[counter + 1].begin(); u5 != theSetOfAllGraphs[counter + 1].end(); u5++) {
				vector<int> temp1 = *u5;
				vector<int>::iterator u6;
				for(u6 = temp1.begin(); u6 != temp1.end(); u6++) {
					cout << *u6 << " ";
				}
				cout << endl;
			}
			cout << endl;


		}
		else {
			cout << endl << "color Inversion not achieved: " << *i1_setOfAllLexico << ". Array index: " << counter;
		}
	}
	
	cout << endl;

	cout << "Total: " << hj << endl;
	cout << setOfAllLexico.size();







	return finalEquivalence;
}
void h11_checkReversecolor(vector<vector<int>> theSetOfAllBicolorations, enum haveWeGotColorInversion &doesWeHaveReverseColor) {
	cout << endl << endl << "In h11_checkReversecolor. " << endl;

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


void auxiliaryFile02_extractIntegers(const string &str, vector<unsigned int> &extracted) {
	cout << endl << endl << "In auxiliaryFile02_extractIntegers. " << endl;

    stringstream ss(str);
    vector<int> integers;
    unsigned int num;
    while (ss >> num) {
        //integers.push_back(num);
        extracted.push_back(num);
    }
    return;
}

void auxiliaryFile03_calculateTwoParametersForNamingGraphForCode2(vector<string> &myParameter1, vector<string> &myParameter2, vector<unsigned int> theTwoThCommandLineArgumentIntegerForCode2Inters) {
	cout << endl << endl << "In auxiliaryFile03_calculateTwoParametersForNamingGraph. " << endl;

	unsigned int rr = theTwoThCommandLineArgumentIntegerForCode2Inters.size();
	//unsigned int rr = 11;
	int LastNumber = rr;
	int difference = -8;
	string p1;

	cout << theTwoThCommandLineArgumentIntegerForCode2Inters.size() << endl << endl;

	for(unsigned int i1 = 1; i1 <= rr; i1++) {
		int currentNUmber = i1;
		p1 = "";

		difference = to_string(LastNumber).size() - to_string(currentNUmber).size();

		//cout << "currentNUmber: " << currentNUmber << ". LastNumber: " << LastNumber << ". Difference: " << difference << ". FinalPrameter1: ";
		for(int i2 = 1; i2 <= difference; i2++) {
			//cout << "0";
			p1 = p1 + "0";
		}
		p1 = p1 + to_string(currentNUmber);
		myParameter1.push_back(p1);
		//cout << currentNUmber;


		 //cout << ". FinalPrameter2: ";
		 string temp1 = "";
		 for(int i3 = 0; i3 < currentNUmber; i3++) {
			 //cout << theTwoThCommandLineArgumentIntegerForCode2Inters[i3];
			 temp1 = temp1 + to_string(theTwoThCommandLineArgumentIntegerForCode2Inters[i3]);
		 }
		 //cout << temp1;
		 myParameter2.push_back(temp1);

		cout << endl;
	}

	return;
}

void auxiliaryFile03_calculateTwoParametersForNamingGraphForCode3(vector<string> &myParameter1, vector<string> &myParameter2, vector<unsigned int> theTwoThCommandLineArgumentIntegerForCode2Inters) {
	cout << endl << "In auxiliaryFile03_calculateTwoParametersForNamingGraphForCode3" << endl;


	return;
}


bool auxiliaryFile04_isInteger(const string& myString) {
	cout << endl << endl << "In auxiliaryFile04_isInteger. " << endl;

    if (myString.empty()) {
        return false; // Empty string is not an integer
    }
    std::istringstream iss(myString);
    int value;
    iss >> value;
    // Check if conversion was successful AND no extra characters remain
    return iss.eof() && !iss.fail();
}






void auxiliaryFile05_computeSetOfLexiStrings(vector<string> &alphabet, int n, vector<string> &theSetOfAllLexicographicalStrings) {
	cout << endl << endl << "In auxiliaryFile05_computeSetOfLexiStrings. " << endl;

	//cout << "alphabet size before: " << alphabet.size() << endl;
	//cout << "n: " << n << endl;

/*
	for(vector<string>::iterator j = alphabet.begin(); j != alphabet.end(); j++) {
		cout << "Alphabet: " << *j << endl;
	}
*/


	//int sizeOfAlphabet = alphabet.size();
	/*for(int i = 0; i < sizeOfAlphabet; i++) {
		//cout << endl << to_string(i);
		alphabet.push_back(to_string(i));
	}*/
	//alphabet = {"0", "1", "2"};  // You can modify this
	//
	//

	//cout << "alphabet size after why six: " << alphabet.size() << endl;



	// Ensure alphabet is in lexicographic order
	sort(alphabet.begin(), alphabet.end());

	//cout << "alphabet size after: " << alphabet.size() << endl;


	for (int length = 1; length <= n; ++length) {
		//cout << "Length " << length << ":\n";
		auxiliaryFile06_generateStrings(alphabet, "", n, length, theSetOfAllLexicographicalStrings);
	}


	return;
}

// Recursive function to generate strings of a specific length
void auxiliaryFile06_generateStrings(const vector<string> alphabet, const string current, const int maxLength, const unsigned int currentLength, vector<string> &theSetOfAllLexicographicalStrings) {
	//cout << endl << endl << "In auxiliaryFile06_generateStrings. " << endl;

	//cout << "alphabet size: " << alphabet.size() << endl;


	if (current.length() == currentLength) {
		//cout << current << "-" << endl;
		theSetOfAllLexicographicalStrings.push_back(current);
		return;
	}

    for (string ch : alphabet) {
    	auxiliaryFile06_generateStrings(alphabet, current + ch, maxLength, currentLength, theSetOfAllLexicographicalStrings);
    }
}

