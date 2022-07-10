/**
 * @file assign6.cpp
 * @author Shashadhar Das (2111cs14)
 * @brief
 * @version 0.1
 * @date 2022-03-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// class represents a graph node
class Node
{
public:
    int value;
    string color;
    Node *next;
};

// class represents adjacency list
class AdjacencyList
{
public:
    Node *head = NULL;
    AdjacencyList *next;
};

// class represents graph
class graph
{
    int vertices;
    AdjacencyList *list;
};

// delimeter to token the file input line
const char *delim = " ";
int noOfVertices;

// checks if the string is valid number
bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (isdigit(c) == 0)
            return false;
    }
    return true;
}

// Read data from the input file ip.txt
bool readDataFromFile(ofstream *outFile)
{
    bool validInput = true;
    int lines = 1;
    ifstream inputFile("ip.txt");

    if (inputFile.is_open())
    {
        string token;
        int lineNo = 1;
        int noOfToken=1;

        // reads the no of vertices
        /**inputFile >> token;
        if(isNumber(token)){
         noOfVertices = stoi(token);
        }else {
            validInput = false;
        }**/
        
        string color;
        string line;
        while (inputFile.good() && inputFile >> line)
        { 
            switch (lineNo)
            {

            // no of vertices    
            case 1:
            {
             if(noOfToken>1){
             if(isNumber(token)){
              noOfVertices = stoi(token);
              }else {
               validInput = false;
              }
            }else{
                // got more no of inputs in line no 1
                validInput = false;
            }
            }
            break;

            // color     
            case 2:
            if(noOfToken)

            break;

            // edges
            case 3:
            break;

            default:
                break;
            }
            cout << line;
            if (inputFile.peek() == '\n') // detect "\n"
            {
                cout <<"new line"<< endl;
                line = lineNo + 1;
                noOfToken = 1;
            }
        }

        //cout << color << endl;
        //string edges;
        //inputFile >> edges;
        //cout << edges;
    }
    inputFile.close();
    return validInput;
}

void functionTest(Node *test)
{
    cout << test[0].color;
}

// Main Function
int main()
{
    int noOfProcess;

    int noOfProcess;

    Node* arr= new Node[2];

    Node node;
    node.color="r";
    node.value=2;
    arr[0] = node;

    Node node2;
    node2.color="g";
    node2.value=9;
    arr[1]= node2;
    
    for(int i=0;i<2;i++){
        cout<<arr[i].color;
    }
    
   // functionTest(arr);

     int a[3] = {3, 4, 5 }; 
     int *ptr = a; 

    for(int i=0;i<2;i++){
        cout<<ptr[i];
    }
    
    ofstream outFile;
    outFile.open("op.txt");
    if (readDataFromFile(&outFile))
    {
    }
    outFile.close();
    return 0;
}
