"""
Problem Statement:
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

Constraints:
0 <= key, value <= 106
At most 104 calls will be made to put, get, and remove.

Difficulty: Easy

"""

#Time Complexity: O(n)
typedef struct MyHashMap{
    int key;
    int value;
    struct MyHashMap* next;
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap* hash = malloc(sizeof(MyHashMap));
    hash->key=-1;
    hash->value=-1;
    hash->next = NULL;
    return hash;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    MyHashMap* temp = obj;
    while(temp!=NULL && temp->key!=key){
        temp=temp->next;
    }
    if(temp==NULL){
        
        temp = malloc(sizeof(MyHashMap));
        temp->key = key;
        temp->value = value;
        temp->next=obj->next;
        obj->next=temp;
    }
    else{
        temp->value = value;
    }
}

int myHashMapGet(MyHashMap* obj, int key) {
  MyHashMap* temp = obj;
  while(temp!=NULL && temp->key!=key){
      temp = temp->next;
  }
  if(temp==NULL){
      return -1;
  }
  return temp->value;

}

void myHashMapRemove(MyHashMap* obj, int key) {
    MyHashMap* temp = obj;
    while(temp->next!=NULL && temp->next->key!=key){
        temp = temp->next;
    }
    if(temp->next!=NULL){
        MyHashMap* to_be_removed = temp->next;
        temp->next = temp->next->next;
        free(to_be_removed);
    }
}

void myHashMapFree(MyHashMap* obj) {
    MyHashMap* temp = obj;
    while(obj!=NULL){
        temp = obj->next;
        free(obj);
        obj=temp;
    }
}

"Reference/Insight used to solve the problem: None"