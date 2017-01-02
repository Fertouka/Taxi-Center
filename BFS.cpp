// fertoud 316295005 amitayi 203839030

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include "BFS.h"
using namespace std;

stack<Node *> BFS::bfs(Grid *grid, Point start, Point end) {
    (*grid).create();
    cout << "grid was created in bfs\n";
    queue<Node*> queue;
    //creating the stating to search the trail with the start point
    Node *node = (*grid).locationInGrid(start);
    cout << "created node of the start point by using the grid\n";
    queue.push(node);
    cout << "node was pushed to the queue\n";
    (*node).setIsVisited(true);
    cout << "now node set to be visited\n";
    while (!queue.empty()) {
        cout << "now in the while loop that checks !queue.empty\n";
        node = queue.front();
        cout << "now node " << node->getPoint() << " is set to be the front of the queue\n";
        queue.pop();
        cout << "queue.pop()\n";
        //if we arrive to the end point
        if ((*node).getPoint() == end) {
            //printing the trail
            (*grid).restart();
            cout << "now moving into print trail \n";
            return BFS::PrintTrail(node, start);
        }
        //searching the neighbours of each node
        std::list<Node*> neighbours = (*node).getNeighbours();
        int size = neighbours.size();
        cout << "the size of neighbours " << size << "\n";
        for (int i = 0; i < size; i++) {
            cout << "now in the for loop of neighbours \n";
            if ((*neighbours.front()).isIsVisited() == false && (*neighbours.front()).getDistance() != -1) {
                (*neighbours.front()).setIsVisited(true);
                cout << "set isvisited \n";
                (*neighbours.front()).setDistance((*node).getDistance() + 1);
                cout << "set distance \n";
                (*neighbours.front()).setFather(node);
                cout << "set father \n";
                queue.push(neighbours.front());
            }
            neighbours.pop_front();
        }

    }
}


stack<Node*> BFS::PrintTrail(Node* node, Point start) {
    cout << "now IN THE FUNC PRINTtrail \n";
    stack<Node*> printStack = stack<Node*>();
    //pushing all the trail's nodes to a stack
    while (!((*node).getPoint() == start)) {
        printStack.push(node);
        cout << "start the restart\n";
        node = node->getFather();
        cout << "after restart \n";
    }
    node->restart();
    cout << "now RETURNING THE STACK IN print trail \n";
   // printStack.push(node);/////////////////////////////////////////////////////////////////////////
    return printStack;
    /*while (!printStack.empty()) {
        std::cout << (*printStack.top()).getPoint();
        printStack.pop();
    }
    return printStack;*/
}


