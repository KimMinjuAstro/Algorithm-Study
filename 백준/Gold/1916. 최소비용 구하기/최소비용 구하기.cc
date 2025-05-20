#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int dist[1001];
struct Edge {
	int num;
	int cost;

	bool operator<(Edge right) const {
		return cost > right.cost;
	}
};
vector<Edge>alis[1001];
int dijkstra(int start, int end) {
	priority_queue<Edge>pq;
	for (int i = 0; i <= n; i++)
			dist[i] = 21e8;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();
		if (dist[now.num] < now.cost)continue;
		for (int i = 0; i < alis[now.num].size(); i++) {
			Edge next = alis[now.num][i];
			int nextcost = dist[now.num] + next.cost;

			if (dist[next.num] <= nextcost)continue;
			dist[next.num] = nextcost;

			pq.push({ next.num, nextcost });
		}
	}
	return dist[end];
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		alis[start].push_back({ end, cost });
	}

	int start, end;
	cin >> start >> end;
	cout << dijkstra(start, end);
}