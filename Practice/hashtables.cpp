//Code taken from https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus
//Used for educational/tutorial purposes

//input output
#include <iostream>
//string functions
#include <string>
//include mapping data structure
#include <map>
//is digit, is char
#include<stdio.h>
#include<ctype.h>
//array
#include <array>

//shortening
using namespace std;

define CAPACITY 50000 //size of hashtable

unsigned long hash_function(char* str)
{
    unsigned long i = 0;

    for (int j = 0; str[j]; j++)
        i += str[j];
    
    return i % CAPACITY;
}

typedef struct Hash_Item
{

    char* key;
    char* val;

}Hash_Item;

typedef struct HashTable
{

    Hash_Item** items;
    int size;
    int count;

}HashTable;

Hash_Item* create_item(char* key, char* val)
{

    Hash_Item* item = (Hash_Item*) malloc(sizeof(Hash_Item));
    item->key = (char*) malloc(strlen(key) + 1);
    item->val = (char*) malloc(strlen(val));
    
    //Copies the C string pointed by source into the array pointed by destination, including the terminating null character (and stopping at that point)
    strcpy(item->key, key);
    strcpy(item->val, val);
    
    return item;

}

HashTable* create_table(int size)
{
    //Create a new Hashtable
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Hash_Item**) calloc(table->size, sizeof(Hash_Item*));

    for(int i = 0; i < table->size; i++)
    {
        table->items[i] = NULL;
    }

    return table;
}

void free_item(Hash_Item* item)
{
    free(item->key);
    free(item->value);
    free(item);
}

void free_Table(HashTable* table)
{
    //free the table
    for(int i = 0; i < table->size; i++)
    {
        Hash_Item* item = table->items[i];

        if(item != NULL)
        {
            free_item(item);
        }
    }

    free(table->items);
    free(table);
}

void print_table(HashTable* table)
{
    printf("\nHash Table\n--------------------\n");

    for(int i = 0; i < table->size; i++)
    {
        if(table->items[i])
        {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i] -> key, table->items[i]->value);
        }
    }

    printf("----------------\n\n");
}

void hashtable_insert(HashTable* table, char* key, char* val)
{
    //create a hash item
    Hash_Item* item = create_item(key, val);

    //determine location in table to be inserted
    int index = hash_function(key);

    Hash_Item* current_item = table->items[index];

    //if they item does not exist
    if(current_item == NULL)
    {
        // HasbTable is full, exit the function
        if (table->count == table->size)
        {
            printf("Insert Error: Hash Table is full\n");
            free_item(item);
            return;
        }
    }
    else // Scenario 1: Update the value at the index
    {
        //compare the strings and if they're equal then update the value
        if (strcmp(current_item->key, key) == 0)
        {
            current_item->val = val;
        }
        else
        {
            handle_collision(table, item);
            return;
        }
    }

    //Insert directly
    table->items[index] = item;
    table->count++;

}

char* hashtable_search(HashTable* table, char* key)
{
    //searches for key in hashtable returns Null if doesn't exist
    int index = hash_function(key);
    Hash_Item* item = table->items[index];

    if(item != NULL)
    {
        if(strcmp(item->key, key) == 0)
            return item->value
    }

    return NULL;
}

typedef struct LinkedList {
    Hash_Item* item;
    struct LinkedList* next;
}

LinkedList* allocate_list()
{
    
}

int main(){

};