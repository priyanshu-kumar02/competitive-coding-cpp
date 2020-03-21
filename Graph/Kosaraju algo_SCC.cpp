#include <bits/stdc++.h>

using namespace std;
#define lli long long int
lli v;

void DFS(vector<lli> graph[],lli source,lli v,lli visited[])
{
  stack<lli> Q;
  Q.push(source);
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

//graph1 is original,graph2 is reversed!
void reverse_this(vector<lli> graph[],vector<lli> graph2[],lli v)
{
    for(lli i=1;i<=v;i++)
    {
        for(lli j=0;j<graph[i].size();j++)
        graph2[ graph[i][j] ].push_back(i);
    }

}

//makes the finish time stack(decreasing),'not reverse of dfs' ,,note dat we HAVE to use recursive dfs
void make_stack(vector<lli> graph[],stack<lli> &finish,lli visited[],lli source,lli v)
{
    visited[source]=1;

    for(lli i=0; i<graph[source].size() ;i++)
    {
        if(!visited[ graph[source][i] ])
        make_stack(graph, finish,visited,graph[source][i],v);
    }



    finish.push(source);
}

void get_SCC(vector<lli> graph[],lli v)
{
    lli visited[v+1];
    for(lli i=1;i<=v;i++)
        visited[i]=0;

    stack<lli> finish;

    for(lli i=1;i<=v;i++)
    if(!visited[i])
    make_stack(graph,finish,visited,i,v);

    for(lli i=1;i<=v;i++) //for dfs on reversed graph
    visited[i]=0;

    vector<lli> graph2[v+1];
    reverse_this(graph,graph2,v);


    while(!finish.empty())
    {
        lli popped=finish.top();
        finish.pop();

        if(!visited[popped])
        {
            DFS(graph2,popped,v,visited);
            cout<<endl;
        }
    }

}
int main()
{
 vector< lli > graph[10];


graph[1].push_back(2);
graph[2].push_back(3);
graph[3].push_back(1);

graph[2].push_back(4);
graph[4].push_back(5);

get_SCC(graph,5);
return 0;
}
