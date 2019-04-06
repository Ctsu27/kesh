#include <stdio.h>
#include <string.h>
#include "array.h"
#include "utils.h"
#include "chai.h"

static int	compare(void *p)
{
	return (!(*((int *)p) == 24));
}

void	*g_p = NULL;

static int	check_capacity(t_array *a, __attribute__((unused))int *data, size_t data_size)
{
	return (a->capacity == round_up_pow(data_size) ? OK : KO);
}

static int	check_size(t_array *a, __attribute__((unused))int *data, size_t data_size)
{
	return (a->size == data_size + 2 * sizeof(*data) ? OK : KO);
}

static int	check_content(t_array *a, int *data, size_t data_size)
{
	return (memcmp(a->p, (void *)data, data_size == 0 ? OK : KO));
}

static int	check_find_content(t_array *a,
				__attribute__((unused)) int *data,
				__attribute__((unused)) size_t data_size)
{
	return ((*(int *)find_array(a, &compare)) == 24 ? OK : KO);
}

static int	check_find_index_content(t_array *a,
				__attribute__((unused)) int *data,
				__attribute__((unused)) size_t data_size)
{
	return ((find_index_array(a, &compare)) == 5 ? OK : KO);
}

static int	check_push_at_array(t_array *a, int *data, size_t data_size)
{
	int		ret = 1;

	ret &= a->size == (data_size + 4 * sizeof(*data));
	ret &= ((int *)a->p)[0] == 42;
	ret &= ((int *)a->p)[1] == 69;
	ret &= ((int *)a->p)[2] == 42;
	ret &= ((int *)a->p)[3] == 69;
	ret &= ((int *)a->p)[4] == 0;
	ret &= ((int *)a->p)[5] == 61;
	ret &= ((int *)a->p)[6] == 222222;
	ret &= ((int *)a->p)[7] == 24;
	ret &= ((int *)a->p)[8] == -4;
	ret &= ((int *)a->p)[9] == 42;
	ret &= ((int *)a->p)[10] == 69;
	return (ret ? OK : KO);
}

int			main(void)
{
	t_chai		test[] = {
		{"Should have good capacity size", &check_capacity, NULL},
		{"Should have good content and size after push_array", &check_size, &push_array},
		{"Should have the same content", &check_content, NULL},
		{"Should find the targeted content", &check_find_content, NULL},
		{"Should find the index of targeted content", &check_find_index_content, NULL},
		{"Should have good content and size after push_at_array", &check_push_at_array, push_at_array}
	};
	int			data[] = {42, 69, 0, 61, 222222, 24, -4};
	t_array		a;
	int			ret = OK;
	int			ret_test;

	printf("Array[%zu]:\n", sizeof(test) / sizeof(*test));
	a = new_array((void *)data, sizeof(data), sizeof(int), 0);
	for (size_t idx = 0, max = sizeof(test) / sizeof(*test);
		 idx < max;
		 ++idx)
	{
		g_p = a.p;
		if (test[idx].apply_before != NULL)
			test[idx].apply_before(&a, (void *)data, 2 * sizeof(*data), 2 * sizeof(*data));
		ret_test = test[idx].check(&a, data, sizeof(data));
		if (ret_test == OK)
			printf(PAD "%s[v]%s", GREEN, X);
		else
			printf(PAD "%s[x]%s", RED, X);
		printf(" %s\n", test[idx].msg);
		ret |= ret_test;
	}

	free(g_p);
	if (ret == KO)
		ret = EXIT_FAILURE;
	else
		ret = EXIT_SUCCESS;
	return (ret);
}
