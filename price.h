#pragma once
#include "product.h"

struct ListNode {   // для зв'язного списку
	Product product;
	ListNode* next = NULL;
};

struct Price {
	const std::string PRICE_FILENAME = "price.txt";
	ListNode* first = NULL;

	bool init();  // інкапсуляція - перенесення функцій, пов'язаних
	bool load();  // з прайсом до окремої "капсули" - структури Price
	void show() const;
};
