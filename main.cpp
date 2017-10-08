// doublybl1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
//Node için yapı oluşturuldu.Öncesini göstermek için node türünde prev  ve sonraki nodu göstermek için node türünde next işaretçisi oluturuldu.
struct n {
	int x;
	n * next;
	n * prev;


};
typedef struct n node;


//Ekleme fonksiyonu
node ekle(node * h, node * t, int x)
{
	node * temp;


	//Eğer header sonraki nodu trailer ise yeni düğümü bu araya ekle
	if (h->next == t)
	{
		temp = (node *)malloc(sizeof(node));
		temp->x = x;

		h->next = temp;
		temp->prev = h;
		temp->next = t;
		t->prev = temp;

	}
	//Eğer bir düğüm varsa .sonra gelecek düğümü duruma göre bir öncesine veya sonrasına yerleştir.
	else if (h->next->next == t)
	{
		if (h->next->x < x)
		{
			temp = (node *)malloc(sizeof(node));
			temp->x = x;

			h->next->next = temp;
			temp->prev = h->next;
			temp->next = t;
			t->prev = temp;

		}
		else

		{
			temp = (node *)malloc(sizeof(node));
			temp->x = x;

			h->next = temp;
			temp->prev = h;
			temp->next = t->prev;
			t->prev->prev = temp;


		}

	}

	//Eğer 2 düğüm oluşmuşsa bu 2 düğüm üzerinden tüm düğümleri karşılaştır.Gerekli yere düğümü koy.
	node * iter = h->next;
	while (iter->next != t)
	{

		if (iter->x > x)
		{
			temp = (node *)malloc(sizeof(node));
			temp->x = x;

			temp->next = h->next;
			h->next->prev = temp;
			h->next = temp;
			temp->prev = h;
			return *h;

		}
		else if (iter->x < x && iter->next->x > x)
		{
			temp = (node *)malloc(sizeof(node));
			temp->x = x;

			temp->next = iter->next;
			iter->next->prev = temp;
			iter->next = temp;
			temp->prev = iter;
			return * h;
		}
		else if (iter->next->next == t && iter->next->x < x)
		{
			temp = (node *)malloc(sizeof(node));
			temp->x = x;


			temp->next = t;
			t->prev = temp;
			iter->next->next = temp;
			temp->prev = iter->next;
			return *h;
		}

		iter = iter->next;
	}
	return *h;
}


//Silme Fonksiyonu
node sil(node * h, node * t, int x) 
{
	node * temp;
	node * iter = h;
	//Silinecek sayı kalmadıysa aşağıdaki ifadeyi bastır.
	if(h->next == t)
	{
		cout << "Silinecek sayi kalmadi";
		
	}
	// Tüm düğümler için silinme işlemi aşağıdaki gibidir.iter ile ileri hareket yaparak 
	while(iter->next !=t )
	{
		if (iter->next->x == x)
		{
			temp = iter->next;
			iter->next = temp->next;
			temp->next->prev = iter;
			free(temp);
			return * h;
		}
		//Eğer x bulunmazsa iteri ilerlet.
	iter = iter->next;
	}
	
	return  * h;
}

//Yazdırma fonksiyonu
void yazdir(node * h, node * t)
{
	node *iter = h->next;
	while (iter != t)
	{
		cout << iter->x;
		iter = iter->next;

		cout << "\t";
	}
	cout << endl;

}
int main()
{  //header ve trailer fonksiyonu mainde oluşturuldu. header sonraki nodu trailer , trailer ın önceki nodu header oldu.
	node * header;
	header = (node *)malloc(sizeof(node));
	node * trailer;
	trailer = (node *)malloc(sizeof(node));
	header->next = trailer;
	trailer->prev = header;


	ekle(header, trailer, 15);
	ekle(header, trailer, 10);
	ekle(header, trailer, 12);
	ekle(header, trailer, 14);
	ekle(header, trailer, 9);
	ekle(header, trailer, 17);
	ekle(header, trailer, 16);
	ekle(header, trailer, 120);
	yazdir(header, trailer);
	sil(header, trailer, 9);

	yazdir(header, trailer);
	sil(header, trailer, 1);

	sil(header, trailer, 120);
	sil(header, trailer, 17);
	yazdir(header, trailer);
	sil(header, trailer, 15);
	sil(header, trailer, 10);
	sil(header, trailer, 12);
	sil(header, trailer, 14);
	sil(header, trailer, 16);//Buraya kadar tüm nodelar silindi.
	sil(header, trailer, 1);
	yazdir(header, trailer);
	system("pause");
	return 0;

}



