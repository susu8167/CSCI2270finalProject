#include <iostream>
#include <string>
#include "linkedList.hpp"
#include "BST.hpp"
#include "hashChaining.hpp"
#include "hashLinear.hpp"
#include "hashQuadratic.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include "stdlib.h"

#define linkListed true
#define Tree true
#define hashChaining true
#define hashLinear true
#define hashQuad true



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
    std::ofstream outFile;

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

    outFile.open("insert_linkedList.csv");
    for(int i=0; i<400; i++){
        outFile<<i+1<<","<<insert[i]<<std::endl;
        //std::cout<<i+1<<","<<insert[i]<<std::endl;
    }
    outFile.close();

    outFile.open("search_linkedList.csv");
    for(int i=0; i<400; i++){
        outFile<<i+1<<","<<search[i]<<std::endl;
        //std::cout<<i+1<<": "<<search[i]<<" ";
    }
    outFile.close();
    #endif
    
    #if Tree
    using namespace std::chrono;
    BST bst;
    for(int i=0; i<400; i++){
        high_resolution_clock::time_point start = high_resolution_clock::now();
        for(int j=100*i; j<100*i+100; j++){
            bst.insert(testData[j]);
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double> time = duration_cast<microseconds>(end-start);
        insert[i] = time.count()/100;

        start = high_resolution_clock::now();
        for(int j=0; j<100; j++){
            bst.search(testData[int(rand()%(100*(i+1)))]);
        }
        end = high_resolution_clock::now();
        time = duration_cast<microseconds>(end-start);
        search[i] = time.count()/100;
        std::ofstream outFile;
    }

    outFile.open("insert_bst.csv");
    for(int i=0; i<400; i++){
        outFile<<i+1<<","<<insert[i]<<std::endl;
    }
    outFile.close();

    outFile.open("search_bst.csv");
    for(int i=0; i<400; i++){
        outFile<<i+1<<","<<search[i]<<std::endl;
    }
    outFile.close();
    #endif

    #if hashChaining
    using namespace std::chrono;
    HashTable hash(40009);
    std::vector<int> insertCollisionChaining;
    std::vector<int> searchCollisionChaining;
    for(int i=0; i<400; i++){
        high_resolution_clock::time_point start = high_resolution_clock::now();
        for(int j=100*i; j<100*i+100; j++){
            hash.insertItem(testData[j]);
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double> time = duration_cast<microseconds>(end-start);
        insert[i] = time.count()/100;
        insertCollisionChaining.push_back(hash.getNumOfCollision());

        start = high_resolution_clock::now();
        for(int j=0; j<100; j++){
            hash.searchItem(testData[int(rand()%(100*(i+1)))]);
            
        }
        end = high_resolution_clock::now();
        time = duration_cast<microseconds>(end-start);
        search[i] = time.count()/100;
        searchCollisionChaining.push_back(hash.getNumOfSearchCollision());
        hash.resetNumCollision();
        hash.resetNumSearchCollision();
    }
    outFile.open("insert_hashChaining.csv");
    for(int i=0; i<400; i++){
        outFile<<i+1<<","<<insert[i]<<std::endl;
        //std::cout<<i+1<<","<<insert[i]<<std::endl;
    }
    outFile.close();

    outFile.open("insertCollision_hashChaining.csv");
    for(int i=0; i< insertCollisionChaining.size(); i++){
        outFile << i+1 << "," << insertCollisionChaining[i] << std::endl;
    }
    outFile.close();

    outFile.open("searchCollision_hashChaining.csv");
    for(int i=0; i< searchCollisionChaining.size(); i++){
        outFile << i+1 << "," << searchCollisionChaining[i] << std::endl;
    }
    outFile.close();

    outFile.open("search_hashChaining.csv");
    for(int i=0; i<400; i++){
        outFile<<i+1<<","<<search[i]<<std::endl;
        //std::cout<<i+1<<": "<<search[i]<<" ";
    }
    outFile.close();
    #endif

    #if hashLinear
    using namespace std::chrono;
    std::vector<int> insertCollisionLinear;
    std::vector<int> searchCollisionLinear;
    HashLinear linear(40009);
    for(int i=0; i<400; i++){
        high_resolution_clock::time_point start = high_resolution_clock::now();
        for(int j=100*i; j<100*i+100; j++){
            linear.insertItem(testData[j]);
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double> time = duration_cast<microseconds>(end-start);
        insert[i] = time.count()/100;
        insertCollisionLinear.push_back(linear.getNumOfCollision());

        start = high_resolution_clock::now();
        for(int j=0; j<100; j++){
            linear.searchItem(testData[int(rand()%(100*(i+1)))]);
        }
        end = high_resolution_clock::now();
        time = duration_cast<microseconds>(end-start);
        search[i] = time.count()/100;
        searchCollisionLinear.push_back(linear.getNumOfSearchCollision());
        linear.resetNumCollision();
        linear.resetNumSearchCollision();
    }

    outFile.open("insert_hashLinear.csv");
    for(int i=0; i<400; i++){
        outFile<<i+1<<","<<insert[i]<<std::endl;
        //std::cout<<i+1<<": "<<insert[i]<<std::endl;
    }
    outFile.close();

    outFile.open("search_hashLinear.csv");
    for(int i=0; i<400; i++){
        outFile<<i+1<<","<<search[i]<<std::endl;
        //std::cout<<i+1<<": "<<search[i]<<" ";
    }
    outFile.close();

    outFile.open("insertCollision_hashLinear.csv");
    for(int i=0; i< insertCollisionLinear.size(); i++){
        outFile << i+1 << "," << insertCollisionLinear[i] << std::endl;
    }
    outFile.close();

    outFile.open("searchCollision_hashLinear.csv");
    for(int i=0; i< searchCollisionLinear.size(); i++){
        outFile << i+1 << "," << searchCollisionLinear[i] << std::endl;
    }
    outFile.close();
    #endif

    #if hashQuad
    using namespace std::chrono;
    HashQuadratic quadratic(40009);
    std::vector<int> insertCollisionQuadratic;
    std::vector<int> searchCollisionQuadratic;

    for(int i=0; i<400; i++){
        high_resolution_clock::time_point start = high_resolution_clock::now();
        for(int j=100*i; j<100*i+100; j++){
            quadratic.insertItem(testData[j]);
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration<double> time = duration_cast<microseconds>(end-start);
        insert[i] = time.count()/100;
        insertCollisionQuadratic.push_back(quadratic.getNumOfCollision());

        start = high_resolution_clock::now();
        for(int j=0; j<100; j++){
            quadratic.searchItem(testData[int(rand()%(100*(i+1)))]);
        }
        end = high_resolution_clock::now();
        time = duration_cast<microseconds>(end-start);
        search[i] = time.count()/100;
        searchCollisionQuadratic.push_back(quadratic.getNumOfSearchCollision());
        quadratic.resetNumCollision();
        quadratic.resetNumSearchCollision();
    }

    outFile.open("insert_hashQuadratic.csv");
    for(int i=0; i<400; i++){
        outFile<<i+1<<","<<insert[i]<<std::endl;
        //std::cout<<i+1<<": "<<insert[i]<<std::endl;
    }
    outFile.close();

    outFile.open("search_hashQuadratic.csv");
    for(int i=0; i<400; i++){
        outFile<<i+1<<","<<search[i]<<std::endl;
        //std::cout<<i+1<<": "<<search[i]<<" ";
    }
    outFile.close();

    outFile.open("insertCollision_hashQuadratic.csv");
    for(int i=0; i< insertCollisionQuadratic.size(); i++){
        outFile << i+1 << "," << insertCollisionQuadratic[i] << std::endl;
    }
    outFile.close();

    outFile.open("searchCollision_hashQuadratic.csv");
    for(int i=0; i< searchCollisionQuadratic.size(); i++){
        outFile << i+1 << "," << searchCollisionQuadratic[i] << std::endl;
    }
    outFile.close();
    
    #endif

return 0;
}