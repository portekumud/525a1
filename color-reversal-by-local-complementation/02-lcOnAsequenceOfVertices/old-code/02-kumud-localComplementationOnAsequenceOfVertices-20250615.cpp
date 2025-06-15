#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <string>


using namespace std;

enum equalORnot {
  yesEqual,
  NotEqual
};

void f01_read_input(vector<vector<int>> &, vector<int> &, char *);
void f02_extractIntegerWords(string, vector<vector<int>> &);
void f03_local_complementation(vector<vector<int>> &, string, vector<vector<int>> &, vector<int>, vector<int> &, vector<int> &);
void f04_color_reversal();
void f05_showMyGraph(vector<vector<int>> &, vector<int> &);
void f06_drawGraph(vector<vector<int>>, vector<int>, string, string);
void extractIntegers(const string &, vector<int> &);
void f08_pleaseClearAll(vector<int> &, vector<int> &, vector<vector<int>> &);
void f09_adjustForNextLoop(vector<vector<int>> &, vector<vector<int>> &, vector<int> &, vector<int> &);
void f10_getTheTwoArgumentForDrawingGraph(vector<int>, vector<string> &, vector<string> &);
void f11_writeTheOutputGraph(vector<vector<vector<int>>> allGraphs, vector<vector<int>> allBicoloration);
void f12_checkIdentical(vector<vector<vector<int>>> allGraphs, vector<vector<int>> allBicoloration, enum equalORnot &);




int main(int argc, char **argv) {
	vector<vector<int>> theGraph;
	vector<int> theBicoloration;
	vector<int> theNewBicoloration;
	vector<vector<int>> myNewGraph;
	vector<int> theNeighborsOfA;
	string a;
	vector<int> extracted;
	vector<string> parameter1_forDrawing, parameter2_forDrawing;
	vector<string>::iterator i1_parameter1_forDrawing, i2_parameter2_forDrawing;
	vector<int>::iterator i3_extracted;
	vector<vector<vector<int>>> allGraphs;
	vector<vector<int>> allBicoloration;

	enum equalORnot checkEqualOrNot = yesEqual;


	//a = "2 1 0 1 2 0 2 1 0 1 1";
	a = *(argv + 2);
	//a = "2";
	f01_read_input(theGraph, theBicoloration, *(argv + 1));
	allGraphs.push_back(theGraph);
	allBicoloration.push_back(theNewBicoloration);


	cout << endl << "Separate a: ";


	 extractIntegers(a, extracted);
 	f10_getTheTwoArgumentForDrawingGraph(extracted, parameter1_forDrawing, parameter2_forDrawing);

	 for (int num : extracted) {
		 std::cout << endl << "Elements of a: " << num << " ";
	 }


	 for(i3_extracted = extracted.begin(), i1_parameter1_forDrawing = parameter1_forDrawing.begin(), i2_parameter2_forDrawing = parameter2_forDrawing.begin(); i3_extracted != extracted.end(); i3_extracted++, i1_parameter1_forDrawing++, i2_parameter2_forDrawing++) {

	    //for (int num : extracted) {
	    	std::cout << endl << endl << endl << endl << "Calling LC via " << *i3_extracted << " only";
	    	f05_showMyGraph(theGraph, theBicoloration);
	    	f08_pleaseClearAll(theNewBicoloration, theNeighborsOfA, myNewGraph);

	    	f03_local_complementation(theGraph, to_string(*i3_extracted), myNewGraph, theBicoloration, theNeighborsOfA, theNewBicoloration);
	    	allGraphs.push_back(myNewGraph);
	    	allBicoloration.push_back(theNewBicoloration);

	    	f09_adjustForNextLoop(theGraph, myNewGraph, theBicoloration, theNewBicoloration);




	    	f05_showMyGraph(theGraph, theBicoloration);
	    	f06_drawGraph(theGraph, theBicoloration, *i1_parameter1_forDrawing, *i2_parameter2_forDrawing);
	    	f11_writeTheOutputGraph(allGraphs, allBicoloration);
	    	f12_checkIdentical(allGraphs, allBicoloration, checkEqualOrNot);





	    	//void f06_drawGraph(theGraph, theBicoloration, string nameIndex, string nameTitle);
	    }
	    std::cout << std::endl;




	    i1_parameter1_forDrawing = parameter1_forDrawing.begin();
	    i2_parameter2_forDrawing = parameter2_forDrawing.begin();

	    while(i1_parameter1_forDrawing != parameter1_forDrawing.end()) {

	    		cout << endl << *i1_parameter1_forDrawing << "-" << *i2_parameter2_forDrawing << endl;
	    	i1_parameter1_forDrawing++;
	    	i2_parameter2_forDrawing++;

	    }





	//f03_local_complementation(theGraph, a, myNewGraph, theBicoloration, theNeighborsOfA, theNewBicoloration);
	//f04_color_reversal();


	//cout << endl << "Test arguments: " << argc << ": " << *(argv + 0) << *(argv + 1);

	return 0;
}

