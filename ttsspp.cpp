#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Function to find the minimum cost Hamiltonian cycle using brute force
pair<int, vector<int>> tsp(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> vertex;
    for (int i = 0; i < n; ++i) {
        if (i != start) vertex.push_back(i);
    }

    int min_path = INF;
    vector<int> min_path_order;

    do {
        int current_pathweight = 0;
        vector<int> path_order;

        int k = start;
        for (int i = 0; i < vertex.size(); ++i) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
            path_order.push_back(k);
        }
        current_pathweight += graph[k][start];

        if (current_pathweight < min_path) {
            min_path = current_pathweight;
            min_path_order = path_order;
        }

    } while (next_permutation(vertex.begin(), vertex.end()));

    min_path_order.push_back(start);

    return {min_path, min_path_order};
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int start = 0; // Starting node
    auto result = tsp(graph, start);
    int min_cost = result.first;
    vector<int> min_path_order = result.second;

    cout << "Minimum cost of the Travelling Salesman Problem: " << min_cost << endl;
    cout << "Shortest path order: ";
    for (int node : min_path_order) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
