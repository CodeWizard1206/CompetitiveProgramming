/*

Your task is to print the whole program in output which you will write here.

*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	string line;
	fstream file;
	file.open("printTheProgram.cpp",ios::in);
	if (file.is_open()) {
		while (getline(file, line))
			cout<<line<<endl;
		file.close();
	} else {
		cout<<"Error while reading file!"<<endl;
	}
	return 0;
}