void f01_read_input(vector<vector<int>> &myGraph, vector<int> &myBicoloration, char * theFilename) {
	//cout << endl << "In read input:  " << fileName[1] << endl;
    	//vector<vector<int>> v2;
        //vector<int> v1;
	vector<vector<int>>::iterator p1_myGraph;
	vector<int>::iterator p2;
	vector<int> temp1;
	void *temp2;

	std::ifstream readFile(theFilename);

	//cout << "theFilename: " << theFilename;







	cout << "Hy 2" << endl;

	if (readFile.is_open()) {
		std::string line;

		//v1.clear();

		while (std::getline(readFile, line)) {
			std::cout << line << typeid(line).name() << ": " << line[0] << endl;

			if (line[0] == '/' || line[0] == '*') {
				cout << "Not an integer" << endl;
						}


			else {
				cout << "Yes an integer" << endl;


			//v1.push_back(line);
			//
			f02_extractIntegerWords(line, myGraph);
			}


	//	    v2.push_back({7, 8, 9});

		}
		readFile.close();

	} else {
		std::cerr << "Unable to open file " << theFilename << "." << std::endl;
	}

   	//myBicoloration.push_back(myGraph[myGraph.size() - 1]);
	//
	//
	cout << endl << "The length is: " << myGraph.size() << endl;
	//cout << endl << "The length is: " << myBicoloration.size() << " : ";// << *p1_myGraph;
	//
	//cout << *p1_myGraph[0];


	/*

	p1_myGraph = myGraph.begin();
		//p2 = (*p1_myGraph).begin();
		cout << "Hy 1" << endl;
		//p2 = (*p1_myGraph).begin();
		cout << typeid(p2).name() << endl;
		cout << typeid((*p1_myGraph).begin()).name() << endl;

		while(p1_myGraph != myGraph.end()) {
			cout << "Hy";
			cout << "ok" << (*p1_myGraph)[0] << " : ";
			//temp1 = *p1_myGraph;
			p2 = (*p1_myGraph).begin();

			while(p2 != (*p1_myGraph).end()) {
					cout << "p2: " << *p2 << endl;
					p2++;
					}
			p1_myGraph++;
		}


		*/

//
	p1_myGraph = myGraph.end() - 1;
	p2 = (*p1_myGraph).begin();
	while(p1_myGraph != myGraph.end()) {
				cout << "Hy color" << endl;
				cout << "ok color: " << (*p1_myGraph)[0] << " : ";
				//temp1 = *p1_myGraph;
				p2 = (*p1_myGraph).begin();

				while(p2 != (*p1_myGraph).end()) {
						cout << "p2: " << *p2 << endl;
						myBicoloration.push_back(*p2);
						p2++;
						}
				p1_myGraph++;
	}
	p1_myGraph  = p1_myGraph - 1;

	myGraph.erase(p1_myGraph, p1_myGraph + 1);



	/*for (int i = 0; i < myGraph.size() - 1; ++i) {
		(*p1_myGraph).pop_back();
	}
*/


	cout << endl << "yahoo 1" << endl;
	f05_showMyGraph(myGraph, myBicoloration);
	f06_drawGraph(myGraph, myBicoloration, "00", "initial");




	return;
}

