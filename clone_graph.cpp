/*
Clone an undirected graph. Each node in the graph contains alabeland a list of itsneighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use#as a separator for each node, and,as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph{0,1,2# 1,2# 2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by#.

First node is labeled as0. Connect node0to both nodes1and2.
Second node is labeled as1. Connect node1to node2.
Third node is labeled as2. Connect node2to node2(itself), thus forming a self-cycle.

*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    std::map<UndirectedGraphNode*,UndirectedGraphNode*> m;
    std::map<UndirectedGraphNode*,UndirectedGraphNode*>::iterator iter;
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return node;
        return dfs(node);
    }
    
    UndirectedGraphNode* dfs(UndirectedGraphNode* node){
        iter=m.end();
        iter=m.find(node);
        if(iter!=m.end())
            return node;
        UndirectedGraphNode* p=new UndirectedGraphNode(node->label);
        m.insert(std::pair<UndirectedGraphNode*,UndirectedGraphNode*>(node,p));
        for(int i=0;i<node->neighbors.size();i++){
            p->neighbors.push_back(dfs(node->neighbors[i]));
        }
        return p;
    }
    
};
