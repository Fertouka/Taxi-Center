

#include <iostream>
#include <list>
#include "Node.h"

Node::Node() {
    Node::distance = 0;
    Node::isVisited = false;
    Node::neighbours = list<Node*>();
};

Node::Node(const Point &point) : point(point) {
    Node::distance = 0;
    Node::isVisited = false;
    Node::neighbours = list<Node*>();
}

Node::Node(const Point &point, const list<Node *> &neighbours) : point(point), neighbours(neighbours) {
    Node::distance = 0;
    Node::isVisited = false;
}

void Node::restart() {
    distance = 0;
    isVisited = false;
    //father = NULL;
}

const Point &Node::getPoint() const {
    return point;
}

void Node::setPoint(const Point &point) {
    Node::point = point;
}

int Node::getDistance() const {
    return distance;
}

void Node::setDistance(int distance2) {
    distance = distance2;
}

void Node::setIsVisited(bool isVisited2) {
    isVisited = isVisited2;
}

bool Node::isIsVisited() const {
    return isVisited;
}

const std::list<Node*> &Node::getNeighbours() const {
    return neighbours;
}

void Node::setNeighbours(const std::list<Node*> &neighbours) {
    Node::neighbours = neighbours;
}

bool Node::operator==(const Node &rhs) const {
    return point == rhs.point &&
           distance == rhs.distance &&
           isVisited == rhs.isVisited &&
           neighbours == rhs.neighbours;
}

bool Node::operator!=(const Node &rhs) const {
    return !(rhs == *this);
}


Node *Node::getFather() const {
    return father;
}

void Node::setFather(Node *father) {
    Node::father = father;
}
