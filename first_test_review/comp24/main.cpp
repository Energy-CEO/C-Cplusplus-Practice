//
// Created by eddi on 23. 12. 18.
//

#include "product/entity/product.h"

int main(void)
{
    product *sample_product = init_product_object(3000, "떡볶이", "정말 맛난다.");

    print_product_info(sample_product);
    clear_product_object(sample_product);

    return 0;
}