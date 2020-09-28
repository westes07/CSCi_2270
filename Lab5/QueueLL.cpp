#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
    queueFront = nullptr;
    queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
    while( !isEmpty() )
        dequeue();
}

bool QueueLL::isEmpty()
{
    /*if(queueFront == nullptr || queueEnd == nullptr)
        return true;
    return false;*/
    return (!queueFront || !queueEnd);
}

// TODO
void QueueLL::enqueue(int key)
{
    Node * nn = new Node;
    nn->key = key;
    nn->next = nullptr;

    // TODO Complete this function, handle the case when you're enqueuing in an empty queue
    if (queueEnd == NULL){
        queueFront = nn;
        queueEnd = nn;
        queueEnd -> next = queueFront;
        return;
    }
    nn->next = queueFront;
    queueEnd->next = nn;
    queueEnd = nn;

}

//TODO
void QueueLL::dequeue()
{
    if(!isEmpty()){
        // TODO Complete this function, handle the case when your queue becomes empty after dequeuing
        if (queueFront -> next == queueFront){
            cout << queueFront->key << endl;
            queueFront ->next = nullptr;
            queueEnd = nullptr;
            // delete queueFront;
            return;
        }

        // queueFront = queueFront -> next;
        queueEnd -> next = queueFront -> next;
        delete queueFront;
        queueFront = queueEnd -> next;
    }
    else{
        cout<<"queue is empty. can not deque"<<endl;
    }
}

int QueueLL::peek()
{
    if( !isEmpty() )
        return queueFront->key;
    else
    {
        cout<< " queue is empty. can not peek"<<endl;
        return -1;
    }
    //return 0;
}
