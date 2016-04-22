#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int BFS(int BFF[], int seen[], int N, int source, int start, int previous) {
    //printf("source = %d\n", source);
    if(seen[BFF[source - 1] - 1] == 0) {
        seen[source - 1] = 1;
        seen[BFF[source - 1] - 1] = 1;
        int previous = source;
        int current = BFF[source - 1];
        int r = 2;
        if(previous == BFF[current - 1]) {
            int m = 0;
            for(int i = 0; i < N; i++) {
                if(seen[i] == 0) {
                    m = max(m, BFS(BFF, seen, N, i + 1, start, current));
                }
            }
            return r + m;
        }
        int m = BFS(BFF, seen, N, BFF[current - 1], start, current);
        if(m == 0) {
            if(BFF[current - 1] == start) return r;
            else return 0;
        }
        return r + m;
    }else if(seen[BFF[source - 1] - 1] == 1 && previous == BFF[source - 1]) {
        seen[source - 1] = 1;
        int m = 0;
        for(int i = 0; i < N; i++) {
            if(seen[i] == 0) {
                m = max(m, BFS(BFF, seen, N, i + 1, start, source));
            }
        }
        return 1 + m;
    }else if(seen[BFF[source - 1] - 1] == 1 && start == BFF[source - 1]) {
        seen[source - 1] = 1;
        return 1;
    }
    return 0;
}

int main() {
    int T, N;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        int BFF[N];
        for(int j = 0; j < N; j++) scanf("%d", &BFF[j]);
        int result = 0;

        for(int j = 0; j < N; j++) {
            int *seen = new int[N];
            for(int k = 0; k < N; k++) seen[k] = 0;
            //seen[j] = 1;
            int m = BFS(BFF, seen, N, j + 1, j + 1, -1);
            //printf("Got %d = %d\n", j + 1, m);
            result = max(result, m);
        }
        
        printf("Case #%d: %d\n", i + 1, result);
    }
}