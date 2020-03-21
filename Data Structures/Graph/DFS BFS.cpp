//BOTH ARE O(E+V)      //source->http://stackoverflow.com/questions/11468621/why-is-the-time-complexity-of-both-dfs-and-bfs-o-v-e

void DFS(vector<lli> graph[],lli source,lli v)
{
  stack<lli> Q;
  Q.push(source);

  lli visited[v+5];
  for(lli i=0;i<v+5;i++) visited[i]=0;
  visited[source]=1;


  while(!Q.empty())
  {
      lli vertex=Q.top();
      cout<<vertex;
      Q.pop();
      for(lli i=0;i<graph[vertex].size();i++)
      {
          if(!visited[ graph[vertex][i] ])
          {
              Q.push(graph[vertex][i]);
              visited[ graph[vertex][i] ]=1;
          }
      }
  }
}

void BFS(vector<lli> graph[],lli source,lli v)
{
  queue<lli> Q;
  Q.push(source);

  lli visited[v+5];
  for(lli i=0;i<v+5;i++) visited[i]=0;
  visited[source]=1;


  while(!Q.empty())
  {
      lli vertex=Q.front();
      cout<<vertex;
      Q.pop();
      for(lli i=0;i<graph[vertex].size();i++)
      {
          if(!visited[ graph[vertex][i] ])
          {
              Q.push(graph[vertex][i]);
              visited[ graph[vertex][i] ]=1;
          }
      }
  }
}
