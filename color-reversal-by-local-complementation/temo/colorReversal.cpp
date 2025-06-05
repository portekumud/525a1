#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>







using namespace std;

void f01_read_input(vector<vector<int>> &);
void f02_extractIntegerWords(string str,vector<vector<int>> &); 
void f03_local_complementation(vector<vector<int>> &, int);
void f04_color_reversal();

int main(int argc, char **argv) {
	vector<vector<int>> v2;
	int a = 0;
	f01_read_input(v2);
	f03_local_complementation(v2, a);
	f04_color_reversal();

	return 0;
}

void f01_read_input(vector<vector<int>> &v2) {
	//cout << endl << "In read input:  " << fileName[1] << endl;
    	//vector<vector<int>> v2;
        //vector<int> v1;
	
	std::ifstream file("input01");

	if (file.is_open()) {
		std::string line;
		
		//v1.clear();
		
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
			//v1.push_back(line);
			//
			f02_extractIntegerWords(line, v2);


	//	    v2.push_back({7, 8, 9});

		}
		file.close();

	} else {
		std::cerr << "Unable to open file." << std::endl;
	}

    
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

void f03_local_complementation(vector<vector<int>> &v2, int a) {
	cout << endl << "In f02_local_complementation";
	cout << endl << "Print v2 and a" << endl;
	
	for (int i = 0; i < v2.size(); i++) {
	    for (int j = 0; j < v2[i].size(); j++) {
		    cout << v2[i][j] << " ";
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
		if(v2[a][x] == 1) {
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


