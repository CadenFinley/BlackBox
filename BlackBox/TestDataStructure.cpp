//
//  main.cpp
//  Queue, pQueue, Stack Librarys
//
//  Created by Caden Finley on 9/26/23.
//
#include <iostream>
#include <string>
#include "p2stack2.h"
#include "p2queue2.h"
#include "p2priorityqueue2.h"
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    string input, commandInput;
    int valueInput;
    bool isStack = true,isQueue = true,isPriorityQueue = true; //initializing all variables
    
    Stack<int> stack;
    Queue<int> queue;
    PriorityQueue<int,int> pq; //initializing all data structures
    
    while (true) { //running loop
        cout << "Command: ";
        getline(cin, input); //take user input
        if (input == "END") { //end loop upon 'END'
            break;
        }
        istringstream inputStream(input);
        inputStream >> commandInput >> valueInput; // separating input into respective variables
        if (commandInput == "PUSH") { //pushing input into all data structures if command is 'PUSH'
            stack.push(valueInput);
            queue.push(valueInput);
            pq.push(valueInput,valueInput);
        }
        else if (commandInput == "POP") { //if command is 'POP' test if input = pop of repective data structure
            if (isStack){
                isStack = !stack.isEmpty() && stack.pop() == valueInput ? true : false;
            }
            if (isQueue){
                isQueue = !queue.isEmpty() && queue.pop() == valueInput ? true : false;
            }
            if (isPriorityQueue){
                isPriorityQueue = !pq.isEmpty() && pq.pop() == valueInput ? true : false;
            }
        }
    }
    
    if (isStack && !isQueue && !isPriorityQueue) { //output logic
        cout << "The black box holds a Stack." << endl;
    } 
    else if (isQueue && !isStack && !isPriorityQueue) {
        cout << "The black box holds a Queue." << endl;
    } 
    else if (isPriorityQueue && !isStack && !isQueue) {
        cout << "The black box holds a Priority Queue." << endl;
    }
    else if (!isPriorityQueue && !isQueue && !isStack){
        cout << "The black box holds something else" << endl;
    }
    else {
        cout << "The black box remains mysterious" << endl;
    }
}

