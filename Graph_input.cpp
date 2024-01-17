/*
    Graph Operations Program

    This C++ program allows users to perform various operations on two undirected graphs,
    including finding the union, intersection, ring sum, and difference of the graphs.
    The program represents graphs using adjacency matrices and handles vertices that are absent
    in each graph. It provides a menu-driven interface for users to input graph details and
    perform desired operations.

    Author: Dev Bachani (21BCE049)
    Date: [10/01/2024]

    How to use:
    1. Enter the number of vertices and edges for each graph.
    2. Specify the vertices that are absent in each graph.
    3. Input edges for both graphs.
    4. View the adjacency matrices for both graphs.
    5. Obtain the union, intersection, ring sum, difference, and complement of the graphs.

    Note: Ensure that input values adhere to the program's expectations.

    Disclaimer: This program assumes that the input graphs are simple and undirected.

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define vint vector<int>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define pll pair<ll, ll>
#define mpll map<ll, ll>
#define ld long double
#define float double

int main()
{

    // Adjacency matrix
    int v1, e1, v2, e2;
    cout << "Enter number of vertices in graph 1: " << endl;
    cin >> v1;
    cout << "Enter number of vertices in graph 2: " << endl;
    cin >> v2;

    cout << "Enter number of edges in graph 1: " << endl;
    cin >> e1;
    cout << "Enter number of edges in graph 2: " << endl;
    cin >> e2;
    int v1_, v2_;
    int v = max(v1, v2);

    cout << "Enter number of vertices absent in graph 1: " << endl;
    cin >> v1_;
    cout << "Enter number of vertices absent in graph 2: " << endl;
    cin >> v2_;
    vector<int> abs_vertices_1;
    vector<int> abs_vertices_2;
    for (int i = 0; i < v1_; i++)
    {
        int a;
        cout << "Absent vertex of Graph 1: " << endl;
        cin >> a;
        abs_vertices_1.push_back(a);
    }
    for (int i = 0; i < v2_; i++)
    {
        int a;
        cout << "Absent vertex of Graph 2: " << endl;
        cin >> a;
        abs_vertices_2.push_back(a);
    }

    sort(abs_vertices_1.begin(), abs_vertices_1.end());
    sort(abs_vertices_2.begin(), abs_vertices_2.end());

    vector<vector<int>> G1(v, vector<int>(v, 0));
    vector<vector<int>> G2(v, vector<int>(v, 0));

    for (int i = 0; i < v1_; i++)
    {
        for (int j = 0; j < v; j++)
        {
            G1[j][abs_vertices_1[i] - 1] = -1;
            G1[abs_vertices_1[i] - 1][j] = -1;
        }
    }
    for (int i = 0; i < v2_; i++)
    {
        for (int j = 0; j < v; j++)
        {
            G2[j][abs_vertices_2[i] - 1] = -1;
            G2[abs_vertices_2[i] - 1][j] = -1;
        }
    }
    cout << "Enter Edges of Graph 1: \n";
    for (int i = 0; i < e1; i++)
    {
        int a, b;
        cout << "Enter the 2 vertices of edge " << i + 1 << endl;
        cin >> a >> b;
        G1[a - 1][b - 1] = 1;
        G1[b - 1][a - 1] = 1;
    }

    cout << "Enter Edges of Graph 2: \n";
    for (int i = 0; i < e1; i++)
    {
        int a, b;
        cout << "Enter the 2 vertices of edge " << i + 1 << endl;
        cin >> a >> b;
        G2[a - 1][b - 1] = 1;
        G2[b - 1][a - 1] = 1;
    }
    // Adjacency list

    int n1, m1, n2, m2;
    cout << "Enter number of vertices in graph 1: " << endl;
    cin >> n1;
    cout << "Enter number of vertices in graph 2: " << endl;
    cin >> n2;

    cout << "Enter number of edges in graph 1: " << endl;
    cin >> m1;
    cout << "Enter number of edges in graph 2: " << endl;
    cin >> m2;

    vector<vector<int>> G1(n1);
    vector<vector<int>> G2(n2);

    cout << "Enter Edges of Graph 1: \n";
    for (int i = 0; i < m1; i++)
    {
        int a, b;
        cout << "Enter the 2 vertices of edge " << i + 1 << endl;
        cin >> a >> b;
        G1[a - 1].push_back(b - 1);
        G1[b - 1].push_back(a - 1);
    }

    cout << "Enter Edges of Graph 2: \n";
    for (int i = 0; i < m1; i++)
    {
        int a, b;
        cout << "Enter the 2 vertices of edge " << i + 1 << endl;
        cin >> a >> b;
        G2[a - 1].push_back(b - 1);
        G2[b - 1].push_back(a - 1);
    }

    if (n1 != n2 || m1 != m2)
    {
        cout << "Graphs are NOT Isomorphic" << endl;
        return 0;
    }
    map<int, int> a;
    map<int, int> b;
    for (int i = 0; i < n1; i++)
    {
        a[i] = G1[i].size();
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = G2[i].size();
    }
    if (a != b)
    {
        cout << "Graphs are NOT Isomorphic" << endl;
        return 0;
    }
}