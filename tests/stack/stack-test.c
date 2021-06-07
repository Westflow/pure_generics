#include <ctest.h>
#include <generic/stack/stack.h>

CTEST(generic_stack, initialize)
{
    Stack(double) stack = init_stack(double);
    ASSERT_EQUAL(0, get_stack_count(stack));
    free_stack(stack);
}

CTEST(generic_stack, push_peek_pop)
{
    Stack(double) stack = init_stack(double);
    for (double i = 0; i < 10; i += 0.5)
    {
        push_stack(stack, i);
    }
    for (double i = 9.5; i >= 0; i -= 0.5)
    {
        ASSERT_EQUAL(9.5, peek_stack(stack));
    }
    for (double i = 9.5; i >= 0; i -= 0.5)
    {
        double res = pop_stack(stack);
        ASSERT_EQUAL(i, res);
    }
    for (size_t i = 0; i < 10; ++i)
    {
        ASSERT_EQUAL(0, peek_stack(stack));
        double res = pop_stack(stack);
        ASSERT_EQUAL(0, res);
    }
    free_stack(stack);
}

typedef struct
{
    double a;
    int b;
    char c[4];
} SomeData;

CTEST(generic_stack, push_peek_pop_complex_data)
{
    Stack(SomeData) stack = init_stack(SomeData);
    for (size_t i = 0; i < 10; ++i)
    {
        SomeData data = {.a = i * 1.5, .b = i, .c = "asd"};
        push_stack(stack, data);
    }
    for (int64_t i = 9; i >= 0; --i)
    {
        SomeData data = peek_stack(stack);
        ASSERT_EQUAL(9 * 1.5, data.a);
        ASSERT_EQUAL(9, data.b);
        ASSERT_STR("asd", data.c);
    }
    ASSERT_EQUAL(10, get_stack_count(stack));
    for (int64_t i = 9; i >= 0; --i)
    {
        SomeData data = pop_stack(stack);
        ASSERT_EQUAL(i * 1.5, data.a);
        ASSERT_EQUAL(i, data.b);
        ASSERT_STR("asd", data.c);
    }
    ASSERT_EQUAL(0, get_stack_count(stack));
    free_stack(stack);
}