/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int top = -1;

    for (int i = 0; i < asteroidsSize; ++i) {
        int cur = asteroids[i];
        int alive = 1;

        while (alive && top >= 0 && asteroids[top] > 0 && cur < 0) {
            int left = asteroids[top];
            if (abs(left) < abs(cur)) {
                --top;
                continue;
            } else if (abs(left) == abs(cur)) {
                --top;
                alive = 0;
                break;
            } else {
                alive = 0;
                break;
            }
        }

        if (alive) {
            asteroids[++top] = cur;
        }
    }

    int* res = (int*)malloc((top + 1) * sizeof(int));
    for (int i = 0; i <= top; ++i) res[i] = asteroids[i];
    *returnSize = top + 1;
    return res;
}
