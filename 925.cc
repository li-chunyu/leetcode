class Solution {
public:
    struct Node {
      char ilabel;
      Node *forward;
      bool selfloop;
      Node *backward;
      bool fin;
      Node(char input):
        ilabel(input), forward(NULL),selfloop(true), fin(false){}
    };

    bool isLongPressedName(string name, string typed) {
      if (name.size() > typed.size())
        return false;
      Node *cur = NULL, *prev = NULL, *head = NULL;
      cur = prev = new Node(name[0]);
      head = cur;
      for (int i = 1; i < name.size(); ++i) {
        cur = new Node(name[i]);
        prev->forward = cur;
        if (cur->ilabel == prev->ilabel) {
          prev->selfloop = false; 
        }
        prev = cur;
      }
      cur->forward = new Node('\0');
      cur->forward->fin = true;
      cur = head;
      int idx = 0;
      cur = head;
      while (idx < typed.size()) {
        if (typed[idx] == cur->ilabel) {
          if (cur->selfloop){
            char c = typed[idx];
            while (++idx < typed.size() && typed[idx] == c);
            cur = cur->forward;
            continue;
          } else {
            cur = cur->forward;
            idx += 1;
          }
        } else {
          return false;
        }
      }
      return cur->fin;
    }
};


// two pointer.
class Solution {
public:
bool isLongPressedName(string name, string typed) {
  int i = 0; // i for name , j for typed.
    for (int j = 0; j < typed.size(); ++j) {
      if (name[i] == typed[j]) {
        ++i;
      } else if (!j || typed[j] != typed[j-1]) {
        return false;
      }
    }
    return i == name.size();
  }
};