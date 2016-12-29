// fertoud 316295005 amitayi 203839030

#ifndef EX1_BFS_H
#define EX1_BFS_H

#include <vector>
#include "Grid.h"
#include "Point.h"
class BFS {
public:
    /**
     * bfs algorithm. searching the short trail between the start and the end point.
     * @param grid
     * @param start point
     * @param end point
     */
    static vector<Node *> bfs(Grid &grid, Point start, Point end);

    /**
     * printing the short trail between the start and the point
     * @param node* the last node of the trail
     * @param start point of the trail
     */
    static vector<Node *> PrintTrail(Node* node, Point start);
};

#endif //EX1_BFS_H
