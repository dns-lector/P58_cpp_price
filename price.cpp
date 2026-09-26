#include "price.h"
#include <iostream>

bool Price::init() {
	std::ofstream file(PRICE_FILENAME);
	if (!file.is_open()) {
		std::cout << "File open error";
		return false;
	}
	Product product = { "Black Pencil", 14.95f, 20, 0 };
	product.save_to_file(file);

	product = { "Blue Pen", 19.95f, 25, 5 };
	product.save_to_file(file);

	product = { "Green Whiteboard Marker", 17.50f, 10, 10 };
	product.save_to_file(file);

	product = { "Lined Copybook", 7.50f, 20, 10 };
	product.save_to_file(file);

	product = { "Grided Copybook", 7.50f, 20, 5 };
	product.save_to_file(file); 

	product = { "Ruller 30cm", 3.50f, 50, 0 };
	product.save_to_file(file); 

	file.close();
	return true;
}

bool Price::load() {
	std::ifstream file(PRICE_FILENAME);
	if (!file.is_open()) {
		std::cout << "File open error";
		return false;
	}
	ListNode* last = NULL;
	// видаляємо наявні товари перед зчитуванням файлу
	if (first) {   // якщо вони є
		do {
			last = first->next;
			delete first;
			first = last;
		} while (first);  // while (first != NULL)
	}
	Product product;
	while (product.load_from_file(file)) {
		if (last == NULL) {
			first = last = new ListNode;
			last->product = product;
			last->next = NULL;
		}
		else {
			last->next = new ListNode;
			last->next->product = product;
			last->next->next = NULL;
			last = last->next;
		}
	}
	file.close();
	return true;
}

void Price::show() const {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}
	ListNode* node = first;
	while (node) {
		std::cout << node->product.to_string() << std::endl;
		node = node->next;
	}
}

void Price::show_by_price_ascending() {
	// сортування - переставляння неправильно впорядкованих елементів
	// до тих пір, поки їх не стане (всі у правильному порядку)
	/* Перестановка у переліку :
	* [p1|n]->[p2|n]->[p3|n]->[p4|n]   поміняти місцями p2 i p3
	* а) поміняти значення Р в двох вузлах (через проміжну змінну)
	*    [p1|n]->[p3|n]->[p2|n]
	*   ! через те, що структури великі, це тягне за собою багато операцій
	* б) поміняти покажчики на вузли
	*    [p1|n]---------->[p3|n]   - більш ефективна операція
	         p4<-[p2|n]<------|    
	*/
	// окремо обробляємо випадки, коли перелік порожній або в ньому один елемент
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}
	if (first->next == NULL) {
		std::cout << first->product.to_string() << std::endl;
		return;
	}
	bool is_ordered;
	do {
		is_ordered = true;
		ListNode* node = first;
		// окремо перевіряємо перші два
		if (node->product.price > node->next->product.price) {
			// f
			// [p1|n]->[p2|n]->[p3|n]
			//
			//  ---->f  
			//       [p2|n]
			//  <--------|
			// [p1|n]--------->[p3|n]
			ListNode* tmp = first->next;
			first->next = first->next->next;  // p1.next = p3 (p2.next)
			first->next->next = first;        // p2.next = p1
			node = first = tmp;               // ---->f 
			is_ordered = false;
		}
		while (node->next->next) {
			ListNode* tmp = node->next;      // tmp = p2
			if (node->next->product.price > node->next->next->product.price) {
				// порядок неправильний - міняємо порядок
				node->next = node->next->next;   // p1.next = p3
				tmp->next = tmp->next->next;  // p2.next = p3.next
				tmp->next->next = tmp;  // p3.next = p2
				is_ordered = false;
			}
			node = tmp;  // переходимо до наступного
		}
	} while (!is_ordered);
	// відображення передаємо на інший метод
	show();
}