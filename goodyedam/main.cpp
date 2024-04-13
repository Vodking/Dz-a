#include<iostream>
#include<cstdlib>

using namespace std;

int SumFinder(int arr[], int* adr);
int MaxFinder(int arr[3]);
int MaxFinder(int arr[3][4]);//не пон€л как передать массив без указани€ размера
int MaxFinder(int arr[3][4][3]);
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	//«адание 1
	const int size = 100;
	int arr[size];
	int iter = 0;
	int* adr = &iter;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
	//cout << "ћинимальна€ сумма - " << SumFinder(arr,adr);
	//«адание 2
	int arr2[3]{ -2,4,8 };
	int arr3[3][4];
	int arr4[3][4][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr3[i][j] = rand() % 100;
		}
		
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				arr4[i][j][k] = rand() % 100;
			}
		}
	}
	cout << MaxFinder(arr2) << endl;
	cout << MaxFinder(arr3) << endl;
	cout << MaxFinder(arr4) << endl;
	return 0;
}

int SumFinder(int arr[], int* adr)//в рекурси€ почему то никак не хочет заканчиватьс€ хоть € и сказал когда возвращать заканчивать
{
	int sum = 0;
	int iter = *adr;
	if (iter == 91)
	{
		return sum;
	}

	for (int i = 99; i != 89; i--)
	{
		sum += arr[i - iter];
	}
	iter++;
	cout << iter << endl;
	
	if (sum > SumFinder(arr,&iter))
	{
		sum = SumFinder(arr,&iter);
		return sum;
	}
	
	
}

int MaxFinder(int arr[3])
{
	int max = 0;
	for (int i = 0; i < 3; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int MaxFinder(int arr[3][4])
{
	int max = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}
	return max;
}

int MaxFinder(int arr[3][4][3])
{
	int max = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (arr[i][j][k] > max)
				{
					max = arr[i][j][k];
				}
			}
		}
	}
	return max;
}