void f02_extractIntegerWords(string str,vector<vector<int>> &v2) {
    stringstream ss;

    vector<int> v1;
	cout << endl << "Yahoo 1" << endl;
    /* Storing the whole string into string stream */
    ss << str;
    /* Running loop till the end of the stream */
    string temp;
    int found;
    v1.clear();
    while (!ss.eof()) {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found)
            cout << ":" << found << " ";
	v1.push_back(found);

        /* To save from space at the end of string */
        temp = "";
    }
    v2.push_back(v1);
    cout << endl << "Yahoo 2" << endl;

    cout << endl << "printing vector: " << endl;
    for (unsigned int i = 0; i < v2.size(); i++) {
	    for (unsigned int j = 0; j < v2[i].size(); j++) {
		    cout << v2[i][j] << " ";
	    }

	    cout << endl;
    }

        cout << endl << "---------------" << endl;

}

void f03_local_complementation(vector<vector<int>> &myGraph, string a11, vector<vector<int>> &myNewGraph, vector<int> theBicoloration, vector<int> &theNeighborsOfA, vector<int> &theNewBicoloration) {

	//vector<int> theNeighborsOfA;
	vector<int>::iterator p1_myGraphSingle;
	vector<vector<int>>::iterator p1_myGraphDouble;
	vector<int>::iterator p2_theNeighborsOfA;
	vector<int>::iterator p3_theNeighborsOfA;
	vector<vector<int>> ::iterator p4_theLCtoDo;
	vector<vector<int>> theLCtoDo;
	vector<vector<int>>::iterator p5_myNewGraph;
	vector<int> temp1, temp2;
	string lastChar;
	int a;
	vector<int>::iterator p6_theBicoloration;

	lastChar = a11[a11.length() - 1];

	a = stoi(lastChar);

	cout << stoi(lastChar);


	int i = 0;

	cout << endl << "In f02_local_complementation";
	cout << endl << "Print v2 and a" << endl;

	cout << endl << "This is input graph: " << endl;
	for (unsigned int i = 0; i < myGraph.size(); i++) {
	    for (unsigned int j = 0; j < myGraph[i].size(); j++) {
		    cout << myGraph[i][j] << " ";
	    }

	    cout << endl;
    }


	p1_myGraphSingle = myGraph[a].begin();


	cout << endl << "This is pivot a: " << a << endl;
	cout << endl << "Neighbors of a: " << endl;

	while(p1_myGraphSingle != myGraph[a].end()) {
		if(*p1_myGraphSingle == 1) {
			cout << "This is one neighbor: " << i << endl;
			theNeighborsOfA.push_back(i);
		}
		p1_myGraphSingle++;
		i++;
	}

	//for(p2_theNeighborsOfA = theNeighborsOfA.begin(), p3_theNeighborsOfA = theNeighborsOfA.begin(); p2_theNeighborsOfA != theNeighborsOfA.end(), p3_theNeighborsOfA != theNeighborsOfA; p2_theNeighborsOfA++, p3_theNeighborsOfA++) {
	for(p2_theNeighborsOfA = theNeighborsOfA.begin(); p2_theNeighborsOfA != theNeighborsOfA.end(); p2_theNeighborsOfA++) {
		for(p3_theNeighborsOfA =theNeighborsOfA.begin(); p3_theNeighborsOfA != theNeighborsOfA.end(); p3_theNeighborsOfA++) {
			if (*p2_theNeighborsOfA < *p3_theNeighborsOfA) {

		cout << *p2_theNeighborsOfA << " : " << *p3_theNeighborsOfA << endl;
		//theLCtoDo.push_back(__x)
		temp1.push_back(*p2_theNeighborsOfA);
		temp1.push_back(*p3_theNeighborsOfA);
		theLCtoDo.push_back(temp1);
		temp1.clear();
			}
		}
		cout << endl;
	}



for(p1_myGraphDouble = myGraph.begin(); p1_myGraphDouble != myGraph.end(); p1_myGraphDouble++) {
	vector<int> oneRow = *p1_myGraphDouble;
	for(vector<int>::iterator p2_oneRow = (*p1_myGraphDouble).begin(); p2_oneRow != (*p1_myGraphDouble).end(); p2_oneRow++) {
		cout << *p2_oneRow << " ";
		temp2.push_back(*p2_oneRow);

	}
	myNewGraph.push_back(temp2);
	temp2.clear();
	cout << endl << "***" << endl;
}


	p6_theBicoloration = theBicoloration.begin();
	while(p6_theBicoloration != theBicoloration.end()) {
		theNewBicoloration.push_back(*p6_theBicoloration);
		p6_theBicoloration++;
	}












	p1_myGraphDouble = myGraph.begin();
	for(p4_theLCtoDo = theLCtoDo.begin(); p4_theLCtoDo != theLCtoDo.end(); p4_theLCtoDo++) {
		cout << endl  << "---------" << endl << (*p4_theLCtoDo)[0] << " - " << (*p4_theLCtoDo)[1] << endl;


		if(p1_myGraphDouble[(*p4_theLCtoDo)[0]][(*p4_theLCtoDo)[1]] == 1) {
			cout << ": conected. Change it" << endl;
			myNewGraph[(*p4_theLCtoDo)[0]][(*p4_theLCtoDo)[1]] = 0;
		}
		else {
			cout << ": Not conected. Change it" << endl;
			myNewGraph[(*p4_theLCtoDo)[0]][(*p4_theLCtoDo)[1]] = 1;
				}

		if(p1_myGraphDouble[(*p4_theLCtoDo)[1]][(*p4_theLCtoDo)[0]] == 1) {
					cout << ": conected. Change it" << endl;
					myNewGraph[(*p4_theLCtoDo)[1]][(*p4_theLCtoDo)[0]] = 0;
				}
				else {
					cout << ": Not conected. Change it" << endl;
					myNewGraph[(*p4_theLCtoDo)[1]][(*p4_theLCtoDo)[0]] = 1;
				}
	}





	//kumud start

	//int arr[3];

	//f05_showMyGraph(myGraph, theBicoloration);

	//f05_showMyGraph(myNewGraph, theBicoloration);




	p6_theBicoloration = theNewBicoloration.begin();

	cout << "The new bicoloration before change" << endl;
	while(p6_theBicoloration != theNewBicoloration.end()) {
		cout << *p6_theBicoloration << " ";
		p6_theBicoloration++;
	}


	for(p2_theNeighborsOfA = theNeighborsOfA.begin(); p2_theNeighborsOfA != theNeighborsOfA.end(); p2_theNeighborsOfA++) {
		cout << "Change this only: " << *p2_theNeighborsOfA << endl;

		if(theNewBicoloration[*p2_theNeighborsOfA] == 1) {
			theNewBicoloration[*p2_theNeighborsOfA] = -1;
		}
		else if (theNewBicoloration[*p2_theNeighborsOfA] == -1) {
			theNewBicoloration[*p2_theNeighborsOfA] = 1;

		}
		else {
			cout << "Wrong code" << endl;
		}

	}
	cout << endl << "How 3? " << myNewGraph.size() << endl;



	cout << "The new bicoloration after change" << endl;
	p6_theBicoloration = theNewBicoloration.begin();
	while(p6_theBicoloration != theNewBicoloration.end()) {
		cout << *p6_theBicoloration << " ";
		p6_theBicoloration++;
	}


	//		f06_drawGraph(myNewGraph, theNewBicoloration, "02", "afterLocalCom");

	cout << endl << "How 1? " << myGraph.size() << endl;
	cout << endl << "How 2? " << myNewGraph.size() << endl;




	//kumud end



















	return;
}

