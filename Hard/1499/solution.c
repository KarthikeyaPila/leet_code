#define INT_MIN –2147483648

int findMaxValueOfEquation(int** points, int pointsSize, int* pointsColSize, int k) {
    int abs_max = INT_MIN;

    for (int i = 0; i < pointsSize - 1; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            int val = points[j][0] - points[i][0];

            if (val > k) {
                break;
            }

            int total = points[i][1] + points[j][1] + val;
            if (total > abs_max) {
                abs_max = total;
            }
        }
    }

    return abs_max;
}

