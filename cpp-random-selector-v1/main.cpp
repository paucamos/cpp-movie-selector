//
//  main.cpp
//  cpp-random-selector-v1
//
//  Created by pablodev on 30/1/21.
//

// Program to choose movies randomly
#include <iostream>
#include<vector>
using namespace std;

void showMenu() {
    cout << "What do you want to do?" << endl;
    cout << "1. Add films/shows" << endl;
    cout << "2. List all films/shows added" << endl;
    cout << "3. Choose a film/show" << endl;
    cout << "0. Quit this script." << endl;
    cout << "\n";
}

vector<string> addElements() {
    vector <string> myList;
    string element;

    do {
        cout << "Film name:" << endl;
        getline(cin, element);
        if (element != "0") {
            myList.push_back(element);
        }
    } while(element != "0");
    return myList;
}

void showList(vector<string> my_list) {

    long len;
    len = my_list.size();

    cout << "Your list: " << endl;
    cout << "***********" << endl;

    for(int i = 0; i < len; i++) {
        cout << my_list[i] << endl;
    }
    cout << "***********" << endl;
}

int main() {

    // Variables declared in the main function
    vector <string> myList;
    string selectedMovie;
    int choice;
    int r_num;

    cout << "Welcome to Movie selector!" << endl;
    cout << "**************************" << endl;
    cout << "\n";

    do {
        // Menu
        showMenu();

        cin >> choice;
        
        switch (choice) {
            case 1:
                myList = addElements();
                if (myList.size() > 0) {
                    showList(myList);
                } else {
                    cout << "Add some content first." << endl;
                }
                break;
            case 2:
                if (myList.size() > 0) {
                    showList(myList);
                } else {
                    cout << "Add some content first." << endl;
                }
                break;
            case 3:
                if (myList.size() > 0) {
                    long len;
                    len = myList.size();
                    r_num = rand() % len;
                    selectedMovie = myList[r_num];
                    cout << "We have choosen you to watch: " << selectedMovie << endl;
                } else {
                    cout << "Please first add a film" << endl;
                }
                break;
            case 0:
                cout << "Thanks for using this script!" << endl;
                cout << "Made by Pau!" << endl;
                exit( 3 );
                break;

            default:
                cout << "Choose a correct option!" << endl;
                break;
        }
        
    } while (choice != 0);
    return 0;
}
