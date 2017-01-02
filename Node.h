// fertoud 316295005 amitayi 203839030

#ifndef EX1_NODE_H
#define EX1_NODE_H

#include <iostream>
#include <list>
#include "Point.h"
using namespace std;

class Node {
private:
    Point point;
    int distance;
    bool isVisited;
    Node* father;
    std::list<Node*> neighbours;
public:

/**
 * default constructor of node
 */
    Node();

/**
 * constructor of node
 * @param point
 * @param neighbours of this node in a grid
 */
    Node(const Point &point, const list<Node *> &neighbours);

/**
 * constructor of node
 * @param point
 */
    Node(const Point &point);

    void restart();

/**
 * getting the point of the node
 * @return point
 */
    const Point &getPoint() const;

/**
 * setting the point of the node
 * @param point
 */
    void setPoint(const Point &point);

/**
 * getting the distance of the node
 * @return the distance
 */
    int getDistance() const;

/**
 * setting the distance of the node
 * @param distance2
 */
    void setDistance(int distance);

/**
 * setting if the node is visited
 * @param isVisited2
 */
    void setIsVisited(bool isVisited);

/**
 * @return if the node is visited
 */
    bool isIsVisited() const;

/**
 * @return a list of the neighbours's node
 */
    const std::list<Node*> &getNeighbours() const;

/**
 * setting the neighbours's node
 * @param neighbours a list of the neighbours's node
 */
    void setNeighbours(const std::list<Node*> &neighbours);

/**
 * @param rhs a node
 * @return if two nodes are equals
 */
    bool operator==(const Node &rhs) const;

/**
 * @param rhs
 * @return if two nodes are not equals
 */
    bool operator!=(const Node &rhs) const;

/**
 * getting the father of the node
 */
    Node *getFather() const;

/**
 * setting the father of the node
 * @param father of the node
 */
    void setFather(Node *father);
};
#endif //EX1_NODE_H
