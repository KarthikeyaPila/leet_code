#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_KEY 1000001

typedef struct {
    bool* data;
} MyHashSet;

// Create a new hash set
MyHashSet* myHashSetCreate() {
    MyHashSet* set = (MyHashSet*)malloc(sizeof(MyHashSet));
    set->data = (bool*)calloc(MAX_KEY, sizeof(bool));  // initialize all to false
    return set;
}

// Add a key to the hash set
void myHashSetAdd(MyHashSet* obj, int key) {
    if (key >= 0 && key < MAX_KEY) {
        obj->data[key] = true;
    }
}

// Remove a key from the hash set
void myHashSetRemove(MyHashSet* obj, int key) {
    if (key >= 0 && key < MAX_KEY) {
        obj->data[key] = false;
    }
}

// Check if the hash set contains the key
bool myHashSetContains(MyHashSet* obj, int key) {
    if (key >= 0 && key < MAX_KEY) {
        return obj->data[key];
    }
    return false;
}

// Free the hash set
void myHashSetFree(MyHashSet* obj) {
    if (obj) {
        free(obj->data);
        free(obj);
    }
}
