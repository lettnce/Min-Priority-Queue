#include "minpriorityqueue.h"

int main() {

    MinPriorityQueue<double> Q1;

    Q1.push(2, 2);
    Q1.push(4, 4);
    Q1.push(7, 7);
    Q1.push(6, 6);

    Q1.pop();
    cout << Q1.front() << endl;

    return 0;
}