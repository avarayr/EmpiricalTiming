#include <memory>
#include "SortedArrayList.hpp"
#include <chrono>

using namespace std;
float startTime = 0;

/**
 * Prints a separator
 */
void printSeparator() {
    printf("%s\n", "———————————————————");
}

/**
 * Starts the timer
 */
void tick() {
    startTime = clock();
}

/*
 * Stops the timer
 */
float tock() {
    return clock() - startTime;
}

/**
 * Tests adding to the list in numerically
 */
void testAddInOrder() {
    printSeparator();

    int testSizes[] = {100, 200, 400, 800, 1600};

    float lastResult = 0;
    for (auto testSize : testSizes) {
        auto *list = new SortedArrayList<int>(testSize);
        tick();
        for (int i = 0; i < testSize; i++) {
            list->add(i);
        }
        auto elapsedTime = tock();
        printf("Add In Order (%d size): %f ms", testSize, elapsedTime);
        if (lastResult != 0) {
            printf(" (x%.1f)", round(elapsedTime / lastResult));
        }
        printf("\n");

        lastResult = elapsedTime;

        delete list;
    }
    printSeparator();
}

/*
 * Tests adding to the list in reverse numerical order
 */
void testAddReverseOrder() {

    int testSizes[] = {100, 200, 400, 800, 1600};

    float lastResult = 0;
    for (auto testSize : testSizes) {
        auto *list = new SortedArrayList<int>(testSize);
        tick();
        for (int i = testSize; i >= 0; i--) {
            list->add(i);
        }
        auto elapsedTime = tock();
        printf("Add In Reverse Order (%d size): %f ms", testSize, elapsedTime);
        if (lastResult != 0) {
            printf(" (x%.1f)", round(elapsedTime / lastResult));
        }
        printf("\n");

        lastResult = elapsedTime;

        delete list;
    }
    printSeparator();
}

/**
 * Test removing elements from the list until it's empty
 */
void testRemoveUntilEmpty() {

    int testSizes[] = {100, 200, 400, 800, 1600};

    float lastResult = 0;
    for (auto testSize : testSizes) {
        auto *list = new SortedArrayList<int>(testSize);

        for (int i = 0; i < testSize; i++) {
            list->add(i);
        }

        tick();
        while (!list->isEmpty()) {
            list->remove(0);
        }
        auto elapsedTime = tock();
        printf("Remove until empty (%d size): %f ms", testSize, elapsedTime);
        if (lastResult != 0) {
            printf(" (x%.1f)", round(elapsedTime / lastResult));
        }
        printf("\n");

        lastResult = elapsedTime;

        delete list;
    }
    printSeparator();
}

/**
 * Tests clearing the list
 */
void testClear() {

    int testSizes[] = {100, 200, 400, 800, 1600};

    float lastResult = 0;
    for (auto testSize : testSizes) {
        auto *list = new SortedArrayList<int>(testSize);

        for (int i = 0; i < testSize; i++) {
            list->add(i);
        }

        tick();
        list->clear();
        auto elapsedTime = tock();
        printf("Test clear (%d size): %f ms", testSize, elapsedTime);
        if (lastResult != 0) {
            printf(" (x%.1f)", round(elapsedTime / lastResult));
        }
        printf("\n");

        lastResult = elapsedTime;

        delete list;
    }
    printSeparator();
}


int main() {
    testAddInOrder();
    testAddReverseOrder();
    testRemoveUntilEmpty();
    testClear();
    return 0;
}
