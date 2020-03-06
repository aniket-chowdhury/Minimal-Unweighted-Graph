#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <initializer_list>

typedef std::vector<char> list;
typedef std::map<char, list> graph;

void dfs(graph g,char s)
{
	int white=0,gray=1,black=-1;
	std::map<char,int> color,distance,prev;
	for (auto elem : g)
	{
		auto c=elem.first;
		color[c]=white;
		distance[c]=-1;
		prev[c]=-1;
	}
	color[s]=gray;
	distance[s]=0;
	std::queue<char> q;
	q.push(s);
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		for(auto vertex : g[u])
		{
			if(color[vertex]==white){
				color[vertex]=gray;
				distance[vertex]=distance[u]+1;
				prev[vertex]=u;
				q.push(vertex);
			}
		}
		color[u]=black;
	}

	for(auto elem : distance)
	{
		std::cout << elem.second << " ";
	}
}

main(int argc, char const *argv[])
{
	graph g;
	g['a'] = list({'b', 'c'});
	g['b'] = list({'a'});
	g['c'] = list({'a', 'b', 'd'});
	g['d'] = list({'c', 'e'});
	g['e'] = list();

	dfs(g,'e');
	return 0;
}
