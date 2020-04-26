#include <iostream>
#include <string>
//#include "linkedList.hpp"
#include "hashChaining.hpp"
#include <fstream>
#include <sstream>
#include "stdlib.h"
//#include "BST.hpp"

#define linkListed false
#define BST false
#define hashChaining true



int main(int argc, char **argv){

    if(argc!=2){
        std::cout <<"invalid number of arguments" << std::endl;
        return 0;
    }
    else{

    }

    std::ifstream inFile;
    inFile.open(argv[1]);
    if(inFile.fail()){
        std::cout <<"Error opening file, may not exist" << std::endl;
    }

    //std::cout<<"checkpoint";

    int testData[40000];
    int currentSize = 0;
    std::string temp, input; // to store lines while reading
    int test=0;
    inFile>>temp;
    std::stringstream ss(temp);
    while(std::getline(ss,input,',')){
        //arr[currentSize] = stoi(input);
        test = stoi(input);
        //std::cout << "index" << currentSize << " test: " << test << std::endl;
        testData[currentSize] = test;
        currentSize++;
    } 
    inFile.close();

    //std::cout<<"checkpoint";

    // for(int i=0; i<40000; i++){
    //     std::cout<<testData[i]<<" ";
    // }

    float insert[400], search[400];
    srand(time(NULL));
    
    #if linkListed
    //std::cout<<"checkpoint";
    using namespace std::chrono;
    linkedList list;
    //std::cout<<"checkpoint";
    for(int i=0; i<400; i++){
        high_resolution_clock::time_point start = high_resolution_clock::now();
        for(int j=100*i; j<100*i+100; j++){
        list.insertNode(testData[j]);
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double> time = duration_cast<microseconds>(end-start);
        insert[i] = time.count()/100;

        start = high_resolution_clock::now();
        for(int j=0; j<100; j++){
            list.search(testData[int(rand()%(100*(i+1)))]);
        }
        end = high_resolution_clock::now();
        time = duration_cast<microseconds>(end-start);
        search[i] = time.count()/100;
    }

    std::ofstream outFile;
    outFile.open("insert_linkedList.csv");
    for(int i=0; i<400; i++){
        outFile<<i<<": "<<insert[i]<<std::endl;
        std::cout<<i<<": "<<insert[i]<<std::endl;
    }
    outFile.close();

    outFile.open("search_linkedList.csv");
    for(int i=0; i<400; i++){
        outFile<<i<<": "<<search[i]<<std::endl;
        //std::cout<<i<<": "<<search[i]<<" ";
    }
    outFile.close();
    #endif
    
    #if BST
    using namespace std::chrono;
    BST bst;
    for(int i=0; i<100; i++){
        high_resolution_clock::time_point start = high_resolution_clock::now();
        for(int j=100*i; j<100*j+100; j++){
        bst.insert(testData[j]);
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double> time = duration_cast<microseconds>(end-start);
        insert[i] = time.count()/100;

        high_resolution_clock::time_point start = high_resolution_clock::now();
        for(int j=0; j<100; j++){
            bst.search(testData[int(rand()%(100*(i+1)))]);
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double> time = duration_cast<microseconds>(end-start);
        search[i] = time.count()/100;
        std::ofstream outFile;
    }

    outFile.open("insert_bst.csv");
    for(int i=0; i<400; i++){
        outFile<<i<<": "<<insert[i]<<std::endl;
    }
    outFile.close();

    outFile.open("search_bst.csv");
    for(int i=0; i<400; i++){
        outFile<<i<<": "<<search[i]<<std::endl;
    }
    outFile.close();
    #endif

    #if hashChaining
    using namespace std::chrono;
    HashTable hash(40009);
    for(int i=0; i<400; i++){
        high_resolution_clock::time_point start = high_resolution_clock::now();
        for(int j=100*i; j<100*i+100; j++){
            hash.insertItem(testData[j]);
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double> time = duration_cast<microseconds>(end-start);
        insert[i] = time.count()/100;

        start = high_resolution_clock::now();
        for(int j=0; j<100; j++){
            hash.searchItem(testData[int(rand()%(100*(i+1)))]);
        }
        end = high_resolution_clock::now();
        time = duration_cast<microseconds>(end-start);
        search[i] = time.count()/100;
    }

    std::ofstream outFile;
    outFile.open("insert_hashChaining.csv");
    for(int i=0; i<400; i++){
        outFile<<i<<": "<<insert[i]<<std::endl;
        std::cout<<i<<": "<<insert[i]<<std::endl;
    }
    outFile.close();

    outFile.open("search_hashChaining.csv");
    for(int i=0; i<400; i++){
        outFile<<i<<": "<<search[i]<<std::endl;
        //std::cout<<i<<": "<<search[i]<<" ";
    }
    outFile.close();
    #endif



return 0;
}