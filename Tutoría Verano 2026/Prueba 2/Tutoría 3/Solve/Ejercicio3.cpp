int tiempoEntrega(int n, vector<vector<pair<int, int>>> &adj, int inicio, int fin)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INF);

    dist[inicio] = 0;
    pq.push({0, inicio});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Si lo que saqué es peor que lo que ya conozco, lo ignoro
        if (d > dist[u])
            continue;

        if (u == fin)
            return d;

        for (auto &arista : adj[u])
        {
            int v = arista.first;
            int peso = arista.second;

            if (dist[u] + peso < dist[v])
            {
                dist[v] = dist[u] + peso;
                pq.push({dist[v], v});
            }
        }
    }
    return -1;
}