#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int data;
	Node* next;
};

constexpr size_t MAX_NODE = 10000;
int node_count = 0;
Node node_pool[MAX_NODE];

Node* new_node(int x) {
	node_pool[node_count].data = x;
	node_pool[node_count].next = nullptr;

	return &node_pool[node_count++];
}

class SinglyLinkedList
{
	Node head;
public:
	SinglyLinkedList() = default;

	void init() {
		head.next = nullptr;
		node_count = 0;
	}

	void ins(int x, int y, vector<int>& s) {
		Node* ptr = &head;
		for (int i = 0; i < x; i++) {
			if (ptr->next == nullptr)
				break;
			ptr = ptr->next;
		}

		for (int i = 0; i < y; i++)
		{
			int d = s[i];
			Node* node = new_node(d);

			if (ptr->next != nullptr)
				node->next = ptr->next;

			ptr->next = node;

			ptr = node;
		}
	}

	void del(int x, int y) {
		Node* ptr = &head;
		for (int i = 0; i < x; i++) {
			if (ptr->next == nullptr)return;
			ptr = ptr->next;
		}

		for (int i = 0; i < y; i++)
		{
			if (ptr->next == nullptr)break;

			ptr->next = ptr->next->next;
		}
	}

	void add(int y, vector<int>& s) {
		Node* ptr = &head;
		while (ptr != nullptr && ptr->next != nullptr) {
			ptr = ptr->next;
		}

		for (int i = 0; i < y; i++)
		{
			int d = s[i];
			Node* node = new_node(d);

			ptr->next = node;
			ptr = node;
		}
	}

	void print() const {
		Node* ptr = head.next;
		for(int i = 0; i < 10; i++) {
			cout << ptr->data;
			if (ptr->next != nullptr)
				cout << " ";
			ptr = ptr->next;
		}
	}
};

SinglyLinkedList slist;
int n, m;

void init() {
	slist.init();
}
void input() {
	cin >> n;
	vector<int>ori_input(n);
	for (int i = 0; i < n; i++) {
		cin >> ori_input[i];
	}
	slist.add(n, ori_input);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		char cmd; cin >> cmd;
		switch (cmd) {
		case 'I': {
			int x, y;
			cin >> x >> y;
			vector<int>s(y);
			for (int j = 0; j < y; j++)
				cin >> s[j];
			slist.ins(x, y, s);
			break;
		}

		case 'D': {
			int x, y; cin >> x >> y;
			slist.del(x, y);
			break;
		}

		case 'A': {
			int y; cin >> y;
			vector<int>s(y);
			for (int j = 0; j < y; j++)
				cin >> s[j];
			slist.add(y, s);
			break;
		}
		}
	}
}

int main() {
	int TC = 10;
	for (int i = 1; i <= 10; i++)
	{
		init();
		input();
		cout << "#" << i << " ";
		slist.print();
		cout << "\n";
	}
	//SinglyLinkedList slist;
	//vector<int>v;
	//slist.init();
	//v.push_back(10);
	//v.push_back(2);
	//v.push_back(25);


	//slist.add(3, v);
	//slist.print();
}

