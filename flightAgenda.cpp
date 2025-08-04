#include <iostream>
#include <climits>
#include <string>
using namespace std;

#define INFINITY 99999  //to represent no direct connection b/w airports
#define MAX 10 //max no. of airports

//class for customers
class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

//stores flight prices b/w airports
class Node3 {
public:
    int destination;
    int price;
    Node3* next;
    Node3(int d, int p) : destination(d), price(p), next(NULL) {}
};

//stores airport lists
class Node2 {
public:
    int source;
    Node3* priceList;
    Node2* down;
    Node2(int src) : source(src), priceList(NULL), down(NULL) {}
};

void insertQueue(Node*& head, int val) {  //insert airport no. to linked list
    Node* newNode = new Node(val);
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int popQueue(Node*& head) {  //deletes & returns first element of linked list
    if (!head) return -1;
    Node* temp = head;
    int val = temp->data;
    head = head->next;
    delete temp;
    return val;
}

void addPricing(Node3*& head, int destination, int price) {
    Node3* newNode = new Node3(destination, price);
    if (!head) head = newNode;
    else {
        Node3* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void getAirlinePrices(Node2*& airlineStart) {
    int adjacency[MAX][MAX] = {
        {0,1,1,0,0,0,0,0,0,0},
        {1,0,0,1,1,0,0,0,0,0},
        {1,0,0,1,1,0,0,0,0,0},
        {0,1,1,0,0,0,1,0,0,0},
        {0,1,1,0,0,1,1,0,0,0},
        {0,0,0,0,1,0,1,0,0,0},
        {0,0,0,1,1,1,0,1,0,1},
        {0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,0,1,0}
    };

    Node2* last = nullptr;

    for (int src = 0; src < MAX; src++) {
        Node2* newAir = new Node2(src);
        if (!airlineStart) airlineStart = newAir;
        else last->down = newAir;
        last = newAir;

        for (int dest = 0; dest < MAX; dest++) {
            if (adjacency[src][dest]) {
                int price;
                cout << "Enter price from airport " << src+1 << " to " << dest+1 << ": ";
                cin >> price;
                addPricing(newAir->priceList, dest, price);
            }
        }
    }
}

void updateMatrixFromList(Node2* airlineStart, int G[MAX][MAX]) {
    while (airlineStart) {
        Node3* pricePtr = airlineStart->priceList;
        while (pricePtr) {
            G[airlineStart->source][pricePtr->destination] = pricePtr->price;
            pricePtr = pricePtr->next;
        }
        airlineStart = airlineStart->down;
    }
}

void dijkstra(int G[MAX][MAX], int n, Node*& head, string airportNames[MAX]) {
    int start = popQueue(head);
    int dest = popQueue(head);

    if (start < 0 || start >= n || dest < 0 || dest >= n) {
        cout << "Invalid airport numbers.\n";
        return;
    }

    int distance[MAX], visited[MAX] = {0}, pred[MAX];
    for (int i = 0; i < n; i++) {
        distance[i] = (G[start][i] == 0) ? INFINITY : G[start][i];
        pred[i] = start;
    }

    distance[start] = 0;
    visited[start] = 1;

    for (int count = 1; count < n - 1; count++) {
        int minDist = INFINITY, nextNode = -1;
        for (int i = 0; i < n; ++i)
            if (!visited[i] && distance[i] < minDist)
                minDist = distance[i], nextNode = i;

        if (nextNode == -1) break;
        visited[nextNode] = 1;

        for (int i = 0; i < n; ++i)
            if (!visited[i] && G[nextNode][i] &&
                distance[nextNode] + G[nextNode][i] < distance[i]) {
                distance[i] = distance[nextNode] + G[nextNode][i];
                pred[i] = nextNode;
            }
    }

    if (distance[dest] == INFINITY) {
        cout << "No available path from airport " << start+1 << " to " << dest+1 << ".\n";
        return;
    }

    cout << "\nTotal Price from "<<start+1<<"."<<airportNames[start] <<" to " <<dest+1<<"."<<airportNames[dest]<< " = Rs. "<<distance[dest] << "\nPath: ";
    int path[MAX], idx = 0;
    for (int v = dest; v != start; v = pred[v])
        path[idx++] = v;
    path[idx] = start;

    for (int i = idx; i >= 0; i--)  {
        cout << path[i]+1 << "."<< airportNames[path[i]];
        if(i > 0) cout<< " -> ";
    }
    cout<<endl;
}

void printAirports() {
    cout << "Airports:\n";
    string airports[MAX] = {
        "Los Angeles", "Atlanta", "Brazil", "LHK", "NBO",
        "DXB", "Delhi", "PEK", "HND", "Sydney"
    };
    for (int i = 0; i < MAX; ++i)
        cout << i+1 << ". " << airports[i] << "\n";
}

int main() {
    Node* userQueue = NULL;
    int G[MAX][MAX] = {
        {0, 4000, 8000, 0, 0, 0, 0, 0, 0, 0},
        {4000, 0, 0, 5000, 2000, 0, 0, 0, 0, 0},
        {8000, 0, 0, 6000, 9000, 0, 0, 0, 0, 0},
        {0, 5000, 6000, 0, 0, 0, 4000, 0, 0, 0},
        {0, 2000, 9000, 0, 0, 1000, 5000, 0, 0, 0},
        {0, 0, 0, 0, 1000, 0, 3000, 0, 0, 0},
        {0, 0, 0, 4000, 5000, 3000, 0, 6000, 0, 5000},
        {0, 0, 0, 0, 0, 0, 6000, 0, 7000, 0},
        {0, 0, 0, 0, 0, 0, 0, 7000, 0, 3000},
        {0, 0, 0, 0, 0, 0, 5000, 0, 3000, 0}
    }; //G holds the prices of flights b/w airports
    int n = MAX;

    Node2* airlineData = nullptr;

    while (true) {
        cout << "\n--- WELCOME TO FLIGHT AGENDA ---\n";
        cout << "1. Airline: Enter Pricing \n";
        cout << "2. Customer: Find Shortest Route\n";
        cout << "3. Exit\nChoice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            airlineData = nullptr;
            getAirlinePrices(airlineData);
            updateMatrixFromList(airlineData, G);
        }
        else if (choice == 2) {
            printAirports();
            int src, dest;
            cout << "Enter source airport number: ";
            cin >> src;
            cout << "Enter destination airport number: ";
            cin >> dest;
            if (src < 1 || src > MAX || dest < 1 || dest > MAX) {
                cout << "Invalid input.\n";
                continue;
            }
            insertQueue(userQueue, src - 1);
            insertQueue(userQueue, dest - 1);
            string airportNames[MAX] = {"Los Angeles", "Atlanta", "Brazil", "LHK", "NBO"
            ,"DXB", "Delhi", "PEK", "HND", "Sydney"
            };
            dijkstra(G, n, userQueue, airportNames);
        }
        else if (choice == 3) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
}
