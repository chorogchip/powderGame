
#include <locale.h>

#include "GameLauncher.h"


int main(int argc, char* args[]) {
	setlocale(LC_ALL, "KOREAN");
	ch::GameLauncher gameLauncher;
	int ret = gameLauncher.launch();

	return ret;
}
