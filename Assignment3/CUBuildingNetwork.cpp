/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of CUBuilding structs to      */
/*     represet communication paths between buildings             */
/****************************************************************/

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUBuildingNetwork::CUBuildingNetwork() {
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUBuildingNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new building to the network
 *   between the building *previous and the Building that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfroom) {
    CUBuilding* newBuilding = new CUBuilding;
    newBuilding->name = buildingName;
    newBuilding->totalRoom = numOfroom;
    if (previous == NULL && head == NULL){
        head = newBuilding;
        cout << "adding: " << buildingName << " (HEAD)" << endl;
    } else if (previous == NULL){
        newBuilding->next = head;
        head = newBuilding;
        cout << "adding: " << buildingName << " (HEAD)" << endl;
    }else{
        newBuilding -> next = previous -> next;
        previous -> next = newBuilding;
        cout << "adding: " << buildingName << " (prev: " << previous->name << ")" << endl;
    }
    
}


/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup(){
    addBuildingInfo(NULL,"FLMG", 2);
    addBuildingInfo(searchForBuilding("FLMG"),"DLC", 10);
    addBuildingInfo(searchForBuilding("DLC"),"ECOT", 6);
    addBuildingInfo(searchForBuilding("ECOT"),"CASE", 5);
    addBuildingInfo(searchForBuilding("CASE"),"AERO", 4);
    addBuildingInfo(searchForBuilding("AERO"),"RGNT", 9);
}

/*
 * Purpose: Search the network for the specified building and return a pointer to that node
 * @param buildingName name of the building to look for in network
 * @return pointer to node of buildingName, or NULL if not found
 *
 */
CUBuilding* CUBuildingNetwork::searchForBuilding(string buildingName){
    if (head == NULL){
        return NULL;
    }
    
    CUBuilding* cur = head;
    while (cur != NULL){
        if (cur->name == buildingName){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}


/*
 * Purpose:
 * @param string receiver
 * @param string msg
 */
void CUBuildingNetwork::transmitRoomInfo(string receiver) {
    if (head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    CUBuilding* end = searchForBuilding(receiver);
    if (end == NULL){
        cout << "Building not found" << endl;
    }else{
        CUBuilding* cur = head;
        while (cur->name != end->name){
            cur -> message = ("available room at " + cur->name + " is ") + to_string(cur->totalRoom);
            cur -> numberMessages++;
            cout << cur -> name << "[# messages received: " << cur->numberMessages
            << "] received: " << cur->message << endl;
            cur = cur->next;
        }
        cur -> message = ("available room at " + cur->name + " is ") + to_string(cur->totalRoom);
        cur -> numberMessages++;    
        cout << cur -> name << "[# messages received: " << cur->numberMessages
        << "] received: " << cur->message << endl;
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork() {
    cout << "== CURRENT PATH ==" << endl;
    if (head == NULL){
        cout << "nothing in path" << endl;
    } else {
        CUBuilding* cur = head;
        while (cur != NULL){
            cout << cur->name << "(" << cur->totalRoom << ") -> ";
            cur = cur -> next;
        }
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
    
}
