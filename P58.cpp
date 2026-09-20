#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "product.h"
#include "price.h"

int main()
{
	setlocale(LC_ALL, "UA");
	Price* price = new Price();
	while (true) {
		int choice;
		std::cout << "Choice an action:\n"
			<< "1: Init price\n"
			<< "2: Load price\n"
			<< "3: Show price\n"
			<< "0: Exit\n";

		choice = _getch();
		switch (choice) {
		case 49:  // '1'
			if (price->init()) {
				std::cout << "Price init success" << std::endl;
			}
			else {
				std::cout << "Price init error" << std::endl;
			}
			break;
		case 50:  // '2'
			if (price->load()) {
				std::cout << "Price load success" << std::endl;
			}
			else {
				std::cout << "Price load error" << std::endl;
			}
			break;
		case 51:  // '3'
			price->show();
			break;
		case 48:  // '0'
			return 0;
		default:
			std::cout << "Invalid choice" << std::endl;
		}
	}
	return 0;
}
/* git - VCS (Version Control System)
система, що дозволяє "зберігати" версії коду з 
можливістю повернення до попередніх версій, а також
утворення відгалужень (гілок) з різним розвитком проєкту.
Суть - збереження "різниці" - відмінностей між попереднім
і поточним станом проєкту - коміти (commits).
Це також спрощує сумісну роботу з проєктом різними учасниками.

Github - hub (місце для розміщення) репозиторіїв проєктів.
Репозиторій - частина проєкту, до якої входить код, 
напрацьований розробниками, і не входять загальні ресурси,
які можна довантажити окремо (загальні бібліотеки тощо),
а також результати компіляції та збірки (проміжні та виконавчі 
файли).
Відмінність задається спец.файлом ".gitignore"

Для того щоб створити та опублікувати репозиторій необхідно
- ініціалізувати репозиторій
- створити перший коміт
- опублікувати репозиторій (GitHub, Azure DevOps, 
   BitBucket, GitLab тощо)
= Visual Studio дозволяє поєднати всі ці кроки в меню 
    Git->Create Git Repository
	але за наявного облікового запису
*/
