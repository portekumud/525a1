#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>

using namespace std;

using Matrix = vector<vector<int>>;

void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
}

// Local complementation at vertex 'v'
void localComplement(Matrix& mat, int v) {
    int n = mat.size() - 1; // last row is color
    // Reverse color of neighbors
    for (int i = 0; i < n; ++i) {
        if (mat[v][i]) {
            mat[n][i] ^= 1; // flip color
        }
    }

    // Perform local complementation on the neighborhood of v
    for (int i = 0; i < n; ++i) {
        if (i == v || mat[v][i] == 0) continue;
        for (int j = i + 1; j < n; ++j) {
            if (j == v || mat[v][j] == 0) continue;
            mat[i][j] ^= 1;
            mat[j][i] ^= 1;
        }
    }
}

// Compare two matrices (including color row)
bool isInverted(const Matrix& original, const Matrix& transformed) {
    int n = original.size() - 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == n) {
                if (original[i][j] == transformed[i][j])
                    return false;
            } else {
                if (original[i][j] != transformed[i][j])
                    return false;
            }
        }
    }
    return true;
}

int main() {
    srand(time(0));

    // Example hardcoded bi-colored graph with 4 vertices
    int n = 4;
    Matrix graph(n + 1, vector<int>(n, 0)); // +1 for color row

    // Define the adjacency matrix
    // You can modify this to create a different graph
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;

    // Random color assignment
    for (int i = 0; i < n; ++i) {
        graph[n][i] = rand() % 2;
    }

    cout << "Initial Graph with Random Colors (last row is color):\n";
    printMatrix(graph);

    // Ask user for sequence length
    int seqLen;
    cout << "Enter the length of vertex sequence: ";
    cin >> seqLen;

    vector<int> vertices(n);
    for (int i = 0; i < n; ++i) vertices[i] = i;

    set<vector<int>> validSequences;

    // Generate all sequences of length seqLen (allow repetition)
    function<void(vector<int>&, int)> generateSequences = [&](vector<int>& seq, int depth) {
        if (depth == seqLen) {
            Matrix temp = graph;
            for (int v : seq) {
                localComplement(temp, v);
            }
            if (isInverted(graph, temp)) {
                validSequences.insert(seq);
            }
            return;
        }
        for (int i = 0; i < n; ++i) {
            seq[depth] = i;
            generateSequences(seq, depth + 1);
        }
    };

    vector<int> seq(seqLen);
    generateSequences(seq, 0);

    cout << "\nSequences resulting in original graph with reversed colors:\n";
    if (validSequences.empty()) {
        cout << "None found.\n";
    } else {
        for (const auto& s : validSequences) {
            for (int v : s) cout << v << " ";
            cout << "\n";
        }
    }

    return 0;
}

