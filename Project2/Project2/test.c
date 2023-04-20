#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int arr[10] = {1,2,3,5,6,7,8,9,10};
//	printf("%p\n",&i);
//	printf("%p\n",arr);
//	for (i = 0; i <= 12; i++)
//	{
//		printf("hehe\n");
//		arr[i] = 0;
//
//	}
//	return 0;
//}

#include <assert.h>
//void my_strcpy(char*a, char*c)
//{
//	assert(a!=NULL);
//	assert(c!=NULL);
//	int i = 0;
//	while (1)
//	{
//		a[i] = c[i];
//		i++;
//		if (c[i] == 0)
//		{
//			a[i] = c[i];
//			break;
//		}
//	}
//
//}
//
//int main()
//{
//	char arr1[] = "#########";
//	char arr2[] = "bit";
//	my_strcpy(arr1,arr2);
//	printf("%s\n",arr1);
//	return 0;
//}

int my_strlen(char* a)
{
	assert(a != NULL);
	int b = 1;
	while (*a != 0)
	{
		b++;
		a++;
	}
	return b;

}

int main()
{
	char arr[] = "abcdfertuio";
	printf("%d\n", my_strlen(arr));
	return 0;
}

