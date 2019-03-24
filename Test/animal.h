#pragma once

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

typedef struct _TestAnimal TestAnimal;
typedef struct _TestAnimalClass TestAnimalClass;

#define TEST_TYPE_ANIMAL test_animal_get_type()
// look more into this
G_DECLARE_DERIVABLE_TYPE (TestAnimal, test_animal, TEST, ANIMAL, GObject);

struct _TestAnimalClass{
  GObjectClass parent_class;

  void (* make_sound)(TestAnimal *);
  void (* move)(TestAnimal *, gint, gint);

  gpointer padding[12];
};

TestAnimal *test_animal_new();
void test_animal_make_sound(TestAnimal *self);
void test_animal_move(TestAnimal *self, gint x, gint y);

G_END_DECLS
