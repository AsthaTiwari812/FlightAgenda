# Flight Agenda 

Flight Agenda is a C++ console-based project designed to help users find the cheapest possible route between airports using Dijkstra’s Algorithm.  
It works by representing each airport as a node in a graph and each flight connection as an edge with an associated price.  
The program takes a source and destination airport, processes the network of flights, and determines the most cost-efficient path, showing both the total cost and the exact route to follow.

This project is a blend of practical application and academic learning. On one hand, it demonstrates how airline ticketing systems could determine the cheapest flight path between two locations. On the other hand, it provides a hands-on way to understand one of the most important algorithms in computer science — Dijkstra’s shortest path algorithm.

## Description

In this project, a graph represents our network of airports and flights. Each airport is labeled with a name (e.g., Los Angeles, Atlanta, Delhi), and each edge represents a flight between two airports along with its cost.  
The system starts with pre-defined flight prices so that a user can check the cheapest route instantly without entering any prices. However, airlines (in the simulation) can also update ticket prices dynamically.

Once a user selects a source and destination, the system calculates the cheapest route, prints it in a readable format with airport names, and displays the total cost in INR for clarity. This makes the system easy to use and understand, even for those not familiar with graph theory.

## Tech Used
The project is built entirely in C++, relying on Dijkstra’s Algorithm for computing the shortest path in a weighted graph.  
It uses:
- Arrays to store distances and visited nodes.
- Linked Lists to manage airport and airline data.
- Queues for intermediate data handling.
  
It runs as a console-based application, meaning it’s lightweight, fast, and requires no special dependencies.

## Usefulness

Flight Agenda is useful in multiple ways. For students and learners, it serves as an excellent example of applying graph algorithms to real-world-like problems. For hobbyists and programmers, it’s a fun project to explore pathfinding and cost optimization techniques. And for those interested in transportation or logistics, it simulates how route optimization can work in a simple yet effective manner.

Since the system is modular and data-driven, it can be easily adapted to other transportation networks like railways, buses, or shipping routes. The idea remains the same — find the cheapest, most efficient path between two points.

## Why Dijkstra’s Algorithm?

Choosing the right algorithm was crucial for this project. I went with Dijkstra’s Algorithm because it is:
• Accurate — It always finds the true cheapest route.
• Efficient — Works well with our network size without unnecessary complexity.
• Perfect for Positive Costs — Flight prices are never negative, making it ideal for Dijkstra.
• Straightforward to Implement — Easier to code and maintain compared to more complex alternatives.
• Deterministic — Produces the same correct results every time.

Other algorithms were considered:
- Bellman-Ford handles negative weights but is slower and unnecessary here.
- Floyd-Warshall finds shortest paths between all airport pairs but is less efficient when you only need one route.
- A* works with heuristics but requires extra data like geographical coordinates, which we don’t use here.

In short, Dijkstra’s Algorithm provides the best balance of speed, simplicity, and accuracy for this project.

## Future Improvements
Some ideas for future versions include:
• Adding flight durations in addition to prices.
• Allowing airlines to update prices dynamically.
• Creating a graphical interface for easier interaction.
• Integrating with real-world airline APIs for live pricing.


## Author
Astha Tiwari
Engineering student passionate about turning algorithms into practical, real-world solutions. Creator of Flight Agenda as a hands-on application of Dijkstra’s shortest path algorithm.
GitHub: https://github.com/AsthaTiwari812
