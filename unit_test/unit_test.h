
#ifndef __UNIT_TEST_H__
#define __UNIT_TEST_H__


#include <stdlib.h>
#include <stdio.h>



#ifdef UT_DEBUG
//打印成功的消息

//测试表达式等于1
#define UT_ASSERT(mess,test)	do { \
								if (!(test)) \
								{sprintf(unit_test_mess,"FAIL: %s:%d: %s\n",__FILE__,__LINE__,mess); \
								return unit_test_mess;} \
								else {printf("OK  : %s:%d: %s\n",__FILE__,__LINE__,mess);}} while (0)


#define UT_STR_EQ(mess,expect)	do { \
								if (!(ut_str_equal(mess,expect))) \
								{sprintf(unit_test_mess,"FAIL: %s:%d: %s != %s\n",__FILE__,__LINE__,mess,expect); \
								return unit_test_mess;} \
								else {printf("OK  : %s:%d: %s == %s\n",__FILE__,__LINE__,mess,expect);} } while (0)

//测试数值相等
#define UT_INT_EQ(num,expect)		do { \
								if (!(num == expect)) \
								{sprintf(unit_test_mess,"FAIL: %s:%d: 0x%08x != 0x%08x\n",__FILE__,__LINE__,num,expect); \
								return unit_test_mess;} \
								else {printf("OK  : %s:%d: 0x%08x == 0x%08x\n",__FILE__,__LINE__,num,expect);} } while (0)

#else

//测试表达式等于1
#define UT_ASSERT(mess,test)	do { \
								if (!(test)) \
								{sprintf(unit_test_mess,"FAIL: %s:%d: %s\n",__FILE__,__LINE__,mess); \
								return unit_test_mess;} } while (0)

//测试字符串相等
#define UT_STR_EQ(mess,expect)	do { \
								if (!(ut_str_equal(mess,expect))) \
								{sprintf(unit_test_mess,"%s:%d: %s != %s\n",__FILE__,__LINE__,mess,expect); \
								return unit_test_mess;} } while (0)

//测试数值相等
#define UT_INT_EQ(num,expect)		do { \
								if (!(num == expect)) \
								{sprintf(unit_test_mess,"%s:%d: 0x%08x != 0x%08x\n",__FILE__,__LINE__,num,expect); \
								return unit_test_mess;} } while (0)

#endif


#define UT_TEST(test)			do {char *what = test(); unit_test_cnt++; \
								if (what) return what; } while (0)

extern int	unit_test_cnt;
extern char unit_test_mess[];

int	unit_test_cnt = 0;
char unit_test_mess[1024] = {0,};

char* ut_all_tests();

int testmain(int argc, char** argv)
{
    char *result = ut_all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("\nALL TESTS PASSED\n");
    }

    printf("Tests run: 0x%08x\n", unit_test_cnt);

    exit(result != 0);
}

//比较2个字符串相等
int ut_str_equal(const char* src1, const char* src2)
{
	if(src1 == NULL && src2 == NULL)return 1;
	if(src1 == NULL)return 0;
	if(src2 == NULL)return 0;
	for(;;)
	{
		if(*src1 != *src2)return 0;
		if(*src1 == 0)return 1;
		src1++;
		src2++;
	}
}

#endif

