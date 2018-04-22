#include<iostream>
using namespace std;

class queue {
	int data[50];
	int rear, front;
public:
	queue() {
		rear = front = -1;
	}

	int empty() {
		if (rear == -1)
			return 1;
		return 0;
	}

	void push(int x) {
		if (empty())
			rear = front = 0;
		else
			rear = rear + 1;
		data[rear] = x;
	}

	int pop() {
		int x = data[front];

		if (rear == front)
			rear = front = -1;
		else
			front = front + 1;
		return x;
	}
};

struct node {
	node *next;
	int ver;
	int comments;
	int mon;
};

class graph {
	int visited[50];
	node *adj_list[50];
	node v[50];
	int n;
	int c[50];
	int month[50];

public:
	void create() {
		int i, j, ans;
		cout << "\nTotal Persons: \t";
		cin >> n;
		for (i = 1; i <= n; i++) {
			cout << "Enter information for person " << i << endl;
			cout << "Enter birthday month(in number):\n";
			cin >> v[i].mon;
			cout << "Enter Number of comments:\n";
			cin >> v[i].comments;
		}
		for (i = 1; i <= n; i++) {
			adj_list[i] = NULL;
		}
		do {
			cout << "Enter pair of person who are friends:";
			cin >> i >> j;
			if (i >= 1 && i <= n && j >= 1 && j <= n) {
				makef(i, j);
				makef(j, i);
			} else
				cout << "Not possible\n";
			cout << "Do u want to enter more pairs?(if Yes press 1/0)\n";
			cin >> ans;
		} while (ans == 1);
	}

	void makef(int i, int j) {
		struct node *p, *q;

		q = new node;
		q->ver = j;
		q->next = NULL;
		if (adj_list[i] == NULL) {
			adj_list[i] = q;
		} else {
			p = adj_list[i];
			while (p->next != NULL) {
				p = p->next;
			}
			p->next = q;
		}
	}

	void initialize() {
		for (int i = 1; i <= n; i++) {
			visited[i] = 0;
		}
	}

	void BFS(int v) {
		int i, w;
		int max = 0;
		queue Q;
		node *p;
		int count[50];
		for (i = 1; i <= n; i++) {
			visited[i] = 0;
			count[i] = 0;
		}
		Q.push(v);
		visited[v] = 1;
		while (!Q.empty()) {
			v = Q.pop();
			for (p = adj_list[v]; p != NULL; p = p->next) {
				w = p->ver;
				if (visited[w] == 0) {
					Q.push(w);
					visited[w] = 1;
				}
				count[v]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (count[i] >= max) {
				max = count[i];
			}
		}
		cout << "\nPerson with maximum no. of friends : ";

		for (i = 1; i <= n; i++) {
			if (max == count[i]) {
				cout << " " << i;
			}
		}
		cout << "\nMaximum no. of friends is : \tss" << max << endl;
	}

	void DFS(int i) {
		node *p;
				p = adj_list[i];
		visited[i] = 1;
		c[i] = v[i].comments;
		month[i] = v[i].mon;
		while (p != NULL) {
			i = p->ver;
			if (visited[i] == 0)
				DFS(i);
			p = p->next;
		}
	}

	void no_comments() {
		int max = 0, min = c[1];
		int maximum, minimum;
		for (int i = 1; i <= n; i++) {
			if (c[i] > max) {
				max = c[i];
				maximum = i;
			}
		}
		cout << "\nPerson with maximum posts : \t" << maximum;
		for (int i = 1; i <= n; i++) {
			if (c[i] <= min) {
				min = c[i];
				minimum = i;
			}
		}
		cout << "\nPerson with minimum posts : \t" << minimum;
	}

	void bday() {
		int mon, i, count;
		cout << "Enter the month(in number):\t";
		cin >> mon;
		cout << "\nPersons with birthday in entered month are:\n";
		i = 1;
		while (i <= n) {
			if (mon == month[i]) {
				cout << i << " ";
				count++;
			}
			i++;
		}
		if (count == 0) {
			cout << "0";
		}
		cout << endl;
	}
};

int main() {
	int ch;
	graph g;
	g.create();
	do {
		cout << "\n1.Person with max friends\n"<<"2.Find Birthday\n"<<"3.Max and Min comments\n"<<"4.Exit\n";
		cout << "Enter Choice : ";
		cin >> ch;
		switch (ch) {
		case 1:
			g.BFS(1);
			cout << "\n";
			break;
		case 2:
			g.initialize();
			g.DFS(1);
			cout << "\n";
			g.bday();
			break;
		case 3:
			g.initialize();
			g.DFS(1);
			cout << "\n";
			g.no_comments();
			break;
		}
	} while (ch < 4);
	return 0;
}

