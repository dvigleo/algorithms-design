#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <chrono>
// Librerias de Boost
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/graph/breadth_first_search.hpp>

using namespace boost;
using namespace std;

typedef property<edge_weight_t, int> EdgeWeightProperty;
typedef adjacency_list<listS, vecS, directedS, no_property, EdgeWeightProperty> grafoInicial;
typedef boost::adjacency_list<boost::vecS, boost::hash_setS, boost::undirectedS, uint32_t, uint32_t, boost::no_property> graph_t;
typedef boost::property<boost::edge_weight_t, int> EdgeWeightProperty;

typedef boost::graph_traits<grafoInicial>::out_edge_iterator oe_it;
typedef boost::graph_traits<grafoInicial>::edge_iterator e_it;
typedef boost::graph_traits<grafoInicial>::vertex_iterator v_it;
typedef boost::graph_traits<grafoInicial>::vertex_descriptor Vertex;
typedef boost::graph_traits<grafoInicial>::edge_descriptor Edge;


grafoInicial g(13);
void AddEdge(int s, int d, int w, grafoInicial &a);
void EraseN(int cual, grafoInicial &a);
void AddN(grafoInicial &grafo);
void EraseEdge(int s, int d, grafoInicial &graf);
void AddEdgeDiff(int s, int d, int w, grafoInicial &a);
void dfs(grafoInicial &a, unsigned long startingNode);
void bfs(grafoInicial &a, unsigned long startingNode);
vector<std::tuple<Vertex, Vertex, int>> kruskal(grafoInicial g);
vector<pair<Vertex, int>> prim(grafoInicial g, int vertexStart);
vector<pair<int, Vertex>> dijkstra(grafoInicial g, unsigned long initialNode);
vector<vector<int>> floydWarshall(grafoInicial g);

struct oper{
    bool operator()(const std::tuple<int,Vertex, Vertex>& one, const std::tuple<int,Vertex, Vertex>& two) { return std::get<0>(one) > std::get<0>(two); }
};

struct oper2{
    bool operator()(const Edge& one, const Edge& two){ return boost::get(boost::edge_weight_t(), g, one) > boost::get(boost::edge_weight_t(), g, two); }
};

int main()
{
    AddEdge(0 ,2, 8, g);
    AddEdge(0, 3, 8, g);
    AddEdge(2, 1, 7, g);
    AddEdge(2, 9, 4, g);
    AddEdge(2, 4, 8, g);
    AddEdge(1, 4, 7, g);
    AddEdge(3, 7, 2, g);
    AddEdge(3, 6, 3, g);
    AddEdge(3, 4, 1, g);
    AddEdge(4, 5, 9, g);
    AddEdge(5, 12, 4, g);
    AddEdge(6, 3, 6, g);
    AddEdge(7, 6, 3, g);
    AddEdge(7, 8, 3, g);
    AddEdge(8, 9, 2, g);
    AddEdge(8, 11, 4, g);
    AddEdge(9, 2, 10, g);
    AddEdge(9, 5, 6, g);
    AddEdge(10, 11, 6, g);
    AddEdge(11, 8, 2, g);
    AddEdge(11, 10, 8, g);
    AddEdge(11, 13, 9, g);
    AddEdge(12, 13, 6, g);
    AddEdge(13,12,12,g);
    graph_traits<grafoInicial>::vertex_iterator vi, vi_fin, sig;
    tie(vi, vi_fin) = vertices(g);
    write_graphviz(cout, g);
    bfs(g, 0);
    dfs(g,0);
    vector<pair<Vertex, int>> Prim = prim(g, 0);
    vector<std::tuple<Vertex, Vertex, int>> Kruskal = kruskal(g);
    vector<pair<int, Vertex>> Dijkstra = dijkstra(g,1);
    vector<vector<int>> FloydWarhsall = floydWarshall(g);

    return 0;
}

void AddEdge(int s, int d, int w, grafoInicial &a) { add_edge(s, d, w, a); }
void AddEdgeDiff(int s, int d, int w, grafoInicial &a)
{
    add_edge(s,d,w,a);
    add_edge(d,s,w,a);
}
void EraseEdge(int s, int d, grafoInicial &graf) { remove_edge(s,d,graf); }
void EraseN(int cual, grafoInicial &a) { remove_vertex(cual, a); }
void AddN(grafoInicial &grafo) { add_vertex(grafo); }

void dfs(grafoInicial &a, unsigned long startingNode)
{
    stack<Vertex> visiting;
    map<Vertex,bool> travelled;
    Vertex checking = a.vertex_set()[startingNode];
    visiting.push(checking);
    travelled[checking] = true;
    while(!visiting.empty())
    {
        checking = visiting.top();
        visiting.pop();
        pair<oe_it,oe_it> iterators = out_edges(checking,a);
        for(oe_it it = iterators.first; it != iterators.second; ++it)
        {
            Vertex target = boost::target(*it,a);
            if(travelled[target]) continue;
            travelled[target] = true;
            visiting.push(target);
        }
        cout << checking << "-";

    }
    cout<<"\n";

}

void bfs(grafoInicial &a, unsigned long startingNode){
    std::queue<Vertex> visiting;
    map<Vertex,bool> travelled;
    Vertex checking = a.vertex_set()[startingNode];
    visiting.push(checking);
    travelled[checking] = true;
    while(!visiting.empty()){
        checking = visiting.front();
        visiting.pop();
        pair<oe_it,oe_it> iterators = out_edges(checking,a);
        for(oe_it it = iterators.first; it != iterators.second; ++it){
            Vertex target = boost::target(*it,a);
            if(travelled[target]) continue;
            travelled[target] = true;
            visiting.push(target);
        }
        cout << checking << "-";
    }
    cout<<"\n";
}

