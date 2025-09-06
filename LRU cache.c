//LRU cache
//https://www.geeksforgeeks.org/problems/lru-cache/1



#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node *prev, *next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node *head, *tail;
} LRUCache;

Node* createNode(int key, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;

    cache->head = createNode(0, 0);
    cache->tail = createNode(0, 0);

    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;

    return cache;
}

void removeNode(LRUCache *cache, Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void addNodeToHead(LRUCache *cache, Node *node) {
    node->next = cache->head->next;
    node->prev = cache->head;
    cache->head->next->prev = node;
    cache->head->next = node;
}

void moveToHead(LRUCache *cache, Node *node) {
    removeNode(cache, node);
    addNodeToHead(cache, node);
}

Node* removeTail(LRUCache *cache) {
    Node *node = cache->tail->prev;
    removeNode(cache, node);
    return node;
}

int lRUCacheGet(LRUCache *cache, int key) {
    Node *curr = cache->head->next;

    while (curr != cache->tail) {
        if (curr->key == key) {
            moveToHead(cache, curr);
            return curr->value;
        }
        curr = curr->next;
    }

    return -1; 
}

void lRUCachePut(LRUCache *cache, int key, int value) {
    Node *curr = cache->head->next;
    Node *newNode;
    Node *tailNode;

    while (curr != cache->tail) {
        if (curr->key == key) {
            curr->value = value;      
            moveToHead(cache, curr);  
            return;
        }
        curr = curr->next;
    }

    newNode = createNode(key, value);
    addNodeToHead(cache, newNode);
    cache->size++;

    if (cache->size > cache->capacity) {
        tailNode = removeTail(cache);
        free(tailNode);
        cache->size--;
    }
}

void lRUCacheFree(LRUCache *cache) {
    Node *curr = cache->head;
    Node *nextNode;

    while (curr) {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }

    free(cache);
}

int main() {
    int cap, Q;
    int i;
    char query[4];
    int x, y;

    scanf("%d %d", &cap, &Q);

    LRUCache* cache = lRUCacheCreate(cap);

    for (i = 0; i < Q; i++) {
        scanf("%s", query);

        if (query[0] == 'P') { 
            scanf("%d %d", &x, &y);
            lRUCachePut(cache, x, y);
        } 
        else if (query[0] == 'G') { 
            scanf("%d", &x);
            printf("%d ", lRUCacheGet(cache, x));
        }
    }

    lRUCacheFree(cache);
    return 0;
}

