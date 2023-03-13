#include <iostream>
#include <stack>
#include <vector>
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

Node *makeNode(int id)
{
    return new Node(id);
}

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

void dfsHelper(Node *node, std::unordered_set<Node *> &visited)
{
    visited.insert(node);
    std::cout << node->id << " ";

    for (Node *neighbor : node->neighbors)
    {
        if (visited.find(neighbor) == visited.end())
        {
            dfsHelper(neighbor, visited);
        }
    }
}

void dfs(Node *start)
{
    std::unordered_set<Node *> visited;
    dfsHelper(start, visited);
}

int main()
{
    Graph g;

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    g.addNode(makeNode(1));
    g.addNode(node2);
    g.addNode(node3);
    g.addNode(node4);

    g.addEdge(node1, node2);
    g.addEdge(node1, node3);
    g.addEdge(node2, node3);
    g.addEdge(node2, node4);

    dfs(node1);

    return 0;
}