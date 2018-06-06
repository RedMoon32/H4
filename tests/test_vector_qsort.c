//vector_create
// Created by cubazis on 05.06.18.
//

#include <check.h>
#include "vector_int.h"
#include <stdlib.h>
#include <stdio.h>
#include <../src/vector.c>

#define NELEMS(x) (sizeof (x)/sizeof (x[0]))


int comp_vectors_int(const void *first, const void *second)
{
    int a=*((int*)first);
    int b=*((int*)second);
    if (a==b){
        return 0;
    }
    if (a<b){
        return -1;
    }
    return 1;
}

START_TEST(test_vector_qsort)
    {
        int size=10;
        Vector* v = vector_create_int(size);
        for (int i = 0; i < size; ++i) {
            ((int*)v->data)[i]=size-i;
        }
        qsort(v->data,size, sizeof(int), comp_vectors_int);
        for (int i = 0; i < size; ++i) {
            printf("%d ",((int*)v->data)[i]);
            if (i>0){
                ck_assert(((int*)v->data)[i]>=((int*)v->data)[i-1]);
            }
        }
    }
END_TEST


        Suite* str_suite (void) {
    Suite *suite = suite_create("Assignment 4");
    TCase *tcase = tcase_create("case");


    tcase_add_test(tcase, test_vector_qsort);

    suite_add_tcase(suite, tcase);
    return suite;
}

int main (int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}