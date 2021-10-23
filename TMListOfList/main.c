#include "header.h"

int main()
{
	list L;
	tim input_tim;
	pemain input_pemain;
	createList(&L);
	int n, i, j;
	scanf("%d", &n);

	forIn(i, n){
		scanf("%s %d", input_tim.nama, &input_tim.tahun);
		addPriorityB(input_tim, &L);
		eBaris* row = getLatestBaris(L, input_tim.nama);

		if (row != NULL)
		{
			forIn(j, 4){
				scanf("%s", input_pemain.nama_pemain);
				if (j == 0 || j == 3) addLastK(input_pemain, row);
				else if(j == 1) addFirstK(input_pemain, row);
				else addAfterK(row->col, input_pemain);
			}
		}
	}

	delAfterK(L.first->next->col->next_kol);
	delLastB(&L);
	delFirstK(L.first);
	printElement(L);

	return 0;
}