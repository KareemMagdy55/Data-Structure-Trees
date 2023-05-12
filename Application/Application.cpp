#include "Application.h"

#define align cout << "\n===================================================\n";

void mainApp::start() {
//    system("CLS");
    userChoice = -1;
    while (userChoice > 5 or userChoice < 1) {
//        system("CLS");
        align
        cout << "1. BST\n"
             << "2. AVL\n"
             << "3. Min Heap\n"
             << "4. Max Heap\n"
             << "5. Exit\n"
             << "\nEnter your choice : ";
        cin >> userChoice;
    }
//    cout << "user choice = " << userChoice << endl;
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
    while (true) {
//        align
        userChoice = -1;
        while (userChoice > 5 or userChoice < 1) {
            align
            cout << "1. Add student\n"
                 << "2. Remove student\n"
                 << "3. Search student\n"
                 << "4. Print All (sorted by id)\n"
                 << "5. Return to menu\n"

                 << "\nEnter your choice : ";
            cin >> userChoice;
        }
        switch (userChoice) {
            case 1: {
                cin >> stud;
                bst.insert(stud);
                cout << "The student is added\n";
//            bstChoice();
                break;
            }
            case 2 : {
                // student is removed //
                int id;
                cout << "id : ";
                cin >> id;
                bool found = bst.search(id);
                bst.remove(bst.getRoot(), id);
                if (found)
                    cout << "Student is deleted\n";
                break;
            }
            case 3 : {
                // chk NULL condition is better solution Search()
                int id;
                cout << "id : ";
                cin >> id;
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
//    bstChoice();

}

void mainApp::avlChoice() {
    while (true) {
        userChoice = -1;
//        align
//        system("CLS");
        while (userChoice > 5 or userChoice < 1) {
            align
//            system("CLS");
            cout << "1. Add student\n"
                 << "2. Remove student\n"
                 << "3. Search student\n"
                 << "4. Print All (sorted by id)\n"
                 << "5. Return to menu\n"
                 << "Enter your choice : ";
            cin >> userChoice;
        }
        switch (userChoice) {
            case 1: {
                cin >> stud;
                avlTree.addStudent(stud);
                cout << "The student is added.\n";
                break;
            }
            case 2 : {
                int id;
                cout << "id : ";
                cin >> id;
                for (int i = 0; i < nStudents; ++i) {
                    if (id == students[i].id) {
                        cout << "Student is found.\n";
                        cout << students[i] << endl;
                        break;
                    }
                }
                if (!avlTree.removeStudent(id)) {
                    cout << "Student is not found.\n";
                } else cout << "Student is deleted.\n";
                break;
            }
            case 3 : {
                int id;
                cout << "id : ";
                cin >> id;
                avlTree.searchStudent(id);
//                cout << "============================\n";
                break;
            }
            case 4 : {
                avlTree.printAll();
//                cout << "============================\n";
                break;
            }
            case 5 : {
                start();
                break;
            }

        }
    }
}

void mainApp::minHeapChoice() {
    while (true) {
        align
        userChoice = -1;

        while (userChoice > 3 or userChoice < 1) {
            align
            cout << "1. Add student\n"
                 << "2. Print students (sorted by GPA)\n"
                 << "3. Return to menu\n"
                 << "Enter your choice : ";

            cin >> userChoice;
        }
        switch (userChoice) {
            case 1: {
                cin >> stud;
                minHeap.insert(stud);
                cout << "The student is added\n";
                break;
            }
            case 2: {
                minHeap.heapSort();
                minHeap.printHeap();
                break;
            }
            case 3 : {
                start();
                break;
            }


        }
    }
}

void mainApp::maxHeapChoice() {
    while (true) {
        userChoice = -1;
        while (userChoice > 3 or userChoice < 1) {
            align
            cout << "1. Add student\n"
                 << "2. Print students (sorted by GPA)\n"
                 << "3. Return to menu\n"
                 << "Enter your choice : ";

            cin >> userChoice;
        }
        switch (userChoice) {
            case 1: {
                cin >> stud;
                maxHeap.insert(stud);
                cout << "The student is added\n";
                break;
            }
            case 2: {
                maxHeap.heapSort();
                maxHeap.printHeap();
                break;
            }
            case 3 : {
                start();
                break;
            }


        }
    }
}
