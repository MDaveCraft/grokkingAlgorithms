#pragma once
int linearSearch(int* arr, int length, int target) {
    for (int cnt = 0; cnt < length; cnt++) if (arr[cnt] == target) return cnt;
    return -1;
}

int bisectLeft(int* arr, int length, int target) {
    int lowerBoundary = 0, higherBoundary = length;
    while (lowerBoundary <= higherBoundary) {
        int mid = (lowerBoundary + higherBoundary) / 2;
        if (arr[mid] == target) {
            if (mid - 1 >= 0 && arr[mid - 1] == target)
                higherBoundary = mid - 1;
            else return mid;
        }
        else if (arr[mid] < target) lowerBoundary = mid + 1;
        else if (arr[mid] > target) higherBoundary = mid - 1;
    }
    return -1;
}

int bisectRight(int* arr, int length, int target) {
    int lowerBoundary = 0, higherBoundary = length-1;
    while (lowerBoundary <= higherBoundary) {
        int mid = (lowerBoundary + higherBoundary) / 2;
        if (arr[mid] == target) {
            if (mid + 1 < length && arr[mid + 1] == target)
                lowerBoundary = mid + 1;
            else return mid;
        }
        else if (arr[mid] > target) lowerBoundary = mid + 1;
        else if (arr[mid] < target) higherBoundary = mid - 1;
    }
    return -1;
}
