#include <stdio.h>
#include <stdarg.h>

int
	ft_printf(char const *format, ...);

#ifndef REAL
# define F	r += ft_printf
#else
# define F	r += printf
#endif

int
	main(void)
{
	int	r;

	r = 0;
	F("Simple test\n");
	F("");
	F("--Format---");
	F("\n");
	F("%d", 0);
	F("%d", 42);
	F("%d", 1);
	F("%d", 5454);
	F("%d", (int)2147483647);
	F("%d", (int)2147483648);
	F("%d", (int)-2147483648);
	F("%d", (int)-2147483649);
	F("\n");
	F("%x", 0);
	F("%x", 42);
	F("%x", 1);
	F("%x", 5454);
	F("%x", (int)2147483647);
	F("%x", (int)2147483648);
	F("%x", (int)-2147483648);
	F("%x", (int)-2147483649);
	F("%x", (int)0xFFFFFFFF);
	F("\n");
	F("%s", "");
	F("%s", "toto");
	F("%s", "wiurwuyrhwrywuier");
	F("%s", NULL);
	F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	F("\n--Mixed---\n");
	F("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	F("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	F("\n");
	F("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	printf("written: %d\n", r);
}
