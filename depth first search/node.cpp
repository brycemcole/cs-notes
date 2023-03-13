#include <iostream>
#include <vector>

class Node
{
public:
    int id;
    std::vector<Node *> neighbors;

    Node(int nodeId)
    {
        id = nodeId;
    }

    void addNeighbor(Node *neighbor)
    {
        neighbors.push_back(neighbor);
    }

    void removeNeighbor(Node *neighbor)
    {
        neighbors.erase(std::remove(neighbors.begin(), neighbors.end(), neighbor), neighbors.end());
    }
};