void f04_color_reversal() {
	cout << endl << "In f03_color_reversal";
	return;
}


void f05_showMyGraph(vector<vector<int>> &myGraph, vector<int> &myBicoloration) {
	vector<vector<int>>::iterator p1_myGraph;
	vector<int>::iterator p2;
	vector<int> temp1;

	cout << "Showing graph" << endl;

	cout << endl << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
	cout << endl << myGraph.size() << endl;

	p1_myGraph = myGraph.begin();
	//p2 = (*p1_myGraph).begin();
	cout << "Hy 1" << endl;
	//p2 = (*p1_myGraph).begin();
	cout << typeid(p2).name() << endl;
	cout << typeid((*p1_myGraph).begin()).name() << endl;

	while(p1_myGraph != myGraph.end()) {
		//cout << endl << "Hy. ";
		//cout << "Ok: " << (*p1_myGraph)[0] << " : " << endl ;

		p2 = (*p1_myGraph).begin();

		while(p2 != (*p1_myGraph).end()) {
			//cout << " p2: " << *p2 << endl;
			cout << *p2 << " ";
			p2++;
		}
		p1_myGraph++;
		cout << endl;
	}

	cout << endl << "Showing color in f05" << endl;

	p2 = myBicoloration.begin();
	while(p2 != myBicoloration.end()) {
		cout << *p2 << " ";
		p2++;
	}
	cout << endl << "bbbbbbbbbbbbbbbbbbbbbbbb" << endl;
	cout << endl;
	return;
}

