#include <iostream>
#include <queue>
#include <memory>
#include <cstdio>
#include <cstring>

using namespace std;

int capacity[101][101], pred[101];
const int minimum = 0x7fffffff;
int maxflow;


void EK_Algorithm(int start, int end, int vertices){
    int minflow = 0;
    int cur;
    while(1){
        queue<int> q;
        q.push(start);
        minflow = minimum;
        memset(pred, 0, sizeof(pred));
        while(!q.empty()){
            cur = q.front();
            q.pop();
            for(int i = 1; i <= vertices; i++){
                if(capacity[cur][i] > 0 && !pred[i] ){
                    pred[i] = cur;
                    q.push(i);
                }
            }
        }
        if(pred[end] == 0)
            break;
        for(int i = end; i != start; i = pred[i]){
            minflow = min(capacity[pred[i]][i], minflow);
        }
        for(int i = end; i != start; i = pred[i]){
            capacity[pred[i]][i] -= minflow;
            capacity[i][pred[i]] += minflow;
        }
        maxflow += minflow;
    }
}

int main(){
    int edge, vertex;
    int start, end, cap;
    while(cin >> edge >> vertex){
        memset(capacity, 0, sizeof(capacity));
        memset(pred, 0, sizeof(pred));
        for(int i = 0; i < edge; i++){
            cin >> start >> end >> cap;
            if(start == end)
                continue;
            capacity[start][end] += cap;
        }
        EK_Algorithm(1,vertex, vertex);
        cout << "maxflow = " << maxflow << endl;
    }
    return 0;
}
