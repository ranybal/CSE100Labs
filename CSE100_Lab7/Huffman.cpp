#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;

struct node {
    char data;
    unsigned int freq;
    // this->data = data;
    // this->freq = freq;
    node *left, *right;
    //left = right = NULL;
    
public:
    node(char d, unsigned int f) {
        node *left, *right;
        left = 0;
        right = 0;
        this->data = d;
        this->freq = f;
    }
    struct comp {
        bool operator()(node* left, node* right) {
            return (left->freq > right->freq);
        }
    };
    
    ~node()
    {
        delete left,delete right;
    }
};
string s[26];

void print(struct node* root1, string str, char arr[], int sizeofarray) {
    
    if (root1 == NULL){}
    if(root1->data !='$') {
        
        for (int i=0; i < sizeofarray; i++) {
            if (root1->data == arr[i]) {
                s[i] = str;
            }
        }
    }
    
    if(root1->data == '$')
    {
        //fill in code
        print(root1->left, str + "0", arr, sizeofarray);
        print(root1->right,str + "1", arr, sizeofarray);
        
    }
}
//taken from pseudocode
void huffman(char arr[], int freq[], int sizeofarray) {
    struct node *l;
    struct node *r;
    struct node *top;
    priority_queue<node*, vector<node*>, node::comp> pq;
    for (int i = 0; i < sizeofarray; i++)
    {
        node *tempnode =new node(arr[i], freq[i]);
        pq.push(tempnode);
    }
    do {
        l = pq.top();
        pq.pop();
        r = pq.top();
        pq.pop();
        
        node *tempnode1 =new node('$', l->freq + r->freq);
        top = tempnode1;
        top->left = l;
        top->right = r;
        pq.push(top);
    }while (pq.size() > 1);
    
    //print function
    print(pq.top(), "", arr, sizeofarray);
    
    for (int i = 0; i < sizeofarray; i++)
        cout<<s[i]<<endl; //display character:frequency
}

int main() {
    int n;
    cin >> n;
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int freq[n];
    for (int i = 0; i < n; i++)
        cin>>freq[i];
    huffman(arr, freq, n);
}