vector<pair<Vertex, int>> prim(grafoInicial g, int vertexStart)
{
    vector<pair<Vertex, int>> result;
    priority_queue<std::tuple<int,Vertex,Vertex>,vector<std::tuple<int,Vertex, Vertex>>, oper> next;
    map<Vertex,bool> travelled;
    std::tuple<int,Vertex,Vertex> now;
    int weight;
    pair<v_it,v_it> iterators = vertices(g);
    Vertex checking = g.vertex_set()[vertexStart];
    for(v_it it = iterators.first; it != iterators.second; ++it) result.push_back(make_pair(-1, INT32_MIN));
    result[checking].second = 0;
    next.push(make_tuple(0,checking,checking));
    while(!next.empty())
    {
        now = next.top();
        next.pop();
        checking = std::get<1>(now);
        if(travelled[checking]) continue;
        travelled[checking] = true;
        result[checking] = make_pair(std::get<2>(now), std::get<0>(now));
        pair<oe_it,oe_it> oeIt = out_edges(checking,g);
        for(oe_it it = oeIt.first; it != oeIt.second; ++it)
        {
            Vertex target = boost::target(*it,g);
            if(travelled[target]) continue;
            weight = boost::get(boost::edge_weight_t(),g, *it);
            next.push(make_tuple(weight,target,checking));
        }
    }
    return result;
}

vector<std::tuple<Vertex, Vertex, int>> kruskal(grafoInicial g)
{
    vector<vector<int>*> travelled;
    vector<std::tuple<Vertex, Vertex, int>> result;
    priority_queue<Edge, vector<Edge>, oper2> next;
    pair<v_it,v_it> iterators = vertices(g);
    int counter = 0;
    Edge checking;
    Vertex source, target;

    for(v_it it = iterators.first; it != iterators.second; ++it)
    {
        vector<int>* a = new vector<int>;
        a->push_back(counter);
        travelled.push_back(a);
        ++counter;
    }

    pair<e_it,e_it> edIt = edges(g);

    for(e_it it = edIt.first; it != edIt.second; ++it)
    {
        std::pair<Edge,bool> a = boost::edge(boost::source(*it,g),boost::target(*it,g), g);
        next.push(a.first);
    }

    while(!next.empty()){
        checking = next.top();
        source = boost::source(checking,g);
        target = boost::target(checking,g);
        next.pop();
        if(*travelled[source] == *travelled[target]) continue;
        vector<int> add;
        for(vector<int>::iterator it = travelled[target]->begin(); it != travelled[target]->end(); ++it){
            travelled[source]->push_back(*it);
            add.push_back(*it);
        }
        for(vector<int>::iterator it = add.begin(); it != add.end(); ++it){
            travelled[*it] = travelled[source];
        }
        result.push_back(make_tuple(source,target, boost::get(boost::edge_weight_t(), g, checking)));
    }
    return result;

}

vector<pair<int, Vertex>> dijkstra(grafoInicial g, unsigned long initialNode)
{
    vector<pair<int, Vertex>> distances;
    map<Vertex, bool> visited;
    priority_queue<std::tuple<int,Vertex,Vertex>, vector<std::tuple<int,Vertex,Vertex>>,oper> next;
    std::tuple<int,Vertex,Vertex> checking;
    Vertex source, target;
    int weight, checkingWeight;
    pair<v_it,v_it> iterators = vertices(g);
    for(v_it it = iterators.first; it != iterators.second; ++it) distances.push_back(make_pair(INT_MAX, -1));
    distances[initialNode].first = 0;
    next.push(std::make_tuple(0,initialNode,initialNode));
    while(!next.empty())
    {
        checking = next.top();
        next.pop();
        target = std::get<2>(checking);
        source = std::get<1>(checking);
        if(visited[target]) continue;
        visited[target] = true;
        checkingWeight = std::get<0>(checking);
        if(distances[target].first < checkingWeight) continue;
        distances[target] = make_pair(checkingWeight,source);
        pair<oe_it,oe_it> oeIt = out_edges(target,g);
        for(oe_it it = oeIt.first; it != oeIt.second; ++it)
        {
            Vertex newTarget = boost::target(*it,g);
            if(visited[newTarget]) continue;
            weight = boost::get(boost::edge_weight_t(),g, *it);
            next.push(make_tuple(distances[target].first + weight,target,newTarget));
        }
    }
    return distances;
}

vector<vector<int>> floydWarshall(grafoInicial g)
{
    vector<vector<int>> distances;
    unsigned long vNum = num_vertices(g);
    distances.resize(vNum);
    pair<v_it,v_it> iterators = vertices(g);
    for(v_it it = iterators.first; it != iterators.second; ++it)
    {
        for(v_it it2 = iterators.first; it2 != iterators.second; ++it2)
        {
            if(it == it2)
            {
                distances[*it].push_back(0);
                continue;
            }
            else distances[*it].push_back(100000);
        }
    }
    pair<e_it,e_it> edIt = edges(g);
    for(e_it it = edIt.first; it != edIt.second; ++it)
    {
        distances[boost::source(*it,g)][boost::target(*it,g)] = boost::get(boost::edge_weight_t(),g, *it);
    }

    for(int k = 0; k < vNum; ++k){
        for(int i = 0; i < vNum; ++i){
            for(int j = 0; j < vNum; ++j){
                if(distances[i][j] > distances[i][k] + distances[k][j])
                    distances[i][j] = distances[i][k] + distances[k][j];
            }
        }
    }
    return distances;
}
