#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>

using namespace std;

class Graph
{
private:
    vector< list<int> > *adj;
public:
    Graph();
    Graph(Graph &obj);
    Graph(int size);
    void addEdge(int v1, int v2);
    void BFS(int s);
    void DFS(int s);
    ~Graph();
};

Graph::Graph()
{
}
Graph::Graph(Graph &obj)
{
    adj = new vector< list<int> >(obj.adj->size());
    *adj = *obj.adj;
}
Graph::Graph(int size)
{
    adj = new vector< list<int> >(size);
}
void Graph::addEdge(int v1, int v2)
{
    (*adj)[v1].push_back(v2);
    //   (*adj)[v2].push_back(v1);
}
void Graph::BFS(int s)
{
    vector<bool> visited(adj->size());

    for (int i = 0; i < visited.size(); i++) {
        visited[i] = false;
    }

    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (list<int>::iterator iter = (*adj)[s].begin(); iter != (*adj)[s].end(); iter++) {
            if (!visited[*iter]) {
                visited[*iter] = true;
                queue.push_back(*iter);
            }
        }
    }
}
void Graph::DFS(int s)
{
    vector<bool> visited(adj->size());

    for (int i = 0; i < visited.size(); i++) {
        visited[i] = false;
    }

    list<int> stack;
    visited[s] = true;
    stack.push_front(s);

    while (!stack.empty()) {
        s = stack.front();
        cout << s << " ";
        stack.pop_front();

        for (list<int>::iterator iter = (*adj)[s].begin(); iter != (*adj)[s].end(); iter++) {
            if (!visited[*iter]) {
                visited[*iter] = true;
                stack.push_front(*iter);
            }
        }
    }
}
Graph::~Graph()
{
    delete adj;
}
/*
 * 0--1
 * | /
 * |/
 * 2--3
 * */
/*
 *                  1
 *                 / \
 *                2   3
 *               / \   \
 *              4   5   6
 *             / \  |
 *            7  8  9
 *
 *
 *
 * */
int main(int argc, char **argv)
{
    Graph g(10);
    /*g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);*/
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 7);
    g.addEdge(4, 8);
    g.addEdge(5, 9);

    cout << "Following is Breadth First Traversal (starting from vertex 2)" << endl;
    g.BFS(atoi(argv[1]));
    cout << endl;
    g.DFS(atoi(argv[1]));
    cout << endl;
    return 0;
}
