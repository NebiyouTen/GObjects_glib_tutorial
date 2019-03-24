
#include "animal.h"

G_DEFINE_TYPE(TestAnimal, test_animal, G_TYPE_OBJECT);

/*
 * concerete functions
 */
void test_animal_real_make_sound(TestAnimal *self);

void test_animal_real_move (TestAnimal *self, gint x, gint y);
/*
 *
 */


TestAnimal *test_animal_new (){
  g_object_new(TEST_TYPE_ANIMAL, NULL);
}

static void test_animal_init (TestAnimal *self){

}

static void test_animal_class_init (TestAnimalClass *klass){
  GObjectClass *parent_class = G_OBJECT_CLASS(klass);
  klass->make_sound = test_animal_real_make_sound;
  klass->move = test_animal_real_move;

}

void test_animal_make_sound(TestAnimal *self){

  g_return_if_fail(TEST_IS_ANIMAL(self));
  TestAnimalClass *klass = TEST_ANIMAL_GET_CLASS(self);
  klass->make_sound(self);
}


void test_animal_move(TestAnimal *self, gint x,gint y){

  g_return_if_fail(TEST_IS_ANIMAL(self));
  TestAnimalClass *klass = TEST_ANIMAL_GET_CLASS(self);
  klass->move(self, x, y);
}

void test_animal_real_make_sound(TestAnimal *self){

    g_print("This animal can't make a sound \n");

}

void test_animal_real_move (TestAnimal *self, gint x, gint y){

  g_print("This animal can't move to (%i, %i) \n", x, y);
}
