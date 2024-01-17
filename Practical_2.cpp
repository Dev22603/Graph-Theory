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

// Isomorphism
const int num1 = 1e5 + 10;
vector<int> graph[num1];
bool vis[num1];

void dfs(int vertex)
{
    vis[vertex] = 1;
    cout << vertex << "->";
    for (int i = 0; i < graph[vertex].size(); i++)
    {
        int child = graph[vertex][i];
        if (vis[child] == 0)
            dfs(child);
    }
    // OR this for loop

    // for (int child : graph[vertex])
    // {
    //     if (vis[child] == 0)
    //         dfs(child);
    // }
}

// Function to print the adjacency matrix representation of a graph
void printMatrix(vector<vector<int>> &a)

{
    cout << "Graph: \n\n";
    cout << "\tVertices\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << " " << i + 1 << "  ";
    }
    cout << "\n\n";
    for (auto row : a)
    {
        for (auto ele : row)
        {
            if (ele > -1)
                cout << " " << ele + 1 << "  ";
            else
                cout << ele + 1 << "  ";
        }
        cout << "\n";
    }
}
int main()
{

    int n1, m1, n2, m2;
    cout << "Enter number of vertices in graph 1: " << endl;
    cin >> n1;
    cout << "Enter number of vertices in graph 2: " << endl;
    cin >> n2;

    cout << "Enter number of edges in graph 1: " << endl;
    cin >> m1;
    cout << "Enter number of edges in graph 2: " << endl;
    cin >> m2;

    vector<vector<int>> G1(n1 + 1, vector<int>(n1 + 1, 0));
    map<int, int> degree1;

    vector<vector<int>> G2(n2 + 1, vector<int>(n2 + 1, 0));
    map<int, int> degree2;

    cout << "Enter Edges of Graph 1: \n";
    for (int i = 0; i < m1; i++)
    {
        int a, b;
        cout << "Enter the 2 vertices of edge " << i + 1 << endl;
        cin >> a >> b;
        G1[a][b] = G1[b][a] = 1;
        degree1[a]++;
        degree1[b]++;
    }

    cout << "Enter Edges of Graph 2: \n";
    for (int i = 0; i < m1; i++)
    {
        int a, b;
        cout << "Enter the 2 vertices of edge " << i + 1 << endl;
        cin >> a >> b;
        G2[a][b] = G2[b][a] = 1;
        degree2[a]++;
        degree2[b]++;
    }

    if (n1 != n2 || m1 != m2)
    {
        cout << "Graphs are NOT Isomorphic" << endl;
        return 0;
    }
    map<int, int> a; // Indicates the frequency of degrees in a graph, for example, degree 3 ki kitni vertices hai, degree 1 ki kitni vertices hai.
    map<int, int> b;

    // Count the frequency of degrees in graph 1
    for (auto v : degree1)
    {
        a[v.second]++;
    }

    // Count the frequency of degrees in graph 2
    for (auto v : degree2)
    {
        b[v.second]++;
    }

    if (a != b) // if the degree frequency maps are not equal then the graphs are not isomorphic
    {
        cout << "Graphs are NOT Isomorphic" << endl;
        return 0;
    }

    map<int, int> vis1, vis2;
    // Iterate through each vertex in graph 1
    for (int i = 1; i <= n1; i++)
    {
        int deg = degree1[i];
        vector<int> n11;

        // Collect the degrees of neighboring vertices in graph 1
        for (int j = 1; j <= n1; j++)
        {
            if (G1[i][j] == 1)
            {
                n11.push_back(degree1[j]);
            }
        }

        // Sort the degrees for comparison
        sort(n11.begin(), n11.end());
        for (auto v : degree2) // Iterate through vertices in graph 2 with the same degree as that of ith vertex
        {
            if (v.second == deg && vis2[v.first] != 1)
            {
                vector<int> n22;
                // Collect the degrees of neighboring vertices in graph 2
                for (int j = 1; j <= n2; j++)
                {
                    if (G2[v.first][j] == 1)
                    {
                        n22.push_back(degree2[j]);
                    }
                }
                sort(n22.begin(), n22.end());
                if (n11 == n22) // If the sorted degree sequences are equal, mark vertices as visited
                {
                    vis1[i] = 1;
                    vis2[v.first] = 1;
                    break;
                }
            }
        }
        if (vis1[i] != 1) // If even a single vertex in graph 1 is not marked as visited, then graphs are not isomorphic
        {
            cout << "\n\nNOT ISOMORPHIC!" << endl;
            return 0;
        }
    }
    cout << "\n\nISOMORPHIC!" << endl;
}