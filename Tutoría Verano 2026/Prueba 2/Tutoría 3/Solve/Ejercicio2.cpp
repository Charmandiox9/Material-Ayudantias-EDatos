vector<int> rutaEscape(int n, vector<vector<int>> &adj, int inicio, int fin)
{
    queue<int> q;
    vector<bool> visitado(n, false);
    vector<int> padre(n, -1);

    q.push(inicio);
    visitado[inicio] = true;

    bool encontrado = false;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == fin)
        {
            encontrado = true;
            break;
        }

        for (int v : adj[u])
        {
            if (!visitado[v])
            {
                visitado[v] = true;
                padre[v] = u; // Guardamos quién nos trajo aquí
                q.push(v);
            }
        }
    }

    vector<int> ruta;
    if (encontrado)
    {
        int actual = fin;
        while (actual != -1)
        {
            ruta.push_back(actual);
            actual = padre[actual];
        }
        reverse(ruta.begin(), ruta.end());
    }
    return ruta;
}