#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>

class Node
{
public:
    int id;
    std::vector<Node *> neighbors;

    Node()
    {
        id = 0;
    }

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

class Graph
{
public:
    std::vector<Node *> nodes;

    void addNode(Node *node)
    {
        nodes.push_back(node);
    }

    void removeNode(Node *node)
    {
        // Remove the node from the list of neighbors of all of its neighbors
        for (Node *neighbor : node->neighbors)
        {
            neighbor->removeNeighbor(node);
        }

        // Remove the node from the list of nodes in the graph
        nodes.erase(std::remove(nodes.begin(), nodes.end(), node), nodes.end());

        // Free the memory used by the node
        delete node;
    }

    void addEdge(Node *node1, Node *node2)
    {
        node1->addNeighbor(node2);
        node2->addNeighbor(node1);
    }

    void removeEdge(Node *node1, Node *node2)
    {
        node1->removeNeighbor(node2);
        node2->removeNeighbor(node1);
    }
};

void bfs(Node *startNode)
{
    std::queue<Node *> nodeQueue;
    std::unordered_set<Node *> visitedNodes;

    nodeQueue.push(startNode);
    visitedNodes.insert(startNode);

    while (!nodeQueue.empty())
    {
        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();

        // Do something with the current node
        std::cout << "Visited node " << currentNode->id << std::endl;

        for (Node *neighbor : currentNode->neighbors)
        {
            if (visitedNodes.find(neighbor) == visitedNodes.end())
            {
                nodeQueue.push(neighbor);
                visitedNodes.insert(neighbor);
            }
        }
    }
}

int main()
{
    Graph g;

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);
    Node *node9 = new Node(9);

    g.addNode(node1);
    g.addNode(node2);
    g.addNode(node3);
    g.addNode(node4);
    g.addNode(node5);
    g.addNode(node6);
    g.addNode(node7);
    g.addNode(node8);
    g.addNode(node9);

    g.addEdge(node1, node2);
    g.addEdge(node1, node3);
    g.addEdge(node1, node5);
    g.addEdge(node2, node4);
    g.addEdge(node4, node8);
    g.addEdge(node3, node6);
    g.addEdge(node3, node7);
    g.addEdge(node5, node9);

    bfs(node1);

    return 0;
}