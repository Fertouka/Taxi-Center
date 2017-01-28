// fertoud 316295005 amitayi 203839030

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include "BFS.h"
using namespace std;

stack<Node *> BFS::bfs(Grid *grid, Point start, Point end) {
    (*grid).create();
    queue<Node*> queue;
    //creating the stating to search the trail with the start point
    Node *node = (*grid).locationInGrid(start);
    queue.push(node);
    (*node).setIsVisited(true);
    while (!queue.empty()) {
        node = queue.front();
        queue.pop();
        //if we arrive to the end point
        if ((*node).getPoint() == end) {
            //printing the trail
            (*grid).restart();
            return BFS::PrintTrail(node, start);
        }
        //searching the neighbours of each node
        std::list<Node*> neighbours = (*node).getNeighbours();
        int size = neighbours.size();
        for (int i = 0; i < size; i++) {
            if ((*neighbours.front()).isIsVisited() == false && (*neighbours.front()).getDistance() != -1) {
                (*neighbours.front()).setIsVisited(true);
                (*neighbours.front()).setDistance((*node).getDistance() + 1);
                (*neighbours.front()).setFather(node);
                queue.push(neighbours.front());
            }
            neighbours.pop_front();
        }
    }
    stack<Node*> emptyStack = stack<Node*>();
    return emptyStack;
}


stack<Node*> BFS::PrintTrail(Node* node, Point start) {
    stack<Node*> printStack = stack<Node*>();
    //pushing all the trail's nodes to a stack
    while (!((*node).getPoint() == start)) {
        printStack.push(node);
        node = node->getFather();
    }
    node->restart();
    return printStack;
}


