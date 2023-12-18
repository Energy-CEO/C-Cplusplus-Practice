//
// Created by eddi on 23. 12. 18.
//

#include "product.h"

#include <malloc.h>
#include <string.h>

product *init_product_object(int price, char *name, char *product_info)
{
    int name_length, product_info_length;
    product *tmp = (product *) malloc(sizeof(product));

    name_length = strlen(name);
    product_info_length = strlen(product_info);

    tmp->name = (char *) malloc(sizeof(char) * name_length + 1);
    tmp->product_info = (char *) malloc(sizeof(char) * product_info_length + 1);

    tmp->price = price;

    strncpy(tmp->name, name, name_length);
    strncpy(tmp->product_info, product_info, product_info_length);

    return tmp;
}

void print_product_info(const product* object)
{
    if (object == NULL) { return; }

    printf("Product ID: %u\n", object->id);
    printf("Product Name: %s\n", object->name);
    printf("Product Price: %d\n", object->price);
    printf("Product Info: %s\n", object->product_info);
}

void clear_product_object(product *object)
{
    // 역순으로 free 해줄 것
    free(object->name);
    free(object->product_info);

    free(object);
}