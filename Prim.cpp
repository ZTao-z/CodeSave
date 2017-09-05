#include <iostream>
#include <vector>

using  namespace std;

#define MAX 100
#define MAXCOST 0x7fffffff

double graph[MAX][MAX];


double prim(double graph[][MAX], int n)
{
    double distance[n];
    int mst[n];
    double sum,min;
    int pos;
    int rec;

    //检查节点是否被遍历，0：否 1：是
    for(int i = 0; i < n; i++)
        mst[i] = 0;

    mst[0] = 1;
    pos = 0;

    //将distance[]转为节点0对应的相邻节点距离
    for(int i = 1; i < n; i++)
        distance[i] = graph[pos][i];

    //开始遍历所有节点
    for(int i = 1; i < n; i++)
    {
        min = MAXCOST;
        rec = pos;

        //寻找pos相邻最近的节点
        for(int j = 0; j < n; j++)
        {
            if(mst[j] == 0 && min > distance[j])
            {
                min = distance[j];
                pos = j;
            }
        }

        cout << rec << " --> " << pos << " = " << min << endl;

        sum += min;
        mst[pos] = 1;

        //将diastance[]转为pos对应的相邻节点距离
        for(int j = 1; j < n; j++)
            if(mst[j] == 0 && distance[j] > graph[pos][j])
                distance[j] = graph[pos][j];
    }

    return sum;
}

int main()
{
    int i, j, k, m, n;
    int x, y;
    double cost,result;
    cin >> m >> n;//m=顶点的个数，n=边的个数
    //初始化图G
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            graph[i][j] = MAXCOST;

    for (k = 0; k < n; k++)
    {
        cin >> i >> j >> cost;
        graph[i][j] = cost;
        graph[j][i] = cost;
    }
    //求解最小生成树
    result = prim(graph, m);
    //输出最小权值和
    cout  << result << endl;
    return 0;
}
