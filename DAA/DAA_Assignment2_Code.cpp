#include <bits/stdc++.h>
using namespace std;

class MinHeapNode
{
public:
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {

        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(MinHeapNode *root, string str)
{

    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(vector<char> &data, vector<int> &freq, int size)
{
    MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    cout << endl;

    vector<char> arr(n);
    vector<int> freq(n);

    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        arr[i] = temp;
    }
    cout << endl;

    cout << "Enter the frequencies: ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        freq[i] = temp;
    }
    cout << endl;

    HuffmanCodes(arr, freq, n);
    return 0;
}