void f06_drawGraph(vector<vector<int>> myGraph, vector<int> myBicoloration, string nameIndex, string nameTitle) {
	vector<vector<int>>::iterator p1_myGraph;
	string name = "graph" + nameIndex + "-" + nameTitle + ".py";
	vector<int>::iterator p2;
	int i = 0, j, k = 0;
	int theNumberOfVertices;
	//ofstream file("graph01-initial.py");


    ofstream file(name);



	cout << endl << "In f06_drawGrap. name: " << name;


	p1_myGraph = myGraph.begin();
	//k = myGraph.size();
	//cout << "k is: " << k;

	file << "import networkx as nx" << endl;
	file << "import matplotlib.pyplot as plt" << endl;
	file << "G = nx.Graph() " << endl;
	file << "plt.subplot(211)" << endl;
	file << "G.add_edges_from([";



	while(p1_myGraph != myGraph.end()) {
		cout << endl << "Hy" << endl;
		cout << "ok" << (*p1_myGraph)[0] << " : ";
		//temp1 = *p1_myGraph;
		p2 = (*p1_myGraph).begin();
		j = 0;
		while(p2 != (*p1_myGraph).end()) {
			if (*p2 == 1) {

				if (k == 0) {
					cout << " (one: " << i << ", " << j << " :one) ";
					file << "(" << i << ", " << j << ")";
					k++;
				}
				else {

					cout << " (one: " << i << ", " << j << " :one) ";
					file << ", (" << i << ", " << j << ")";
				}
			}
			cout << "p2: " << *p2 << endl;
			p2++;
			j++;
		}
		p1_myGraph++;
		i++;
	}

		cout << "Showing color" << endl;

		p2 = myBicoloration.begin();
		while(p2 != myBicoloration.end()) {
			cout << *p2 << " ";
			p2++;
		}

		file << "])";

		if (k == 1) {
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
		}

//		file << "#This is the graph.";
	//	file << "#This is the graph.";

		//file <<  endl <<"plt.subplot(211)" << endl;
		//file << "nx.draw_networkx(G)" << endl;
		file << endl << "plt.savefig('graph";
		file << nameIndex;
		file << "-";
		file << nameTitle;
		file << ".pdf')" << endl;

		file.close();





	return;
}

void extractIntegers(const std::string& str, std::vector<int> &extracted) {
    std::stringstream ss(str);
    std::vector<int> integers;
    int num;
    while (ss >> num) {
        //integers.push_back(num);
        extracted.push_back(num);
    }
    return;
}

void f08_pleaseClearAll(vector<int> &theNewBicoloration, vector<int> &theNeighborsOfA, vector<vector<int>> &myNewGraph) {
	theNewBicoloration.clear();
		    	theNeighborsOfA.clear();
		    	myNewGraph.clear();

	return;
}

void f09_adjustForNextLoop(vector<vector<int>> &theGraph, vector<vector<int>> &myNewGraph, vector<int> &theBicoloration, vector<int> &theNewBicoloration) {
	theGraph = myNewGraph;
		    	theBicoloration = theNewBicoloration;
		    	return;
}

