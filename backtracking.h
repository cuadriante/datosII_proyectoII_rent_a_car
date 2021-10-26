path_t *allocatePath(int n_routes) {
    path_t *path = NULL;
    path = (path_t *) malloc(sizeof(path_t) + n_routes * sizeof(path->path[0]));
    if (path == NULL)
        return NULL;

    return path;
}

path_t *rec(path_t *path, Graph roads, int current, int start, int end, int n_routes) {
    path_t *best_path, *cur_path;
    int cur_best_gas, gas, path_length;
    

    // If we've reached the end, return path
    if (current == end)
        return path;
        
    best_path = allocatePath(n_routes);
    best_path->max_gas = 1000;
    for (int j = 0; j < n_routes; j++) {
        best_path->path[j] = path->path[j];
    }

    // Save path length
    path_length = path->length;

    // Check every path
    for (int i = 0; i < n_routes; i++) {
        if (roads.adj[current][i] == -1 || i == start) // Non-existant paths
            continue;

        if (roads.adj[current][i] > path->max_gas)
            path->max_gas = roads.adj[current][i];
        
        // Set path location length to i
        path->path[path_length] = i;
        path->length = path_length + 1;
        
        // Mark next location to your current one as -1, so you don't go back
        roads.adj[i][current] = -1;

        path = rec(path, roads, i, start, end, n_routes);

        if (path->max_gas < best_path->max_gas) {
            // Set best paths max gas to returned paths max gas
            best_path->max_gas = path->max_gas;
            best_path->length = path->length;

            // Copy over path
            for (int j = 0; j < n_routes; j++) {
                best_path->path[j] = path->path[j];
            }
        }
    }

    free(path);
    return best_path;
}