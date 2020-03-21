//the algo finds minimum distance of all vertices from start with edge-weight in{0,1}

void bfs (int start)
    {
        deque <int > Q;     // double ended queue
        Q.push_back( start); 
        distance[ start ] = 0;       
        while( !Q.empty ())
        {
            int v = Q.front( );
            Q.pop_front(); 
            for( int i = 0 ; i < edges[v].size(); i++)
    {
        /* if distance of neighbour of v from start node is greater than sum of distance of v from start node and edge weight between v and its neighbour (distance between v and its neighbour of v) ,then change it */
    if(distance[ edges[ v ][ i ].first ] > distance[ v ] + edges[ v ][ i ].second ) 
        {

            distance[ edges[ v ][ i ].first ] = distance[ v ] + edges[ v ][ i ].second;
            /*if edge weight between v and its neighbour is 0 then push it to front of
    double ended queue else push it to back*/
                if(edges[ v ][ i ].second == 0)
                {
                    Q.push_front( edges[ v ][ i ].first);
                }
                else
                    {
                        Q.push_back( edges[ v ][ i ].first);

                    }
            }
        }