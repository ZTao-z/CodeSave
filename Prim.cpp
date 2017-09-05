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

    //���ڵ��Ƿ񱻱�����0���� 1����
    for(int i = 0; i < n; i++)
        mst[i] = 0;

    mst[0] = 1;
    pos = 0;

    //��distance[]תΪ�ڵ�0��Ӧ�����ڽڵ����
    for(int i = 1; i < n; i++)
        distance[i] = graph[pos][i];

    //��ʼ�������нڵ�
    for(int i = 1; i < n; i++)
    {
        min = MAXCOST;
        rec = pos;

        //Ѱ��pos��������Ľڵ�
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

        //��diastance[]תΪpos��Ӧ�����ڽڵ����
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
    cin >> m >> n;//m=����ĸ�����n=�ߵĸ���
    //��ʼ��ͼG
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            graph[i][j] = MAXCOST;

    for (k = 0; k < n; k++)
    {
        cin >> i >> j >> cost;
        graph[i][j] = cost;
        graph[j][i] = cost;
    }
    //�����С������
    result = prim(graph, m);
    //�����СȨֵ��
    cout  << result << endl;
    return 0;
}
