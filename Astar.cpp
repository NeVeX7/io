
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef pair<double, int> pdi;

vector<vector<pi>> graph;
vector<double> heuristic;

void addedge(int x, int y, int cost) {
    graph[x].push_back(make_pair(cost, y));
    graph[y].push_back(make_pair(cost, x));
}

void a_star(int start, int goal, int n) {
    vector<double> g(n, INT_MAX);
    vector<int> came_from(n, -1);
    priority_queue<pdi, vector<pdi>, greater<pdi>> open_set;

    g[start] = 0;
    open_set.push(make_pair(heuristic[start], start));

    while (!open_set.empty()) {
        int current = open_set.top().second;
        open_set.pop();

        if (current == goal) {
            vector<int> path;
            while (current != -1) {
                path.push_back(current);
                current = came_from[current];
            }
            reverse(path.begin(), path.end());
            cout << "Path: ";
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
            return;
        }

        for (auto& neighbor : graph[current]) {
            int neighbor_node = neighbor.second;
            double tentative_g = g[current] + neighbor.first;

            if (tentative_g < g[neighbor_node]) {
                came_from[neighbor_node] = current;
                g[neighbor_node] = tentative_g;
                double f = g[neighbor_node] + heuristic[neighbor_node];
                open_set.push(make_pair(f, neighbor_node));
            }
        }
    }

    cout << "No path found." << endl;
}

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    graph.resize(v);
    heuristic.resize(v);

    cout << "Enter the edges (format: source destination cost):" << endl;
    for (int i = 0; i < e; ++i) {
        int x, y, cost;
        cin >> x >> y >> cost;
        addedge(x, y, cost);
    }

    cout << "Enter the heuristic values for each vertex:" << endl;
    for (int i = 0; i < v; ++i) {
        cin >> heuristic[i];
    }

    int start, goal;
    cout << "Enter the start vertex: ";
    cin >> start;
    cout << "Enter the goal vertex: ";
    cin >> goal;

    a_star(start, goal, v);

    return 0;
}
