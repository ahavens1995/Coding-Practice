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

int main(){

};