#include <gtest/gtest.h>

#include "../../product/entity/product.h"

TEST(product_entity, create_product_entity)
{
    product *sample = init_product_object(1500, "붕어빵", "맛있다");

    EXPECT_NE(sample, nullptr);

    clear_product_object(sample);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
