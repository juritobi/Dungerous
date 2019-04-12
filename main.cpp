#include "include/App.h"
#include <iostream>
int main()
{
	App* app = App::getApp();
    app->run();
}
