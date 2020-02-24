#include <iostream>
#include <fstream>
#include "traditional_LIST_int.h"
#include "traditional_LIST_string.h"

void WRITE_FILE(List L) {
    std::ofstream myfile ("myfile.txt");
    if (myfile.is_open()) {
        for (int index = 0; index < L.Last; index++) {
            myfile << L.Elements[index];
            if (index == L.Last - 1);
            else myfile << "    ";
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";
}
void WRITE_FILE(List_str L) {
    std::ofstream myfile ("myfileline.txt");
    if (myfile.is_open()) {
        for (int index = 0; index < L.Last; index++) {
            myfile << L.Elements[index];
            if (index == L.Last - 1);
            else myfile << "\n";
        }
        myfile.close();
    }
    else std::cout << "Unable to write file";
}
void READ_FILE(List &L) {
    std::ifstream myfile("myfileint.txt");
    int data;

    MAKENULL_LIST(L);
    if (myfile.is_open()) {
        while(!myfile.eof()) {
            myfile >> data;
            INSERT_LIST(data, ENDLIST(L), L);
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";
}
bool READ_FILE(List_str &L) {
    std::ifstream myfile("myfileline.txt");
    std::string data;

    MAKENULL_LIST(L);
    if (myfile.is_open()) {
        while(getline(myfile,data) ) {
            INSERT_LIST(data, ENDLIST(L), L);
            std::cout << data << std::endl;
        }
        myfile.close();
        return true;
    }
    else {
        std::cout << "Unable to open file";
        return false;
    }
}
void READ_FILE_BINARY() {
    std::streampos size;
    char* memblock;

    std::ifstream file ("Cat09.jpg", std::ios::in|std::ios::binary);
    if (file.is_open()) {
        size = file.tellg();
        memblock = new char [size];
        file.seekg (0, std::ios::beg);
        file.read (memblock, size);
        file.close();
        delete[] memblock;
    }
    else std::cout << "Unable to open file";
}
int main () {
    List test;
    List_str test2, test3;
    MAKENULL_LIST(test);
    MAKENULL_LIST(test2);
    MAKENULL_LIST(test3);
//    INSERT_LIST(5, 1, test);
//    INSERT_LIST(7, 2, test);
//    INSERT_LIST(3, 1, test);
//    PRINT_LIST(test);
    READ_LIST(test2);
//    PRINT_LIST(test2);
    WRITE_FILE(test2);
    if(READ_FILE(test3))
        PRINT_LIST(test3);
//    READ_FILE_BINARY();
}