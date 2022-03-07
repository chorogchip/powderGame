

#include <locale.h>

#include "ch/main/GameLauncher.h"


int main(int argc, char* args[]) {
	setlocale(LC_ALL, "KOREAN");
	ch::GameLauncher gameLauncher;
	int result = gameLauncher.launch();

	return result;
}
