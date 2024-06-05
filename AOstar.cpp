#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

struct Node {
    int id;
    vector<vector<pi>> children; // AND-OR children
    double heuristic;
    bool isSolved;
    bool isExpanded;

    Node(int id = 0, double heuristic = 0.0) : id(id), heuristic(heuristic), isSolved(false), isExpanded(false) {}
};

vector<Node> graph;

void addedge(int x, int y, int cost) {
    // Assuming x and y are 0-based indices
    if (x < graph.size() && y < graph.size()) {
        graph[x].children.push_back({make_pair(cost, y)});
    }
}

void ao_star(int start) {
    if (graph[start].isSolved) {
        return;
    }

    graph[start].isExpanded = true;

    for (auto& children : graph[start].children) {
        double cost_sum = 0;
        bool all_solved = true;

        for (auto& child : children) {
            if (!graph[child.second].isExpanded) {
                ao_star(child.second);
            }
            if (!graph[child.second].isSolved) {
                all_solved = false;
            }
            cost_sum += child.first + graph[child.second].heuristic;
        }

        if (all_solved) {
            graph[start].isSolved = true;
            graph[start].heuristic = cost_sum;
            return;
        }
    }

    if (!graph[start].isSolved) {
        double min_cost = INT_MAX;

        for (auto& children : graph[start].children) {
            double cost_sum = 0;
            for (auto& child : children) {
                cost_sum += child.first + graph[child.second].heuristic;
            }
            min_cost = min(min_cost, cost_sum);
        }

        graph[start].heuristic = min_cost;
    }
}

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    graph.resize(v);

    cout << "Enter the heuristic values for each vertex:" << endl;
    for (int i = 0; i < v; ++i) {
        double heuristic;
        cin >> heuristic;
        graph[i] = Node(i, heuristic);
    }

    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges (format: source destination cost):" << endl;
    for (int i = 0; i < e; ++i) {
        int x, y, cost;
        cin >> x >> y >> cost;
        addedge(x, y, cost);
    }

    int start;
    cout << "Enter the start vertex: ";
    cin >> start;

    ao_star(start);

    cout << "Heuristic cost from start vertex " << start << " is: " << graph[start].heuristic << endl;

    return 0;
}
