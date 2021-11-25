#include <stdio.h>
int main()
{
	while (1)
	{
		int week, index, number;
		printf("Week,index,number\n");
		scanf("%d%*c%d%*c%d", &week, &index, &number);
		if ((week >= 1 && week <= 7) && index >= 0 && (number >= 0 && number <= 9))
		{
			if (index < 200) printf("Yes\n");
			else
			{
				if (index <= 300)
				{
					switch (week)
					{
					case 1:
						if (number == 6) printf("Yes\n");
						else printf("No\n");
						break;
					case 2:
						if (number == 7) printf("Yes\n");
						else printf("No\n");
						break;
					case 3:
						if (number == 8) printf("Yes\n");
						else printf("No\n");
						break;
					case 4:
						if (number == 9) printf("Yes\n");
						else printf("No\n");
						break;
					case 5:
						if (number == 0) printf("Yes\n");
						else printf("No\n");
						break;
					case 6:
						printf("Yes\n");
						break;
					case 7:
						printf("Yes\n");
						break;
					default:
						printf("error\n");
						break;
					}
				}
				else
				{
					if (index > 300)
					{
						switch (week == 2 || week == 4 || week == 6)
						{
						case 0:
							if (number == 1 || number == 3 || number == 5 || number == 7 || number == 9) printf("Yes\n");
							else printf("No\n");
							break;
						case 1:
							if (number == 2 || number == 4 || number == 6) printf("Yes\n");
							else printf("No\n");
							break;
						default:
							printf("error\n");
							break;
						}
					}
				}
			}
		}
		else printf("error\n");
	}
}

