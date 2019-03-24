#pragma once

#include "animal.h"

G_BEGIN_DECLS


#define TEST_TYPE_DOG test_dog_get_type()

G_DECLARE_FINAL_TYPE(TestDog, test_dog, TEST, DOG, TestAnimal)

TestDog *test_dog_new();


G_END_DECLS
