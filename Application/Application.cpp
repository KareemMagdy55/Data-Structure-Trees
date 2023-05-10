#include "Application.h"

void mainApp::start() {
    system("CLS");
    while(userChoice > 5 or userChoice <1){
        system("CLS");
        cout << "1. BST\n"
             << "2. AVL\n"
             << "3. Min Heap\n"
             << "4. Max Heap\n"
             << "5. Exit\n"
             << "Enter your choice : ";
        cin >> userChoice;
    }
    switch (userChoice) {
        case 1 : {
            bstChoice();
            break;
        }
        case 2 : {
            avlChoice();
            break;
        }
        case 3 : {
            minHeapChoice();
            break;
        }
        case 4 : {
            maxHeapChoice();
            break;
        }
        case 5 : {
            exit(0);
        }
    }


}

void mainApp::bstChoice() {
    userChoice = -1 ;
    system("CLS");
    while ( userChoice > 5 or userChoice < 1) {
        system("CLS");
        cout << "1. Add student\n"
             << "2. Remove student\n"
             << "3. Search student\n"
             << "4. Print All (sorted by id)\n"
             << "5. Return to menu\n"
             << "Enter your choice : ";
        cin >> userChoice;
    }
    switch (userChoice) {
        case 1:{
            cin >> stud;
            bst.insert(stud);
            cout << "The student is added\n";
            break;
        }
        case 2 : {
            int id ;
            cout << "id : "; cin >> id;
            bool found = bst.search(id);
            bst.remove(bst.getRoot(), id);
            if ( found)
                cout << "Student is deleted\n";
            break;
        }
        case 3 : {
            int id ;
            cout << "id : "; cin >> id;
            bst.search(id);
            break;
        }
        case 4 : {
            bst.print(bst.getRoot());
            break;
        }
        case 5 : {
            start();
            break;
        }

    }

}

void mainApp::avlChoice() {
    userChoice = -1 ;

    system("CLS");
    while ( userChoice > 5 or userChoice < 1) {
        system("CLS");
        cout << "1. Add student\n"
             << "2. Remove student\n"
             << "3. Search student\n"
             << "4. Print All (sorted by id)\n"
             << "5. Return to menu\n"
             << "Enter your choice : ";
        cin >> userChoice;
    }
    switch (userChoice) {
        case 1:{
            cin >> stud;
            avlTree.addStudent(stud);
            cout << "The student is added\n";
            break;
        }
        case 2 : {
            int id ;
            cout << "id : "; cin >> id;
            avlTree.removeStudent(id);
        }
        case 3 : {
            int id ;
            cout << "id : "; cin >> id;
            avlTree.searchStudent(id);
            break;
        }
        case 4 : {
            avlTree.printAll();
            break;
        }
        case 5 : {
            start();
            break;
        }

    }
}

void mainApp::minHeapChoice() {
    userChoice = -1 ;

    system("CLS");
    while ( userChoice > 3 or userChoice < 1) {
        system("CLS");
        cout << "1. Add student\n"
             << "2. Remove student\n"
             << "3. Return to menu\n"
             << "Enter your choice : ";

        cin >> userChoice;
    }
    switch (userChoice) {
        case 1:{
            cin >> stud;
            minHeap.insert(stud);
            cout << "The student is added\n";
            break;
        }case 2:{
            minHeap.printHeap();
            break;
        }case 3 :{
            start();
            break;
        }


    }
}

void mainApp::maxHeapChoice() {
    userChoice = -1 ;

    system("CLS");
    while ( userChoice > 3 or userChoice < 1) {
        system("CLS");
        cout << "1. Add student\n"
             << "2. Remove student\n"
             << "3. Return to menu\n"
             << "Enter your choice : ";

        cin >> userChoice;
    }
    switch (userChoice) {
        case 1:{
            cin >> stud;
            maxHeap.insert(stud);
            cout << "The student is added\n";
            break;
        }case 2:{
            maxHeap.printHeap();
            break;
        }case 3 :{
            start();
            break;
        }


    }
}
