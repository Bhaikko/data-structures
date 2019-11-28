#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>

#define GRID_SIZE 6

struct Coordinate
{
    int x;
    int y;
};

class Node
{
    private:
        Coordinate coordinate;
        Node* parent;
        bool isWalkable;

    public:
        int gCost;
        int hCost;

        Node(int x, int y) {
            this->coordinate.x = x;
            this->coordinate.y = y;
            this->isWalkable = true;
        }

        const int fCost() {
            return this->gCost + this->hCost;
        }

        void make_unwalkable() {
            this->isWalkable = false;
        }

        const Coordinate get_coordinate() {
            return this->coordinate;
        }

        const bool walkable() {
            return this->isWalkable;
        }

        Node* get_parent() {
            return this->parent;
        }

        void set_parent(Node* parent) {
            this->parent = parent;
        }

        friend std::ostream& operator << (std::ostream& os, Node* node); 

};

std::ostream& operator << (std::ostream& os, Node* node)
{
    std::cout << "(" << node->get_coordinate().x << " , " << node->get_coordinate().y << ")" << std::endl;

    return os;
}

struct FCostMinHeap
{
    bool operator () (Node* node1, Node* node2) {
        return node1->fCost() > node2->fCost();
    }
};

bool contains(std::vector<Node*>* neighbours, Node* currentNode) 
{
    for (int i = 0; i < neighbours->size(); i++) {
        if (neighbours->at(i) == currentNode) {
            return true;
        }
    }
    return false;
}

bool openSetContains(std::priority_queue<Node*, std::vector<Node*>, FCostMinHeap>* openset, Node* current)
{
    bool bContain = false;

    std::vector<Node*>* nodes = new std::vector<Node*>();

    while (!openset->empty()) {
        Node* temp = openset->top();
        openset->pop();
        nodes->push_back(temp);
    }

    if (contains(nodes, current)) {
        bContain = true;
    }

    for (int i = 0; i < nodes->size(); i++) {
        openset->push(nodes->at(i));
    }

    return bContain;
}

double distance(Node* node1, Node* node2)
{
    int x = pow((node1->get_coordinate().x - node2->get_coordinate().x), 2);
    int y = pow((node1->get_coordinate().y - node2->get_coordinate().y), 2);

    return sqrt(x + y) * 10;
}

std::vector<Node*>* getNeighbours(Node* current, Node* graph[][GRID_SIZE]) 
{
    std::vector<Node*>* neighbours = new std::vector<Node*>();

    int xCoordinate = current->get_coordinate().x;
    int yCoordinate = current->get_coordinate().y;

    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) {
                continue;
            }
            xCoordinate = current->get_coordinate().x;
            yCoordinate = current->get_coordinate().y;

            if (xCoordinate + x <= -1 || xCoordinate + x >= GRID_SIZE || yCoordinate + y >= GRID_SIZE || yCoordinate + y <= -1) {
                continue;
            }

            neighbours->push_back(graph[xCoordinate + x][yCoordinate + y]);
        }
    }

    xCoordinate = current->get_coordinate().x;
    yCoordinate = current->get_coordinate().y;

    if (xCoordinate - 1 != -1) {
        neighbours->push_back(graph[xCoordinate - 1][yCoordinate]);
    }
    if (xCoordinate + 1 != GRID_SIZE) {
        neighbours->push_back(graph[xCoordinate + 1][yCoordinate]);
    }
    if (yCoordinate - 1 != -1) {
        neighbours->push_back(graph[xCoordinate][yCoordinate - 1]);
    }
    if (yCoordinate + 1 != GRID_SIZE) {
        neighbours->push_back(graph[xCoordinate][yCoordinate + 1]);
    }

    return neighbours;
}

void path(Node* seeker, Node* target) 
{
    // this function will print path in reverse order
    Node* current = target;
    while (current != seeker) {
        std::cout << current;
        current = current->get_parent();
    }

    std::cout << seeker;
}

void aStarPathFinding(Node* graph[][GRID_SIZE], Node* seeker, Node* target)
{
    std::priority_queue<Node*, std::vector<Node*>, FCostMinHeap>* openset = new std::priority_queue<Node*, std::vector<Node*>, FCostMinHeap>();

    std::vector<Node*>* closedSet = new std::vector<Node*>();

    openset->push(seeker);
    while (!openset->empty()) {
        Node* current = openset->top();

        openset->pop();
        closedSet->push_back(current);

        if (current == target) {
            path(seeker, target);
            return;
        }

        std::vector<Node*>* neighbours = getNeighbours(current, graph);
        for (int i = 0; i < neighbours->size(); i++) {
            Node* neighbour = neighbours->at(i);

            if (!neighbour->walkable() || contains(closedSet, neighbour)) {
                continue;
            } 

            int newMovementCostToNeighbour = current->gCost + distance(current, neighbour);

            if (newMovementCostToNeighbour < neighbour->gCost || !openSetContains(openset, neighbour)) {
                neighbour->gCost = newMovementCostToNeighbour;
                neighbour->hCost = distance(neighbour, target);

                neighbour->set_parent(current);

                if (!openSetContains(openset, neighbour)) {
                    openset->push(neighbour);
                }
            }
        }
    }

    std::cout << "No Path Exists!!!" << std::endl;
    return;
}

int main()
{
    Node* graph[GRID_SIZE][GRID_SIZE];

    for (int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            graph[i][j] = new Node(i, j);
        }
    }

    Node* seeker = graph[0][0];
    Node* target = graph[0][3];
    graph[0][1]->make_unwalkable();
    graph[1][1]->make_unwalkable();
    graph[2][1]->make_unwalkable();
    graph[3][1]->make_unwalkable();
    graph[4][1]->make_unwalkable();
    // graph[5][1]->make_unwalkable();

    aStarPathFinding(graph, seeker, target);
}





