#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>







using namespace std;

void f01_read_input(vector<vector<int>> &, vector<int> &, char *);
void f02_extractIntegerWords(string str,vector<vector<int>> &);
void f03_local_complementation(vector<vector<int>> &, int);
void f04_color_reversal();
void f05_showMyGraph(vector<vector<int>> &, vector<int> &myBicoloration);

int main(int argc, char **argv) {
	vector<vector<int>> theGraph;
	vector<int> theBicoloration;
	int a = 0;
	f01_read_input(theGraph, theBicoloration, *(argv + 1));

	//f05_showMyGraph(theGraph);
	//f03_local_complementation(theGraph, a);
	//f04_color_reversal();


	//cout << endl << "Test arguments: " << argc << ": " << *(argv + 0) << *(argv + 1);

	return 0;
}

void f01_read_input(vector<vector<int>> &myGraph, vector<int> &myBicoloration, char *theFilename) {
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
			std::cout << line << std::endl;
			//v1.push_back(line);
			//
			f02_extractIntegerWords(line, myGraph);


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
    for (int i = 0; i < v2.size(); i++) {
	    for (int j = 0; j < v2[i].size(); j++) {
		    cout << v2[i][j] << " ";
	    }

	    cout << endl;
    }

        cout << endl << "---------------" << endl;

}

void f03_local_complementation(vector<vector<int>> &myGraph, int a) {
	cout << endl << "In f02_local_complementation";
	cout << endl << "Print v2 and a" << endl;

	for (unsigned int i = 0; i < myGraph.size(); i++) {
	    for (unsigned int j = 0; j < myGraph[i].size(); j++) {
		    cout << myGraph[i][j] << " ";
	    }

	    cout << endl;
    }



	cout << endl << "Value of a: " << a << endl;

	//kumud start

	//int arr[3];
	vector<int> arr;
	int i = 0;
	int x;

	for(x = 0; x <= 4; x++) {
		if(myGraph[a][x] == 1) {
			arr.push_back(x);

			//arr[i++] = x;
		}
	}



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

	p1_myGraph = myGraph.begin();
	//p2 = (*p1_myGraph).begin();
	cout << "Hy 1" << endl;
	//p2 = (*p1_myGraph).begin();
	cout << typeid(p2).name() << endl;
	cout << typeid((*p1_myGraph).begin()).name() << endl;

	while(p1_myGraph != myGraph.end()) {
		cout << endl << "Hy" << endl;
		cout << "ok" << (*p1_myGraph)[0] << " : ";
		//temp1 = *p1_myGraph;
		p2 = (*p1_myGraph).begin();

		while(p2 != (*p1_myGraph).end()) {
			cout << "p2: " << *p2 << endl;
			p2++;
		}
		p1_myGraph++;
	}

	cout << "Showing color" << endl;
	return;
}

