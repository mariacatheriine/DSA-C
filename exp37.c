#include <stdio.h>
#define MAX 100
struct State {
    int c1, c2, c3;
};
struct QueueNode {
    struct State state;
    int parent;
};
int visited[11][8][5];
int isGoal(struct State s) {
    return (s.c2 == 2 || s.c3 == 2);
}
void pour(struct State src, struct State* dest, int from, int to) {
    int capacities[3] = {10, 7, 4};
    int amounts[3] = {src.c1, src.c2, src.c3};
    int space = capacities[to] - amounts[to];
    int transfer;
    if (amounts[from] < space)
        transfer = amounts[from];
    else
        transfer = space;
    amounts[from] -= transfer;
    amounts[to] += transfer;
    dest->c1 = amounts[0];
    dest->c2 = amounts[1];
    dest->c3 = amounts[2];
}
void printPath(struct QueueNode nodes[], int index) {
    if (index == -1)
        return;
    printPath(nodes, nodes[index].parent);
    printf("(%d, %d, %d)\n",
           nodes[index].state.c1,
           nodes[index].state.c2,
           nodes[index].state.c3);
}
void BFS(struct State start) {
    struct QueueNode queue[MAX];
    int front = 0;
    int rear = 0;
    queue[rear].state = start;
    queue[rear].parent = -1;
    visited[start.c1][start.c2][start.c3] = 1;
    rear++;
    while (front < rear) {
        struct QueueNode currentNode = queue[front];
        struct State current = currentNode.state;
        if (isGoal(current)) {
            printf("\nSolution Path:\n");
            printPath(queue, front);
            return;
        }
        for (int from = 0; from < 3; from++) {
            for (int to = 0; to < 3; to++) {
                if (from != to) {
                    int amounts[3] = {current.c1, current.c2, current.c3};
                    int capacities[3] = {10, 7, 4};
                    if (amounts[from] == 0 || amounts[to] == capacities[to])
                        continue;
                    struct State next;
                    pour(current, &next, from, to);
                    if (!visited[next.c1][next.c2][next.c3]) {
                        visited[next.c1][next.c2][next.c3] = 1;
                        queue[rear].state = next;
                        queue[rear].parent = front;
                        rear++;
                    }
                }
            }
        }
        front++;
    }
    printf("No solution found\n");
}
int main() {
    struct State start;
    start.c1 = 0;
    start.c2 = 7;
    start.c3 = 4;
    printf("Initial State: (%d, %d, %d)\n",
           start.c1,
           start.c2,
           start.c3);
    BFS(start);
    return 0;
}