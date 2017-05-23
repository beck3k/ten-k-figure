#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

struct Coord {
    int x;
    int y;
};

//vector<int> x;
//vector<int> y;
vector<Coord> c;

int target = 100;
int side_target = 9997;
int sides = 0;
/*
int printVectors(vector<int> v){
	for(int i = 0; i < v.size(); i++){
	    cout << v[i] << ", ";
	}
	cout << endl;
}
*/
void writeCoords(int xIn, int yIn){
    //x.push_back(xIn);
    //y.push_back(yIn);
    c.push_back(Coord{xIn, yIn});
    sides++;
}

int pyrry(){
    ofstream outputfile;
    outputfile.open("out.txt");
    for(auto i : c) {
        outputfile << '[';
        outputfile << i.x;
        outputfile << ", ";
        outputfile << i.y;
        outputfile << "], ";
    }
    outputfile.close();

}

int main() {
	writeCoords(-target, -target); //start here
	int height = 0;
	int length = 0;
    while (sides < side_target){
        for(int i = 0; i < target; i++){
            height = height + 2;
            writeCoords(-target + length + 2, -target + height);
            height = height + 2;
            writeCoords(-target - 2 + length, -target + height);
        }
        length = length + 5;
        writeCoords(-target + length, -target + height);
        for(int i = 0; i < target; i++){
            height = height - 2;
            writeCoords(-target + length + 2, -target + height);
            height = height - 2;
            writeCoords(-target - 2 + length, -target + height);
        }
        length = length + 5;
        writeCoords(-target + length + 2, -target + height);
    }
    writeCoords(target + length + 4, -target - 1);
    writeCoords(-target, -target);

    /*
    cout << "X contains: ";
    printVectors(x);
    cout << "Y contains: ";
    printVectors(y);
    cout << "Coordinates: ";
    printCoords();
    */
    pyrry();
	return 0;
}
