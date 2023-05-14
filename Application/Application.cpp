#include "Application.h"

#define align cout << "\n===================================================\n";

void mainApp::start() {
    userChoice = -1;
    while (userChoice > 5 or userChoice < 1) {
        align
        cout << "1. BST\n"
             << "2. AVL\n"
             << "3. Min Heap\n"
             << "4. Max Heap\n"
             << "5. Exit\n"
             << "\nEnter your choice : ";
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
    while (true) {
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
                break;
            }
            case 2 : {
                int id;
                cout << "id : ";
                cin >> id;
                auto *tempNode = new BstNode();
                tempNode = bst.Search(bst.getRoot(), id);
                if (tempNode != nullptr) {
                    stud = tempNode->data;
                    bst.decreaseDep(stud.dep);
                    bst.remove(bst.getRoot(), id);
                    cout << "The student is removed\n";
                }
                else
                    cout << "Student is not found\n";
                break;
            }
            case 3 : {
                int id;
                cout << "id : ";
                cin >> id;
                if (bst.Search(bst.getRoot(), id) != nullptr) {
                    cout << "Student is found\n";
                    cout << bst.Search(bst.getRoot(), id)->data;
                } else
                    cout << "Student is not found\n";
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

}

void mainApp::avlChoice() {
    while (true) {
        userChoice = -1;
        while (userChoice > 5 or userChoice < 1) {
            align
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
