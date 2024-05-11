/*

857. Minimum Cost to Hire K Workers
There are n workers. You are given two integer arrays quality and wage where
quality[i] is the quality of the ith worker and wage[i] is the minimum wage
expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k
workers, we must pay them according to the following rules:

Every worker in the paid group must be paid at least their minimum wage
expectation. In the group, each worker's pay must be directly proportional to
their quality. This means if a worker’s quality is double that of another worker
in the group, then they must be paid twice as much as the other worker. Given
the integer k, return the least amount of money needed to form a paid group
satisfying the above conditions. Answers within 10-5 of the actual answer will
be accepted.

*/

/*
Intuition:
So, we want to hire k people,

1. each people should be proportionally be paid based on their quality
2. the money a person get paid would not be smaller than his expected wage.

It's a hard problem. We need to find a creative way to solve the problem with
two constraints above:

1. We find the ratio wage/quality of each person. Also we realize that higher
ratio means higher ability to cover the pay of the people who has lower ratio
--> We sort the ratio
2. We use the maxHeap to keep smallest total Quality we can encounter --> Hard
to think this point So imagine, our heap has 2, 3,5 in the current iteration
It's easy to remove 5 from our heap for the next iteration,

If next value is 4 --> It works well, we have no thinking because 2,3,4 is
definetely smaller than 2,3,5 However, if next value is 6. it raised some
concerns because 2,3,6 is greater than 2,3,5. But we should remember than in
order to us the ratio in this iteration, number 6 has to be used.

And again, hard thinking question

*/

class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
    vector<pair<double, int>> workerRatios;
    int n = quality.size();
    for (int i = 0; i < n; i++) {
      workerRatios.push_back({(double)wage[i] / quality[i], quality[i]});
    }
    sort(workerRatios.begin(), workerRatios.end());
    priority_queue<int> pq;
    double minSum = numeric_limits<double>::max();
    int totalQuality = 0;
    int cnt = 0;
    for (auto &[ratio, quality] : workerRatios) {
      totalQuality += quality;
      cnt++;
      pq.push(quality);
      if (cnt == k) {
        cnt--;
        minSum = min(minSum, totalQuality * ratio);
        totalQuality -= pq.top();
        pq.pop();
      }
    }
    return minSum;
  }
};