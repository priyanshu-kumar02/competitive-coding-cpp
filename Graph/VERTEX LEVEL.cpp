void BFS(vector<lli> graph[],lli source,lli v)
{
  queue<lli> Q;
  Q.push(source);

  lli visited[v+5];
  for(lli i=0;i<v+5;i++) visited[i]=0;
  visited[source]=1;

 lli level[v+5];
 level[source]=0;

  while(!Q.empty())
  {
      lli vertex=Q.front();
      cout<<vertex;
      Q.pop();

      for(lli i=0;i<graph[vertex].size();i++)
      {
          if(!visited[ graph[vertex][i] ])
          {
              level[graph[vertex][i]]=level[vertex]+1;
              Q.push(graph[vertex][i]);
              visited[ graph[vertex][i] ]=1;
          }
      }

  }

  for(lli i=1;i<=v;i++)
  cout<<i<<" level-> "<<level[i]<<endl;
}