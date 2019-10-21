class Solution {
public:
    struct Node {
        Node *parent;
        double value;
        Node(){ parent = this;}
    };
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, Node*> map;
        for (int i = 0; i < equations.size(); ++i) {
            auto eq = equations[i];
            if (map.count(eq[0]) == 0 && map.count(eq[1]) == 0) {
                map[eq[0]] = new Node;
                map[eq[1]] = new Node;
                map[eq[0]]->value = values[i];
                map[eq[0]]->parent = map[eq[1]];
                map[eq[1]]->value = 1.0;
            } else if (map.count(eq[0]) != 0 && map.count(eq[1]) == 0) {
                map[eq[1]] = new Node;
                map[eq[1]]->parent = map[eq[0]];
                map[eq[1]]->value = map[eq[0]]->value / values[i];
            } else if (map.count(eq[0]) == 0 && map.count(eq[1]) != 0) {
                map[eq[0]] = new Node;
                map[eq[0]]->parent = map[eq[1]];
                map[eq[0]]->value = values[i] * (map[eq[1]]->value);
            } else {
                union_node(eq[0], eq[1], values[i], map);
            }
        }
        vector<double> ret;
        for (auto iter = queries.begin(); iter != queries.end(); ++iter) {
            if (map.count((*iter)[0]) == 0 || map.count((*iter)[1]) ==0 || find(map[(*iter)[0]]) != find(map[(*iter)[1]])) {
                ret.push_back(-1.0);
            } else {
                ret.push_back(map[(*iter)[0]]->value / map[(*iter)[1]]->value);
            }
        }
        return ret;
        
    }
    
    void union_node(string s0, string s1, double value, unordered_map<string, Node*> &map) {
        Node *p0 = find(map[s0]);
        Node *p1 = find(map[s1]);
        double r = value * (map[s1]->value / map[s0]->value);
        for (auto it = map.begin(); it != map.end(); ++it) {
            if (it->second->parent == p0) {
                it->second->value *= r;
            }
        }
        p0->parent = p1;
    }
    
    Node* find(Node *n) {
        if (n->parent == n)
            return n;
        return find(n->parent);
    }
    
    
};