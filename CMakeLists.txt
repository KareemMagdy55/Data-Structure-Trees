cmake_minimum_required(VERSION 3.21)

project(Data_Structures_Trees VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(Students_database)
include_directories(Heap)
include_directories(Avl)
include_directories(BST)
include_directories(Application)

add_executable(Data_Structures_Trees main.cpp)
add_executable(students_database Students_database/students_DB.cpp)
add_executable(minHeap Heap/min_heap.cpp)
add_executable(maxHeap Heap/max_heap.cpp)
add_executable(Avl Avl/Avl.cpp)
add_executable(bst BST/BST.cpp)
add_executable(App Application/Application.cpp)

target_include_directories(Data_Structures_Trees PUBLIC ${CMAKE_DL_LIBS})
target_include_directories(students_database PUBLIC ${CMAKE_DL_LIBS})
target_include_directories(minHeap PUBLIC ${CMAKE_DL_LIBS})
target_include_directories(maxHeap PUBLIC ${CMAKE_DL_LIBS})
target_include_directories(Avl PUBLIC ${CMAKE_DL_LIBS})