void f10_getTheTwoArgumentForDrawingGraph(vector<int> myInput, vector<string> &parameter1_forDrawing, vector<string> &parameter2_forDrawing) {
	int temp1 = myInput.size();
	string theParameter1, theParameter2;
	vector<int>::iterator i1_myInput, i2_myInput;

	//cout << endl << "f10_getTheTwoArgumentForDrawingGraph. myInput size: " << myInput.size() << endl;


	for(int i1 : myInput) {
		cout << i1 << " ";
	}

	cout << endl;

	for (int var = 0; var < temp1; var++) {
		theParameter1 = "";
		for (long unsigned int var2 = 0; var2 < to_string(temp1).length() - to_string(var + 1).length(); var2++) {
			//cout << "0";
			theParameter1 = theParameter1 + "0";
		}
		//parameter1_forDrawing.push_back(to_string(var + 1));

		//cout << theParameter1 + to_string(var + 1) << " : " << to_string(var).length() << endl;
		parameter1_forDrawing.push_back(theParameter1 + to_string(var + 1));
	}
	cout << endl << "==========" << endl;

	for(i1_myInput = myInput.begin(); i1_myInput != myInput.end(); i1_myInput++) {
		theParameter2 = "";
		for(i2_myInput = myInput.begin(); i2_myInput < i1_myInput; i2_myInput++) {
			//cout << *i2_myInput;
			theParameter2 = theParameter2 + to_string(*i2_myInput);
		}

		//cout << theParameter2 + to_string(*i1_myInput) << endl;
		parameter2_forDrawing.push_back(theParameter2 + to_string(*i1_myInput));
	}


	return;
}


void f11_writeTheOutputGraph(vector<vector<vector<int>>> allGraphs, vector<vector<int>> allBicoloration) {
	string name = "theoutput";
	ofstream file(name, ios::app);
	vector<vector<int>> ::iterator p1_myGraph;
	vector<int>::iterator p2;


	//file << "import networkx as nx" << endl;
/*

	p1_myGraph = myGraph.begin();
	while(p1_myGraph != myGraph.end()) {
			//cout << endl << "Hy. ";
			//cout << "Ok: " << (*p1_myGraph)[0] << " : " << endl ;

			p2 = (*p1_myGraph).begin();

			while(p2 != (*p1_myGraph).end()) {
				//cout << " p2: " << *p2 << endl;
				//cout << *p2 << " ";
				file << *p2 << " ";
				p2++;
			}
			p1_myGraph++;
			//cout << endl;
			file << endl;
		}
*/

/*



	p2 = myBioloration.begin();
			while(p2 != myBioloration.end()) {
				file << *p2 << " ";
				p2++;
			}
	*/

	file.close();
	return;
}



void f12_checkIdentical(vector<vector<vector<int>>> allGraphs, vector<vector<int>> allBicoloration, enum equalORnot &checkEqualOrNot) {
	cout << endl << "In f12: " << allGraphs.size() << endl;

	vector<vector<int>> graphZero, graphLast;
	vector<vector<int>>::iterator i1_graphZero, i2_graphLast;

	vector<int> eachRowGraphZero, eachRowGraphLast;
	vector<int>::iterator i3_eachRowGraphZero, i4_eachRowGraphLast;
	string name = "equalOrNot";
		ofstream file(name, ios::app);

	graphZero = allGraphs[0];
	graphLast = allGraphs[allGraphs.size() - 1];


	i1_graphZero = allGraphs[0].begin();
	i2_graphLast = allGraphs[allGraphs.size() - 1].begin();

	while (i1_graphZero != allGraphs[0].end()) {
		eachRowGraphZero = *i1_graphZero;
		eachRowGraphLast = *i2_graphLast;

		i3_eachRowGraphZero = eachRowGraphZero.begin();
		i4_eachRowGraphLast = eachRowGraphLast.begin();
		while (i3_eachRowGraphZero != eachRowGraphZero.end()) {
			if (*i3_eachRowGraphZero != *i4_eachRowGraphLast) {
				checkEqualOrNot = NotEqual;
				break;
			}

			i3_eachRowGraphZero++;
			i4_eachRowGraphLast++;
		}


		i1_graphZero++;
		i2_graphLast++;
	}

	cout << endl << "After first comparison: ";
	file << "'Graph zero' and 'Graph " << allGraphs.size() - 1 << " are ";

	if (checkEqualOrNot == yesEqual) {
		cout << " equal (bicoloration checking pending)" << endl;
		file << "equal (bicoloration checking pending)" << endl;
	}
	else if (checkEqualOrNot == NotEqual) {
		cout << " not equal" << endl;
		file << "not equal" << endl;

	}
	else {
		cout << " wrong code" << endl;
	}

	file.close();



	return;
}






