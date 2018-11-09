#include <stdio.h>
#include "inc.h"

int main(int argc, char *argv[])
{
	printf("Hello, world\n");


	
	return 0;
}

int test_exam(int a, int b, int c)
{
	if(da_max(a,b) == a)return a;
}

#ifdef UNIT_TEST

//增加依赖文件,以冒号结尾
//#DEP_FILE: da.c db.c:
//添加编译文件需要的gcc参数
//#CMP_FLAG: -lm -I.:

#include <stdlib.h>
#include <stdio.h>
#include "unit_test.h"

char* test_db_min()
{
    UT_ASSERT("db_min(10,20) != 10", db_min(10,20) == 10);
	UT_ASSERT("db_min(20,10) != 10", db_min(20,10) == 10);
    return 0;
}

char* test_da_max()
{
    UT_ASSERT("da_max(10,20) != 20", da_max(10,20) == 20);
	UT_ASSERT("da_max(20,10) != 20", da_max(20,10) == 20);
    return 0;
}

//定义自己的all_tests
char* ut_all_tests()
{
    UT_TEST(test_db_min);
    UT_TEST(test_da_max);
    return 0;
}

#endif
