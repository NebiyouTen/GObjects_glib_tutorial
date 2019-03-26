
#include "animal.h"
#include "cat.h"
#include "dog.h"

int main (char **argv, int argc){
  TestAnimal *a = test_animal_new();
  TestCat *c = test_cat_new ();
  TestDog *d = test_dog_new ();

  test_animal_make_sound(a);
  test_animal_move (a,5,6);
  
  test_animal_make_sound (TEST_ANIMAL(c));
  test_animal_move(TEST_ANIMAL(c),10,11);


  test_animal_make_sound (TEST_ANIMAL(d));
  test_animal_move(TEST_ANIMAL(d),6,6);

  g_object_unref(c);
  g_object_unref(d);

  g_object_unref(a);

  return 0;

}
