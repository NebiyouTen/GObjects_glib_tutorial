#pragma once

#include "animal.h"

G_BEGIN_DECLS


#define TEST_TYPE_CAT test_cat_get_type()

G_DECLARE_FINAL_TYPE(TestCat, test_cat, TEST, CAT, TestAnimal)

TestCat *test_cat_new();


G_END_DECLS
